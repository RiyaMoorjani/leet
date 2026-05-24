class Solution {
public:
    void solve(vector<int>& candidates, int target,vector<vector<int>>& ans,vector<int> &op,int i,int n){
        if(target==0){
            ans.push_back(op);
            return;

        }
        for(int idx=i;idx<n;idx++){

            if(idx>i && candidates[idx]==candidates[idx-1]){
                continue;
            }
            if(candidates[idx]>target){
                break;
            }
            op.push_back(candidates[idx]);
            solve(candidates,target-candidates[idx],ans,op,idx+1,n);
            op.pop_back();

        }
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