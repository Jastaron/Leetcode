/* 递归版本 */
struct ListNode* deleteDuplicates(struct ListNode* head){
	if( !head || !head->next)
		return head;   
	while( head && head->next && head->val == head->next->val ){
		struct ListNode* temp = head->next;
		head->next = temp;
		free(temp);
	}
	head->next = deleteDuplicates(head->next);     //调用递归处理下一层逻辑
	return head;
}

/* 迭代版本 */
struct ListNode* deleteDuplicates(struct ListNode* head){
	if( !head || !head->next )
		return head;
	struct ListNode* cur = head;
	struct ListNode* temp;
	while( cur  && cur->next ){
		if( cur->val == cur->next->val ){
			temp = cur->next;
			cur->next = temp->next;
			free(temp)l;
		}
		else cur = cur->next
	}
	return head;
}
