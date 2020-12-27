#include <iostream>
#include <cstdlib>
using namespace std;

class IntSLLNode{	

public:
	int info;
  	IntSLLNode *next;
  
	IntSLLNode(){
		info=0;
		next=NULL;
	}

	IntSLLNode(int i, IntSLLNode* in=NULL){
		info=i;
		next=in;
	}
};

class IntSLL{

public:
	IntSLLNode *head;
	IntSLLNode *tail;

	IntSLL(){
		head=NULL;
		tail=NULL;
	}

	void insertattail(int ele);
	void deletefromhead();
};

class Queue
{
public:
	IntSLL queue;

	Queue(){
		queue = new IntSLL;
	}
	
	void enqueue(int ele);
	void dequeue();
	int isEmpty();
};

void IntSLL::insertattail(int element){
	if (head==NULL)		//when list is empty
	{
		IntSLLNode *N= new IntSLLNode(element);
		head = N;
		tail = N;
	}

	else if(head==tail || head!=tail){	//when list has one or more than one element
			IntSLLNode *N= new IntSLLNode(element);
			tail->next = N;
			tail = N;
		}
	}
void IntSLL::deletefromhead(){

    if(head==NULL) return;

    else if(head==tail)
	{ delete(head);
	  head=NULL;
	  tail=NULL;
	}

    else if(head!=tail)
	{ IntSLLNode *temp = head;
	  head = head->next;
	  delete(temp);
	}
}

void Queue::enqueue(int ele){
	queue.insertattail(ele);
}

void Queue::dequeue(){
	if(queue.isEmpty == -1)
		queue.deletefromhead();
	else
		return;
}

int isEmpty(){
	if (queue.head == NULL)
		return 1;	//queue is empty
	else
		return -1;	//queue is not empty
}