# ctypes-tutorial
Tutorial, tips, and tricks for wrapping C/C++ projects into Python using ctypes.

## Table of contents
* [General info](#general-info)
* [Setup](#setup)
    * [Dependencies](#dependencies)
    * [Usage](#usage)
* [Features](#features)
* [Status](#status)
* [License](#license)
* [Contributors](#contributors)
* [Acknowledgments](#acknowledgments)

## General info
This repository serves as an example on how to smartly wrap a C project into
Python using `ctypes`, the in-built foreign-function Python library. The
motivation of this work is to modernize C software and libraries by wrapping
them into Python.

## Setup
### Dependencies
* Bash
* C compiler -- has been tested on gcc.
* Python 2.7 -- for now; support for other versions of Python may be added later.

### Usage
CMake is used to build this project. Run the following commands from your
terminal to build the library and the Python interface:
```
mkdir build
cd build
cmake -DMAKE_SHARED_LIBRARY=ON ..
make
cd ..
```

Then run python from the root directory, import the pybinarytree package and use
it. For example:
```
import pybinarytree as pbt
tree = pbt.Tree()
tree.insertVal([-1, 2, 0, 6, 1, 221, -3, 5, 8, 7])
tree.showOrdered()
```

## Features
List of features that are ready:
* Demonstrates examples of how an entire project can be wrapped into ctypes
  smartly
* Demonstrates how to handle preprocessor-directive-dependent code (#ifdef ...)
* Demonstrates pitfalls of wrapping C code using ctypes

## Status
Project is: _in progress_.

## License
This repository is is unlicensed. See the
[LICENSE file](https://github.com/gajanan-choudhary/ctypes-tutorial/blob/master/LICENSE)
in the main/root directory of this repository, or visit
[https://unlicense.org](https://unlicense.org) for details.

This repository uses and builds upon another code by the same author (Gajanan
Choudhary), named
[binarytree](https://github.com/gajanan-choudhary/binarytree). That code is also
unlicensed.

## Contributor
* **Gajanan Choudhary** - [website](https://users.oden.utexas.edu/~gajanan/)

## Acknowledgments
* `ctypes` documentation
* Stackoverflow

