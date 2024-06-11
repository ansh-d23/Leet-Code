class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {

        int lenScore  = score.size();
        vector<string> answer(lenScore);
        priority_queue<pair<int,int>> maxheap;

        for(int i=0;i<lenScore;i++){
            maxheap.push({score[i],i});
        } 

        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        int num =1;

        while(!maxheap.empty()){

            auto  top = maxheap.top();
            maxheap.pop();
            int index = top.second;

            if(num<4){
                answer[index] = rank[num-1];
            }else{
                answer[index] = to_string(num);
            }
            num++;
        }

        return answer;
        
    }
};