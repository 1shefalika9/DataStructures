//SHEFALIKA GHOSH
//19544
//PROGRAM FOR CREATING, STORING, DISPLAYING AN INTEGER DIAGONAL MATRIX

#include <iostream>
#include <cstdlib>
using namespace std;

class diagMat
{  int *ptr, size, k;
public:
	diagMat(int n, int * elements){
		size=n;
		ptr=elements;
	};

	int get(int i, int j){
		if (i==j)
		 { k=i-1; return *(ptr+k); }
		else return 0;
		
	}

	void set(int i, int j, int value){
		if (i==j)
		  k=i-1;
		else{}
		ptr[k]=value;	
	}

	void display(){
		for (int i = 0; i < size; ++i)
		 { cout<<"\n";
		 	for (int j = 0; j < size; ++j)
			{
				if (i==j)
				  cout<<ptr[i]<<" ";
				else
				  cout<<0<<" ";
			}
		}
	 }

	~diagMat(){}	
};

int main(int argc, char const *argv[])
{
	int n, r=2;
	int dmatrix[r];
	cout<<"No. of rows and columns in your nxn diagonal matrix?: n=";
	cin>>n;
	cout<<"\nEnter the elements of main diagonal of your diagonal matrix: \n";
	for (int i = 0; i < n; ++i)
	{
		cout<<"matrix["<<i+1<<"]["<<i+1<<"]: ";
		cin>>dmatrix[i];
	}

	diagMat dm(n, dmatrix);
    int choice; 
    char ch;
    //do{
	cout<<"\nChoose one of the following options: ";
	cout<<"\n1. Display an element of the diagonal matrix";
	cout<<"\n2. Set a value in diagonal matrix";
	cout<<"\n3. Display the diagonal matrix";
	cout<<"\n4. Exit";
    cin>>choice;

	int row, col, val, elm;
	switch(choice){
		case 1: cout<<"\n Enter the index values for the element to be displayed: ";
				cout<<"\ni index(row value): ";
				cin>>row;
				cout<<"\nj index(column value): ";
				cin>>col;
				elm=dm.get(row,col);
                cout<<"\nThe required element is: "<<elm;
                break;
		case 2: cout<<"\nEnter the index values for the element to be changed: ";
				cout<<"\ni index(row value): ";
				cin>>row;
				cout<<"\nj index(column value): ";
				cin>>col;
				cout<<"\nEnter the new value: ";
				cin>>val;
				dm.set(row,col,val); cout<<"\n";
                cout<<"\nThe new matrix is: ";
                dm.display();
                break;
		case 3: dm.display(); break;			
		case 4: dm.~diagMat(); exit(0);	
	} 
    /*cout<<"\nDo you wish to perform more operations?: ";
    cin>>ch;} while(ch=='y' || ch=='Y');    */
	return 0;
}