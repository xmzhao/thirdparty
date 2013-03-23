
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
