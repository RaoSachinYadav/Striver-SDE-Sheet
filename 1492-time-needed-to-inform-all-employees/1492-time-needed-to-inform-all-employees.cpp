class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];

        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[manager[i]].push_back(i);
            }
        }


        queue<pair<int,int>>q;
        q.push({headID,0});
        int ans=0;

        while(!q.empty()){
            int node=q.front().first;
            int t=q.front().second;
            q.pop();

            for(auto it:adj[node]){
                ans=max(ans,t+informTime[node]);
                q.push({it,t+informTime[node]});
            }
        }
        return ans;
    }
};