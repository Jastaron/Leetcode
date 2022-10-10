/* 因为我们递归地从中间开始建树，可以保证我们的树是搜索树且平衡树 */
struct TreeNode* buildTree(int* nums, int left, int right){
	if( left > right ){        //规定区间为左闭右闭区间，所以left>right时即结束
		return NULL;
	}
	int mid = ( left + right ) / 2;
	struct TreeNode* root = malloc( sizeof(struct TreeNode) );
	root->val = nums[mid];     //将当前数组中间的值赋给root
	root->left = buildTree(nums, 0, mid -1 );           //调用递归建立左右子树
	root->right = buildTree(nums, mid + 1, right);
	return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int* numsSize){
	return buildTree(nums, 0, numsSize - 1);
}


