class Solution {
public:
    int solve(vector<int>& nums,  int start,int end ){
        int n=end-start+1;
        vector<int> mp(n,0);
        
        mp[0]=nums[start];
        if(n==1) return mp[0];
        mp[1]=max(nums[start],nums[start+1]);
        for(int i=2;i<n;i++){
            int rob=nums[start+i]+mp[i-2];
            int dontrob=mp[i-1];
            mp[i]=max(rob,dontrob);
        }
        return mp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        if(n==1) return nums[0];
        int case1=solve(nums,0,n-2);
        int case2=solve(nums,1,n-1);
        return max(case1,case2);
    }
};