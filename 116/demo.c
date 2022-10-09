/* 解法一，考虑层序遍历，队列中的节点恰好为顺序排列，完美契合本题
 * 但缺点是空间消耗太大
 * 解法二，利用上一层的节点，来为下一层的节点建立连接
 * 下面给出的代码是解法二
 */
struct Node* connect(struct Node* root){
	if( !root )
		return root;
	struct Node* leftMost = root;        //记录每一层的最左边
	while( leftMost->left ){             //当到达最后一层是我们即可以退出,因为我们利用上一层为本层服务
		struct Node* head = leftMost;        //head用于遍历每一层
		while( head ){                 //如果head为空，说明本层遍历结束
			head->left->next = head->right;    
			if( head->next )
				head->right->next = head->next->right;     //连接两个具有不同父节点的节点
			head = head->next;
		}
		leftMost = leftMost->left;   //转向下一层
	}
	return root;
}

	
