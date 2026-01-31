class Solution {
public:
	int getHeight(TreeNode* root) {
		if (root == nullptr) return 0;
		int leftH = getHeight(root->left);
		if (leftH == -1) return -1;
		int rightH = getHeight(root->right);
		if (rightH == -1) return -1;
		if (abs(leftH - rightH) > 1) {
			return -1; 
		}
		return max(leftH, rightH) + 1;
	}
	
	bool isBalanced(TreeNode* root) {
		return getHeight(root) != -1;
	}
};