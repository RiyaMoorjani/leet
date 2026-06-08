class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> arr1,arr2;
        int p=0,j=0;
        while(j<nums.size()){
            if(nums[j]<pivot){
                arr1.push_back(nums[j]);
                j++;
            }
            else if(nums[j]>pivot){
                arr2.push_back(nums[j]);
                j++;
            }
            else{
                p++;j++;
            }
        }
        vector<int> ans;
        for(int x = 0; x <arr1.size(); x++){
            ans.push_back(arr1[x]);
        }
        for(int x = 0; x < p; x++){
            ans.push_back(pivot);
        }
        for(int x = 0; x < arr2.size(); x++){
            ans.push_back(arr2[x]);
        }
        return ans;
    }
};