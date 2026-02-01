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
                // 优化：用一个指针接住队头，方便后面操作
                TreeNode* cur = que.front(); 
                que.pop(); // 记得弹出！
                
                temp.push_back(cur->val);
                
                // ⚠️ 修正点：判空后再入队
                if(cur->left != nullptr) que.push(cur->left);
                if(cur->right != nullptr) que.push(cur->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};