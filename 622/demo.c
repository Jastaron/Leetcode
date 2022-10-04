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
	q->rear = 0;
	if( k == 1 )
		q->front = 0;
	else q->front = 1;         //除了leetcode用例，谁又会使用容量为1的队列呢~
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
