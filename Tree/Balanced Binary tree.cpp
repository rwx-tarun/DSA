Brute for 
- go to all nodes calculate height 
- check height Left - heght right < 2
O(n2)

Optimal 

  int f(TreeNode * root){
        if(root == NULL)    return 0;
        int lf = f(root->left);
        int rt = f(root->right);

        if(lf == -1 || rt == -1)    return -1;
        if(abs (lf - rt) > 1)   return - 1;
        return 1 + max(lf,rt);
    }
    bool isBalanced(TreeNode* root) {
        int res = f(root);
        if(res == -1)
            return false;
        return true;
    }
