//SHEFALIKA GHOSH
//19544
/*PROGRAM FOR CREATING A SORTED (in ascending order) SLL (assuming list has no duplicate elements) AND PERFORMING
THE FOLLOWING FUNCTIONS ON IT- INSERTION, DELETION, SEARCH, TRAVERSAL, MERGING TWO SORTED LISTS*/

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
	void merge(IntSLL slist2);
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

void IntSLL::merge(IntSLL slist2){
    if(slist2.head == NULL)
        return;

    else if(head == NULL){
        head = slist2.head;
        tail = slist2.tail;
    }

    else{
        IntSLLNode *cur1 = head;
        IntSLLNode *prev1 = head;
        IntSLLNode *cur2 = slist2.head;
    
        while((cur1 != NULL)&&(cur2!=NULL)){
            if(cur1->info < cur2->info){
                prev1 = cur1;
                cur1 = cur1->next;
        
            }
            else{
                IntSLLNode *temp;
                if (cur1 == head)
                {
                      temp = cur2->next;
                      cur2 ->next = cur1;
                      prev1 = cur2;
                      head = prev1;
                      cur2 = temp;
                }
                else
                {
                    temp = cur2->next;
                    cur2 ->next = cur1;
                    prev1->next = cur2;
                    prev1 = cur2;
                    cur2 = temp;
                }
            }
        }
        if(cur1==NULL){
            prev1->next = cur2;
            tail = slist2.tail;
        }
    }
}

int main(int argc, char const *argv[])
{
	int element;
	IntSLL slist1, slist2;
	char more= 'y';
    do{
	cout<<"\nChoose to perform one of the following options:";
	cout<<"\n1)Insert an element in list 1\n2)Insert an element in list 2\n3)Display all list elements of list 1\n4)Display all list elements of list 2\n5)Search if an element exists in list 1\n6)Search if an element exists in list 2\n7)Delete an element from list 1\n8)Delete an element from list 2\n9)Exit from the program\n";
	int choice;
	cin>>choice;
	switch(choice){
		case 1:cout<<"\nEnter new element to be inserted in list 1: ";
			   cin>>element;
			   slist1.sortedInsert(element);	
			   break;
		case 2:cout<<"\nEnter new element to be inserted in list 2: ";
			   cin>>element;
			   slist2.sortedInsert(element);	
			   break;
		case 3:cout<<"\nThe list elements in list 1 are: ";
         	   int r;
			   r = slist1.traverse();
			   if(r== -1)
			   	cout<<"\nEmpty list!!";
			   break;
		case 4:cout<<"\nThe list elements in list 2 are: ";
         	   int r1;
			   r1 = slist2.traverse();
			   if(r1== -1)
			   	cout<<"\nEmpty list!!";
			   break;
		case 5:cout<<"\nEnter the element to be searched for in list 1: ";
			   cin>>element;
			   int r2;
			   r2 = slist1.search(element);
			   if (r2== -1)
			  	  cout<<"\nElement not in list!!";
			   else if(r2== -2)
			   	  cout<<"\nEmpty list!!";
			   else
			   	  cout<<"\nElement is in list!!";
			   break;
		case 6:cout<<"\nEnter the element to be searched for in list 2: ";
			   cin>>element;
			   int r3;
			   r3 = slist2.search(element);
			   if (r3== -1)
			  	  cout<<"\nElement not in list!!";
			   else if(r3== -2)
			   	  cout<<"\nEmpty list!!";
			   else
			   	  cout<<"\nElement is in list!!";
			   break;
		case 7:cout<<"\nEnter the element to be deleted in list 1: ";
			   cin>>element;
			   int r4;
			   r4 = slist1.deleteNode(element);
			   if(r4== -2)
			   	cout<<"\nEmpty list!!";
			   else if(r4== -1)
			   	cout<<"\nElement not in list!";
			   break;
		case 8:cout<<"\nEnter the element to be deleted in list 2: ";
			   cin>>element;
			   int r5;
			   r5 = slist2.deleteNode(element);
			   if(r5== -2)
			   	cout<<"\nEmpty list!!";
			   else if(r5== -1)
			   	cout<<"\nElement not in list!";
			   break;
		case 9:exit(0);
	  }
	cout<<"\nDo you wish to perform more operations on lists?: (y/n): ";
    cin>>more;
  	}while (more=='y');

  	cout<<"\nThe final sorted merged list from the two sorted lists is:\n";
  	slist1.merge(slist2);
  	slist1.traverse();

	return 0;
}