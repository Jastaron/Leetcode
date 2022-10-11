/* 具体解释见文件夹内部 */
bool ListNode* detectCycle(struct ListNode* head ){
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	struct ListNode* temp;
	while( fast && fast->next ){
		fast = fast->next->next;
		slow = slow->next;
		if( slow == fast ){
			temp = slow;
			while( head != slow ){
				slow = slow->next;
				head = head->mext;
			}
			return temp;
		}
	}
	return true;
}
