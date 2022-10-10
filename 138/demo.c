/* 为了便于访问相对应节点的random域
 * 我们不妨直接将新节点插入旧节点之后
 * 这样就可以通过旧节点的random域的next域找到新节点的random域
 * 最后连接起新节点即可
 */

struct Node* copyRandomList(struct Node* head){
	//插入新节点
	for( struct Node* temp = head; temp != NULL; temp = temp->next->next){
		//由于我们每次循环都插入了新节点，所以temp一次移动两步
		struct Node* newNode = malloc( sizeof(struct Node) );
		newNode->val = temp->val;
		newNode->next = temp->next;
		newNode->random = temp->random;   //暂时置random域为NULL以免有不必要的错误
		temp->next = newNode->next;
	}
	
	//建立新节点的random域
	for(struct Node* temp = head; temp != NULL; temp = temp->next->next){
		//由于我们只需要访问旧节点即可完成操作，temp同样一次移动两步
		if( temp->random )
			temp->next->random = temp->random->next;
		else
			temp->next->random = NULL;     //若旧节点不存在random域为空，新节点的random域也置为NULL
      	}

	//连接新节点
	struct Node* tempHead = malloc( sizeof(struct Node) );
	tempHead->next = NULL;
	struct Node* tail = tempHead;
	for(struct Node* temp = head; temp != NULL; temp = temp->next->next){
		tail->next = temp->next;
		tail = tail->next;
	}
	return tempHead->next;
}
