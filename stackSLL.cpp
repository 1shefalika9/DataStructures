// Stack as linked list

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class IntSLLNode{	

public:
	int info;
  	IntSLLNode *next;

	IntSLLNode(int i, IntSLLNode* in=NULL){
		info=i;
		next=in;
	}
};

class IntSLL{

public:
	IntSLLNode *head;

	IntSLL(){
		head=NULL;
	}	

	void insertathead(int ele);
	void deletefromhead();
	int traverse();
};

class Stack{
public:
	IntSLL stack;

	void push(int ele);
	void pop();
	int topEle();
	bool isEmpty();
	int disp();
};

void IntSLL::insertathead(int element){
	if (head==NULL)		//when list is empty
	{
		IntSLLNode *N= new IntSLLNode(element);
		head = N;
	}

	else 		//when list has one or more than one element
	{	
		IntSLLNode *N= new IntSLLNode(element);
		N->next = head;
		head = N;
	}	 
}

void IntSLL::deletefromhead(){

    if(head==NULL) return;

    else if(head->next == NULL)
	{ delete(head);
	  head=NULL;
	}

    else 
	{ IntSLLNode *temp = head;
	  head = head->next;
	  delete(temp);
	}
}

int IntSLL::traverse(){			//Use this function only for debugging
	IntSLLNode *temp= head;
	if(head==NULL)
		return -1;
	else{
		while(temp!=NULL){
			cout<<setw(2)<<temp->info<<" ";
			temp = temp->next;
		} return 1;
	}
}

void Stack::push(int ele){
	stack.insertathead(ele);
}

void Stack::pop(){
	stack.deletefromhead();
}

int Stack::topEle(){
	if(stack.head==NULL)
		return -1;
	else
		return stack.head->info;
}

bool Stack::isEmpty(){
	if(stack.head==NULL)
		return true;
	else
		return false;
}

int Stack::disp(){
	int res;
	res = stack.traverse();
	return res;
}

int main(int argc, char const *argv[])
{	int element;
	Stack st;
	char more= 'y';
    do{
	cout<<"\nChoose to perform one of the following options:";
	cout<<"\n1)Push an element into stack\n2)Pop an element from stack\n3)Display the top element of stack\n4)Check if stack is empty\n5)Display stack\n6)Exit from the program\n";
	int choice;
	cin>>choice;
	switch(choice){
		case 1:cout<<"\nEnter new element to be pushed into stack: ";
			   cin>>element;
			   st.push(element);	
			   break;
		case 2:st.pop();
			   cout<<"\nTop-most element popped from stack!!";	
			   break;
		case 3:cout<<"\nThe top element of stack is: ";
         	   int r;
			   r = st.topEle();
			   if(r== -1)
			   	cout<<"\nEmpty stack!!";
        	   else
          		cout<<r;
			   break;
		case 4:bool r1;
			   r1 = st.isEmpty();
			   if(r1== true)
			   	cout<<"\nEmpty stack!!";
			   else
			   	cout<<"\nStack is not empty.";
			   break;
		case 5:cout<<"\nThe stack is: ";
			   int r2;
			   r2 = st.disp();
			   if (r2== -1)
			  	  cout<<"\nEmpty stack!!";
			   break;
		case 6:exit(0);
	  }
	cout<<"\nDo you wish to perform more operations on stack?: (y/n): ";
    cin>>more;
  	}while (more=='y');

	return 0;
}