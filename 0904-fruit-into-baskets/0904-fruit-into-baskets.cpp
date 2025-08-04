class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int i = 0, maxLen = 0;

        for (int j = 0; j < fruits.size(); ++j) {
            count[fruits[j]]++;

            while (count.size() > 2) {
                count[fruits[i]]--;
                if (count[fruits[i]] == 0) {
                    count.erase(fruits[i]);
                }
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};
