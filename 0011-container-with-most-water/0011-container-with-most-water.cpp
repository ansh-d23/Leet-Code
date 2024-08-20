class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end=height.size()-1;
        long long maxm=0;
        while(start<end ){
           long long amount = min(height[start], height[end]) * (end - start);
            maxm = max(amount,maxm);
            if(height[start]==height[end]){
                start++;
                end--;
            }else if(height[start]<height[end]){
                start++;
            }else{
                end--;
            }
        }
        return maxm;
    }
};