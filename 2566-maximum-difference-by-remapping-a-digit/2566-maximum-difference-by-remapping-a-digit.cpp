class Solution {

    int solve(vector<int>& nums){
        int ans=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            ans = ans*10 + nums[i];
        }

        return ans;
    }

public:
    int minMaxDifference(int num) {

        vector<int> mini;
        vector<int> maxm;

        int temp=num;

        while(temp > 0){
            mini.push_back(temp%10);
            temp/=10;
        }

        reverse(mini.begin(),mini.end());
        maxm = mini;

        //maxm
        int set = -1;
        int n = maxm.size();
        bool flag = true;

        for(int i=0;i<n;i++){
            if(flag && maxm[i]!=9){
                set = maxm[i];
                flag=false;
            }
            if(set!=-1 && maxm[i]==set){
               maxm[i]=9;
            }
        }

        //min 
        set = -1;
        flag = true;

        for(int i=0;i<n;i++){
            if(flag && mini[i]!=0){
                set = mini[i];
                flag=false;
            }
            if(set!=-1 && mini[i]==set){
                mini[i]=0;
            }
        }

        int max_num = solve(maxm);
        int min_num = solve(mini);

        return max_num - min_num;
        
    }
};