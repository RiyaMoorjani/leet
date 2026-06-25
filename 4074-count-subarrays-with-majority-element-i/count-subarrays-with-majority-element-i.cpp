class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target){
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            int size=0;
            for(int j=i;j<nums.size();j++){
                
                if(nums[j]==target){
                    cnt++;
                }
                size++;
                if(cnt>size/2){
                res++;
                }

            }
            
            
        }
        return res;
    }
};  