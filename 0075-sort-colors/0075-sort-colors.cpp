class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector<int> freq(3,0);
        int n = nums.size();

        for(auto& it : nums) freq[it]++;

        int i=0;
        while(freq[0]>0){
            nums[i]=0;
            freq[0]--;
            i++;
        }

        while(freq[1]>0){
            nums[i]=1;
            freq[1]--;
            i++;
        }

        while(freq[2]>0){
            nums[i]=2;
            freq[2]--;
            i++;
        }
        
    }
};