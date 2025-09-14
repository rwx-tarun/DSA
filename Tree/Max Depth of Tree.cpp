class Solution {
public:
    int f(TreeNode* root) {
        if(root == NULL)    return 0;
        int lf = f(root->left);
        int rt = f(root->right);
        return 1 + max(lf , rt);
    }
    int maxDepth(TreeNode* root) {
        return f(root);
    }
};
