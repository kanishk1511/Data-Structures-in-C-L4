#include <vector>
#include <algorithm>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        int ans=pq[0];
        int temp;
        pq[0]= pq[pq.size() - 1];
        pq.pop_back();
        
        int PI=0,minIndex;
        while(PI < pq.size()){
            int lci=2*PI+1, rci=2*PI+2;
            if(lci>=pq.size())
                break;
            if(rci>=pq.size() && lci<pq.size()){
                if(pq[PI]>pq[lci]){
                    
                    temp = pq[lci];
                    pq[lci]=pq[PI];
                    pq[PI]=temp;
                    minIndex=lci;
                }
                else
                    break;
            }
            else{
                if(pq[PI]>pq[lci] && pq[lci]<pq[rci]){
                    minIndex=lci;
                    temp = pq[lci];
                    pq[lci]=pq[PI];
                    pq[PI]=temp;
                }
                else if(pq[PI]>pq[rci] && pq[rci]<pq[lci]){
                    minIndex=rci;
                    temp = pq[rci];
                    pq[rci]=pq[PI];
                    pq[PI]=temp;
                }
                else{
                    break;
                }
            }
            
            PI=minIndex;
        }
        return ans;
        // Write your code here
    }
};
