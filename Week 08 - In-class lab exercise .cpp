//Index Number : 200395P
#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int size, int parentIndex)
{
    int largest = parentIndex; // initialize largest as parent index
    int leftChildIndex = 2 * parentIndex + 1; // index of left child
    int rightChildIndex = 2 * parentIndex + 2; // index of right child

    // if left child is larger than parent
    if (leftChildIndex < size && arr[leftChildIndex] > arr[largest])
        largest = leftChildIndex;

    // if right child is larger than largest so far
    if (rightChildIndex < size && arr[rightChildIndex] > arr[largest])
        largest = rightChildIndex;

    // if largest is not the parent
    if (largest != parentIndex)
    {
        swap(arr[parentIndex], arr[largest]);

        // recursively heapify the affected sub-tree
        heapify(arr, size, largest);
    }
}

// implementing heap sort
void heapSort(int arr[], int size)
{
    // build heap
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // extracting elements from heap one by one
    for (int i = size - 1; i > 0; i--)
    {
        // move current root to end
        swap(arr[0], arr[i]);

        // call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* print contents of array */
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}

