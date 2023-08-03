Link: https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule

vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> adj[n];
        for(auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }
        
        int vis[n]={0};
        for(int i=0;i<n;i++)
        {
            for(auto it:adj[i])
            {
                vis[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto it:adj[node])
            {
                vis[it]--;
                if(vis[it]==0)
                q.push(it);
            }
        }
       
        if(ans.size()==n){
           return ans;
        }
       
        return {};
        
    }
