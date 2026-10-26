class Solution {
public:
    int solve(vector<vector<int>>& grid, int m , int n, int i , int j){
        if(i>=m || j>=n || i<0 || j<0 )
            return 1;
        if(grid[i][j]==0)
            return 1;
        if(grid[i][j]==2) 
            return 0;
        grid[i][j]=2;
        
        return solve(grid,m,n,i+1,j)
                +solve(grid,m,n,i,j+1)
                +solve(grid,m,n,i-1,j)
                +solve(grid,m,n,i,j-1);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return solve(grid,m,n,i,j);
                }
            }
        }
        return 0;
    }
};