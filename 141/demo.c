/* 根据floyd 判圈算法，对于两个人一快一慢，在同一位置（即使不在链表上)
 * 朝着同一方向前进，若链表有圈，则一定会相遇
 * 具体介绍见网络
 */
bool hasCycle(struct ListNode* head){
	if( !head && !head->next )
		return false;
	//为了配合上面的处理，我们假定有一个头节点，并且快慢指针各移动了一步
	struct ListNode* fast = head->next;
	struct ListNode* slow = head;
	while( fast != slow ){         
		if( !fast || !fast->next )        //如果不存在圈，直接返回false;
			return false;
		fast = fast->next->next;
		slow = slow->next;
	}

	return true;
}


