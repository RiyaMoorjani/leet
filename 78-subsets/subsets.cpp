class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> op,int i,int n){
        if(i==n){
            ans.push_back(op);
            return;
        }
        //ignore
        solve(nums,ans,op,i+1,n);
        //accept
        op.push_back(nums[i]);
        //recursive call
        solve(nums,ans,op,i+1,n);
        //backtrack
        op.pop_back();

    }
    vector<vector<int>> subsets(vector<int>& nums) {
      
      int n=nums.size();
      vector<vector<int>> ans;
      vector<int> op;
      solve(nums,ans,op,0,n);
      return ans;
    }
};