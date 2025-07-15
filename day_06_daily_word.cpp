class Solution {
public:
    bool isValid(string s) {
        int countd = 0;
        int countv = 0;
        int countc = 0;
        if(s.size()<3)return false;
        for(int i =0; i<s.size();i++){
            if((int)s[i]>=48&&(int)s[i]<=57){
                countd++;
            }
            if((int)s[i]>=65&&(int)s[i]<91||(int)s[i]>=97&&(int)s[i]<123){
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                    countv++;
                }
                else{
                    countc++;
                }
            }
        }
        if(countv>0&&countc>0){
            if(countv+countc+countd==s.size()){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
       
    }
};
