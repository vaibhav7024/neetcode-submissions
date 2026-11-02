class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        vector<int> inorder(numCourses);
        for(auto pre:prerequisites){
            int u = pre[0];
            int v = pre[1];
            adj[v].push_back(u);
            inorder[u]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();q.pop();
            ans.push_back(node);
            for(int nei:adj[node]){
                inorder[nei]--;
                if(inorder[nei]==0){
                    q.push(nei);
                }
            }
        }
        if(ans.size()!=numCourses) return {};
        return ans;
    }
};
