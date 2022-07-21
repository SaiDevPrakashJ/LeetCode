class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,compare> point_distance(points.begin(),points.end());
        vector<vector<int>> result;
        for(int i=0;i<k;i++){
            result.push_back(point_distance.top());
            point_distance.pop();
        }
        return result;
        
        //failing for same distance points
        // unordered_map<int,vector<int>> point_distance;
        // priority_queue<int,vector<int>,greater<int>> min_distance;
        // for(int i=0;i<points.size();i++){
        //     int distance = (points[i][0])^2 + (points[i][1])^2;
        //     point_distance[distance] = points[i];
        //     min_distance.push(distance);
        // }
        // vector<vector<int>> result;
        // for(int i=0;i<k;i++){
        //     result.push_back(point_distance[min_distance.top()]);
        //     min_distance.pop();
        // }
        // return result;    
    }
    
    struct compare{
        bool operator()(vector<int>& p,vector<int>& q){
            return p[0]*p[0] + p[1]*p[1] > q[0]*q[0] + q[1]*q[1] ;  
        }
    };
    
};