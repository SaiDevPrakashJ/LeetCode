class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),Comparator());
        int remainingTrucksize=truckSize;
        int totalunits=0;
        for(auto boxtype:boxTypes){
            int unitTrucksize=min(boxtype[0],remainingTrucksize);
            totalunits+=unitTrucksize*boxtype[1];
            remainingTrucksize-=unitTrucksize;
        }
        return totalunits;
    }
    
    struct Comparator {
        bool operator()(vector<int>const& p1,vector<int>const& p2){
            return p1[1]>p2[1];
        }
    };
};