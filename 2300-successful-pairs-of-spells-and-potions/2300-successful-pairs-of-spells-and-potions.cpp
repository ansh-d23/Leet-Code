class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
            int k=potions.size(),val;
            vector<int> ans(spells.size());
            sort(potions.begin(),potions.end());
            for(int i=0;i<spells.size();i++){
                int start=0;
                int end=potions.size()-1;
                while(start<=end){
                    val=0;
                    int mid=start+ (end-start)/2;
                    if(mid==0 && spells[i]*potions[mid]>=success){
                        val=k-mid;
                        break;
                    }else if(spells[i]*potions[mid]>=success && spells[i]*potions[mid-1]<success){
                        val=k-mid;
                        break;
                    }else if(spells[i]*potions[mid]<success) start=mid+1;
                    else end=mid-1;
                }
                ans[i]=val;
            }
            return ans;
    }
};