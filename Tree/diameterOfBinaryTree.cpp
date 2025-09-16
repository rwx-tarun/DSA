/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int f(TreeNode * root , int &mx){
        if(root == NULL)    return 0;
        int lf = f(root->left, mx);
        int rt = f(root->right, mx);
        mx = max(mx , (lf + rt));
        return 1 + max(lf ,rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int mx = 0;
        f(root,mx);
        return mx;
    }
};
