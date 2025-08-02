class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        unordered_map<int,int> mpp;

        for(auto it : basket1){
            mpp[it]++;
        }

        for(auto it : basket2){
            mpp[it]--;
        }

        vector<int> excessA, excessB;
        int min_fruit = INT_MAX;

        for(auto [fruit, diff] : mpp) {
            if (diff % 2 != 0) {
                return -1; 
            }

            min_fruit = min(min_fruit, fruit);
            int count = abs(diff) / 2;

            for (int i = 0; i < count; ++i) {
                if (diff > 0)
                    excessA.push_back(fruit);
                else
                    excessB.push_back(fruit);
            }
        }

        sort(excessA.begin(), excessA.end());
        sort(excessB.rbegin(), excessB.rend());

        long long cost = 0;
        for (int i = 0; i < excessA.size(); ++i) {
            int a = excessA[i];
            int b = excessB[i];
            cost += min({a, b, 2 * min_fruit});
        }

        return cost;
    }
};