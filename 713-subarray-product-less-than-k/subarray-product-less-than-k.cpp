class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int cnt=0;
        int product=1;
        if(k<=1){
            return 0;
        }
        
        while(j<n){
            product*=nums[j];
            while(product>=k){
                product=product/nums[i];
                i++;
            }
            cnt += j-i+1;
            
            j++;
        }
        return cnt;
    }
};