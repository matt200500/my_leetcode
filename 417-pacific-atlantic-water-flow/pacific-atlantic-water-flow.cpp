class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<tuple<int,int>> pacific_queue;
        queue<tuple<int,int>> atlantic_queue;
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        for(int row = 0; row < heights.size(); ++row){
            for(int column = 0; column < heights[0].size(); ++column){
                if(row == 0 || column == 0){
                    pacific_queue.push({row,column});
                }
                if (row == heights.size() - 1 || column == heights[0].size() -1){
                    atlantic_queue.push({row,column});
                }
            }
        }

        while(!pacific_queue.empty()){
            int current_row = get<0>(pacific_queue.front());
            int current_column = get<1>(pacific_queue.front());
            pacific_queue.pop();
            DFS(current_row, current_column, heights, pacific);
        }
        while(!atlantic_queue.empty()){
            int current_row = get<0>(atlantic_queue.front());
            int current_column = get<1>(atlantic_queue.front());
            atlantic_queue.pop();
            DFS(current_row, current_column, heights, atlantic);
        }

        vector<vector<int>> output;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    output.push_back({i, j});
                }
            }
        }
        return output;
    }

private:
    void DFS(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        int rows = heights.size();
        int cols = heights[0].size();
        visited[row][col] = true;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                !visited[newRow][newCol] &&
                heights[newRow][newCol] >= heights[row][col]) {
                DFS(newRow, newCol, heights, visited);
            }
        }
    }
};
