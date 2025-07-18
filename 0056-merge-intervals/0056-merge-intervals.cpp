class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end());

        for(int i=1;i<n;i++){
            if(intervals[i-1][1] >= intervals[i][0]){
                intervals[i][0] = intervals[i-1][0];
            }else{
                ans.push_back(intervals[i-1]);
            }
        }

        ans.push_back(intervals[n-1]);

        return ans;
    }
};