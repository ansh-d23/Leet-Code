class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // booyes more algorith - based on idea of votes and candidate (validate + check)

        int n = nums.size();

        int cand = nums[0];
        int count=0;

        for(int i=0;i<n;i++){
            if(nums[i]==cand){
                count++;
            }else{
                count--;
            }

            if(count<=0){
                cand=nums[i];
                count=1;
            }
        }

        //validate
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==cand) ans++;
        }

        return (ans > (n/2)) ? cand : -1;


        
    }
};