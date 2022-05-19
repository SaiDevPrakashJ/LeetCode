class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur=1,prev=0,res=0;
        for(int i=1;i<s.length();i++){
            if(s[i-1]==s[i]){
                cur++;
            }else{
                res+=min(cur,prev);
                prev=cur;
                cur=1;
            }
        }
        return res+min(cur,prev);
    }
};