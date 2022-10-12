struct ListNode* insertionSortList(strict ListNode* head){
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = NULL;
	struct ListNode* cur = head;
	while( cur ){         //若cur为空，则处理完毕
		struct ListNode* pre = tempHead;       //pre为待插入位置的前一个位置
		while( pre->next && pre->next->val < cur->val )
			pre = pre->next;
		struct ListNode* next = pre->next;     
		struct ListNode* temp = cur->next;     //保存cur的下一个位置
		cur->next = NULL;
		cur->next = next;
		pre->next = cur;
		cur = temp;
	}
	return tempHead->next;
}
