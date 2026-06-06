class Solution {
public:
    int leftsum(vector<int> nums,int i){
        int sum=0;
        for(int j=0;j<i;j++){
            sum+=nums[j];
        }
        return sum;
    }
    int rightsum(vector<int> nums,int i){
        int sum=0;
        for(int k=i+1;k<nums.size();k++){
            sum+=nums[k];
        }
        return sum;

    }
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        vector<int> leftans(n);
        vector<int> rightans(n);
        for(int i=0;i<n;i++){
            leftans[i]=leftsum(nums,i);
            rightans[i]=rightsum(nums,i);
            ans[i]=abs(leftans[i]-rightans[i]);
        }
        return ans;

    }
};