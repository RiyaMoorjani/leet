class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.size()!=t.size()){
        //     return false;
        // }
        // unordered_map<char,int> mp;
        // for(char ch:s) {
        //     mp[ch]++;
        // }
        // for(char ch: t){
        //     mp[ch]--;
        // }
        // for(auto it : mp){
        //     if(it.second!=0){
        //         return false;
        //     }
        // }
        // return true;

        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char,int > mp1;
        unordered_map<char,int > mp2;
        for(auto ch : s){
            mp1[ch]++;
        }
        for(auto it : t){
            mp2[it]++;
        }
        if(mp1==mp2){
            return true;
        }

        return false;
    }
};