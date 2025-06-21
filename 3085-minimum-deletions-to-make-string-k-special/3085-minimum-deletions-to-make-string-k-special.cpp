class Solution {

    int memo(int i,int j, vector<int>& freq ,vector<vector<int>>& dpp, int& k){

        if(i==j) return 0;
        if(freq[j]-freq[i]<=k) return 0;

        int delLeft = freq[i] + memo(i+1,j,freq, dpp,k);
        int delRight = (freq[j]-freq[i]-k) + memo(i,j-1, freq ,dpp,k);

        return min(delLeft,delRight);

    }


public:
    int minimumDeletions(string word, int k) {
       
       int n = word.length();
       vector<int> freq(26,0);

       for(auto& ch : word) freq[ch-'a']++;

       vector<vector<int>> dpp(26,vector<int>(26,-1));

       sort(freq.begin(),freq.end());

       return  memo(0,25, freq, dpp,k);
    }
};