class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size()==0) return 0;

        unordered_set<int> stt;
        int longest = 1;

        for(auto it : nums) stt.insert(it);

        for(auto it : stt){
            if(stt.find(it-1) == stt.end()){
                int count=1;
                int x=it;
                while(stt.find(x+1) != stt.end()){
                    count++;
                    x++;
                }

                longest = max(longest,count);

            }
        }

        return longest;
        
    }
};