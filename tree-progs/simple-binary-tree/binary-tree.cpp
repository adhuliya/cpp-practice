#include "binary-tree.hh"
#include <iostream>

int BinaryTree::remove (int key) {

}

int BinaryTree::add (int key, int data) {
    int success = 1;

    if (btree == nullptr) {
        btree = new BinaryTreeNode(key, data);
        return success;
    }

    auto addhere = find_insert_point(key);

    if (*addhere == nullptr) {
        *addhere = new BinaryTreeNode(key, data);
    } else {
        success = 0;
    }

    return success;
}

BinaryTreeNode* BinaryTree::find_node(int key) {
    // FIXME
    BinaryTreeNode *btn = btree;

    while(btn != nullptr) {
        if (key == btn->key ) {
            return btn;
        } else if (key <= btn->key) {
            btn = btn->left;
        } else {
            btn = btn->right;
        }
    }

    return nullptr;
}

BinaryTreeNode** BinaryTree::find_insert_point(int key) {
    BinaryTreeNode *btn = btree;

    while(btn != nullptr) {
        if (key == btn->key ) {
            return nullptr;
        } else if (key <= btn->key) {
            if (btn->left == nullptr) return &(btn->left);
            btn = btn->left;
        } else {
            if (btn->right == nullptr) return &(btn->right);
            btn = btn->right;
        }
    }

    return nullptr;
}

void BinaryTree::print_inorder () {
    print_inorder (btree);
}

void BinaryTree::print_inorder (BinaryTreeNode *btn) {
    if (btn == nullptr) return;

    print_inorder(btn->left);
    std::cout << "(" << btn->key << ", " << btn->data << ") ";
    print_inorder(btn->right);
}

BinaryTreeNode::BinaryTreeNode () {
    key = data = 0;
    left = right = nullptr;
}

BinaryTreeNode::BinaryTreeNode (int key, int data) {
    this->key = key;
    this->data = data;
    left = right = nullptr;
}
