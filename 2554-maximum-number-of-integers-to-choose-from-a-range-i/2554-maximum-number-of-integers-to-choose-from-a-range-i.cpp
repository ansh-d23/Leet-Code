class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        unordered_set<int> stt;

        for(int it : banned){
            stt.insert(it);
        }

        int sum=0;
        int count=0;
        for(int i=1;i<=n;i++){
            if(stt.find(i) == stt.end()){
                int temp = sum+i;
                if(temp<=maxSum){
                    sum+=i;
                    count++;
                }
            }
        }

        return count;
        
    }
};