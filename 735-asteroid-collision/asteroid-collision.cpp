class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            bool des=false;
            while(!st.empty() && st.top()>0 && asteroids[i]<0){
                if(abs(asteroids[i])>st.top()){
                    st.pop();
                }
                else if(abs(asteroids[i])==st.top()){
                    //remove both 
                    st.pop();
                    des=true;
                    break;
                }
                else{//curr ast is destroyed 
                    des=true;
                    break;
                }
            }
            if(!des){//if ast still remain and is not des 
                st.push(asteroids[i]);
            }
        }
        vector<int> ans(st.size());
        for(int i=st.size()-1; i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};