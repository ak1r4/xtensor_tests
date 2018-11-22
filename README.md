xtensor tests

``` bash
$ conda create -p env xtensor-python python=3.6
$ conda activate $PWD/env
$ mkdir build
$ cd build
$ cmake -DCMAKE_MODULE_PATH=$PWD/../cmake ..
$ make

# c++
$ ./xtensor_test

# python
$ PYTHONPATH=. python ../test.py
```
