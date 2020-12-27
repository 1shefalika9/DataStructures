//SHEFALIKA GHOSH
//19544
//SORTING AN ARRAY IN ASCENDING ORDER (USING BUBBLE SORT)

#include<iostream>
using namespace std; 

void bsort(int A[],int size)
{ int temp,ctr=0,cmpr;
  for(int i=0;i<size;i++)
  { cmpr=0;
    for(int j=0;j<(size-1)-i;j++)
   { cmpr++; 
     if(A[j]>A[j+1])
      {temp=A[j];
       A[j]=A[j+1];
       A[j+1]=temp;  } }
  cout<<"\nArray after iteration- "<<++ctr<<" is: " ;
  for(int k=0;k<size;k++)
  cout<<A[k]<<" ";
  cout<<endl; 
  cout<<"No. of comparisons made="<<cmpr; } 
  }

int main(int argc, char const *argv[])
{
int *AR, N;		
cout<<"How many elements do you want to create array with?: ";
cin>>N;
AR = new int[N];
cout<<"\nEnter the elements of the array: ";
for(int i=0;i<N;i++)
  cin>>*(AR + i);
bsort(AR,N);
cout<<"\nThe sorted array is shown below: ";
for (int i=0;i<N;i++)
  cout<<AR[i]<<" ";
cout<<endl;

return 0;

}
