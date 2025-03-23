class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        unordered_set<int> ter;
        vector<int> ans;

        for(int i=0;i<n;i++){
            if(graph[i].size()==0) ter.insert(i);
        }

        for(int i=0;i<n;i++){
            int count=0;
            int k = graph[i].size();
            if(graph[i].size()==0){
                ans.push_back(i);
                continue;
            }
            for(auto it : graph[i]){
                if(ter.find(it) != ter.end()){
                    count++;
                }
            }

            if(count==k) ans.push_back(i);
        }


        return ans; 
    }
};