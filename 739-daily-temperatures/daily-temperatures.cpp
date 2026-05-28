class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n=temperatures.size();
        vector<int> ans(n);
        stack<pair<int,int>> st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first<=temperatures[i]){
                st.pop();
            }
            //if stack is not empty 
            if(!st.empty()){
                ans[i]=st.top().second-i;
            }
            else{
                //if stack is emty
                ans[i]=0;
            }
            st.push({temperatures[i],i});
        }
        return ans; 
    }
};