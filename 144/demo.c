void traverse(struct TreeNode* root, int* arr, int* returnSize){
	if( root ){
		arr[(*returnSize)++] = root->val;
		traverse(root->left, arr, returnSize);
		traverse(root->right, arr, returnSize);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	/* 前序遍历的顺序是：前->中->右 */
	*returnSize = 0;
	int* ans = malloc( sizeof(int) * 100 ); 
	traverse(root, ans, returnSize);
	return ans;
}
