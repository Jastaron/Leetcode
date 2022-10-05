/* 二叉搜索树的性质：如果按照中序遍历得到一个数组
 * 那这个数组一定是升序排列的
 * 只需要比较每个节点和它的'前'一个节点即可
 */

bool isvalidBST(struct TreeNode* root){
	long long pre = LONG_MIN;       //leetcode会出现卡边界值的测试用例
	int* stack = malloc( sizeof(struct TreeNode) * 1000 );
	int top = -1;         //用栈实现迭代的中序遍历
	while( top != -1 && root ){
		while( root ){
			stack[++top] = root;
			root = root->left;
		}
		root = stack[top--];
		if( root->val <= pre )
			return false;   //若出现比前一个节点小的情况，直接返回false
		root = root->right;
	}
	free(stack);
	return true;
