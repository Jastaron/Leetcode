typedef struct{
	int size;
	int capacity;         //队列的容量
	int* data;
	int rear;
	int front;
}MyCircularQueue;

MyCircularQueue* MyCircularQueueCreate(int k ){
	MyCircularQueue q = malloc( sizeof(MyCircularQueue) );
	q->size = 0;
	q->capacity = k;
	q->data = malloc( sizeof(int) * k );
	q->rear = k - 1;      //将rear置于队列的最后一个位置,这样一次插入后，rear就可以和front处于一个位置
	q->front = 0;
	return q;
}

bool MyCircularQueueEnqueue(MyCircularQueue* obj, int value){
	if( obj->size == obj->capacity )
		return false;
	obj->rear = ( obj->rear + 1 ) % obj->capacity;      //越界则回到下标为0的位置
	obj->data[obj->rear] = value;
	obj->size++;
	return true;
}

bool MyCircularQueueDeQueue(MyCircularQueue* obj, int value){
	if( obj->size == 0 )
		return false;
	obj->front = ( obj->front + 1 ) % obj->capacity;    //越界则回到下标为0的位置
	obj->size--;
	return true;
}

int MyCircularQueueFront(MyCircularQueue* obj){
	if( obj->size == 0 )
		return -1;
	return obj->data[obj->front];
}

int MyCircularQueueRear(MyCircularQueue* obj){
	if( obj->size == 0 )
		return -1;
	return obj->data[obj->rear];
}

void MyCircularQueueFree(MyCircularQueue* obj){
	free(obj->data);
	free(obj);
}
