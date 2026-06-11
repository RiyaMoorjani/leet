class Solution {
public:

    void solve(int curr, vector<vector<int>>& adj, vector<bool>& vis) {

        vis[curr] = true;

        for(int neighbour : adj[curr]) {

            if(!vis[neighbour]) {
                solve(neighbour, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        // 1-based adjacency list
        vector<vector<int>> adj(n + 1);

        vector<bool> vis(n + 1, false);

        // Build graph
        for(int i = 1; i <= n; i++) {

            for(int j = 1; j <= n; j++) {

                if(i != j && isConnected[i - 1][j - 1] == 1) {

                    adj[i].push_back(j);
                }
            }
        }

        int cnt = 0;

        for(int i = 1; i <= n; i++) {

            if(!vis[i]) {

                cnt++;

                solve(i, adj, vis);
            }
        }

        return cnt;
    }
};