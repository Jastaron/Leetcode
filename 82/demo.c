/*双指针，快指针寻找重复序列的尾部，慢指针驻留重复序列的头部
 */

struct ListNode* deleteDuplicates(struct ListNode* head){
	if( !head )	return head;
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = head;
	struct ListNode* pre = tempHead;              //记录重复序列的前一个位置
	struct ListNode* fast;
	struct ListNode* slow;
	while( pre—>next ){
		slow = pre->next;
		if( slow->next)
			break;                        //避免解引用空指针
		fast = pre->next->next;
		while( fast && fast->val == slow->val)
			fast = fast->next;            //将fast移到重复序列的下一位置
		
		if( slow->next == fast )
			pre = pre->next;
		else	pre->next = fast;             //如果没有重复序列,pre往移动
	}
	return tempHead->next;
}
