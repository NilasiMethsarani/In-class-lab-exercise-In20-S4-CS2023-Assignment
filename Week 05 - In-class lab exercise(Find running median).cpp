//Code for to calculate the Running median

#include <iostream>
#include <queue>
#include <iomanip> // For printing double precision numbers to 1 decimal place

using namespace std;

// Calculates median of the list
double getMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if (maxHeap.empty() && minHeap.empty()) {
        return 0.0;
    }

    if (maxHeap.size() == minHeap.size()) {
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
    else if (maxHeap.size() > minHeap.size()) {
        return maxHeap.top();
    }
    else {
        return minHeap.top();
    }
}

// Adds new element to the list and returns updated median
double addToRunningList(int num, priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap) {
    if (maxHeap.empty() || num <= maxHeap.top()) {
        maxHeap.push(num);
    }
    else {
        minHeap.push(num);
    }

    // Re-balance heaps
    if (maxHeap.size() > minHeap.size() + 1) {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if (minHeap.size() > maxHeap.size() + 1) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

    return getMedian(maxHeap, minHeap);
}

// Prints median of the list for each new element added
void printMedians(int arr[], int n) {
    priority_queue<int> maxHeap; // Max-heap for smaller half of the list
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap for larger half of the list

    for (int i = 0; i < n; i++) {
        double median = addToRunningList(arr[i], maxHeap, minHeap);
        cout << "[";
        for (int j = 0; j <= i; j++) {
            cout << arr[j];
            if (j != i) {
                cout << ", ";
            }
        }
        cout << "] " << fixed << setprecision(1) << median << endl;
    }
}

// Example usage
int main() {
    int arr[] = { 7, 3, 5, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printMedians(arr, n);
    return 0;
}
