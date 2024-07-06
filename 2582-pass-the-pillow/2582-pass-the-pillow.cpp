class Solution {
public:
    int passThePillow(int n, int time) {
        int restart = (n-1)*2;
        int index = time%restart;

        if(index > n-1){
            index = restart-index;
        }

        return index+1;
    }
};