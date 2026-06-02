class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
       sort(costs.begin(),costs.end());
       int cnt=0;
       for(int i=0;i<costs.size();i++){
        
        if(coins>=costs[i]){
            cnt++;
            coins-=costs[i];
        }else if(coins==0){
            break;
        }
       } 
       return cnt;
    }
};