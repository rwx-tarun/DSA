PreOrder Traversal 

TC - O(N) - all nodes accessed once 
SC - O(N) - stack 

1.take stack push node 
2. push node to res pop from stack 
3. push the right first 
4. push left 


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
          
            res.push_back(root->data);
            f(root->left,res);
            f(root->right,res);
        }
		vector<int> preorder(TreeNode* root){
	        if(root == NULL)    return {};
	        vector<int>res;
            stack<TreeNode* >st;
            st.push(root);
            while(!st.empty()){
                TreeNode* node = st.top();
                st.pop();
                res.push_back(node->data);
                if(node->right){
                    st.push(node->right);
                }
                if(node->left){
                    st.push(node->left);
                }
            }
            return res;
		}
};
