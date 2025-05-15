class Solution {
public:
    // Recursive approach (without memoization)
    vector<string> solveRE(int i, int lastGroup, vector<string>& words, vector<int>& groups) {
        if (i >= words.size())
            return {};

        // Skip current word
        vector<string> skip = solveRE(i + 1, lastGroup, words, groups);

        // Take current word if its group is not the same as the last used group
        if (groups[i] != lastGroup) {
            vector<string> take = solveRE(i + 1, groups[i], words, groups);
            take.insert(take.begin(), words[i]);
            return (take.size() > skip.size()) ? take : skip;
        }

        return skip;
    }

    // Memoized version of the recursive approach
    vector<string> solveME(int i, int lastGroup, vector<string>& words, vector<int>& groups,
                           vector<vector<vector<string>>>& dp) {
        if (i >= words.size())
            return {};

        // Offset lastGroup by +1 to avoid negative indexing
        if (!dp[i][lastGroup + 1].empty())
            return dp[i][lastGroup + 1];

        vector<string> skip = solveME(i + 1, lastGroup, words, groups, dp);

        if (groups[i] != lastGroup) {
            vector<string> take = solveME(i + 1, groups[i], words, groups, dp);
            take.insert(take.begin(), words[i]);
            dp[i][lastGroup + 1] = (take.size() > skip.size()) ? take : skip;
        } else {
            dp[i][lastGroup + 1] = skip;
        }

        return dp[i][lastGroup + 1];
    }

    // Main function
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int g = groups.size(); // Maximum number of groups

        // DP array of size [n][g + 1] since lastGroup can be -1 to g-1
        vector<vector<vector<string>>> dp(n, vector<vector<string>>(g + 1));

        return solveME(0, -1, words, groups, dp);
    }
};