#define ll long long

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {

    priority_queue<ll, vector<ll>, greater<ll>> minHeap;

    for (auto it : nums) {
        ll num = stoll(it);
        minHeap.push(num);
        
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    return to_string(minHeap.top());
        
    }
};