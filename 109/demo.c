/* 此题思路与108基本相同
 * 不同点是，我们不能通过下标直接获得中间元素
 * 但是876题给了我们找出链表中间节点的方法，只需稍加修改即可使用
 */

struct ListNode* findMid(struct ListNode* head, struct ListNode* tail){
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while( head != tail && head->next!= tail ){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

struct TreeNode* buildTree(struct ListNode* head, struct ListNode* tail){
	if( head == tail )
		return NULL;       //此题的循环区间为左闭右开区间，head==tail时区间无意义
	struct ListNode* mid = findMid(head, tail);
	struct TreeNode* root = malloc( sizeof(struct TreeNode) );
	root->val = mid->val;
	root->left = buildTree(head, mid);
	root->right = buildTree(mid->next, tail);
	return root;
}

struct TreeNode* sortedListToBST(struct ListNode* head){
	return buildTree(head, NULL);        //链表的结尾肯定是NULL
}


