class Solution {
public:
    int calc_ab(string& s, int x) {
        stack<char> stk;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (!stk.empty() && stk.top() == 'a' && s[i] == 'b') {
                stk.pop();
                count++;
            } else {
                stk.push(s[i]);
            }
        }

        string temp;
        while (!stk.empty()) {
            temp += stk.top();
            stk.pop();
        }
        reverse(temp.begin(), temp.end()); 
        s = temp; 
        return count * x; 
    }

    int calc_ba(string& s, int y) {
        stack<char> stk;
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (!stk.empty() && stk.top() == 'b' && s[i] == 'a') {
                stk.pop();
                count++; 
            } else {
                stk.push(s[i]); 
            }
        }

        string temp;
        while (!stk.empty()) {
            temp += stk.top();
            stk.pop();
        }
        reverse(temp.begin(), temp.end()); 
        s = temp;
        return count * y; 
    }

    int maximumGain(string s, int x, int y) {
        if (x > y) {
            int ab = calc_ab(s, x); 
            int ba = calc_ba(s, y); 
            return ab + ba;
        } else {
            int ba = calc_ba(s, y); 
            int ab = calc_ab(s, x);
            return ab + ba;
        }
    }
};
