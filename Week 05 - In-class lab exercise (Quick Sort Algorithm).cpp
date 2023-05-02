//Code for Sorting the array using Quick Sort recursively

#include <iostream>
#include <vector>
#include <chrono>  // For measuring time

using namespace std;
using namespace std::chrono;

// Partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Sort the array using Quick Sort
void quickSort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pivotIndex = partition(arr, start, end);
        quickSort(arr, start, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, end);
    }
}

// Example usage
int main() {
    const int numArrays = 5;
    const int minArrayLength = 500;
    const int maxArrayLength = 1000;

    // Sort five arrays of random integers
    for (int i = 0; i < numArrays; i++) {
        int arrayLength = minArrayLength + (rand() % (maxArrayLength - minArrayLength + 1));
        vector<int> arr(arrayLength);

        // Fill array with random integers
        for (int j = 0; j < arrayLength; j++) {
            arr[j] = rand() % 10000;
        }

        // Measure sorting time
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, arrayLength - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << "Array " << i+1 << " of length " << arrayLength << " sorted in " << duration.count() << " nanoseconds." << endl;
    }

    return 0;
}

//Code for Sorting the array using Quick Sort iteratively

#include <iostream>
#include <vector>
#include <chrono> // For measuring time

using namespace std;
using namespace std::chrono;

// Partition the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Sort the array using Quick Sort iteratively
void iterativeQuickSort(vector<int>& arr, int start, int end) {
    vector<pair<int, int>> subArrays;

    subArrays.push_back({ start, end });

    while (!subArrays.empty()) {
        int low = subArrays.back().first;
        int high = subArrays.back().second;
        subArrays.pop_back();

        while (low < high) {
            int pivotIndex = partition(arr, low, high);

            if (pivotIndex - low < high - pivotIndex) {
                subArrays.push_back({ pivotIndex + 1, high });
                high = pivotIndex - 1;
            }
            else {
                subArrays.push_back({ low, pivotIndex - 1 });
                low = pivotIndex + 1;
            }
        }
    }
}

// Example usage
int main() {
    const int numArrays = 5;
    const int minArrayLength = 500;
    const int maxArrayLength = 1000;

    for (int i = 0; i < numArrays; i++) {
        int arrayLength = minArrayLength + (rand() % (maxArrayLength - minArrayLength + 1));
        vector<int> arr(arrayLength);

        // Fill array with random integers
        for (int j = 0; j < arrayLength; j++) {
            arr[j] = rand() % 10000;
        }

        // Measure sorting time
        auto start = high_resolution_clock::now();
        iterativeQuickSort(arr, 0, arrayLength - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << "Array " << i+1 << " of length " << arrayLength << " sorted in " << duration.count() << " nanoseconds." << endl;
    }

    return 0;
}


/*The above code is an implementation of the Quick Sort algorithm in C++ using both recursive and iterative approaches.
The code starts by including the necessary C++ libraries for input-output, vector handling, and time measurement using the <iostream>, <vector>, and <chrono> libraries, respectively.
The Quick Sort algorithm is then implemented using two functions: partition() and quickSort() for the recursive approach, and iterativeQuickSort() for the iterative approach.
The partition() function selects the last element of the sub-array as the pivot element and arranges all the smaller elements to its left and all larger elements to its right, then it returns the index of the pivot element.
The quickSort() function recursively sorts the sub-arrays on both sides of the pivot element. It uses the partition() function to partition the array and then calls itself on the left and right sub-arrays.
The iterativeQuickSort() function is an iterative implementation of the Quick Sort algorithm using a stack to keep track of the sub-arrays that need to be sorted. It uses a loop instead of recursion to sort the sub-arrays.
The main() function generates random arrays of integers and sorts them using both recursive and iterative approaches. It measures the time taken to sort each array using the <chrono> library, and then prints out the sorting time for each array.
Overall, the code provides a clear implementation of the Quick Sort algorithm using both recursive and iterative approaches, and measures the performance of each approach by sorting random arrays of different sizes.*/
