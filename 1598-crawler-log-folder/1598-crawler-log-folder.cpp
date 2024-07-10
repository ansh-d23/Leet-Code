class Solution {
public:
    int minOperations(vector<string>& logs) {

        int n = logs.size();
        int ans=0;

        for(int i=0;i<n;i++){
            if(logs[i]=="../" && ans==0) continue;
            if(logs[i]=="../" && ans>0){
                ans--;
            }else
            if(logs[i] != "./"){
                ans++;
            }
        }

        return ans;
    }
};