
    ~/github$ ls
    ~/github$ git clone https://github.com/chen3feng/typhoon-blade
    ~/github$ touch BLADE_ROOT
    BLADE_ROOT typhoon-blade
    ~/github$ ./typhoon-blade/install
    ~/github$ mkdir thirdparty
    ~/github$ ls
    BLADE_ROOT  thirdparty  typhoon-blade

## gfalgs ##

    ~/github/thirdparty/install$ ls
    gflags-2.0.tar.gz  readme.md

    ~/github/thirdparty/install$ tar xvzf gflags-2.0.tar.gz
    ~/github/thirdparty/install/gflags-2.0$ cd gflags-2.0 && ./configure
    ~/github/thirdparty/install/gflags-2.0$ cd .. && mv gflags-2.0 ../..

## gtest ##

同`gflags`类似. 注意: 因为此处将gtest放在thirdparty, 而不是系统安装,
需要修改`~/github/typhoon-blade$ vi src/blade/configparse.py`:

    28             'cc_test_config' : {                                                
    29                 'dynamic_link' : False,                                         
    30                 'heap_check' : '',                                              
    31                 'gperftools_lib' : '#tcmalloc',                                 
    32                 'gperftools_debug_lib' : '#tcmalloc_debug',                     
    33                 'gtest_lib' : 'thirdparty/gtest:gtest',                         
    34                 'gtest_main_lib' : 'thirdparty/gtest:gtest_main'                
    35             },

修改完成后, 执行:

    ~/github/typhoon-blade$ ./dist_blade && ./install 

## opencv ##

### prerequisites ###

    sudo apt-get install build-essential
    sudo apt-get install cmake
    sudo apt-get install pkg-config
    sudo apt-get install libpng12-0 libpng12-dev libpng++-dev libpng3
    sudo apt-get install libpnglite-dev libpngwriter0-dev libpngwriter0c2
    sudo apt-get install zlib1g-dbg zlib1g zlib1g-dev
    sudo apt-get install libjasper-dev libjasper-runtime libjasper1
    sudo apt-get install pngtools libtiff4-dev libtiff4 libtiffxx0c2 libtiff-tools
    sudo apt-get install libjpeg8 libjpeg8-dev libjpeg8-dbg libjpeg-prog
    sudo apt-get install ffmpeg libavcodec-dev libavcodec52 libavformat52 libavformat-dev
    sudo apt-get install libgstreamer0.10-0-dbg libgstreamer0.10-0 libgstreamer0.10-dev
    sudo apt-get install libxine1-ffmpeg libxine-dev libxine1-bin
    sudo apt-get install libunicap2 libunicap2-dev
    sudo apt-get install libdc1394-22-dev libdc1394-22 libdc1394-utils
    sudo apt-get install swig
    sudo apt-get install libv4l-0 libv4l-dev
    sudo apt-get install libpython2.7 python-dev python2.7-dev 
    sudo apt-get install python-numpy
    
安装webp, [libwebp-0.2.1.tar.gz](https://code.google.com/p/webp/downloads/detail?name=libwebp-0.2.1.tar.gz):

    tar xvzf libwebp-0.2.1.tar.gz
    ./configure
    make
    make install

安装openexr, 需要[ilmbase-1.0.2.tar.gz](http://www.openexr.com/downloads.html)和
[openexr-1.7.0.tar.gz](http://www.openexr.com/downloads.html):

    [install ilmbase]
    The same as libwebp.
    
    [install openexr]
    in dir ~/github/thirdparty/install/openexr-1.7.0:
    1. /usr/local/include/OpenEXR/ImathMatrix.h:1813:5:error: 'memset' was not declared in this scope
    
      sudo chmod a+w /usr/local/include/OpenEXR/ImathMatrix.h
      vi /usr/local/include/OpenEXR/ImathMatrix.h
      add #include "string.h"
    
    2. blurImage.cpp:423:62:error: ‘memcpy’ was not declared in this scope

      sudo chmod a+w exrenvmap/blurImage.cpp
      vi exrenvmap/blurImage.cpp
      add #include "string.h"

**注: 折腾了半天安装如上两个库`webp`和`openexr`, 最后发现其实并不需要, 在opencv的3rdparty下有提供.**

### build ###

Download source code:

    ~/github/thirdparty/install$ git clone https://github.com/Itseez/opencv opencv-trunk

To generate shared library:

    ~/github/thirdparty/install/opencv-trunk$ cmake \
      -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=~/tmp/opencv2 \
      -D BUILD_NEW_PYTHON_SUPPORT=ON \
      -D BUILD_EXAMPLES=ON \
      -D BUILD_SHARED_LIBS=OFF \
      .
    
    ~/tmp/opencv2$ ls lib/
    libopencv_calib3d.so           libopencv_flann.so ...

To generate static library:

    ~/github/thirdparty/install/opencv-trunk$ cmake \
      -D BUILD_SHARED_LIBS=OFF \
      -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=~/tmp/opencv2 \
      -D BUILD_NEW_PYTHON_SUPPORT=ON \
      -D BUILD_EXAMPLES=ON \
      -D BUILD_SHARED_LIBS=OFF \
      .
    
    OR
    
    ~/github/thirdparty/install/opencv-trunk$ cmake \
      -D BUILD_SHARED_LIBS=OFF 
      -D CMAKE_BUILD_TYPE=RELEASE \
      -D CMAKE_INSTALL_PREFIX=~/tmp/opencv2 
      -D BUILD_NEW_PYTHON_SUPPORT=ON \
      -D BUILD_EXAMPLES=ON \
      -D BUILD_SHARED_LIBS=OFF \
      -D BUILD_ZLIB=ON \
      -D BUILD_TIFF=ON \
      -D BUILD_JASPER=ON \
      -D BUILD_JPEG=ON \
      -D BUILD_PNG=ON \
      -D OPENCV_BUILD_3RDPARTY_LIBS=ON \
      .

    ~/tmp/opencv2$ ls lib/
    libopencv_calib3d.a            libopencv_flann.a ...
    libopencv_calib3d.so           libopencv_flann.so ...

### setting ###

    ~/github/thirdparty/install$ ./opencv-install.sh

注意: Opencv trunk中的代码不太稳定, 总是有一些小问题, 比如其install程序忘了
拷贝很多的.hpp文件到安装目录, 还需要执行:

    ~/github/thirdparty/install/opencv-trunk/modules$
    cp imgproc/include/opencv2/core.hpp ~/github/thirdparty/opencv2
    cp imgproc/include/opencv2/imgproc.hpp ~/github/thirdparty/opencv2
    cp photo/include/opencv2/photo.hpp ~/github/thirdparty/opencv2
    cp video/include/opencv2/video.hpp ~/github/thirdparty/opencv2
    cp features2d/include/opencv2/features2d.hpp ~/github/thirdparty/opencv2
    cp objdetect/include/opencv2/objdetect.hpp ~/github/thirdparty/opencv2
    cp calib3d/include/opencv2/calib3d.hpp ~/github/thirdparty/opencv2
    cp ml/include/opencv2/ml.hpp ~/github/thirdparty/opencv2
    cp highgui/include/opencv2/highgui.hpp ~/github/thirdparty/opencv2
    cp contrib/include/opencv2/contrib.hpp ~/github/thirdparty/opencv2
    cp flann/include/opencv2/flann.hpp ~/github/thirdparty/opencv2
    cp legacy/include/opencv2/legacy.hpp ~/github/thirdparty/opencv2

Append the following setting

    export PYTHONPATH=/home/qkjd/github/thirdparty/opencv2/lib/python2.7/dist-packages:$PYTHONPATH
    export LD_LIBRARY_PATH=/home/qkjd/github/thirdparty/opencv2/lib:$LD_LIBRARY_PATH

into file `~/.bashrc` or `~/.profile`.

### Simple testing ###

    [c/c++]
    ~/github/thirdparty/install/opencv-trunk/bin$ ./opencv_perf_core
    
    ...
    
    [----------] Global test environment tear-down
    [==========] 1682 tests from 47 test cases ran. (1293819 ms total)
    [  PASSED  ] 1682 tests.
    
    ~/github/thirdparty/install/opencv-trunk/bin$ ./opencv_test_flann 
    [==========] Running 1 test from 1 test case.
    [----------] Global test environment set-up.
    [----------] 1 test from Flann_LshTable
    [ RUN      ] Flann_LshTable.badarg
    [       OK ] Flann_LshTable.badarg (48 ms)
    [----------] 1 test from Flann_LshTable (48 ms total)

    [----------] Global test environment tear-down
    [==========] 1 test from 1 test case ran. (49 ms total)
    [  PASSED  ] 1 test.
    
    [python]
    ~/github/thirdparty/opencv2$ python
    Python 2.7.3 (default, Aug  1 2012, 05:16:07) 
    [GCC 4.6.3] on linux2
    Type "help", "copyright", "credits" or "license" for more information.
    >>> import cv
    >>> help(cv)
    Help on module cv:

    NAME
      cv - #/usr/bin/env python

    FILE
      /home/qkjd/github/thirdparty/opencv2/lib/python2.7/dist-packages/cv.py

    FUNCTIONS
      16SC(...)
        CV_16SC(n) -> int

    ...
    
    >>> print cv.Sqrt(2)
    1.41421353817

### references ###

1. [OpenCV Installation Guide](http://opencv.willowgarage.com/wiki/InstallGuide)

2. [Installing OpenCV on Linux](http://opencv.willowgarage.com/wiki/InstallGuide_Linux)

3. [OpenCV Installation Guide on Debian and Ubuntu](http://opencv.willowgarage.com/wiki/InstallGuide%20%3A%20Debian)

4. [Ubuntu12.04利用CMake-2.8.10.4编译OpenCV-2.4.4](http://blog.csdn.net/lili893628843/article/details/8688582)

by **xueminzhao** 3/23/2013