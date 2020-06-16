#!/usr/bin/env python
"""
CMAKE generated critical python file to enforce compatibility
between C binarytree library structures and python class definitions.
"""

from ctypes import cdll

from define_h import ON, OFF

__all__ = [
          'pybtlib',
          'BUILD_DEBUG_LEVEL',
          '_DEBUG',
          'ON',
          'OFF',
          ]

pybintree_path      = '/workspace/gajanan/postdoc_2019/ctypes-tutorial'
libbintree_path     = '/workspace/gajanan/postdoc_2019/ctypes-tutorial/build/lib/libbinarytree_shared.so'

BUILD_DEBUG_LEVEL   = 0
_DEBUG              = OFF

pybtlib = cdll.LoadLibrary(libbintree_path)


if (__name__ == '__main__'):
    print '_DEBUG            =', _DEBUG
