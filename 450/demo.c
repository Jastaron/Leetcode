/* 当待删除的节点是叶子节点时，直接删除即可
 * 当待删除的节点只有一个子节点，绕过此节点后删除
 * 当待删除的节点有两个子节点，首先找到其右子树的最小值，
 * 由二叉搜索树的性质，右子树的最小值所在的节点必是一个叶子节点
 * 将这个值赋给待删除节点，转而删除此右子树最小节点即可
 */
struct TreeNode* findMin(struct TreeNode* head){
	while( head && head->left );
		head = head->left;
	return head;
}

struct TreeNode* deleteNode(struct TreeNode* root, int key){
	if( !root )
		return NULL;       //这一句可以解决key在树中不存在的情况
	if( root->val < key )      //若root的值小于key,转向root右子树进行删除
		root->right = deleteNode(root->right, key);
	else if( root->val > key)  //若root的值大于key,转向root左子树进行删除
		root->left = deleteNode(root->left, key);
	else{                      //找到了待删除的位置
		struct TreeNode* temp;
		if( root->left && root->right ){        //root有两个子节点
			temp = findMin(root->right);
			root->val = temp->val;
			root->right = deleteNode(root->right, temp->key);
		}
		else if( root->left || root->right ){  //root有一个子节点
			temp = root;
			root = root->left == NULL ? root->right : root->left;
			free(temp);
		}
		else{                                  //root是叶子节点
			temp = root;
			root = NULL;
			free(temp);
		}
	}

}



