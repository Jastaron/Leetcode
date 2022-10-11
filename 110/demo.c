/* 方法一:如果当前树平衡，则左右子树之差的绝对值小于1，并且左右子树也平衡 */
bool isBalanced(struct TreeNode* root ){
	if( !root )
		return true;
	int left = height(root->left);       //height为求树高度的函数
	int right = height(roor->right);
	return fabs(left - right ) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

/* 方法一从上往下遍历，每个节点都遍历了两次，时间复杂度为O(n ^ 2)
 * 若改为从下网上，时间复杂度可以减小为O(n)
 */
int height(struct TreeNode* root){      //这个height函数不是上文所提到的height,上文的是纯粹求高度的函数
	if( !root )
		return 0;
	int left = height(root->left);
	int right = height(root->right);
	int height = left < right ? right + ! : left + 1;
	if( left == -1 || right == -1 || fabs(left - right) > 1 )
		return -1;         //-1即已经出现不平衡的树
	else
		return height;
}
bool isBalanced(struct TreeeNode* root){
	return height(root) >=0;
}

