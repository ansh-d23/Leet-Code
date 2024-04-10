class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int> ans(deck.size());
        deque<int> que;
        for(int i=0;i<deck.size();i++){
            que.push_back(i);
        }

        for(int i=0;i<deck.size();i++){
            int idx= que.front();
            que.pop_front();
            ans[idx]=deck[i];
            if(!que.empty()){
                que.push_back(que.front());
                que.pop_front();
            }

        }
        return ans;
    }
};