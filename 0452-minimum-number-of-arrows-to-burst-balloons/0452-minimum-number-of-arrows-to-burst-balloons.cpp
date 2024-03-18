class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int count=0;
        for(int i=0;i<points.size()-1;i++){
            if(points[i][1]<points[i+1][0]){
                count++;
                continue;
            }else{
                int maxi= max(points[i][0],points[i+1][0]);
                int mini= min(points[i][1],points[i+1][1]);
                points[i+1][0]=maxi;
                points[i+1][1]=mini;
            }
        }
        return count+1;
    }
};