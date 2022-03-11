
#include <queue>

void findMedian(int* arr, int n) {
    priority_queue<int, vector<int>, greater<int> > minHeap;
    priority_queue<int> maxHeap;

    // For each element in the data stream
    for (int i = 0; i < n; i++) {
        if (maxHeap.size() && arr[i] > maxHeap.top()) {
            minHeap.push(arr[i]);
        } else {
            maxHeap.push(arr[i]);
        }

        if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1) {
            if (maxHeap.size() > minHeap.size()) {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            } else {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }

        int median;
        int totalSize = maxHeap.size() + minHeap.size();

        // When number of elements is odd
        if (totalSize % 2 == 1) {
            if (maxHeap.size() > minHeap.size()) {
                median = maxHeap.top();
            } else {
                median = minHeap.top();
            }
        }

        // When number of elements is even
        else {
            median = 0;
            if (!maxHeap.empty()) median += maxHeap.top();
            if (!minHeap.empty()) median += minHeap.top();
            median /= 2;
        }

        cout << median << " ";
    }
}
