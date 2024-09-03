class Solution {
public:
    int getLucky(string s, int k) {
        // Convert each character in the string to its corresponding numeric value
        string number = "";
        for (char x : s) {
            number += to_string(x - 'a' + 1);
        }
        
        while (k > 0) {
            int temp = 0;
            for (char x : number) {
                temp += x - '0';  
            }
            number = to_string(temp);  
            k--;
        }
        return stoi(number); 
    }
};