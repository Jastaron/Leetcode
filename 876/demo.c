/* 一个很朴素的想法，求长度除2 
 * 这里采用双指针
 * 快指针走两步，慢指针走一步
 * 当快指针到达开头的时候，慢指针一定位于中间
 */

struct ListNode* middleNode(struct ListNode* head){
	struct ListNode* fast = head;
	struct ListNode* slow = head;
	while( fast && fast->next){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
