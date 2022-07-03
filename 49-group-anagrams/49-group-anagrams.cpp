#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        string temp;
        for(int i=0;i<strs.size();i++){
            temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            map[strs[i]].push_back(temp);
        }
        vector<vector<string>> output;
        for(auto i=map.begin();i!=map.end();i++){
            output.push_back(i->second);
        }
        return output;
    }
};