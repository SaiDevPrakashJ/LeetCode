#include<unordered_map>
class Solution{
public:
    vector<int> twoSum(vector<int>& nums,int target){
        unordered_map<int,int> nums_remember;
        vector<int> result;
        
        for(int i=0;i<nums.size();i++){
            if(nums_remember.find(target-nums[i]) != nums_remember.end()){
                result.push_back(i);
                result.push_back(nums_remember[target-nums[i]]);
            }else{
                nums_remember[nums[i]] = i;
            }
        }
        return result;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         vector<int> result;
//         unordered_map<int,int> search;
//         for(int i=0;i<nums.size();i++){
//             int y = target-nums[i];
            
//             if(search.find(y)!= search.end()){
//                 result.push_back(i);
//                 result.push_back(search[y]);
//                 break;
//             }
//             search[nums[i]]=i;
//         }
//         return result;
    }


};






















// class Solution{
// public:
//     vector<int> twoSum(vector<int>& nums,int target){
//         vector<int> result;
//         for(int i =0; i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[j] == target - nums[i]){
//                     result.push_back(i);
//                     result.push_back(j);
//                     return result;
//                 }
//             }
            
//         }
//         return result;
//     }
    
// };