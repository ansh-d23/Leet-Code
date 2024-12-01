class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        int n = arr.size();

        sort(arr.begin(),arr.end());

        int i=0;
        int j=n-1;

        while(i<j){
            if(arr[i]*2 == arr[j]) return true;

            if((2*arr[i]) < arr[j]) i++;
            else j--;
        }

        return false;
        
    }
};