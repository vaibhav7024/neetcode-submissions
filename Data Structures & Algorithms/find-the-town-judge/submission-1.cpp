class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> rank(n+1);
        for(auto t:trust){
            rank[t[0]]--;
            rank[t[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(rank[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};