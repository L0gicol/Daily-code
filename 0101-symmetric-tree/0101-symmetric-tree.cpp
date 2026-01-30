class Solution {
public:
	bool check(TreeNode* l,TreeNode* r){
		if(l == nullptr && r == nullptr){
			return true;
		}
		else if((l == nullptr || r == nullptr)&&(l || r)){
			return false;
		}
		else if(l->val != r->val){
			return false;
		}
		return check(l->left, r->right) && check(l->right, r->left);
	}
	bool isSymmetric(TreeNode* root) {
		return check(root->left,root->right);
	}
};