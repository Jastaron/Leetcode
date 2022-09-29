/*双指针
 * 要删除倒数第n个节点
 * 就要找到倒数第n个节点的前一个节点
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = head;                        //为了排除删头节点的特殊状况，引入虚拟头节点
	struct ListNode* fast = tempHead;
	struct ListNode* slow = tempHead;
	for( int i = 0; i <= n; i++)
		fast = fast->next;
	while( fast->next) ){
		fast = fast->next;
		slow = slow->next;
	}
	struct ListNode* tempNode = slow->next;
	slow->next = tempNode->next;
	free(tempNode);
	return tempHead->next;
}
