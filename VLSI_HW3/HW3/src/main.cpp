#include "design_io.hpp"
#include "detailPlacement.hpp"
#include <iostream>
#include <cstdint>
int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage:\n  "
                  << argv[0]
                  << " <input.lef> <input.def> <output.def>\n"
                  << "Example:\n  "
                  << argv[0]
                  << " ../testcase/public1.lef ../testcase/public1.def ../output/public1.def\n";
        return 1;
    }
    const std::string lefIn  = argv[1];  // e.g. ../testcase/public1.lef
    const std::string defIn  = argv[2];  // e.g. ../testcase/public1.def
    const std::string defOut = argv[3];  // e.g. ../output/public1.def

    Design d;

    if (!loadLEF(lefIn, d)) {
        std::cerr << "[ERR] loadLEF failed on " << lefIn << "\n";
        return 1;
    }
    
    if (!loadDEF(defIn, d)) {
        std::cerr << "[ERR] loadDEF failed on " << defIn << "\n";
        return 1;
    }

    std::cout << "macros=" << d.macros.size()
              << " insts=" << d.insts.size()
              << " nets="   << d.nets.size()
              << " rows="   << d.layout.rows.size()
              << "\n";

    if (!d.macros.empty()) {
        std::cout << "firstMacro " << d.macros[0].name
                  << " size=(" << d.macros[0].width
                  << ","       << d.macros[0].height
                  << ")\n";
    }

    if (!d.sites.empty()) {
        std::cout << "firstSite " << d.sites[0].name
                  << " size=(" << d.sites[0].sizeX
                  << ","       << d.sites[0].sizeY
                  << ")\n";
    }

    int64_t hpwl_before = d.totalHPWL();
    std::cout << "HPWL before = " << hpwl_before << "\n";
    simpleDetailPlacement(
        d,
        /*maxIter=*/10,
        /*deltaX_micron=*/1  // currently unused in most of our newer impls
    );
    if (!writeDEFPreserve(defIn, defOut, d)) {
        std::cerr << "[ERR] writeDEFPreserve failed writing " << defOut << "\n";
        return 1;
    }

    std::cout << "Output DEF written to " << defOut << "\n";
    return 0;
}

