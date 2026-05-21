class Solution {
public:
    // variable sliding window 
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, maxlen = 0;
        int n = s.length();
        vector<int> hash(256, -1);

        while(j < n) {
            //alaredy occured character
            if(hash[s[j]]!=-1){//not equal to - 1means it has occured laready 
                if(hash[s[j]]>=i){//means it is also a part of window 
                    i=hash[s[j]]+1;
                }

            }
            int len =j-i+1;
            maxlen=max(maxlen,len);
            //srore the index of the value
            hash[s[j]]=j;
            j++;
        }

        return maxlen;
    }
};
