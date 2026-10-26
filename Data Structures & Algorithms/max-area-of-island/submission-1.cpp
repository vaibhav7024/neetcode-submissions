class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i>=m|| j>=n || i<0 || j<0 || grid[i][j]==0){
            return 0;
        }
        grid[i][j]=0;
        return 1+dfs(grid,i+1,j)+dfs(grid,i-1,j)+dfs(grid,i,j+1)+dfs(grid,i,j-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n  = grid[0].size();
        int res =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                res = max(res,dfs(grid,i,j));
            }
        }
        return res;
    }
};
