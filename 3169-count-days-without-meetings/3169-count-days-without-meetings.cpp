class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(),meetings.end());

        int count=0;
        int mini = meetings[0][0];
        int maxm= meetings[0][1];


        for(int i=0;i<meetings.size()-1;i++){

            if(meetings[i][1] < meetings[i+1][0]){
                count+= meetings[i+1][0]-meetings[i][1]-1;
                maxm=meetings[i+1][1];
 
            }else{

                
                maxm = max(meetings[i][1],meetings[i+1][1]);

                meetings[i+1][1]=maxm;
               

            }
        }

        count+= (days-maxm);


        count+= (mini-1);

        return count;
        
    }
};