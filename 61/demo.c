/* 将链表首尾相连
 * 在适当的地方断掉两个节点之间的连接并返回新的头节点
 */

struct ListNode* rotateRight(struct ListNode* head, int k){
	struct ListNode* node = head;
	int len = 1;
	while( node->next ){
		len++；
		node = node->next;
	}
	node->next = head;
	node = head;
	for(int i = 1; i <= len - k - 1; i++)    //简单运算即可得到
		node = node->next;
	struct ListNode* ans = node->next;       
	node->next = NULL;         //断开ans与之前节点的连接，得到单链表
	return ans;
}	

