struct ListNode* swapPairs(struct ListNode* head){
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = head;
	struct ListNode* left;
	struct listNode* right;
	struct listNode* temp;
	struct ListNode* cur = tempHead;
	while( cur->next && cur->next->next ){
		temp= cur->next->next->next;
		left = cur->next;
		right = cur->next->next;
		cur->next = right;
		right->next = left;
		left->next= temp;
		cur = cur->next->next;
	}
	return tempHead->next;
}
