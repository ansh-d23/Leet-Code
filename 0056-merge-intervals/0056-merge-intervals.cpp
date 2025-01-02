class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>> temp;
         int n = intervals.size();
         sort(intervals.begin(),intervals.end());
         int start=intervals[0][0],end=intervals[0][1];
    vector<int> ans;
        
         for(int i=0;i<n;i++){
             
             int x=intervals[i][0];
             int y=intervals[i][1];
             if(x<start && y<start){
                 //exit
                ans.push_back(x);
                ans.push_back(y);
                temp.push_back(ans);
                ans.clear();
             }else
              if(x>end){
                ans.push_back(start);
                ans.push_back(end);
                temp.push_back(ans);
                ans.clear();
                start=x; end=y; 
              }else{
                  if(x<start){
                      start=x;
                  }
                  if(y>end){
                  end=y;
                  }
              }

              if(i==n-1){
                  //exit
                ans.push_back(start);
                ans.push_back(end);
                temp.push_back(ans);
              }
         }
         return temp;
    }
};