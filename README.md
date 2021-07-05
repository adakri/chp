# chp



# icp-testbench

Test bench for different ICP implementations.

## OpenCV's ICP

The goal of this project is to provide a test bench for the OpenCV ICP algorithm, the main objective being to determine the influence of all the matching problem's parameyers (point cloud properties, transformation parameters and ICP initialization) on the efficiency and precision of the ICP's resulting transformation pose.

### src/opencv_icp
Contains different C++ files for ICP tests. 
**Models/** Default folder for the point clouds that could be used for the testing.
**test_files** Default folder for output files (testing results).

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
The output is a **.csv** file named after the parameter the user chose to change: it details through different metrics (L1,L2,Linf and L2inv norms) between the real and ICP transfomation matrices as well as the difference betwen the real and ICP motion parameters.


<div class="mxgraph" style="max-width:100%;border:1px solid transparent;" data-mxgraph="{&quot;highlight&quot;:&quot;#0000ff&quot;,&quot;nav&quot;:true,&quot;resize&quot;:true,&quot;toolbar&quot;:&quot;zoom layers lightbox&quot;,&quot;edit&quot;:&quot;_blank&quot;,&quot;xml&quot;:&quot;&lt;mxfile host=\&quot;app.diagrams.net\&quot; modified=\&quot;2021-07-05T13:31:32.065Z\&quot; agent=\&quot;5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36\&quot; etag=\&quot;TAf6640ipeZMi47hnowc\&quot; version=\&quot;14.8.4\&quot; type=\&quot;google\&quot;&gt;&lt;diagram id=\&quot;lUKmA2nsRijQkwaukXyh\&quot; name=\&quot;Page-1\&quot;&gt;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&lt;/diagram&gt;&lt;/mxfile&gt;&quot;}"></div>
<script type="text/javascript" src="https://viewer.diagrams.net/js/viewer-static.min.js"></script>
