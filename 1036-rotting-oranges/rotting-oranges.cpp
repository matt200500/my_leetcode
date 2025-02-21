class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        int total_oranges = 0;
        queue<tuple<int,int>> q;
        for (int row = 0; row < grid.size(); ++row){
            for (int column = 0; column < grid[0].size(); ++column){
                if(grid[row][column] == 2){
                    q.push({row, column});
                }
                if (grid[row][column] == 1){
                    ++total_oranges;
                }
            }
        }
        BFS(grid, minutes, q, total_oranges);
        if (total_oranges != 0){
            return -1;
        }
        return minutes;
    }

private:
    void BFS(vector<vector<int>>& grid, int& minutes, queue<tuple<int,int>>& q, int& total_oranges){
        while(!q.empty()){
            bool rotted = false;
            std::vector<tuple<int,int>> next_level;

            while(!q.empty()){
                int current_row = get<0>(q.front());
                int current_column = get<1>(q.front());
                q.pop();

                if (current_row < 0 || current_row > grid.size() -1){
                    continue;
                }
                if (current_column < 0 || current_column > grid[0].size() -1){
                    continue;
                }
                if (grid[current_row][current_column] == 0){
                    continue;
                }

                if (grid[current_row][current_column] == 1){
                    grid[current_row][current_column] = 2;
                }
                
                if (current_row + 1 < grid.size() && grid[current_row + 1][current_column] == 1) {
                    grid[current_row + 1][current_column] = 2;
                    next_level.push_back({current_row + 1, current_column});
                    rotted = true;
                    --total_oranges;
                }
                if (current_row - 1 >= 0 && grid[current_row - 1][current_column] == 1) {
                    grid[current_row - 1][current_column] = 2;
                    next_level.push_back({current_row - 1, current_column});
                    rotted = true;
                    --total_oranges;
                }
                if (current_column + 1 < grid[0].size() && grid[current_row][current_column + 1] == 1) {
                    grid[current_row][current_column + 1] = 2;
                    next_level.push_back({current_row, current_column + 1});
                    rotted = true;
                    --total_oranges;
                }
                if (current_column - 1 >= 0 && grid[current_row][current_column - 1] == 1) {
                    grid[current_row][current_column - 1] = 2;
                    next_level.push_back({current_row, current_column - 1});
                    rotted = true;
                    --total_oranges;
                }
            }

            for (int i = 0; i < next_level.size(); ++i){
                q.push(next_level[i]);
            }
            if (rotted == true){
                ++minutes;
            }    
        }
        
    }
};
