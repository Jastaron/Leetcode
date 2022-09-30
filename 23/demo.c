/* 方法1：按照顺序都加到一个链表上即可 */
struct ListNode* mergeKLists(struct ListNode* lists, int listsSize){
	if( !lists || !listsSize )          //如果lists为空或者长度为0，直接返回NULL
		return NULL;

	struct ListNode* ans = NULL;
	for(int i = 0; i < listsSize; i++)
		ans = mergeTwoLists(ans, lists[i]);   //此函数见题21 合并两个有序链表
	return ans;
}

