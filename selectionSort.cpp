//SHEFALIKA GHOSH
//19544
//SORTING AN ARRAY IN ASCENDING ORDER (USING SELECTION SORT)

#include <iostream>
using namespace std;

void sel_sort(int A[], int size)
{ int small, pos, temp;
  for (int i = 0; i < size-1; ++i)
  {
    small=A[i];
    pos=i;
    for (int j=i+1; j < size; ++j)
    {
      if (A[j]<small)
          {
            small=A[j];
            pos=j;
          }   }
   temp=A[i];
   A[i]=A[pos];
   A[pos]=temp;

   cout<<"\nArray after pass- "<<i+1<<" is: ";
   for (int j = 0; j < size; ++j)
   {
     cout<<A[j]<<" ";
   }
}}

int main(int argc, char const *argv[])
{
  int arr[50], n;
  cout<<"\nEnter array size(max 50): ";
  cin>>n;
   
  cout<<"\nEnter array elements: ";
  for (int i = 0; i < n; ++i)
  {
    cin>>arr[i];
  }

  cout<<"\nThe array entered is: \n";
  for (int i = 0; i < n; ++i)
  {
    cout<<arr[i]<<" ";
  }

  sel_sort(arr,n);

  cout<<"\nThe final sorted array is: \n";
  for (int i = 0; i < n; ++i)
  {
    cout<<arr[i]<<" ";
   }

  return 0;
}