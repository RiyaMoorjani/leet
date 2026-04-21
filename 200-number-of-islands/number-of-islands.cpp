class Solution {
public:
void dfs(int i, int j,int n , int m,vector<vector<int>>& vis,vector<vector<char>>& grid ){
    vis[i][j]=1;
    vector<pair<int,int>> neighbor={{0,1}, {0,-1},{1,0},{-1,0}};
    for(auto nei : neighbor){
        int ni = nei.first +i;
        int nj=nei.second+j;
        if(ni >= 0 && nj >= 0 && ni < n && nj < m &&
   grid[ni][nj] == '1' && vis[ni][nj] == 0){
            dfs(ni,nj,n,m,vis,grid);
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,n,m,vis, grid );
                    cnt++;
                }
            }
        }
        return cnt;
    }
};