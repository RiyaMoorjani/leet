class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1==str2){
            return str1;
        }
        if(str2.length()>str1.length()){
            return gcdOfStrings(str2,str1);
        }
        if(str1.substr(0,str2.length())!=str2){
            return "";
        }
        return gcdOfStrings(str1.substr(str2.length()),str2);//gdc(a,b)=gdc(a-b,b); here a>b
        //removes str2 from str1
    }
};