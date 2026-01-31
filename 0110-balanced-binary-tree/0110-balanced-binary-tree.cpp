class Solution {
public:
	int deep(TreeNode* root){
		if(root == nullptr) return 0;
		int leftdep = deep(root->left);
		int rightdep = deep(root->right);
		return max(leftdep,rightdep)+1;
		
	}
	bool isBalanced(TreeNode* root) {
		if(root == nullptr)	return true;
		if((deep(root->left)-deep(root->right)) * (deep(root->left)-deep(root->right)) > 1) return false;
		return isBalanced((root->left)) && isBalanced((root->right));
	}
};