# AVL Tree
AVL trees are height-balanced binary search trees. This BST's nodes keep a balance factor by calculating the difference of their subtrees' heights. Height difference can no more than 1 else the tree has to rotate. Find, Insert, and Delete operation of an AVL tree takes O(log N) but deletions and insertions may require double rotations.

[More Info Wiki](https://en.wikipedia.org/wiki/AVL_tree)
[Visualisation](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)

### Setup
- This project uses [Google C++ Test Framework](https://github.com/google/googletest) for its tests, you need to link gtest in order to be able to run the tests. ([Psst! Do you want to know how to keep console open](https://stackoverflow.com/a/1152873))

- This project is coded and tested on Windows using Visual Studio without the intention of cross platform.

- If you are not going to use tests then there shouldn't be any need for an external library. 
