cd ~/VLSI/VLSI_HW3
tar -zcvf CS6135_HW3_114062616.tar.gz HW3/
scp CS6135_HW3_114062616.tar.gz \
    g114062616@ic21:/users/course/2025F/VLSIPDA202510/g114062616/HW3_grading/student/114062616/
ssh g114062616@ic21 "cd HW3_grading && bash HW3_grading.sh"