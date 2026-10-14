class MedianFinder {
public:
priority_queue<int>maxh;
priority_queue<int, vector<int>, greater<int>>minh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxh.push(num);
        if(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        if(!minh.empty()){
            if(maxh.top()>minh.top()){
                maxh.push(minh.top());
                minh.pop();
                minh.push(maxh.top());
                maxh.pop();
            }
        }
    }
    
    double findMedian() {
        if(minh.size()==maxh.size()) return double(minh.top()+maxh.top())/2.0;
        return maxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */