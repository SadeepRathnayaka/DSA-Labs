#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int largest = root;  
    int left = 2*root + 1;  
    int right = 2*root + 2;  

    if (right < n && arr[right] > arr[largest]) {largest = right;}

    if (left < n && arr[left] > arr[largest])  {largest = left;}
  
    if (largest != root) {
        int swap = arr[root] ;
        arr[root] = arr[largest] ;
        arr[largest] = swap ;        
        heapify(arr, n, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);}
  
    for (int i = n - 1; i >= 0; i--) {
        int swap = arr[0] ;
        arr[0] = arr[i];
        arr[i] = swap ;
        heapify(arr, i, 0);}
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   srand(time(0));  
   int n = 6;  
   int arr[6];
   for (int i = 0; i < n; i++) {
       arr[i] = rand() % 100 ;
   }

   cout << "Input array " << endl;
   displayArray(arr, n);
   heapSort(arr, n);
   cout << "Sorted array " << endl;
   displayArray(arr, n);

   return 0;
}