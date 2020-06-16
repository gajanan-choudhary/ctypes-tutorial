#!/usr/bin/python
import ctypes

from build_options import pybtlib, _DEBUG, ON

##############################################################################################
#ifndef __BINARYTREE__HEADER__
#define __BINARYTREE__HEADER__
def testGeneralTree():
    """Wrapper for C function testGeneralTree()."""
    pybtlib.testGeneralTree.restype = None
    pybtlib.testGeneralTree.argtypes = None
    return pybtlib.testGeneralTree()

def testSortedTraversal():
    """Wrapper for C function testSortedTraversal()."""
    pybtlib.testSortedTraversal.restype = None
    pybtlib.testSortedTraversal.argtypes = None
    return pybtlib.testSortedTraversal()
#endif

##############################################################################################
def tests():
    testGeneralTree()
    testSortedTraversal()
    return 0

##############################################################################################
if (__name__ == '__main__'):
    tests()
