class Solution {
public:
    
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& health, string directions) {
        int n =positions.size();

        vector<int> actual_idx(n);
        iota(actual_idx.begin(),actual_idx.end(),0);

        auto compare_with_pos = [&](int & i, int& j){
        return positions[i]<positions[j];
        };

        sort(actual_idx.begin(),actual_idx.end(),compare_with_pos);

        vector<int> ans;
        stack<int> stk;

        for(int curr_idx : actual_idx){
            if(directions[curr_idx] == 'R'){
                stk.push(curr_idx);
            }else{
                while(!stk.empty() && health[curr_idx]>0){
                    int top = stk.top();
                    stk.pop();

                    if(health[top] > health[curr_idx]){
                        health[top]--;
                        health[curr_idx]=0;
                        stk.push(top);
                    }else if(health[top] < health[curr_idx]){
                        health[curr_idx]--;
                        health[top]=0;
                    }else{
                        health[curr_idx]=0;
                        health[top]=0;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            if(health[i]>0) ans.push_back(health[i]);
        }

        return ans;


    }
};