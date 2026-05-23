class Solution {
public:
    bool solve(int n,int i){
        if (pow(2,i)>n){
            return false;
        }
        if(pow(2,i)==n){
            return true;
        }
        return solve(n,i+1);
    }
    bool isPowerOfTwo(int n) {
        return solve (n,0);
    }
};