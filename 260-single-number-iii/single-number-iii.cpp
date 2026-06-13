class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr=0;
        for(int i=0;i<nums.size();i++){
            xorr^=nums[i];
        }
        int b=xorr&-xorr;
        long long b1=0,b2=0;
        for(int i:nums){
            if(i&b){
                b1^=i;
            }else{
                b2^=i;
            }
        }
        return {(int)b1,(int)b2};
    }
};