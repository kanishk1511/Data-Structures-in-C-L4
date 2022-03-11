// int kthLargest(int* arr, int n, int k) {
//     // Write your code here
// }
#include <vector>
#include <queue>
using namespace std;
int kthLargest(int* arr, int n, int k)
{
    
  priority_queue <int> pq; 
    
    // push first k eements in the priority queue
    for(int i=0 ;i<n; i++)
         pq.push(arr[i]);
        
    // for remaining elements compare the element with max of pq ie top
    //if smaller push in heap
    for(int j=0;j<k-1;j++){
        pq.pop();
    }
    return pq.top();
}
