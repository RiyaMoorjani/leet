class Solution {
public:
    int kadanes_min(vector<int>& nums){
        int currsum=nums[0];
        int minsum=nums[0];
        for(int i=1;i<nums.size();i++){
            currsum=min(currsum+nums[i],nums[i]);
            minsum=min(currsum,minsum);
        }
        return minsum;
    }
    int kadanes_max(vector<int>& nums){
        int currsum=nums[0];
        int maxsum=nums[0];
        for(int i=1;i<nums.size();i++){
            currsum=max(currsum+nums[i],nums[i]);
            maxsum=max(currsum,maxsum);
        }
        return maxsum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int normal_max=kadanes_max(nums);
        if(normal_max<0){
            return normal_max;
        }
        int total =0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int circular_max=total-kadanes_min(nums);
        int ans=max(normal_max,circular_max);
        return ans;
    }
};