class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        
        queue<TreeNode*> que;    
        que.push(root);
        
        while(!que.empty()){
            int lenth = que.size();
            vector<int> temp;
            
            for(int i = 0; i < lenth; i++){
                TreeNode* cur = que.front(); 
                que.pop();
                
                temp.push_back(cur->val);
                
                if(cur->left != nullptr) que.push(cur->left);
                if(cur->right != nullptr) que.push(cur->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};