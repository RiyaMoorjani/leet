class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &op,int i,int n){
        ans.push_back(op);
        for(int index=i;index<n;index++){
            if(index>i && nums[index]==nums[index-1]){
                continue;
            }
            //add
            op.push_back(nums[index]);
            //ignore
            solve(nums,ans,op,index+1,n);
            op.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> op;
        solve(nums,ans,op,0,n);
        return ans;
    }
};