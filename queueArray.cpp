#include <iostream>
#include <iomanip>
using namespace std; 

class  Queue{
private:
  	int size;
	int *storage;
	int first, last;

public:
	Queue(int len)
	{
		first = last = -1;
    	size = len;
    	storage = new int[size];
	}

	int enqueue(int);
	int dequeue();
	bool isFull(){
		if ((first == 0 and last == size-1) or (first == last+1))
			return true;
		else
			return false;
	}
	bool isEmpty(){
		return (first == -1);
	}
	int disp();
};

int Queue::enqueue(int ele){
	if (!isFull())
	{
		if (last == size-1 or last == -1)
		{
			storage[0] = ele;
			last = 0;
			if (first == -1)
				first = 0;
		}
		else
			storage[++last] = ele;

		return 0;
	}
	return -1;
}

int Queue::dequeue(){
	int temp;
	temp = storage[first];
	if(first == last)
  	{ 	
  		if (first == -1)
      		return -17;
    	first = last = -1;
  	}
	else if (first == size-1)
		first = 0;
	else
		first++ ;

	return temp;
}

int Queue::disp(){
	if (last == -1)
		return -1;
	else if (last < first)
	{ 	
		for (int i = first; i < size; ++i)
			cout<<setw(2)<<storage[i];
    	for (int i = 0; i <= last; ++i)
			cout<<setw(2)<<storage[i];		
		return 0;
	}
	else
	{
		for (int i = first; i <= last; ++i)
			cout<<setw(2)<<storage[i];
		return 0;
	}
}

int main(int argc, char const *argv[])
{	int n;
  	cout<<"\nEnter the maximum queue size: ";
  	cin>>n;
	Queue q(n);
	char more= 'y';
  	do{
		int choice;
		cout<<"\nChoose: \n1)Insert element in queue.\n2)Delete element from queue.\n3)Display queue.\n";
		cin>>choice;
		switch(choice)
		{
			case 1:	int item;
					cout<<"\nEnter element to be inserted in queue: ";
					cin>>item;
					int res;
					res = q.enqueue(item);
					if (res == -1)
						cout<<"\nSorry! Queue is full, no new element can be inserted before deleting element(s).";
    				break;
			case 2:	int element;
					element = q.dequeue();
          			if(element == -17)
            			cout<<"\nEmpty Queue!!";
          			else
					  cout<<"\nElement "<<element<<" has been removed from queue.";
					break;
			case 3: int res2;
					res2 = q.disp();
					if(res2 == -1)
						cout<<"\nEmpty Queue!!";
          			break;
      		default: cout<<"\nInvalid input!!";
		}
	cout<<"\nDo you wish to perform more operations?: (y/n): ";
  	cin>>more;
  	}while (more=='y');
	return 0;
}