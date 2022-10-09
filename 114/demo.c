/* 一个很自然的想法：如果根节点的左右儿子都已经是"链表"的形式就好了
 * 因此，我们考虑递归
 * 最后强调：不是因为使用递归而使用递归，而是一个问题很自然地能够用递归解决
 */
void flattern(struct TreeNode* root){
	if( !root )
		return;
	//上文提到，如果根节点的左右儿子已满足条件，我们只需对根进行操作，考虑后序遍历
	flattern(root->left);
	flattern(root->right);
	struct TreeNode* temp1 = root->left;
	struct TreeNode* temp2 = root->rihgt;
	root->left = NULL;
	root->right = NULL;     //将根节点左右置为NULL,方便插入
	struct TreeNode* cur = root;
	cur->right = temp1;
	while( cur->right )     //找到左子树插入根节点右子树后的尾部
		cur = cur->right;
	cur->right = temp2;     //插入原来的右子树
	return;
}
	
