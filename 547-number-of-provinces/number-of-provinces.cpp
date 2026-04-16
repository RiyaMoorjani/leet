class Solution {
public:
    void dfs(map<int,list<int>> &adj,int node,vector<int>& visited ){
        visited[node]=1;
        for(auto neighbor : adj[node]){
            if(!visited[neighbor]){
                dfs(adj,neighbor,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        //create adj list
        map<int,list<int>> adj;
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }
        vector<int> visited(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(adj,i,visited);
            }
        }
        return cnt;
        
    }
};