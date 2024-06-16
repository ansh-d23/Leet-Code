class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        priority_queue<int> maxheap;

        for(int i=0;i<heights.size()-1;i++){
            int gap = heights[i+1]-heights[i];

            if(gap>0){
                
                maxheap.push(gap);

                bricks-=gap;

                if(bricks<0){
                    if(ladders==0) return i;
                    else{
                        int topp = maxheap.top();
                        bricks+=topp;
                        maxheap.pop();
                        ladders--;
                    }
                }
            }
        }
        return heights.size()-1;
    }
};