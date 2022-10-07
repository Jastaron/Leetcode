/* 维护一个大链表和一个小链表， 最后合并即可 */
struct ListNode* partition(struct ListNode* head, int x){
	if( !head )
		return head;
	struct ListNode* smallHead = malloc( sizeof(struct ListNode) );
	smallHead->next = NULL;
	struct ListNode* smallTail = smallHead;
	struct ListNode* bigHead = malloc( sizeof(struct ListNode) );
	bigHead->next = NULL;
	struct ListNode* bigTail = bigHead;
	while( head ){
		if( head->val < x ){
			smallTail->next = head;
			smallTail = smallTail->next;
		}
		else{
			bigTail->next = head;
			bigTail = bigTail->next;
		}
		head = head->next;
	}
	bigTail->next = NULL;
	smallTail->next = bigHead->next;
	return smallHead->next;

