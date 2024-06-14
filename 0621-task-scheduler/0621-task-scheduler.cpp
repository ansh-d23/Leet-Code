class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> mpp;
        priority_queue<int> maxheap;

        for(int i=0;i<tasks.size();i++){
            mpp[tasks[i]]++;
        }

        for( auto it : mpp){
            maxheap.push(it.second);
        }

        queue<pair<int,int>> que;

        int time=0;

        while(!que.empty() || !maxheap.empty()){

            time++;

            if(!maxheap.empty()) {
                int cnt  = maxheap.top();
                maxheap.pop();
                cnt--;
                if(cnt>0){
                    que.push({cnt, n+time});
                }
            }

            if(!que.empty() && que.front().second == time){
                maxheap.push(que.front().first);
                que.pop();
            }
        }


        return time;
        
    }
};