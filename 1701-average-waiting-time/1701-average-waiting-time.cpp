class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        int n = customers.size();
        int net_time = 0;
        double waiting_time = 0;

        for(int i=0;i<n;i++){

            vector<int> temp = customers[i];

            if(temp[0] > net_time) net_time=temp[0];

            net_time+=temp[1];
            waiting_time+=(net_time-temp[0]);
        }

        return waiting_time / n ;
        
    }
};