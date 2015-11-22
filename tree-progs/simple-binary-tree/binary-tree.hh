class BinaryTreeNode {
    public:
        int key;
        int data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
        
        BinaryTreeNode ();
        BinaryTreeNode (int key, int data);
};

class BinaryTree {
    BinaryTreeNode *btree;
    public:
        BinaryTree () {
            btree = nullptr; // new BinaryTreeNode();
        }
        void print_inorder ();
        void print_inorder (BinaryTreeNode *btn);
        int add (int key, int data = 0);
        int remove (int key);
        // int update (int key, int newdata);
        // int get (int key);
        BinaryTreeNode** find_insert_point(int key);
        BinaryTreeNode* find_node(int key);
};

