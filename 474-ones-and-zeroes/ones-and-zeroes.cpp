class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string>& strs,int i, int m, int n){
        if(i==strs.size()){
            return 0;
        }
        if(dp[i][m][n]!=-1){
            return dp[i][m][n];
        }
        int zeros=0;
        int ones=0;
        for(int ch: strs[i]){
            if(ch=='0'){
                zeros++;
            }else{
                ones++;
            }
        }
        int not_take=solve(strs,i+1,m,n);
        int take=0;
        if(m>=zeros && n>=ones){
            take=1+solve(strs,i+1,m-zeros,n-ones);
        }
        dp[i][m][n]=max(not_take,take);
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(strs,0,m,n);
    }
};