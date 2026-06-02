class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int tosum=0;
        for(int i=0;i<n;i++){
            tosum+=nums[i];
        }
        int operations =INT_MAX,windsum=0;
        int reqsum=tosum-x;
        int l=0,r=0;
        while(r<n){
            windsum+=nums[r];
            while(l<=r && windsum >reqsum){
                windsum-=nums[l];
                l++;
            }
            if(windsum==reqsum){
                operations=min(operations,n-(r-l+1));
            }
            r++;
        }
        if(operations!=INT_MAX){
            return operations;
        }else{
            return -1;
        }
    }
};