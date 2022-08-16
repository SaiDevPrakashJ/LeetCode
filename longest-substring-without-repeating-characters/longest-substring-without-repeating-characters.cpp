class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // sliding window concept
        int start =0;
        int end = 0;
        int max_len =0;
        unordered_map<char,int> character;
        while(end < s.length()){
            if(character.find(s[end]) != character.end()){
                if(start <= character[s[end]]){
                    start = character[s[end]] +1;
                }
            }
                character[s[end]]=end;
                max_len = max(max_len,end-start+1);
                end++;
        }
        
        return max_len;
    }
};