class KthLargest {
public:
    int global_k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {

        global_k = k;

        for (int i = 0; i < nums.size(); i++) minHeap.push(nums[i]);
        
        while (minHeap.size() > global_k) minHeap.pop();
    }
    
    int add(int val) {

        minHeap.push(val);

        if (minHeap.size() > global_k) minHeap.pop();
        
        return minHeap.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */