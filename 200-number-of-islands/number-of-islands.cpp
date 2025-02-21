class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int total_islands = 0;
        for (int row = 0; row < grid.size();++row){
            for(int column = 0; column < grid[0].size(); ++column){
                if(grid[row][column] == '1'){
                    BFS(row, column, grid);
                    ++total_islands;
                }
            }
        }  
        return total_islands;     
    }

private:
    void BFS(int row, int column, vector<vector<char>>& grid){
        queue<tuple<int,int>> q;

        q.push({row,column});

        while(!q.empty()){
            int current_row = get<0>(q.front());
            int current_column = get<1>(q.front());

            if (current_row < 0 || current_row >= grid.size()){
                q.pop();
                continue;
            }
            if (current_column < 0 || current_column >= grid[0].size()){
                q.pop();
                continue;
            }

            if(grid[current_row][current_column] != '1'){
                q.pop();
                continue;
            }

            q.pop();
            grid[current_row][current_column] = '2'; // mark seen

            q.push({current_row+1,current_column});
            q.push({current_row-1,current_column});
            q.push({current_row,current_column+1});
            q.push({current_row,current_column-1});
        }
    }
};
