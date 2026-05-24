class Solution {
public:
    bool isPossible(vector<int>& position,int mid ,int m){
        int cntBalls=1;
        int prev=position[0];
        for(int i=0; i<position.size();i++){
            int curr=position[i];
            if(curr-prev>=mid){
                cntBalls++;
                prev=curr;

            }
            if(cntBalls==m){
                return true;
                break;
            }
        }
        return (cntBalls==m);
    }
    int maxDistance(vector<int>& position, int m) {
       sort(position.begin(),position.end());
       int low=1;
       int n=position.size();
       int high= position[n-1]-position[0];
       int result=0;
       while(low<=high){
        int mid=low+(high-low)/2;
        if(isPossible(position,mid,m)){
            result=mid;//max force
            low=mid+1;
        }
        else{
            high=mid-1;
        }
       }
       return result;
    }
};