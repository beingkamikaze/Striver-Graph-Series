Link : https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph

bool check(int start,int V,vector<int>adj[],vector<int> &vis)
   {
       queue<int> q;
	    q.push(start);
	    vis[start]=0;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        for(int it:adj[node])
	        {
	            if(vis[it]==-1)
	            {
	                vis[it]=!vis[node];
	                q.push(it);
	            }
	            else if(vis[it]==vis[node])
	            {
	                return false;
	            }
	        }
	    }
	    return true;
   }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==-1)
	        {
	            if(check(i,V,adj,vis)==false)
	            return false;
	        }
	    }
	    return true;
	}
