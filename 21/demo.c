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

