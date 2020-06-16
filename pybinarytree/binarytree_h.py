#!/usr/bin/python
import ctypes

__all__ = ['Node', 'Tree']

from build_options import pybtlib, _DEBUG, ON

##############################################################################################
#ifndef __BINARYTREE__HEADER__
#define __BINARYTREE__HEADER__

UNSET_NODE_ID = -3

class Node(ctypes.Structure):
    """Wrapper for C struct Node."""
    pass

_Node_fields = [    #typedef struct Node{
              ("id", ctypes.c_int), #int id;
              ("val", ctypes.c_int), #int val;
              ("left", ctypes.POINTER(Node)), #Node* left;
              ("right", ctypes.POINTER(Node)), #Node* right;
              ] #} Node;

def _Node_showNodeOrdered(self, parent, left_or_right):
    """Wrapper for void showNodeOrdered(Node *, int, int)."""
    pybtlib.showNodeOrdered.restype = None
    pybtlib.showNodeOrdered.argtypes = [ctypes.POINTER(Node),
                                       ctypes.c_int, ctypes.c_int]
    return pybtlib.showNodeOrdered(ctypes.byref(self), parent, left_or_right)
def _Node_findNodeByVal(node_ptr, val):
    """Wrapper for Node **findNodeByVal(Node *)."""
    pybtlib.findNodeByVal.restype = ctypes.POINTER(ctypes.POINTER(Node))
    pybtlib.findNodeByVal.argtypes = [ctypes.POINTER(ctypes.POINTER(Node)),
                                     ctypes.c_int]
    return pybtlib.findNodeByVal(ctypes.byref(node_ptr), val)
def _Node__init__(self):
    """Node initializer."""
    self.id = UNSET_NODE_ID
    self.val = 0
    self.left = None
    self.right = None
    return
def _Node__del__(self):
    """Node destructor."""
    freeNodeArray(self.left)
    freeNodeArray(self.right)
    return

# Finally define the class below:
Node._fields_ = _Node_fields
Node.__init__ = _Node__init__
Node.__del__ = _Node__del__
Node.showOrdered = _Node_showNodeOrdered
Node.findNodeByVal = _Node_findNodeByVal

def freeNodeArray(node_ptr):
    """Wrapper for void freeNode(Node *)."""
    pybtlib.freeNode.restype = None
    pybtlib.freeNode.argtypes = [ctypes.POINTER(Node)]
    return pybtlib.freeNode(node_ptr)

##############################################################################################
class Tree(ctypes.Structure):
    """Wrapper for C struct Tree."""
    _fields_ = [    #typedef struct{
               ("root", ctypes.POINTER(Node)), #Node* root;
               ] #} Tree;
    def __init__(self):
        """Tree initializer."""
        self.root = None
        return
    def __del__(self):
        """Tree destructor."""
        return freeNodeArray(self.root)
    def showOrdered(self):
        """Wrapper for void showTree(Tree *)."""
        pybtlib.showTree.restype = None
        pybtlib.showTree.argtypes = [ctypes.POINTER(Tree)]
        return pybtlib.showTree(ctypes.byref(self))
    def insertVal(self, val):
        """Wrapper for void insertVal(Tree *, int).
        Instead of inserting a single val, a list of vals can be inserted."""
        pybtlib.insertVal.restype = None
        pybtlib.insertVal.argtypes = [ctypes.POINTER(Tree), ctypes.c_int]
        try:
            for i in val:
                pybtlib.insertVal(ctypes.byref(self), i)
        except:
            pybtlib.insertVal(ctypes.byref(self), val)
        return
    def lookupVal(self, val):
        """Wrapper for int lookupVal(Tree *, int)."""
        pybtlib.lookupVal.restype = ctypes.c_int
        pybtlib.lookupVal.argtypes = [ctypes.POINTER(Tree), ctypes.c_int]
        return pybtlib.lookupVal(ctypes.byref(self), val)

def allocTree(tree_ptr):
    """Wrapper for void allocTree(Tree **).
    Note: this is redundant since the Tree.__init__ function does it easily."""
    pybtlib.allocTree.argtypes = [ctypes.POINTER(ctypes.POINTER(Tree))]
    pybtlib.allocTree.restype  = None
    return pybtlib.allocTree(ctypes.byref(tree_ptr))
def freeTree(tree_ptr):
    """Wrapper for void freeTree(Tree *)."""
    pybtlib.freeTree.restype = None
    pybtlib.freeTree.argtypes = [ctypes.POINTER(Tree)]
    if (self is not None):
        print("Failed to free the tree. Exiting the program.")
        sys.exit(1)
    return pybtlib.freeTree(tree_ptr)

#endif

##############################################################################################
def tests():
    pass

##############################################################################################
if (__name__ == '__main__'):
    tests()
