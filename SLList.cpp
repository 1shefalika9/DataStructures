//SHEFALIKA GHOSH
//19544
/*PROGRAM FOR CREATING A SINGLY LINKED LIST(SLL) AND PERFORMING THE FOLLOWING OPERATIONS ON IT: INSERTION, DELETION, SEARCH, TRAVERSAL, AVERAGE, COUNTING LIST ELEMENTS, LIST REVERSAL IN THE SAME LIST*/


#include <iostream>
#include <cstdlib>
#include <iomanip>
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

	void insertathead(int ele);
	void insertattail(int ele);
	void deletefromhead();
    void deletefromtail();
	void traverse();
	int count();
	float average();
	IntSLLNode *search_ptr(int element);
	bool search(int element);
  	void reverseSLL();
  	int insertafterpos(int pos, int val);
  	int insertbeforepos(int pos, int val);
};

void IntSLL::insertathead(int element){
	if (head==NULL)		//when list is empty
	{
		IntSLLNode *N= new IntSLLNode(element);
		head = N;
		tail = N;
	}

	else if(head==tail || head!=tail){	//when list has one or more than one element
			IntSLLNode *N= new IntSLLNode(element);
			N->next = head;
			head = N;
		}	 
	}
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

void IntSLL::deletefromtail(){

	if(head==NULL) return;

	else if(head==tail)
	{ delete(head);
	  head=NULL;
	  tail=NULL;
	}

	else if(head!=tail)
	{ IntSLLNode *temp = head;
	  while(temp->next != tail)
	  	{ temp = temp->next;  }
	  delete(tail);
	  tail = temp;
	  tail->next = NULL;
	}
}	

void IntSLL::traverse(){
	IntSLLNode *temp= head;
	while(temp!=NULL){
		cout<<setw(2)<<temp->info<<" ";
		temp = temp->next;
	}
}

int IntSLL::count(){
    IntSLLNode *temp = head;
    int ctr=0;
    while(temp!=NULL)
      {	ctr++;
	temp = temp->next; }
    return ctr;
}

float IntSLL::average(){
    IntSLLNode *temp = head;
    float sum=0;
    int ctr=0;
    while(temp!=NULL)
      {	ctr++;
	sum+= temp->info;
	temp = temp->next; }	
    float avg= float(sum/ctr);
    return avg;
}

IntSLLNode* IntSLL::search_ptr(int element){
	IntSLLNode *temp = head;
	while(temp!=NULL){
		if(temp->info == element)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

bool IntSLL::search(int element){
	IntSLLNode *temp = head;
	int flag = 0;
	while(temp!=NULL){
		if (temp->info == element)
		{
			flag=1;
			break;
		}
		temp = temp->next;
	}
	if (flag!=0) 
		return true;
	else 
		return false;
}

void IntSLL::reverseSLL()		//reversing in the same SLL list
   {	IntSLLNode *temp = head;
	IntSLLNode *nt = temp->next;
        IntSLLNode *temp2;					
	while (nt != NULL)
 		{temp2 = nt->next;
		 nt->next = temp;
  		 temp = nt;
  		 nt = temp2;}
	tail = head;
	head = temp;
	tail->next = NULL;
  }

int IntSLL::insertafterpos(int pos, int val){
   IntSLLNode *temp = head;
   int index = 0;   
   if (temp == NULL)	//empty list
     	return -2;
   else if (pos<=0)	//can't insert before head and make it new head
        return -1;	
   else{
	while(1){
          index++;
	  	  if(temp == NULL) //when given position is out of bounds
	    	return -1;	   //-won't be true on the first run but maybe later 
    	  else if (index == pos)
	    	break;
	  	  temp = temp->next;
    	}
    IntSLLNode *N = new IntSLLNode(val);   
	if(temp->next == NULL){
		tail->next = N;
		N->next = NULL;
		tail = N;
	  	return 1;
   	}
	else{
	  	N->next = temp->next;
		temp->next = N;
		return 1;
	}  
 }
}

int IntSLL::insertbeforepos(int pos, int val){
   IntSLLNode *temp = head;   
   int index = 0;  
   if(temp==NULL)	//Empty list
     return -2;
   else if (pos<=0)	//Invalid position
        return -1;
   else if(pos==1)	
     	{ IntSLLNode *N= new IntSLLNode(val);
       	  N->next = temp;
          head = N;
          return 1; 
	}
   else       
      { while(1){
	         index++;
	         if (temp==NULL) //position out of bounds
	            return -3;
	         else if(index==pos-1)	//general case
	            break; 
	         temp = temp->next;           
	} 
  	IntSLLNode *N= new IntSLLNode(val);
	N->next = temp->next;
	temp->next = N; 
	return 1;        
         }
}

int main(int argc, char const *argv[])
{
	int ele;
	IntSLL list;
  
  char more= 'y';
  do{
	cout<<"\nChoose to perform one of the following options:";
	cout<<"\n1)Insert an element in the beginning of list\n2)Insert an element at the end of list\n3)Delete an element from beginning of list\n4)Delete an element from the end of list\n5)Count the total no. of elements in list\n6)Display all list elements\n7)Find the average of all list elements\n8)Find and display an element from list\n9)Confirm whether an element is part of the list\n10)Reverse the list\n11)Insert after a position in list\n12)Insert before a position in list\n13)Exit from program\n";
	int choice;
	cin>>choice;
	switch(choice){
		case 1:cout<<"\nEnter new element to be inserted in the beginning of list: ";
			   cin>>ele;
			   list.insertathead(ele);	
			   break;
		case 2:cout<<"\nEnter new element to be inserted at the end of list: ";
			   cin>>ele;
			   list.insertattail(ele);	
			   break;	   
		case 3:list.deletefromhead();
			   break;
    	case 4:list.deletefromtail();
			   break;
		case 5:int total;
           	   total=list.count();
			   cout<<"\nThe total no. of elements in list is: "<<total;
			   break;
		case 6:cout<<"\nThe list elements are: \n";
		       list.traverse();
		       break;
		case 7:float mean;
           	   mean = list.average();
		       cout<<"\nThe average of all list elements is: "<<mean;
		       break;
		case 8:cout<<"\nEnter the element to be searched for: ";
		       cin>>ele;
		       IntSLLNode* found;
         	   found = list.search_ptr(ele);
		       if(found == NULL)
			   cout<<"\nElement not in list!!";
		       else
			   cout<<"\nElement "<<found->info<<" found in list.";
		       break;			     
		case 9:cout<<"\nEnter the element to be searched for: ";
		       cin>>ele;
		       bool val;
         	   val = list.search(ele);
		       if(val == true)
			   cout<<"\nElement is present in list";
		       else
			   cout<<"\nElement not present in list!!";
		       break;
    	case 10:list.reverseSLL();
            	break;
    	case 11: cout<<"\nEnter new element to be inserted: ";
             	cin>>ele;
             	int position;
             	cout<<"\nEnter position after which the new element is to be inserted: ";             
            	cin>>position;
             	int res3;
             	res3 = list.insertafterpos(position, ele);
             	if(res3 == -1)
               		cout<<"\nError!! Invalid position.";
             	else if(res3 == -2)
               		cout<<"\nError!! Empty list.";
             	break;
    	case 12:cout<<"\nEnter new element to be inserted: ";
             	cin>>ele;
             	int pos2;
             	cout<<"\nEnter position before which the new element is to be inserted: ";             
             	cin>>pos2;
             	int res4;
             	res4 = list.insertbeforepos(pos2, ele);
             	if(res4 == -1)
               		cout<<"\nError!! Invalid position.";
             	else if(res4 == -2)
               		cout<<"\nError!! Empty list.";
             	else if(res4 == -3)
               		cout<<"\nError!! Position out of bounds.";
             	break;
		case 13:exit(0);
	}
  cout<<"\nDo you wish to perform more operations on list?: (y/n): ";
  cin>>more;
  }while (more=='y');
   
	return 0;
}