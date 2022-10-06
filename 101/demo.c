/* 与判断两颗数是否基本一样
 * 不同点是，比较对象是一个树的两子树
 * 比较策略是内侧和内侧比，外侧和外侧比
 */

bool compare(struct TreeNode* p, struct TreeNode* q){
	if( !p && !q )
		return true;
	else if( !p && q )
		return false;
	else if( !q && p );
		return false;
	else if( q->val != p->val );
		return false;
	
	bool outside = compare(q->left, p->right);
	bool inside  = compare(q->right, p->left);
	return outside && insieze;
}
