//SHEFALIKA GHOSH
//19544
//PROGRAM FOR CREATING, STORING, DISPLAYING AN INTEGER TRI-DIAGONAL MATRIX

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class triDiagonal
{	int *tDiag, size, k, total;
public:
	triDiagonal(int n){
		size=n;
		total= (3*n)-2;
		tDiag = (int*) malloc(total*sizeof(int));
		for (int i = 0; i < total; ++i)
		{
			*(tDiag+i)= -1;
		}
	}

	int get(int r, int c);
	void set(int r, int c, int value);
	void display();

	~triDiagonal(){}
	
};

int triDiagonal::get(int r, int c){
	if (r-c == 1)
	  k= r-2;
	
	else if (r==c)
	  k= (size-1)+(r-1);

	else if (r-c == -1)
	  k= (2*size)+r-2;

	else
	  return 0;

	return *(tDiag+k);
}


void triDiagonal::set(int r, int c, int value){
	if (r-c == 1)
	  k= r-2;
	
	else if (r==c)
	  k= (size-1)+(r-1);

	else if (r-c == -1)
	  k= (2*size)+r-2;

	else{}

	*(tDiag+k)=value;	

}

void triDiagonal::display(){
  for (int i = 1; i <= size; ++i)
	{ cout<<"\n";
	  for (int j = 1; j <= size; ++j)
	  	{ if (i-j == 1)
	  		{ k= i-2; 
	  		  cout<<setw(2)<< *(tDiag+k) <<" "; }
	
		  else if (i==j)
	  		{ k= (size-1)+(i-1); 
	  		  cout<<setw(2)<< *(tDiag+k) <<" "; }

	      else if (i-j == -1)
	  		{ k= (2*size)+i-2; 
	  		  cout<<setw(2)<< *(tDiag+k) <<" "; }

	      else
	  		{ cout<<setw(2)<<0<<" ";	}
        }
    }
 }  
  
int main(int argc, char const *argv[])
{
	int n, choice, row, col;
	cout<<"\nEnter the no. of rows for your tri-diagonal matrix, n= ";
	cin>>n;
	triDiagonal d1(n);
    label:
	cout<<"\nChoose to perform one of the following options in a tri-diagonal matrix: ";
	cout<<"\n1. Display an element of the tri-diagonal matrix";
	cout<<"\n2. Set a value in tri-diagonal matrix";
	cout<<"\n3. Display the tri-diagonal matrix";
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
    	case 1: elm=d1.get(row,col);
                cout<<"\nThe required element is: "<<elm;
                break;
		case 2: cout<<"\nEnter the new value: ";
				cin>>val;
				d1.set(row,col,val); cout<<"\n";
                cout<<"\nThe new matrix is(by default non-zero values of tri-diagonal matrix not manually changed by user are -1): ";
                d1.display();
                break;
		case 3: cout<<"\nThe final matrix is(by default non-zero values of tri-diagonal matrix not manually changed by user are -1): ";
                d1.display(); 
                break;			
		case 4: d1.~triDiagonal(); exit(0);	
    }
      goto label;

	return 0;
}