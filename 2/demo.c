/* 由于题目给出的数是倒序存放的，所以逐项相加即可
 * 特别注意进位值，若两个链表都已处理完毕但进位值不为空，此时依然没有处理完
 * 可以迭代与递归解决
 */

struct ListNode* add(ListNode* list1, struct ListNode* list2, int carry){
	struct ListNode* temp = malloc( sizeof(struct ListNode) );
	if( list1 && list2 ){
		temp->val = ( list1->val + list2->val + carry ) % 10;
		carry = ( list1->val + list2->val + carry ) / 10;
	       	list1 = list1->next;
		list2 = list2->next;
		temp->next = add(list1->next, list2->next, carry)   //调用递归处理下一层
	}
	else if( list1 && !list2 ){
		temp->val = ( list1->val + carry ) % 10;
		carry = ( list1->val + carry ) / 10;
		list1 = list1->next;
		temp->next = add(list1->next, carry, carry);
	}
	else if( list2 && !list1 ){
		temp->val = ( list2->val + carry ) % 10;
		carry = ( list2->val + carry ) / 10;
		list2 = list2->next;
		temp->next = add(NULL, list2->next, carry);	
	}
	else if( !pre ){                              //两个数都处理完，但是此时还有一个进位
		temp->val = pre;
		temp->next = NULL;
	}
	return temp
}
struct ListNode* addTwoNumbers(struct ListNode list1, struct ListNode list2){
	//递归版本
	return add(list1, list2, 0);                  //初始进位值等于0
}


struct ListNode* addTwoNumbers(struct ListNode* list2, struct ListNode* list2){
	//迭代版本即显式地展现出递归的过程
	int carry = 0;                                //进位值
	struct ListNode* tempHead = malloc( sizeof(struct ListNode) );
	tempHead->next = NULL;
	struct ListNode* tail = tempHead;             //记录链表的尾部方便插入
	while( list1 || list2 || pre ){           //这个循环可以处理包括两链表为空且进位值不为0的所有情况
		struct ListNode* temp = malloc( sizeof(struct ListNode) );
		temp->next = NULL;
		if( list1 && list2 ){
			temp->val = (list1->val + list2->val + carry ) % 10;
			carry = (list1->val + list2->val + carry) / 10;
			list1 = list1->next;
			list2 = list2->next;
		}
		else if( list1 && !list2 ){
			temp->val = (list1->val + carry) % 10;
			carry = (list1->val + carry) / 10;
			list1 = list1->next;
		}
		else if( list2 && !list1 ){
			temp->val = (list2->val + carry) % 10;
			carry = (list2->val + carry) / 10;
			list2 = list2->next;
		}
		else if( !pre ){
			temp->val = carry;
			pre = pre / 10;
		}
		tail->next = temp;
		tail = tail->next;
	}
	return tempHead->next;
}
