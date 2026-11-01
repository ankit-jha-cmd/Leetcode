class MedianFinder {
public:
priority_queue<int>maxi;
priority_queue<int, vector<int>, greater<int>>mini;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxi.push(num);
        if(maxi.size()-mini.size()>1){
            mini.push(maxi.top());
            maxi.pop();
        }

        if(!mini.empty() && maxi.top()>mini.top()){
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(mini.top());
            mini.pop();
        }
    }
    
    double findMedian() {
        if(maxi.size()==mini.size()) return double(maxi.top()+mini.top())/2.0;
        return maxi.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */