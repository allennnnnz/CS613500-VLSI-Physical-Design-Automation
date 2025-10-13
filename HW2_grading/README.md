# Homework 2 Grading Script
We will use this script to grade your program. **Make sure your program can be executed by this script.**

## Preparing
* Step1:  
    Enter the `HW2_grading` directory and create a new directory named with your student ID in the `student` directory.
    ```sh
    $ cd HW2_grading/
    $ mkdir student/${your_student_id}
    ```
    For example,
    ```sh
    $ cd HW2_grading/
    $ mkdir student/114000000
    ```

* Step2:  
    Put your compressed file in the directory which you just created.  
    The correct path should be:
    ```
    HW2_grading/student/${your_student_id}/CS6135_HW2_${your_student_id}.tar.gz
    ```
    For example,
    ```
    HW2_grading/student/114000000/CS6135_HW2_114000000.tar.gz
    ```

### Notice:
**Please make sure not to put your original directory here**, as it will remove all directories before unzipping the compressed file.

## Grading
* Step1:  
    Navigate to the `HW2_grading` directory and run `HW2_grading.sh`.
    ```sh
    $ cd HW2_grading/
    $ bash HW2_grading.sh
    ```

* Step2:  
    Check your output. Ensure the status of each checking item is **yes**.
    * If the status of a testcase is **success**, it means your program finished in time, and the output result is legal.
        ```
        host name: ic21
        compiler version: g++ (GCC) 9.3.0
        
        grading on 114000000:
         checking item          | status
        ------------------------|--------
         correct tar.gz         | yes
         correct file structure | yes
         have README            | yes
         have Makefile          | yes
         correct make clean     | yes
         correct make           | yes
        
          testcase |      #ways |   cut size |    runtime | status
        -----------|------------|------------|------------|--------
           public1 |          2 |        557 |       0.12 | success
           public1 |          4 |       1450 |       0.17 | success
           public2 |          2 |       5240 |       5.19 | success
           public2 |          4 |       7269 |      10.76 | success
        ```

    * If the status of a testcase is not **success**, it means your program failed in this testcase.
        ```
        host name: ic21
        compiler version: g++ (GCC) 9.3.0
        
        grading on 114000000:
         checking item          | status
        ------------------------|--------
         correct tar.gz         | yes
         correct file structure | yes
         have README            | yes
         have Makefile          | yes
         correct make clean     | yes
         correct make           | yes
        
          testcase |      #ways |   cut size |    runtime | status
        -----------|------------|------------|------------|--------
           public1 |          2 |        557 |       0.12 | success
           public1 |          4 |       1450 |       0.19 | success
           public2 |          2 |        N/A |        TLE | Time out while testing public2.
           public2 |          4 |        N/A |        TLE | Time out while testing public2.
        ```
