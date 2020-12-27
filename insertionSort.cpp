//SHEFALIKA GHOSH
//19544
//SORTING AN ARRAY IN ASCENDING ORDER (USING INSERTION SORT)

#include <iostream> 
using namespace std; 
  
/* Function to sort an array using insertion sort in ascending order*/
void insertionSort(int arr[], int n)  
{  
    int i, key, j, cmpr, ctr=0;  
    for (i = 1; i < n; i++) 
    {   cmpr=0;
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {   cmpr++;
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
        cout<<"\nArray after pass "<<++ctr<<" is: ";
        	for(int k=0; k<n; k++)
        	  cout<<arr[k]<<" ";
        	  cout<<"\nNo. of comparisons made = "<<cmpr;	
    }  
}  
   
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  
int main()  
{  
    int AR[50], N;
    cout<<"How many elements do you want to create array with?(max. 50): ";
    cin>>N;
    cout<<"\nEnter the elements of the array: ";
    for(int i=0;i<N;i++)
    cin>>AR[i];
    insertionSort(AR,N);
    cout<<"\nThe sorted array is shown below: ";
    printArray(AR,N);  
     
  
    return 0;  
}  