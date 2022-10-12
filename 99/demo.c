/* 二叉搜索树的重要性质：中序遍历得到的序列一定是升序的
 * 找出位置出错的两个位置，交换即可
 */

void recoverTree(struct TreeNode* root){
	struct TreeNode* stack[1000];
	int top = -1;
	struct TreeNode* x = NULL;
	struct TreeNode* y = NULL;
	struct TreeNode* pre = NULL;
	while( !root || top != -1 ){
		while( root ){
			stack[++top] = root;
			root = root->left;
		}
		root = stack[top--];
		if( pre != NULL && pre->val > root->val ){
			y = root;
			if( x == NULL )
				x = pre;          //错误的位置相邻
			else
				break;            //错位的位置不相邻，直接退出循环
		}
		pre = root;
		root = root->right;
	}
	int temp = x->val;
	x->val = y->val;
	y->val = x->val;
}
