class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int orgcolor,int newcolor ,vector<vector<int>> &visited){
        if(i<0 || j<0 || i>=image.size()||j>=image[0].size() || image[i][j]!=orgcolor || visited[i][j]==1){
            return ;
        }
        image[i][j]=newcolor;
        visited[i][j]=1;
        //right
        dfs(image,i,j+1,orgcolor,newcolor,visited);
        //left
        dfs(image,i,j-1,orgcolor,newcolor,visited);
        //top
        dfs(image,i-1,j,orgcolor,newcolor,visited);
        //down
        dfs(image,i+1,j,orgcolor,newcolor,visited);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgcolor=image[sr][sc];
        if(orgcolor==color){return image;}
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        dfs(image,sr,sc,orgcolor,color,visited);
        return image;
    }
};