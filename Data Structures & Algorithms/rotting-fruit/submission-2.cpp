class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        if(fresh==0) return 0;
        int minutes = -1;
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int size=q.size();
            for(int a=0;a<size;a++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto dir:dirs){
                    int ix = i+dir[0];
                    int jx = j+dir[1];
                    if(ix>=0 && ix<m && jx>=0 && jx<n && grid[ix][jx]==1){
                        fresh--;
                        q.push({ix,jx});
                        grid[ix][jx] =2;
                    }
                }
                // if(fresh==0) return minutes;
            }
            minutes++;
        }
        if(fresh>0) return -1;
        return minutes;
    }
};
