//SHEFALIKA GHOSH
//19544
//PROGRAM FOR CREATING, STORING, DISPLAYING AN INTEGER SYMMETRIC MATRIX

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class symmetric
{	int *sym, size, k, total;
public:
	symmetric(int n){
		size=n;
		total= (n*(n+1))/2;
		sym = (int*) malloc(total*sizeof(int));
		for (int i = 0; i < total; ++i)
		{
			*(sym+i)= -1;
		}
	}

	int get(int r, int c);
	void set(int r, int c, int value);
	void display();

	~symmetric(){}
	
};

int symmetric::get(int r, int c){
	if (r<c)
	 {
	 	int temp = r;
	 	r = c;
	 	c = temp;
	 }

	k= r*(r-1)/2 + (c-1);
	return *(sym+k);
	
}

void symmetric::set(int r, int c, int value){
	if (r<c)
	 {
	 	int temp = r;
	 	r = c;
	 	c = temp;
	 }

	 k= r*(r-1)/2 + (c-1);
	 *(sym+k)=value;
}

void symmetric::display(){
	for (int i = 1; i <= size; ++i)
	{ cout<<"\n";
	  for (int j = 1; j <= size; ++j)
	  	{ 			
	  				int temp_i = i;
					int temp_j = j;

					if(temp_i < temp_j)
					{
						int temp = temp_i;
						temp_i = temp_j;
						temp_j = temp; 
					}

	  		  k= temp_i*(temp_i-1)/2 + (temp_j-1); 
	  		  cout<<setw(2)<< *(sym+k) <<" "; 
	  			    
        }
    }
}

int main(int argc, char const *argv[])
{
	int n, choice, row, col;
	cout<<"\nEnter the no. of rows for your symmetric matrix, n= ";
	cin>>n;
	symmetric s1(n);
    label:
	cout<<"\nChoose to perform one of the following options in a symmetric matrix: ";
	cout<<"\n1. Display an element of the symmetric matrix";
	cout<<"\n2. Set a value in symmetric matrix";
	cout<<"\n3. Display the symmetric matrix";
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
    	case 1: elm=s1.get(row,col);
                cout<<"\nThe required element is: "<<elm;
                break;
		case 2: cout<<"\nEnter the new value: ";
				cin>>val;
				s1.set(row,col,val); cout<<"\n";                
                break;
		case 3: cout<<"\nThe final matrix is(by default non-zero values of symmetric matrix not manually changed by user are -1): ";
                s1.display(); 
                break;			
		case 4: s1.~symmetric(); exit(0);	
    }
      goto label;

	return 0;
}