/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
	int maxdepth(TreeNode* root){
		int leftdepth = 0;
		int rightdepth = 0;
		if(root == nullptr){
			return 0;
		}
		leftdepth = maxdepth(root->left);
		rightdepth = maxdepth(root->right);
		return (leftdepth>rightdepth)?leftdepth + 1 : rightdepth + 1;
	}
public:
	int maxDepth(TreeNode* root) {
		return maxdepth(root);
	}
};