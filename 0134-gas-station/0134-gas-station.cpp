class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();

        for(int i=0;i<n;i++) gas[i] -=cost[i];

        if(n==1){
            if(gas[0]>=0) return 0;
            else return -1;
        }

        for(int i=0;i<n;i++){
            if(gas[i]>0){
                int tank=0;
                for(int j=i;j<i+n;j++){
                    tank += gas[j%n];
                    if(tank<0) break;
                }
                if(tank>=0) return i;
            }
        }
        return -1;
    }
};