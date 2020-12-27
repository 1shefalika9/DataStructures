//SHEFALIKA GHOSH
//19544
/*PROGRAM FOR CREATING A SORTED (in ascending order) SLL (assuming list has no duplicate elements) AND PERFORMING
THE FOLLOWING FUNCTIONS ON IT- INSERTION, DELETION, SEARCH, TRAVERSAL*/

#include <iostream>
#include <cstdlib>
#include <iomanip>
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
	IntSLLNode *tail;

	IntSLL(){
		head=NULL;
		tail=NULL;
	}

	void sortedInsert(int ele);
	int traverse();
	int search(int ele);
	int deleteNode(int ele);
};

void IntSLL::sortedInsert(int ele){
  IntSLLNode *N=new IntSLLNode(ele);
  if(head==NULL)
    { head = N;
      tail = N; }
  else
    { IntSLLNode *prev = head;
      IntSLLNode *cur = head;
      if(head==tail){  			//for  when list has only 1 element
      		if(ele < prev->info)
	 			{ N->next = head;
	   		  	  head = N; }
		    else
	  			{ prev->next =  N;
	   		 	  tail = N; }
	    }
      else{						//for when list has more than 1 element
		    if(ele < head->info)		//for when element has to be made the new head
			    { N->next = head;
  			    head = N; }
		    else{
  			  while(cur->info < ele){
            	prev = cur;
        	  	cur = cur->next;
            	if(cur==NULL){
              		tail->next = N;
              		tail = N;
              		break;
            	}            
          	}
  			  prev->next = N;		    //for general cases-inserting in the middle of the list
  			  N->next = cur;
  		  } 
		}
	}
}

int IntSLL::traverse(){
	if(head==NULL)		//empty list
		return -1;
	else{
		IntSLLNode *temp = head;
		while(temp!=NULL){
			cout<<setw(2)<<temp->info<<" ";
			temp = temp->next;
		}
		return 1;
	}
}

int IntSLL::search(int ele){
	if(head==NULL)		//empty list
		return -2;
	else{
		IntSLLNode *temp = head;
		while(ele >= temp->info){
			if(temp == NULL)
				return -1;
			else if (temp->info == ele)
				return 1;
			temp = temp->next;			
		}
		return -1;
	}
}

int IntSLL::deleteNode(int ele){
  int flag = 0;
	if (head==NULL)		//Empty list
		return -2;

	else if(head == tail){
		if(head->info == ele){	//When list has only 1 element
			delete(head);
			head = NULL;
			tail = NULL;
			return 1;
		}
		else
			return -1;
	}

	else{					//When list has more than 1 element
		IntSLLNode *temp = head;
		if(ele == head->info){
			head = temp->next;
			delete(temp);
			return 1;
		}
		else{
			while(ele >= temp->next->info){
				if(temp->next == NULL)
					return -1;
				else if(temp->next->info==ele)
					{ flag = 1;
            break;}
				temp = temp->next;
			}
      		if(flag==1){
				if (temp->next == tail){
					delete(tail);
					temp->next = NULL;					
					tail = temp;          
				}

				else{
          			IntSLLNode *temp1 = temp->next;
					IntSLLNode *temp2 = temp->next->next;          
					temp->next = temp2;
					delete(temp1);          					
				}

        		return 1;
     		}

			return -1;
		}
	}

}

int main(int argc, char const *argv[])
{
	int element;
	IntSLL slist;
	char more= 'y';
    do{
	cout<<"\nChoose to perform one of the following options:";
	cout<<"\n1)Insert an element in the list\n2)Display all list elements\n3)Search if an element exists in the list\n4)Delete an element from list\n5)Exit from the program\n";
	int choice;
	cin>>choice;
	switch(choice){
		case 1:cout<<"\nEnter new element to be inserted in the list: ";
			   cin>>element;
			   slist.sortedInsert(element);	
			   break;
		case 2:cout<<"\nThe list elements are: ";
         	   int r;
			   r = slist.traverse();
			   if(r== -1)
			   	cout<<"\nEmpty list!!";
			   break;
		case 3:cout<<"\nEnter the element to be searched for: ";
			   cin>>element;
			   int r2;
			   r2 = slist.search(element);
			   if (r2== -1)
			  	  cout<<"\nElement not in list!!";
			   else if(r2== -2)
			   	  cout<<"\nEmpty list!!";
			   else
			   	  cout<<"\nElement is in list!!";
			   break;
		case 4:cout<<"\nEnter the element to be deleted: ";
			   cin>>element;
			   int r3;
			   r3 = slist.deleteNode(element);
			   if(r3== -2)
			   	cout<<"\nEmpty list!!";
			   else if(r3== -1)
			   	cout<<"\nElement not in list!";
			   break;
		case 5:exit(0);
	  }
	cout<<"\nDo you wish to perform more operations on list?: (y/n): ";
    cin>>more;
  	}while (more=='y');

	return 0;
}