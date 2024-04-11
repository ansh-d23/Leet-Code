class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> numStack;
        if(num.length()==k) return "0";
        for (char digit : num) {
            while (k > 0 && !numStack.empty() && digit < numStack.top()) {
                numStack.pop();
                k--;
            }
            numStack.push(digit);
        }
        
        while (k > 0 && !numStack.empty()) {
            numStack.pop();
            k--;
        }

        string temp = "";
        while (!numStack.empty()) {
            temp.push_back(numStack.top());
            numStack.pop();
        }
        reverse(temp.begin(), temp.end());

        int m = temp.size();
        string result = "";
        int foundNonZero = 0;
        for (int i = 0; i < m; i++) {
            if (temp[i] == '0' && foundNonZero == 0) {
                continue;
            } else {
                result.push_back(temp[i]);
                foundNonZero = 1;
            }
        }
        return result;
    }
};