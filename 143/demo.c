/* 总共分三步
 * 1：找到中间节点,根据中间节点将链表分为两部分
 * 2：反转后半部分的链表
 * 3：合并链表
 * middleNode, merge, reverse三个函数不再给出
 */
struct ListNode* reorderList(struct ListNode* head){
	struct ListNode* mid = middleNode(head);
	struct ListNode* list2 = mid->next;
	mid->next = NULL;
	struct ListNode* list1 = head;
	return merge(list1, reverse(list2) );
}
