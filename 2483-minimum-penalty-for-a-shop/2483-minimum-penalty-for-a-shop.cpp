class Solution {
public:
    int bestClosingTime(string customers) {
        customers+='N';
        int countY=0,countN=0;
        int min=INT_MAX;
        int index=0;
        for(int i=0;i<customers.length();i++){
            if(customers[i]=='Y') countY++;
        }
        for(int i=0;i<customers.length();i++){
            int temp=countN+countY;
            if(temp<min){
                min=temp;
                index=i;
            }
            if(customers[i]=='Y') countY--;
            if(customers[i]=='N') countN++;
        }
        return index;
    }
};