struct ListNode* reverse(struct ListNode* cur, struct ListNode* pre){
	if( !cur ) //当cur为空指针时，递归结束
		return pre;
	struct ListNode* temp = cur->next;
	cur->next = pre; 
	pre = cur; // 单层递归逻辑
	return reverse(temp, cur); //调用递归解决子问题
}
struct ListNode* reverseList(struct ListNode* head){
	/*递归版本， 需要上一个函数辅助*/
	struct ListNode* pre = NULL;
	struct ListNode* cur = head;
	return reversal(cur, pre);
}

struct ListNode* reversaList(struct ListNode* head){
	/*迭代版本，逻辑与递归类似*/
	struct ListNode* temp;
	struct ListNode* cur = head;
	struct ListNOde* pre = NULL;
	while( !cur ){
		temp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = temp
	}
	return pre;
}
