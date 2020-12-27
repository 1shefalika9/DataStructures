//SHEFALIKA GHOSH
//19544
/*PROGRAM FOR CREATING A DOUBLY LINKED LIST(SLL) AND PERFORMING THE FOLLOWING OPERATIONS ON IT: INSERTION, DELETION, SEARCH, TRAVERSAL*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class IntDLLNode{

public:
  int info;
  IntDLLNode *prev;
  IntDLLNode *next;

  IntDLLNode(){
    info=0;
    prev=NULL;
    next=NULL;
  }

  IntDLLNode(int i, IntDLLNode *pv=NULL, IntDLLNode *nex=NULL){
    info = i;
    prev = pv;
    next = nex;
  }
};

class IntDLL{
public:
  IntDLLNode *head;
  IntDLLNode *tail;

  IntDLL(){
    head=NULL;
    tail=NULL;
  }

  void traverseforward();
  void traversebackward();
  void addathead(int ele);
  void addattail(int ele);
  void deletefromhead();
  void deletefromtail();
  bool search(int ele);
  int insertafterpos(int pos, int val);
  int insertbeforepos(int pos, int val);
};

void IntDLL::traverseforward(){
   IntDLLNode *temp = head;
  while(temp!=NULL){
    cout<<setw(2)<<temp->info<<" ";
    temp = temp->next;
  }
}

void IntDLL::traversebackward(){
   IntDLLNode *temp = tail;
  while(temp!=NULL){
    cout<<setw(2)<<temp->info<<" ";
    temp = temp->prev;
  }
}

void IntDLL::addathead(int ele){
  IntDLLNode *N = new IntDLLNode(ele);
  if(head==NULL){   
    head = N;
    tail = N;  
}
  else   //if((head != tail) || (head==tail))
 {  
    head -> prev = N;
    N -> next = head;  
    head = N;
  }
}

void IntDLL::addattail(int ele){
  IntDLLNode *N = new IntDLLNode(ele);
  if(head==NULL){   
    head = N;
    tail = N;  
  }
  else   //if((head != tail) || (head==tail))
 {   
    tail -> next = N;
    N -> prev = tail;
    tail = N;
  } 
}

void IntDLL::deletefromhead(){
    
    if(head==NULL)
      return;

    else if (head==tail)
    {
      delete(head);
      head = NULL;
      tail = NULL;
    }

    else if(head!=tail)
    {
      IntDLLNode *temp = head;
      head = head->next;
      delete(temp);
      head->prev = NULL;
    }
}

void IntDLL::deletefromtail(){

    if(head==NULL)
      return;

    else if (head==tail)
    {
      delete(head);
      head = NULL;
      tail = NULL;
    }

    else if(head!=tail)
    {
      IntDLLNode *temp = tail;
      tail = tail->prev;
      delete(temp);
      tail->next = NULL;
    }
}

bool IntDLL::search(int ele){
  
  IntDLLNode *temp = head;  
  while(temp!=NULL){
    if (temp->info == ele)
      return true;
    temp = temp->next;
  }

  return false;  
}

int IntDLL::insertafterpos(int pos, int val){
  IntDLLNode *temp = head;
  int index = 0;

  if(head == NULL)
    return -1;

  else if(pos <= 0)
    return -2;

  while(1){
    index++ ;
    if(temp == NULL)
      return -2;
    else if(index == pos)
      break;
    temp = temp->next;
  }
  IntDLLNode *N = new IntDLLNode(val);
  if(temp==tail){
    tail->next = N;
    N->prev = tail;
    tail = N;
  }
  else{
    N->next = temp->next;
    N->prev = temp;
    temp->next->prev = N;
    temp->next = N;
  }
    return 1;
}

int IntDLL::insertbeforepos(int pos, int val){
  IntDLLNode *temp = head;
  int index = 0;

  if(head == NULL)
    return -1;

  else if(pos <= 0)
    return -2;

  while(1){
    index++ ;
    if(temp == NULL)
      return -2;
    else if(index == pos)
      break;
    temp = temp->next;
  }
  IntDLLNode *N = new IntDLLNode(val);
  if (temp==head)
  {
    head->prev = N;
    N->next = head;
    head = N;
  }
  else{
    N->next = temp;
    N->prev = temp->prev;
    temp->prev->next = N;
    temp->prev = N;
  }
  return 1;
}

int main(int argc, char const *argv[])
{
  int element, position;
  IntDLL dlist;
  char more;
  do{
  cout<<"\nChoose to perform one of the following options:";
  cout<<"\n1)Insert an element at the beginning of list\n2)Insert an element at the end of list\n3)Delete an element from beginning of list\n4)Delete an element from the end of list\n5)Display all list elements\n6)Display all list elements in reverse order\n7)Find if an element exists in the list\n8)Insert an element before a position\n9)Insert an element after a position\n10)Exit from program\n";
  int choice;
  cin>>choice;
  switch(choice){
    case 1:cout<<"\nEnter new element(to be inserted at the beginning of list): ";
           cin>>element;
           dlist.addathead(element);  
           break;
    case 2:cout<<"\nEnter new element(to be inserted at the end of list): ";
           cin>>element;
           dlist.addattail(element);  
           break;    
    case 3:dlist.deletefromhead();
           break;
    case 4:dlist.deletefromtail();
           break;
    case 5:cout<<"\nThe list elements are: \n";
           dlist.traverseforward();
           break;
    case 6:cout<<"\nThe list elements(in reverse order)are: \n";
           dlist.traversebackward();
           break;
    case 7:cout<<"\nEnter the element to be searched for: ";
           cin>>element;
           bool val;
           val = dlist.search(element);
           if(val == true)
              cout<<"\nElement is present in list";
           else
              cout<<"\nElement not present in list!!";
           break;
    case 8:cout<<"\nEnter new element to be inserted: ";
           cin>>element;           
           cout<<"\nEnter position before which the new element is to be inserted: ";             
           cin>>position;
           int res;
           res = dlist.insertbeforepos(position, element);
           if(res == -1)
               cout<<"\nError!! Empty list.";
           else if(res == -2)
               cout<<"\nError!! Invalid position.";
           break;
    case 9:cout<<"\nEnter new element to be inserted: ";
           cin>>element;           
           cout<<"\nEnter position after which the new element is to be inserted: ";             
           cin>>position;
           int res2;
           res2 = dlist.insertafterpos(position, element);
           if(res2 == -1)
               cout<<"\nError!! Empty list.";
           else if(res2 == -2)
               cout<<"\nError!! Invalid position.";
           break;
    case 10:exit(0);  
  }
  cout<<"\nDo you wish to perform more operations on list?: (y/n): ";
  cin>>more;
  }while (more=='y');

  return 0;
}







// bool palindrome(){
//   IntDLLNode *temp1= head;
//   IntDLLNode *temp2= tail;
// if(temp1->next==temp2)
//   { if(temp1->info != temp2->info)
//        return false; }
//else{  
//  while((temp1 != temp2)){
//      if(temp1->info != temp2->info)
//         return false;
//      temp1 = temp1->next;
//      temp2 = temp2->prev; 
//    }
//  }
//  return true;
// } 

// reverseDLL(){
//    *rev = NULL;
//    *temp=head;
//     while(temp!=NULL){
//   rev = temp->prev;
//   temp->prev = temp->next;
//   temp->next = rev;
//         //temp = temp->next;
//      }
// }