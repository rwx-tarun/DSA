TC - O(N)
SC - O(N) - recursion stack or stack in iterative 


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
        void f(TreeNode * root,vector<int> &res){
            if(root == NULL){
                return;
            }
            f(root->left,res);
            res.push_back(root->data);
            f(root->right,res);
        }
		vector<int> inorder(TreeNode* root){
            if(root == NULL)    return {};
	        // vector<int>res;
            // f(root,res);
            // return res;
            vector<int>res;
            TreeNode* node = root;
            stack<TreeNode*>st;
            while(true){
                if(node != NULL){
                    st.push(node);
                    node = node->left;
                }else{
                    if(st.empty())  break;
                    node = st.top();
                    st.pop();
                    res.push_back(node->data);
                    node = node->right;
                }
            }
            return res;
		}
};
