class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> adj;
        for(auto& pre : prerequisites){
            int u = pre[0];
            int v = pre[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(int i:adj[top]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()==numCourses) return true;
        return false;
    }
};
