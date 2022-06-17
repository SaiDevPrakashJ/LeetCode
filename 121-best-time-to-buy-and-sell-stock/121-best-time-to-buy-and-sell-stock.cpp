
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int min=INT_MAX,profit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min){
                min=prices[i];

            }
            else if(prices[i]-min>profit){
              profit=prices[i]-min; 
            }
           

        }
        return profit;
        
    }
      
};





















// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int profit = 0;
//         for(long i=0;i<prices.size();i++){
//             for(long j=i+1;j<prices.size();j++){
//                 int temp=prices[j]-prices[i];
//                 if(temp>profit){
//                     profit = temp;
//                 }
//             }
//         }
//         return profit;
//     }
      
// };