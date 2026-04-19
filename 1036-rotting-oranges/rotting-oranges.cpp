class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();//no of rows
        int m = grid[0].size();//no of colm 
        //quue row, colm
        queue<pair<int,int>> que;
        int freshcnt = 0;

        // Step 1: Initialize queue & count fresh oranges
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    //que rotten postn 
                    que.push({i, j});
                }
                else if(grid[i][j] == 1){
                    freshcnt++;
                }
            }
        }

        if(freshcnt == 0) return 0;

        int time = 0;

        // Directions: up, down, left, right
        //up - (row -1 , col) down -( row +1, col) , left -( row,col-1) , right -row, col+1
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // Step 2: BFS
        while(!que.empty()){
            int size = que.size();
            

            for(int i = 0; i < size; i++){
                auto curr = que.front();
                que.pop();

                int x = curr.first;
                int y = curr.second;

                for(auto d : dir){
                    int nx = x + d.first;
                    int ny = y + d.second;

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        que.push({nx, ny});
                        freshcnt--;
                        
                    }
                }
            }

            time++;
        }

        return (freshcnt == 0) ? time-1 : -1;
    }
};