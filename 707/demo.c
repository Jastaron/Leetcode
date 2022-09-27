/*注意到给出的函数签名中参数均为一重指针，因此只能用带头节点的链表*/
typedef struct{
	int data;
	struct MyLinkedList* next;
}

MyLinkedList* myLinkedListCreate(){
	MyLinkedList* head = malloc( sizeof(MyLinkedList) );
	head->next = NULL;
	return head;
}

int MyLinkedListGet(MyLinkedList* obj, int index){
	/*注意下标的启示位置是0*/
	if( index < 0 )
		return -1;
	MyLinkedList* temp = obj.next;                //要获得相应下标的值，就将指针移到那个下标的位置去
	int i = 0;                                    //i=0对应了temp=obj.next,即0号元素
	while( i < index && temp ){                   //下标有可能越界，需要随时检查当前指针是否为空
	temp = temp->next;
	i++;
	}
	if( temp )                                    //指针不为空，即找到了相应元素
		return temp->data;
	else
		return -1                             //下标越界
}	  

void myLinkedListAddAtHead(MyLinkedList* obj, int val){
	MyLinkedList* node = malloc( sizeof(MyLinkedList) );
	node->data = val;
	node->next = obj->next;
	obj->next = node;
}

void myLinkedListAddAtTail(myLinkedList* obj, int val){
	myLinkedList* temp = obj; 
	while( temp->next )                           //找到链表的尾指针
		temp = temp->next;
	MyLinkedList* node = malloc( sizeof(MyLinkedList) );
	node->next = NULL;
	temp->next = node;
}	

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val){
	/*要将一个元素插入到第index个位置
	 * 就要找到index-1个位置
	 * 因此我们将头节点规定为-1号元素
	 */
	MyLinkedList* temp = obj;
	int i = -1;
	while( i < index - 1 && temp ){               //越界时退出循环
		temp = temp->next;
		i++;
	}
	if( temp ){
		MyLinkedList* node = malloc( sizeof(MyLinkedList) );
		node->data = val;
		node->next = temp->next;
		temp->next = node;
	}	
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index){
	/*基本思路同上个函数
	 * 要想删除第index个元素
	 * 就得找到第index-1个元素
	 */
	MyLinkedList* temp = obj;
	int i = -1;
	while( i < index - 1 && temp ){
		temp = temp->next;
		i++;
	}

	if( temp && temp->next ){                     //只有temp和temp->next都不为空才能说明在有效位置进行删除
		MyLinkedlist* node = temp->next;
		temp->next = node->next;
		free(node)                            //释放空间
	}
}		   

void myLinkedListFree(myLinkedList* obj){
	MyLinkedList* temp;
	while( obj ){                                 //obj不为空，说明还未全部释放
		temp = obj;
		obj = obj->next;
		free(temp);
	}
}	
