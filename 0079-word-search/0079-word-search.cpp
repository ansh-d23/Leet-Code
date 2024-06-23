class Solution {
public:
    bool helper(vector<vector<char>>& board, int i, int j, int index, string& word) {
        if (index == word.size()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '*';

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (auto& d : directions) {
            int new_i = i + d.first;
            int new_j = j + d.second;
            if (helper(board, new_i, new_j, index + 1, word)) return true;
        }

        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && helper(board, i, j, 0, word)) return true;
            }
        }
        return false;
    }
};
