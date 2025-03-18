
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return {};

        unordered_map<string, vector<string>> parents;
        unordered_set<string> current_level, next_level;
        current_level.insert(beginWord);
        bool found = false;

        while (!current_level.empty() && !found) {
            for (const string& word : current_level) words.erase(word);
            next_level.clear();

            for (const string& word : current_level) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == originalChar) continue;
                        temp[i] = c;
                        if (words.count(temp)) {
                            next_level.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            swap(current_level, next_level);
        }

        vector<vector<string>> result;
        if (found) {
            vector<string> path = {endWord};
            dfs(result, path, parents, beginWord, endWord);
        }
        return result;
    }

private:
    void dfs(vector<vector<string>>& result, vector<string>& path,
             unordered_map<string, vector<string>>& parents,
             const string& beginWord, const string& word) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }
        for (const string& parent : parents[word]) {
            path.push_back(parent);
            dfs(result, path, parents, beginWord, parent);
            path.pop_back();
        }
    }
};