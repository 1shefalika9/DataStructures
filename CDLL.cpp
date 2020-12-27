//SHEFALIKA GHOSH
//19544
/*PROGRAM FOR CREATING A CIRCULAR DOUBLY LINKED LIST(SLL) AND PERFORMING THE FOLLOWING OPERATIONS ON IT: INSERTION, DELETION, SEARCH, TRAVERSAL*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class IntCDLLNode{

public:
  int info;
  IntCDLLNode *prev;
  IntCDLLNode *next;

  IntCDLLNode(int i){
    info = i;
    prev = this;
    next = this;
  }
};

class IntCDLL{
public:  
  IntCDLLNode *tail;

  IntCDLL(){    
    tail=NULL;
  }

  int traverseforward();
  int traversebackward();
  void addathead(int ele);
  void addattail(int ele);
  void deletefromhead();
  void deletefromtail();
  bool search(int ele);
};

int IntCDLL::traverseforward(){	
	if(tail==NULL)
    return -1;
  else{
  IntCDLLNode *temp1 = tail->next;
	while(temp1 != tail){
		cout<<setw(2)<<temp1->info<<" ";
    	temp1 = temp1->next;
	}cout<<setw(2)<<temp1->info<<" ";
   return 1;
}}

int IntCDLL::traversebackward(){
	if(tail==NULL)
    return -1;
  else{
  IntCDLLNode *temp1 = tail;
	while(temp1 != tail->next){
		cout<<setw(2)<<temp1->info<<" ";
    	temp1 = temp1->prev;
	 }cout<<setw(2)<<temp1->info<<" ";
   return 1;
}}

void IntCDLL::addathead(int ele){
	IntCDLLNode *N = new IntCDLLNode(ele);
	if (tail==NULL)
	{		
		tail = N;
		tail->next = N;
		tail->prev = N;
	}
	else{
		IntCDLLNode *temp = tail->next;
    
    tail->next = N;
		N->next = temp;
    temp->prev = N;
    N->prev = tail;
		
	}
}

void IntCDLL::addattail(int ele){
	IntCDLLNode *N = new IntCDLLNode(ele);
	if (tail==NULL)
	{
		tail = N;
		tail->next = N;
		tail->prev = N;
	}
	
	else{
		IntCDLLNode *temp = tail->next;
		N->next = temp;		
		tail->next = N;
    N->prev = tail;
		tail = N;
	}
}

void IntCDLL::deletefromhead(){
	if(tail==NULL)
		return;
	else if (tail->next == tail)
	{
		delete(tail);
		tail = NULL;
	}
	else{
		IntCDLLNode *temp = tail->next;
		tail->next = temp->next;
		temp->next->prev = tail;
		delete(temp);
	}
}

void IntCDLL::deletefromtail(){
	if(tail==NULL)
		return;
	else if (tail->next == tail)
	{
		delete(tail);
		tail = NULL;
	}
	else{
		IntCDLLNode *temp1 = tail->next;
		IntCDLLNode *temp2 = tail->prev;
		temp2->next = temp1;
		temp1->prev = temp2;
		delete(tail);
		tail = temp2;
	}
}

bool IntCDLL::search(int ele){
	IntCDLLNode *temp1 = tail->next;
	IntCDLLNode *temp2 = tail->next;
	while(temp1->next != temp2){
		if(temp1->info == ele)
			return true;
		temp1 = temp1->next;
	}
	return false;
}

int main(int argc, char const *argv[])
{
  int element;
  IntCDLL cdlist;
  char more;
  do{
  cout<<"\nChoose to perform one of the following options:";
  cout<<"\n1)Insert an element at the beginning of list\n2)Insert an element at the end of list\n3)Delete an element from beginning of list\n4)Delete an element from the end of list\n5)Display all list elements\n6)Display all list elements in reverse order\n7)Find if an element exists in the list\n8)Exit from program\n";
  int choice;
  cin>>choice;
  switch(choice){
    case 1:cout<<"\nEnter new element(to be inserted at the beginning of list): ";
           cin>>element;
           cdlist.addathead(element);  
           break;
    case 2:cout<<"\nEnter new element(to be inserted at the end of list): ";
           cin>>element;
           cdlist.addattail(element);  
           break;    
    case 3:cdlist.deletefromhead();
           break;
    case 4:cdlist.deletefromtail();
           break;
    case 5:cout<<"\nThe list elements are: \n";
           int res;
           res = cdlist.traverseforward();
           if(res== -1)
             cout<<"Empty List!!";
           break;
    case 6:cout<<"\nThe list elements(in reverse order)are: \n";
          int res2;
           res2 = cdlist.traversebackward();
           if(res2== -1)
             cout<<"Empty List!!";
           break;
    case 7:cout<<"\nEnter the element to be searched for: ";
           cin>>element;
           bool val;
           val = cdlist.search(element);
           if(val == true)
              cout<<"\nElement is present in list";
           else
              cout<<"\nElement not present in list!!";
           break;
    case 8:exit(0);  
  }
  cout<<"\nDo you wish to perform more operations on list?: (y/n): ";
  cin>>more;
  }while (more=='y');

	return 0;
}