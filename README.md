# chp



# icp-testbench

Test bench for different ICP implementations

## src/opencv_icp
The goal of this project is to provide a test bench for the OpenCV ICP algorithm, the main objective being to determine the influence of all the matching problem's parameyers (point cloud properties, transformation parameters and ICP initialization) on the efficiency and precision of the ICP's resulting transformation pose.

### OpenCV's ICP implementation

The first ICP algoruthm we tested is the matching algorithm that can be found in the `ppf_match_3d` class in **OpenCV**'s [surface matching module](https://docs.opencv.org/3.2.0/d0/de6/namespacecv_1_1ppf__match__3d.html).
This class implements a relatively efficient and robust variant of the iterative closest point (ICP) algorithm. The task is to register a 3D model (or point cloud) against a set of noisy target data. This implementation is able to compute from two point clouds (**the model** the 'original' point cloud, and **the scene** the coorespending moved point cloud) as well as a number of input parameters, the transformation's matrix and therfore its parameters. 

### How to build and compile this project
This project is built with Cmake and uses the `OpenCV` [librairy](https://opencv.org/), when in the source folder:
```shell
mkdir build
cmake -S . -B build/
```

Compile with `make` in the **build** folder.

### How to use the OpenCV ICP test bench:
The file **param.txt** contains all the input parameters (ICP and motion parameters). Under each parameter the user can specify the start and end of the testing interval as well as the number of testing points:
````text
parameter
start end number_of_test_points
````
An example and more explanation are provided in the input file.
>**_NOTE:_** Only one parameter can be varied in one execution run, the third field of all the other parameters is to remain 0.

To execute the code on sample point cloud **sample.ply**  using ICP parameters located in file **param.txt** when in **build/**:
```shell
make sample.ply param.txt
```
