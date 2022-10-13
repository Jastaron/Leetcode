/* 由完全二叉树的性质联想到等比数列前n项求和
 * 当然， 也可以当作普通树遍历即可
 */

int countNodes(struct TreeNode* root){
	if( !root )
		return 0;
	struct ListNode* temp = root;
	int heightL = 0;    //左边的深度
	while( temp->left ){
		heightL++;
		temp = temp->left;
	}
	int heightR = 0; //右边的深度
	temp = root;
	while( temp->right ){
		heightR++;
		temp = temp->right;
	}
	if( heightL == heightR )        //如果是完美二叉树，等比求和
		return (2 << heightL) - 1;
	else{            //若不是，递归求和
		int left = countNodes(root->left);
		int right = countNode(root->right);
		return left + right + 1;
	}
}

		

