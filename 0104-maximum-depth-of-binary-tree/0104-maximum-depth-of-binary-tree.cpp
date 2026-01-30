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
		leftdepth = maxdepth(root->left) + 1;
		rightdepth = maxdepth(root->right) + 1;
		return (leftdepth>rightdepth)?leftdepth:rightdepth;
	}
public:
	int maxDepth(TreeNode* root) {
		return maxdepth(root);
	}
};