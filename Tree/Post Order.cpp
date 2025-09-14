
Post order traversal  - iterative 

vector<int> postorder(TreeNode* root){
    vector<int> result; 
    stack <TreeNode*> nodeStack; 
    nodeStack.push(root); 
    while(!nodeStack.empty()) {
        TreeNode* node = nodeStack.top(); 
        nodeStack.pop(); 
        result.push_back(node-> data); 
        if(node-> left) nodeStack.push(node-> left); 
        if(node-> right) nodeStack.push(node-> right);
    }
    reverse(result.begin(), result.end());
    return result; 
}
