class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int req_cnt=t.length();
        int l=0,r=0;int start=0;
        int minwindowsize=INT_MAX;
        if(req_cnt>n){
            return "";
        }
        unordered_map<char,int> mp;
        for (char ch: t){//store all req char in map 
            mp[ch]++;
        }
        while(r<n){
            char ch=s[r];
            if(mp[ch]>0){//if freq is 1, 2, 3, means ch is present in window
                req_cnt--;
            }
            mp[ch]--;//as we move r so reduce freq mp 
            // if mp[ch]> pos means that ch is req in string 
            while(req_cnt==0){
                int currsize=r-l+1;//we found substrg 
                if(minwindowsize>currsize){//shrink to reduce size 
                    minwindowsize=currsize;
                    start=l;
                }
                mp[s[l]]++;//when we are moving l inc freq of ch
                if(mp[s[l]]>0){
                    req_cnt++;// remove ch that is req so inc the req cnt also 
                }
                l++;
            }
            r++;
        }
        return minwindowsize==INT_MAX?"":s.substr(start,minwindowsize);
    }
};