class Solution {
public:
    int nC2(int n){
        return (n*(n-1))/2;
    }

    int tupleSameProduct(vector<int>& nums) {

        unordered_map<int, int> mpp;
        int count = 0;

        int n = nums.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mpp[nums[i]*nums[j]]++;
            }
        }

        for(auto [product,freq] : mpp){
            count += 8 *  nC2(freq);
        }

        return count;
        
    }
};