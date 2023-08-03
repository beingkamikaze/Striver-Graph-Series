Link : https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int ndeg[V]={0};
	    for(int i=0;i<V;i++)
	    {
	        for(auto it: adj[i])
	        {
	            ndeg[it]++;
	        }
	    }
	    queue<int> q;
	    {
	        for(int i=0;i<V;i++)
	        {
	            if(ndeg[i]==0)
	            q.push(i);
	        }
	    }
	    vector<int> ans;
	    while(!q.empty())
	    {
	        int node=q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it:adj[node])
	        {
	            ndeg[it]--;
	            if(ndeg[it]==0)
	            q.push(it);
	        }
	    }
	    return ans;
	}
};
