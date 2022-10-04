typedef struct{
	int* out;
	int* in;
	int outTop;
	int inTop;
}MyQueue;

MyQueue* myQueueCreate(){
	MyQueue* q = malloc( sizeof(MyQueue) );
	q->out = malloc( sizeof(int) * 100 );
	q->in  = malloc( sizeof(int) * 100 );
	q->outTop = -1;
	q->inTop  = -1;
	return q;
}

void MyQueuePush(MyQueue* obj, int x){
	obj->in[++obj->inTop] = x;      //入队时，往in栈里面压入即可
}

int MyQueuePop(MyQueue* obj){
/* 如果out栈为空,那么先把in栈里的元素栈顺序一次入out栈,
 * 否则直接返回out栈栈顶的元素
 */

	if( obj->outTop == -1 )
		while( obj->inTop >= 0 )
			obj->out[++obj->outTop] = obj->in[obj->inTop--];
	return obj->out[obj->outTop--];
}

int MyQueuePeek(MyQueue* obj){
	int val = MyQueuePop(obj);
	obj->outTop++;
	return val;
}

bool MyQueueEmpty(MyQueue* obj){
	return obj->outTop == -1 && obj—>inTop == -1;
}

void MyQueueFree(MyQueue* obj){
	free(obj->in);
	free(obj->out);
	free(obj);
}
	   

