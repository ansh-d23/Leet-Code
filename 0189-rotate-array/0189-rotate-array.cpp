class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       k = (k % nums.size());
       int i=0;
       int j=nums.size()-1;
       while(k--){
        int temp=nums[j];
        for(int t=j;t>=i;t--){
            if(t==i){
                nums[t]=temp;
            }else{
                nums[t]=nums[t-1];
            } 
        }
       }
    }
};