class Stack{
public:
	int *A;
	int top;
	Stack(int max){
		A = new int[max];
		top = 0;
	}
	int push(int val);
	int pop();
	int topEl();
	bool isEmpty();
	bool isFull();	
};

bool Stack::isEmpty(){
	if (top == -1)
		return true;
	else
		return false;
}

bool Stack::isFull(){
	if (top > max)
		return true;
	else
		return false;
}

int Stack::topEl(){
	if isEmpty()
		return -1;
	else
		return A[top];
}

int Stack::push(int val){
	if isFull()
		return -1;
	else{
		A[top] = val;
		top++;
	}
}

int Stack::pop(){
	if isEmpty()
		return -1;
	else{
		top--;
		return A[top];
	}
}