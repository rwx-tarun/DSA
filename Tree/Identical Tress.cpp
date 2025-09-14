    bool f(TreeNode * p , TreeNode * q){
        if(p == NULL || q == NULL){
            return p ==q ;
        }
        return (p->data == q->data) && f(p->left,q->left) && f(p->right,q->right);

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       return f(p,q);
    }
