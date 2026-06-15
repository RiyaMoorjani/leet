class Solution {
public:
    int solve(vector<int>& prices,int day,int state,vector<vector<int>>& dp){
        int profit=0;
        
        if(day >=prices.size()){
            return profit;
        }
        if(dp[day][state]!=-1){
            return dp[day][state];
        }
        if(state==0){
            int buy= -prices[day]+solve(prices,day+1,1,dp);
            int dontbuy=solve(prices,day+1,0,dp);
            profit=max(buy,dontbuy);
        }else{
            int sell=+prices[day]+solve(prices,day+2,0,dp);
            int dontsell=solve(prices,day+1,1,dp);
            profit=max(sell,dontsell);
        }
        dp[day][state]=profit;
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int max_profit=0;
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,0,0,dp);
    }
};