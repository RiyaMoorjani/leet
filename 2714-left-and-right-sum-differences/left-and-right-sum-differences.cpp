class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        int total=0,leftsum=0,rightsum=0;
        for(int num : nums){
            total+=num;
        }
        rightsum=total;
        for(int i=0;i<n;i++){
            rightsum-=nums[i];
            ans[i]=abs(leftsum-rightsum);
            leftsum+=nums[i];
        }
        return ans;
    }
};