/* 树的定义就是就用了递归的方法
 * 所以遇到树有关的题目，思考递归
 */
struct TreeNode* insertIntoBST(struct TreeNode* root, int val){
	if( !root ){     
		/* 这里有两种情况
		 * 1:root一开始就为空
		 * 2:root不为空，找到了插入的位置，此时肯定为空
		 */
		struct TreeNode* node = malloc( sizeof(struct TreeNode) );
		node->val = val;
		node->left = node->right = NULL;
		return root;
	}
	if( root->val < val )      //当root的值小于val, 递归插入root的右边
		root->right = insertIntoBST(root->right, val);
	else if( root->val > val )      //反之亦然
		root->left = insertIntoBST(root->left, val);
	/* leetcode保证了插入结点未在树中出现过
	 * 若应对可能重复的情况，此代码也能解决
	 */
	return root;
}
