class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty()) 
            return 0;
        
        //pair used for storing i,j values easily
        queue<pair<int,int>> rotten;
        int m = grid.size(), n= grid[0].size(), minutes=0, number_of_oranges=0,total_elements_went_in_queue=0;
        
        //Keeping all minutue 0 rotten oranges in queue for BFS and also counting total number of oranges for future use
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                   number_of_oranges++;
                    if(grid[i][j]==2){
                        //This way we have to push the pair in queue
                        rotten.push({i,j});
                    }
                }  
            }
        }
       //Will help for a particular point to go in 4 directions (0,-1), (0,+1), (-1,0), (1,0)
        int dx[4] = {0,0,1,-1};
        int dy[4] = {-1,1,0,0};
        
        //BFS done here
        //here !rotten.empty() can also be used
        while(rotten.size()!=0){
            int size = rotten.size();
            total_elements_went_in_queue+=size;
            //itearting over the existing elements in queue
            for(int i=0;i<size;i++){
                int x =rotten.front().first, y = rotten.front().second;
                rotten.pop();
                //Tells how to iterate over 4 directions
                for(int j=0;j<4;j++){
                    int nx = x+dx[j], ny= y+dy[j];
                    //TO check if it is in boundary and it is not empty cell or rotten orange
                    if(nx<0 || ny<0 || nx>=m ||  ny>=n || grid[nx][ny]!=1 ) continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx,ny});
                }
                
                
            }
                
            //if still the queue is not empty we have rotten few oranges which are are done in 1 min so increasing minutes by 1.
                if(rotten.size()!=0) minutes++;
                
                
        }
        
        if(number_of_oranges==total_elements_went_in_queue){
            return minutes;
        }
        
        return -1;
        
        
    }
};