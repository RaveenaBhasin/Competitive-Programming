class MedianFinder {
public:
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<>>minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.empty() || num >= minHeap.top()) {
            minHeap.push(num);
            if(minHeap.size() > maxHeap.size() + 1){
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        else{
            maxHeap.push(num);
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if((maxHeap.size() + minHeap.size()) % 2 == 0){
            return (double)(maxHeap.top() + minHeap.top())/2;
        }
        else{
            return minHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
**/