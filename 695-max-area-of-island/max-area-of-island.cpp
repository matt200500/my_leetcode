class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int best_size = 0;
        for (int row = 0; row < grid.size(); ++row){
            for (int column = 0; column < grid[0].size(); ++column){
                if (grid[row][column] == 1){
                    int size = BFS(row, column, grid);
                    best_size = max(size, best_size);
                }
            }
        }
        return best_size;
    }
private:
    int BFS(int row, int column, vector<vector<int>>& grid){
        queue<tuple<int,int>> q;
        q.push({row,column});
        int size = 0;

        while(!q.empty()){
            int current_row = get<0>(q.front());
            int current_column = get<1>(q.front());

            if (current_row < 0 || current_row > grid.size() -1){
                q.pop();
                continue;
            }
            if(current_column < 0 || current_column > grid[0].size() - 1){
                q.pop();
                continue;
            }
            if (grid[current_row][current_column] != 1){
                q.pop();
                continue;
            }

            grid[current_row][current_column] = 2;
            q.pop();
            ++size;
            
            q.push({current_row+1,current_column});
            q.push({current_row-1,current_column});
            q.push({current_row,current_column+1});
            q.push({current_row,current_column-1});
        }

        return size;
    }
};
