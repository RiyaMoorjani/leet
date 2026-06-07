class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int len1=word1.length();
        int len2=word2.length();
        int i=0,j=0;
        while(i<len1 && j<len2){
            ans+=word1[i++];
            ans+=word2[j++];
        }
        
        while(len1>i){
            ans+=word1[i++];
        }
        while(len2>j){
            ans+=word2[j++];
        }
        return ans;
    }
};