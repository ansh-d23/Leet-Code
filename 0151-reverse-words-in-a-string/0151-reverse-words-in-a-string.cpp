class Solution {
public:
    string reverseWords(string s) {

        //tokenize then reverse + add back
        vector<string> token;
        istringstream iss(s);
        string word, res;

        while(iss >> word){
            token.push_back(word);
        }

        for (int i = token.size() - 1; i >= 0; i--) {
            res += token[i] + " ";
        }

        if (!res.empty()) res.pop_back(); 

        return res;
    }
};