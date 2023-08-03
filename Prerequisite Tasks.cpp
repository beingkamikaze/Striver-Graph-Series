Link : https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks

bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    vector<int> adj[N];
	    for(auto it : prerequisites)
	    {
	        adj[it.first].push_back(it.second);
	    }
	    
	    int ndeg[N]={0};
	    for(int i=0;i<N;i++)
	    {
	        for(auto it:adj[i])
	        {
	            ndeg[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<N;i++)
	    {
	        if(ndeg[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node])
	        {
	            ndeg[it]--;
	            if(ndeg[it]==0)
	            q.push(it);
	        }
	    }
	    if(ans.size() == N)return true;
	    return false;
	}
