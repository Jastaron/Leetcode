/* 方法一：迭代 */
struct ListNode* removeElements(struct ListNode* head, int val){
	//不清楚是否删除头节点， 所以引入虚拟节点
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );     
	tempHead->next = head;
	struct ListNode* cur = tempHead;
	while( cur ){
		if( cur->next->val == val ){
			struct ListNode* temp = cur->next;
			cur->next = temp;
			free(temp);
		}
		else	cur = cur->next;
	}
	return tempHead->next;
}

/* 方法二：递归 
 * 先处理头节点后面的元素，再处理头节点
 */
struct ListNode* removeElements(struct ListNode* head, int val){
	if( !head )
		return NULL;
	removeElements(head->next, int val);
	head = head->val == val ? head->next : head;   
	return head;
}
