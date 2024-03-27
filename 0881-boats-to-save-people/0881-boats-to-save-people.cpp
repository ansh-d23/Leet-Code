class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=1;
        int count=0;
        while(i<people.size()){
            if(i==people.size()-1){
                count++;
                break;
            }else
            if(people[i]+people[j]<=limit){
                count++;
                i+=2;
                j+=2;
            }else{
                count++;
                i++; j++;
            }
        }
        return count;
    }
};