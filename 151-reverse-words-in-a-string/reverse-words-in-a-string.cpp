class Solution {
public:

    void reverse(string &s,int start,int end){

        while(start<end){
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s) {

        // remove extra spaces first
        string temp="";
        int i=0;
        int n=s.size();

        while(i<n){

            // skip spaces
            while(i<n && s[i]==' ') i++;

            // add word
            while(i<n && s[i]!=' '){
                temp+=s[i];
                i++;
            }

            // skip extra spaces
            while(i<n && s[i]==' ') i++;

            // add single space if more words exist
            if(i<n) temp+=' ';
        }

        s=temp;

        n=s.size()-1;

        // reverse whole string
        reverse(s,0,n);

        int startstr=0;

        for(int i=0;i<s.size();i++){

            if(s[i]==' '){

                reverse(s,startstr,i-1);

                startstr=i+1;
            }
        }

        // reverse last word
        reverse(s,startstr,n);

        return s;
    }
};