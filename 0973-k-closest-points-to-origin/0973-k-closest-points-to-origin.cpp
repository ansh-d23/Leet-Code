class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n =points.size();
        vector<vector<int>> ans;

        priority_queue<pair<double,int>> maxheap;

        for(int i=0;i<n;i++){

            double distance  = sqrt( pow(points[i][0],2) + pow(points[i][1],2) );
            maxheap.push({distance,i});
           
            if(maxheap.size()>k) maxheap.pop();
        }

        while(!maxheap.empty()){
            auto it  = maxheap.top();

            ans.push_back(points[it.second]);

            maxheap.pop();

        }

        return ans;
        
    }
};