#include "binary-tree.hh"


int main(int argc, char **argv) {
    BinaryTree bt;

    bt.add(10);
    bt.add(5);
    bt.add(6);
    bt.add(14);
    bt.add(12);
    bt.add(15);

    bt.print_inorder();

    return 0;

}
