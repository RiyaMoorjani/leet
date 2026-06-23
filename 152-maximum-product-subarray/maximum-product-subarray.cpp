class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //dp approach 
        int n=nums.size();
        int dpmin[n];
        int dpmax[n];
        dpmin[0]=nums[0];
        dpmax[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            dpmin[i]=min({nums[i],dpmin[i-1]*nums[i],dpmax[i-1]*nums[i]});
            dpmax[i]=max({nums[i],dpmin[i-1]*nums[i],dpmax[i-1]*nums[i]});
            ans=max(ans,dpmax[i]);
        }
        return ans;
    }
};