/* 方法一：先分别遍历一次获得两链表的长度
 * 从而将两链表头部调整到同一位置
 * 最后再同时遍历一次即可
 */

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB){
	if( !headA || !headB )
		return NULL;
	struct ListNode* temp = headA;
	int lenA = 1;
	while( temp->next ){
		lenA++;
		temp = temp->next;
	}
	temp = headB;
	int lenB = 0;
	while( temp->next ){
		lenB++;
		temp = temp->next;
	}
	if( lenA > lenB )
		for(int i = 1; i <= fabs(lenA - lenB); i++)
			headA = headA->next;
	else
		for(int i = 1; i <= fabs(lenA - lenB); i++)
			headB = headB->next;
	while( headA ){
		if( headA == headB )
			return headA;
		headA = headA->next;
		headB = headB->next;
	}
	return NULL;     //循环结束，说明没有找到相交节点

/*方法二：“我会错过你“， “没关系，我会沿着你走过的路找到你”
 * 人话：双指针
 * 原理：若两链表相交，记第一个链表相交前的长度为a，第二个链表相交前的长度为b，公共长度为c
 * a + c + b = b + c + a
 * 即一个链表遍历完后，转到另一链表继续遍历，若相交，总会相遇
 */

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB){
	if( !headA || !headB )
		return NULL;
	struct ListNode* tempA = headA;
	struct ListNode* tempB = headB;
	while( headA || headB ){
		if( !headA )       //若一条为空，转到另一条
			headA = tempB;
		if( !headB )
			headB = tempA;
		if( headA == headB )
			return headA;
		headA = headA->next;
		headB = headB->next;
	}
	return NULL;     //两条链表都为空，说明无交点
}



















				
	
