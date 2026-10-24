#include <iostream>
#include <cassert>
#include "intbst.h"

using namespace std;

int main() {
    IntBST tree;

    assert(tree.count() == 0);
    assert(tree.sum() == 0);
    assert(!tree.contains(10));

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(20);

    assert(tree.count() == 7);
    assert(tree.sum() == 72);

    assert(tree.contains(10));
    assert(tree.contains(3));
    assert(tree.contains(20));
    assert(!tree.contains(100));

    assert(!tree.insert(10));
    assert(tree.count() == 7);

    cout << "Preorder: ";
    tree.printPreOrder();
    cout << endl;

    cout << "Inorder: ";
    tree.printInOrder();
    cout << endl;

    cout << "Postorder: ";
    tree.printPostOrder();
    cout << endl;

    assert(tree.getPredecessor(10) == 7);
    assert(tree.getPredecessor(3) == 0);
    assert(tree.getSuccessor(10) == 12);
    assert(tree.getSuccessor(20) == 0);

    assert(tree.remove(3));
    assert(!tree.contains(3));

    assert(tree.remove(15));
    assert(!tree.contains(15));

    assert(tree.remove(10));
    assert(!tree.contains(10));

    assert(!tree.remove(100));

    assert(tree.count() == 4);
    assert(tree.sum() == 44);

    cout << "All tests passed!" << endl;

    return 0;
}
