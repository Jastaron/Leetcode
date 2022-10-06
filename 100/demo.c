/* 先序遍历依次比较即可 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if( !p && !q )
		return true;       //两个都为空，返回真
	else if( p && !q )
		return false;      //一个为空，一个不为空，返回假
	else if( !p && q )
		return false;
	else if( p->val != q->val )     //两者都不为空，但值不相等
		return false;

	/* 两者值相等，开始比较他们的子节点 */
	bool left = isSameTree(p->left, q->left);
	bool right = isSameTree(p->right, q->right);
	return left && right;
}
