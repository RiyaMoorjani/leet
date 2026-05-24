class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> &op,int i,int n){
        if(i==n){
            ans.push_back(op);
            return ;
        }
        //include
        op.push_back(nums[i]);
        solve(nums,ans,op,i+1,n);
        op.pop_back();

        int index=i+1;
        while(index < n && nums[index]==nums[index-1] ){//skip same val
            index++;
        }
        solve(nums,ans,op,index,n);


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