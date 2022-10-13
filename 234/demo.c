/* 维护两个新链表
 * 一个链表与旧链表相同，一个链表为旧链表的反转
 * 比较两个新链表即可
 */

struct ListNode* copyList(struct ListNode* head){
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = NULL;
	struct ListNode* tail = tempHead;
	while( head ){
		struct ListNode* node = malloc( sizeof(struct ListNode) );
		node->val = head->val;
		node->next = NULL;
		tail = tail->next = node;
		head = head->next;
	}
	return tempHead->next;
}

struct ListNode* reverseList(struct ListNode* head);   //此函数的实现可在206目录下找到

bool isPalindrome(struct ListNode* head){
	struct ListNode* list1 = head;
	struct ListNode* list2 = reverseList(head);
	while( list1 ){
		if( list1->val != list2->val )
			return false;
		list1 = list1->next;
		list2 = list2->next;
	}
	return true;

}

