class Solution {
public:
    vector<int> merge(vector<int> left,vector<int> right){
        int i=0,j=0;
        vector<int> ans;
        while(i<left.size() && j<right.size()){
            if(left[i]< right[j]){
                ans.push_back(left[i]);
                i++;
            }else{
                ans.push_back(right[j]);
                j++;
            }
            
        }
        while(left.size()>i){
                ans.push_back(left[i]);
                i++;
            }
        while(right.size()>j){
                ans.push_back(right[j]);
                j++;
        }
        return ans;

    }
    vector<int> merge_sort(vector<int>& nums,int start,int end){
        if(start == end){
            return {nums[start]};
        }
        int n=nums.size();
        int mid=(start+end)/2;
        vector<int> left=merge_sort(nums,start,mid);
        vector<int> right=merge_sort(nums,mid+1,end);
        return merge(left,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        return merge_sort(nums,0,n-1);
    }
};