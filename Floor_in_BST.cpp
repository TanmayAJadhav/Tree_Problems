// You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
// Note: when x is smaller than the smallest node of BST then returns -1.

int floor(Node* root, int x)
{
    if (root == NULL) return -1;
    int floor = -1;
    while(root != NULL)
    {
        if(root->data == x)
        {
            return x;
        }
        if(root->data > x)
        {
            root = root->left;
        }
        else
        {
            floor = root->data;
            root = root->right;
        }
    }
    return floor;
}