class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int> &op,int i,int n){
        //BC
        if(target==0){
            ans.push_back(op);
            return;

        }
        if(i>=n || target<0){
            return ;
        }
        
        if(candidates[i]>target){
            return;
        }
        //include
        op.push_back(candidates[i]);
        solve(candidates,target-candidates[i],ans,op,i+1,n);
        op.pop_back();//backtrack
        //check duplicate
        while(i+1<n && candidates[i]==candidates[i+1]){
            i++;
        }
        //exclude
        solve(candidates,target,ans,op,i+1,n);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,op,0,n);
        return ans;
    }
};