class Solution {
public:
    int maxDifference(string s) {

        unordered_map<char,int> mpp;
        for(auto ch : s){
            mpp[ch]++;
        }

        int oddmx=INT_MIN;
        int evenmin = INT_MAX;

        for(auto it : mpp){
            int var = it.second;
            if(var%2==0){
                evenmin = min(evenmin, var);
            }else{
                oddmx = max(oddmx, var);
            }
        }

        return (oddmx - evenmin);
    }
};