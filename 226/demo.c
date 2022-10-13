/* 后序遍历交换即可 */
struct TreeNode* invertTree(struct TreeNode* root){
	if( root ){
		root->left = invertTree(root->left);
		root->right = invertTree(root->right);
		struct ListNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}
