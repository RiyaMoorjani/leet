class Solution {
public:
    vector<vector<int>> directions {{1,1},{1,0},{0,1},{-1,-1},{0,-1},{-1,0},{1,-1},{-1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(m==0 || n==0 || grid[0][0]!=0 || grid[n-1][m-1]!=0)
            return -1;

        queue<pair<int,int>> que;
        que.push({0,0});
        grid[0][0]=1;
        int level =0;
        
        while(!que.empty()){
            int N =que.size();
            while(N>0){
                auto curr=que.front();
                que.pop();
                N--;
                int x=curr.first;
                int y=curr.second;
                if(x==n-1 && y==m-1)
                    return level+1;
                for(auto dir : directions){
                int new_x=x+dir[0];
                int new_y=y+dir[1];
                    if (new_x<=n-1 && new_y<=m-1 && new_x>=0 && new_y>=0 && grid[new_x][new_y]==0){
                    que.push({new_x,new_y});
                    grid[new_x][new_y]=1;
                    }
                }
            }
            
            
        level++;
        }
        return -1;
    }
};