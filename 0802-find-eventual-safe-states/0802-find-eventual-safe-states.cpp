class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int v = graph.size();
        vector<vector<int>> outgo(v);
        vector<int> outdeg(v);

        for(int i=0;i<v;i++){
            for(auto& it : graph[i]){
                outgo[it].push_back(i);
            }
        }

        for(int i=0;i<v;i++){
            for(auto& it : outgo[i]){
                outdeg[it]++;
            }
        }

        queue<int> que;
        for(int i=0;i<v;i++){
            if(outdeg[i]==0) que.push(i);
        }

        vector<int> ans;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            ans.push_back(node);

            for(auto& it : outgo[node]){
                outdeg[it]--;
                if(outdeg[it]==0){
                    que.push(it);
                }
            }

        }

        sort(ans.begin(),ans.end());

        return ans;

    }
};