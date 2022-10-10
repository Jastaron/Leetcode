/* 由于此题目给出的树不是完美二叉树，所以116的思路不在适用
 * 但有一点不变，如果我们要连接某一层的节点，我们必须处于这层节点的上一层
 * 将二叉树的每一层当作链表遍历即可
 */

struct Node* connnect(struct Node* root){
	if( !root )
		return;
	struct Node* cur = root;
	struct Node* tempHead = malloc( sizeof(struct Node) );
	while( cur ){         //外层循环，每层循环处理每个节点
		tempHead->next = NULL;       //上一层的节点可以有cur访问，这里将tempHead后面置空以保存本层节点
		struct Node* pre = tempHead;
		while( cur ){           //内存循环，每层循环处理一个节点
			if( cur->right ){
				pre->next = cur->right;
				pre = pre->next;       //更新pre，以便进行本层下个节点的连接
			}

			if( cur->right ){
				pre->next = cur->right;
				pre = pre->next;
			}
			cur = cur->next;
		}
		cur = tempHead->next;   //进入下一层
	}
	return root;
}
