class Solution {
public:
    int solve(vector<int>& prices,int day,int state,vector<vector<vector<int>>>& dp,int k){
        int profit=0;
        
        if(day==prices.size()|| k==0){
            return 0;
        }
        
        if(dp[day][state][k]!=-1){
            return dp[day][state][k];
        }
        
        if(state==0){
            int buy= -prices[day]+solve(prices,day+1,1,dp,k);
            int dontbuy=solve(prices,day+1,0,dp,k);
            profit=max(buy,dontbuy);
        }else{
            int sell=+prices[day]+solve(prices,day+1,0,dp,k-1);
            int dontsell=solve(prices,day+1,1,dp,k);
            profit=max(sell,dontsell);
        }
        dp[day][state][k]=profit;
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int max_profit=0;
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,0,0,dp,k);
    }
};