struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = NULL;
	struct ListNode* tail = tempHead;
	while( list1 && list2 ){                        //当其中一个遍历到尾部，退出循环
		if( list1->val == list2->val ){         //两个相等时，都需要插入
			tail->next = list1;
			list1 = list1->next;
			tail = tail->next;
			tail->next = list2;
			list2 = list2->next;
			tail = tail->next;
		}
		else if( list1->val < list2->val ){      //否则插入较大者即可
			tail->next = list1;
			list1 = list1->next;
			tail = tail->next;
		}
		else{
			tail->next = list2;
			list2 = list2->next;
			tail = tail->next;
		}
	}
	if( list1 )                                    //将剩下不为空的那个链表直接接在tail后
		tail->next = list1;
	else 
		tail->next = list2;
	return tempHead->next;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
/* 要将两条链表合并，就要将两个链表的尾部合并，考虑递归
 * 递归基：其中一个链表为空，将另一个链表接在已有链表尾部
 */
	if( list1 && !list2 )                         
		return list1;
	else if(list2 && !list1 )
		return list2;
	else if( !list1 && !list2 )
		return NULL;
	
	if( list1->val < list2->val ){
		list1->next = merge(list1->next,list2);
		return list1;
	}
	else{
		list2->next = mergeTwoLists(list1, list2->next);
		return list2;
	}
