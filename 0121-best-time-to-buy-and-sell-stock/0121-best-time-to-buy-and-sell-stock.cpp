class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int maxm = prices[n-1];

        vector<int> max_right(n);

        max_right[n-1] = maxm;

        for(int i=n-1;i>0;i--){
            if(prices[i]>=maxm){
                maxm = prices[i];
            }
            max_right[i-1] = maxm;
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            if(max_right[i] - prices[i] > ans){
                ans = max_right[i] - prices[i];
            }
        }

        return ans;
        
    }
};