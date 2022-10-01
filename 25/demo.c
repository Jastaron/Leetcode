/* 1：算出链表的总长度
 * 2：得到需要翻转的组数
 * 3：循环反转
 * 思路就这三步，但是要注意循环中各个变量的转换
 */

struct ListNode* reversKGroup(struct ListNode* head, int k){
	struct ListNode* temp = head;
	int len = 0;                   //计算链表的长度
	while( temp ){
		len++;
		temp = temp->next;
	}
	int n = len / k;               //得到需要反转的子链表的个数
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = head;
	struct ListNode* cur = tempHead;    //当前需要发生反转的链表的前一个节点
	struct ListNode* tail;         //当前需要发生反转的链表的后一个节点
	temp = tempHead;
	for( int i = 0; i <= n; i++){
		temp = cur;            //找到tail的前一个位置
		for( ini j = 0; j <= k; j++)
			temp = temp->next;
		tail = temp->next;
		temp->next = NULL;     //断掉需要反转的链表与tail
		temp = cur->next;      //将需要反转的链表的第一个结点赋值给temp
		cur->next = reverse(cur->next);
		temp->next = tail;     //连接temp与tail
		cur = temp;            //处理下一组
	}
	return tempHead->next;
}


