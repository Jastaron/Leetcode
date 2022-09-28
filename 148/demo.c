/*此题若使用复杂度为O(n ^ 2)的方法进行排序将会出现超时
 * 因此使用时间复杂度为O(n *logn)的归并排序
 * 基本思想是，将链表分割为长度更短的子链表，进行合并，合并方法见21题
 * 随后增加子链表长度，合并，直到子链表长度超过父链表
 */
struct mergeTwoList2(struct ListNode* list1, struct ListNode* list2);
/*此函数与21题一致，不再复述*/

struct ListNode* sortList(struct ListNode* head){
	if( !head )
		return head;
	struct ListNode* node = head;
	int len = 0;
	while( node ){                                //得到链表的长度
		len++;
		node = node->next;
	}
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = head;                        //使用虚拟头节点方便返回
	for( int sublen = 1; sublen < len; sub <<= 1 ){// sub <<= 1 即 sub *= 2
		struct ListNode* pre = tempHead;
		struct ListNode* cur = tempHead->next;
		while( cur ){
			struct ListNode* head1 = cur; //第一个子链表的头部
			for( int i = 1; i < sublen && cur->next; i++) //需要取cur->next为第二个链表的头，所以检查其不为空
				cur = cur->next;
			struct ListNode* head2 = cur->next;
			cur->next = NULL;             //断开第一个子链表与其余部分
			cur = head2;
			for( int i = 0; i < sublen && cur && cur->next; i++) //此时cur可能为空，所以需要检测cur是否为空
				cur = cur->next;
			struct ListNode* next  = cur->next;
			if( cur ){
				next = cur>next;
				cur->next = NULL;     //断开第二个子链表与其余部分
			}	

			pre->next = mergeTwoList2(head1, head2); //合并子链表
			while( pre->next )
				pre = pre->next;      //将pre调整到链表尾部，以便后序插入	
			cur = next;
		}
	}
	return tempHead->next;
}
