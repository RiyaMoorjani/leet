class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int i=0;
       int j=0;
       int n=nums.size();
       while(j<n){
        if(nums[j]!=0){
            nums[i]=nums[j];
            i++;
        }
        j++;
       }
       for(int k=i;k<n;k++){
        nums[k]=0;
       }

    }
};