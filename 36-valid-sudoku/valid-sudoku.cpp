class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_map<int,unordered_set<char>> rows;
        std::unordered_map<int,unordered_set<char>> columns;
        std::unordered_map<int,unordered_set<char>> subgrids;

        for (int i = 0; i < board.size(); ++i){
            for (int y = 0; y < board.size(); ++y){
                if (board[i][y] == '.'){
                    continue;
                }
                int subgrid_index = (i / 3) * 3 + (y / 3);

                if (!rows[i].insert(board[i][y]).second ||
                !columns[y].insert(board[i][y]).second ||
                !subgrids[subgrid_index].insert(board[i][y]).second) {
                    return false;
                }
            }
        }

        return true;
    }
};
