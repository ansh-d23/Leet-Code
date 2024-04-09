class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int i=0;
        int count=0;
        while(tickets[k]!=0){
            if(i==tickets.size()) i=0;
            if(tickets[i]==0){
                i++;
                continue;
            }
            else{
                tickets[i]--;
                count++;
            }
            i++;
        }
        return count;
    }
};