class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> maxheap;

        for(int i=0;i<stones.size();i++){
            maxheap.push(stones[i]);
        }

        while(maxheap.size()!=1){
            int l1 = maxheap.top();
            maxheap.pop();
            int l2 = maxheap.top();
            maxheap.pop();

            if(l1!=l2){
                maxheap.push(l1-l2);
            }

            if(maxheap.empty()) return 0;
        }

        return maxheap.top();
        
    }
};