class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int pre[n+1];
        pre[0]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+gain[i-1];
        }
        int high=pre[0];
        for(int j=1;j<=n;j++){
            if(pre[j]>high){
                high=max(high,pre[j]);
            }
        }
        return high;
    }
};