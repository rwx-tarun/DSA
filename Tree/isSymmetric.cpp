/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    bool mirror(TreeNode* left,TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        if(left->data != right->data)   return false;
        return mirror(left->left,right->right) && mirror(left->right,right->left);

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)    return true;
        return mirror(root->left,root->right);
    }
};
