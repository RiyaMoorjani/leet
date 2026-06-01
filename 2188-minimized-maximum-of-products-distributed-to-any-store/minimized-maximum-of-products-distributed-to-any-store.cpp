class Solution {
public:
    bool can_distribute(int mid,int n, vector<int>& quantities){
        int stores=0;
        for(int i=0;i<quantities.size();i++){
            stores+=(quantities[i]+mid-1)/mid;
        }
        if (stores<=n){
            return true;
        }
        return false;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int s=1;
        int e=*max_element(quantities.begin(),quantities.end());
        int mid,ans;

        while(s<=e){
            mid=(s+e)/2;
            if(can_distribute(mid,n ,quantities)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }

        }
        return ans;
    }
};