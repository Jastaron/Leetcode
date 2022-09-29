/*此题可先求出链表的长度，根据链表的长度与k的值求出倒数第k个值的位置，交换即可
 * 但这种方法需要遍历链表两次
 * 因此我们采用双指针
 *先将快指针移动k步，此时快指针的位置就是第k的元素的位置
 *再同时移动快慢指针，当快指针到达链表尾部时，慢指针也到了相应位置的前一个，删除即可
 */
struct ListNode* swapNodes(struct ListNode* head, int k){
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	for(int i = 0; i < k; i++)
		fast = fast->next;
	struct ListNode* node1 = fast;                //使用一个变量记录此时的位置
	while( fast->next){
		fast = fast->next;
		slow = slow->next;
	}
	int val = node1->val;
	node1->val = slow->val;
	slow->val = val;
	return head;
}
