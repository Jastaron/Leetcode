struct ListNode* reversal(struct ListNode* head){
	struct ListNode* pre = NULL;
	struct ListNode* cur = head;
	struct ListNode* temp;
	while( cur ){
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp;
	}
	return pre
}
struct ListNode* reversalBetween(struct ListNode* head, int left, int right){
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = head;
	struct ListNode* leftNode 
	struct ListNode* left_of_leftNode;
	struct ListNode* right_of_rightNode;
	struct ListNode* temp = tempHead;
	int i;
	for( i = 0; i < left - 1; i++)
		temp = temp->next;
	left_of_leftNode = temp;
	leftNode = temp->next;

	for( i = 0; i < right - left + 1; i++)
		temp = temp->next;
	right_of_rightNode = temp->next;
	temp->next = NULL;

	left_of_leftNode->next = reversal(leftNode);
	leftNode->next = right_of_rightNode;
	return tempHead->next;
