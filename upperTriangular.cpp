//SHEFALIKA GHOSH
//19544
//PROGRAM FOR CREATING, STORING, DISPLAYING AN INTEGER UPPER TRIANGULAR MATRIX

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class upperTriangular
{	int *utriang, size, k, total;
public:
	upperTriangular(int n){
		size=n;
		total= (n*(n+1))/2;
		utriang = (int*) malloc(total*sizeof(int));
		for (int i = 0; i < total; ++i)
		{
			*(utriang+i)= -1;
		}
	}

	int get(int r, int c);
	void set(int r, int c, int value);
	void display();

	~upperTriangular(){}
	
};

int upperTriangular::get(int r, int c){
	if (r<=c)
	{
		k= r*(r-1)/2 + (c-1);
		return *(utriang+k);
	}
	else
		return 0;
}

void upperTriangular::set(int r, int c, int value){
	if (r<=c)
	{
		k= r*(r-1)/2 + (c-1);
		*(utriang+k)=value;
	}
}

void upperTriangular::display(){
	for (int i = 1; i <= size; ++i)
	{ cout<<"\n";
	  for (int j = 1; j <= size; ++j)
	  	{ if (i<=j)
	  		{ k= i*(i-1)/2 + (j-1); 
	  		  cout<<setw(2)<< *(utriang+k) <<" "; }

	      else
	  		{ cout<<setw(2)<<0<<" ";	}
        }
    }
}

int main(int argc, char const *argv[])
{
	int n, choice, row, col;
	cout<<"\nEnter the no. of rows for your upper triangular matrix, n= ";
	cin>>n;
	upperTriangular u1(n);
    label:
	cout<<"\nChoose to perform one of the following options in a upper triangular matrix: ";
	cout<<"\n1. Display an element of the upper triangular matrix(by default non-zero values of upper triangular matrix not manually changed by user are -1)";
	cout<<"\n2. Set a value in upper triangular matrix";
	cout<<"\n3. Display the upper triangular matrix";
	cout<<"\n4. Exit from program\n";
    cin>>choice;

    while (choice==1 || choice==2)
    {	
    	cout<<"\ni index(row value): ";
		cin>>row;
		cout<<"\nj index(column value): ";
		cin>>col;
		if (row>n || row<=0 || col>n || col<=0)
		{
			cout<<"\nInvalid row/column index! Enter again.";
			continue;
		}
        else { break;}                  
    }
    
    int elm, val;
    switch(choice){
    	case 1: elm=u1.get(row,col);
                cout<<"\nThe required element is: "<<elm;
                break;
		case 2: cout<<"\nEnter the new value: ";
				cin>>val;
				u1.set(row,col,val); cout<<"\n";
                break;
		case 3: cout<<"\nThe final matrix is(by default non-zero values of upper triangular matrix not manually changed by user are -1): ";
                u1.display(); 
                break;			
		case 4: u1.~upperTriangular(); exit(0);	
    }
      goto label;

	return 0;
}