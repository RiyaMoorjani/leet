class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int tosum=0;
        for(int i=0;i<nums.size();i++){
            tosum+=nums[i];
        }
        int leftsum=0,rightsum=0;
        for(int i=0;i<nums.size();i++){
            
            rightsum=tosum-leftsum-nums[i];
            
            if(rightsum==leftsum){
                return i;
            }
            leftsum+=nums[i];
        }
        return -1;
    }
};