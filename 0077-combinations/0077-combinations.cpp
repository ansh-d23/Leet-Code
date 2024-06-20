class Solution {
public:
    
    void combination(int i, vector<int>& temp,vector<int>& arr,vector<vector<int>>& ans,int k){

        if(i==arr.size()){
            return;
        }
       

        temp.push_back(arr[i]);
        combination(i+1,temp,arr,ans,k);

        if(temp.size()==k){
            ans.push_back(temp);
        }

        temp.pop_back();
        combination(i+1,temp,arr,ans,k);
    }


    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> ans;
        vector<int> arr(n);
        vector<int> temp;

        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }

        combination(0,temp,arr,ans,k);
        return ans;     
    }
};