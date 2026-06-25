class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target){
        
        int res=0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            int size=0;
            vector<int> ans;
            for(int j=i;j<nums.size();j++){
                
                if(nums[j]==target){
                    cnt++;
                }
                ans.push_back(nums[j]);
                int s=ans.size();
                if(cnt>s/2){
                res++;
                }

            }
            
            
        }
        return res;
    }
};  