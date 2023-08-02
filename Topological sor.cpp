Link : https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort
class Solution
{
	public:
	void dfs(int node, int vis[],stack<int>&st,vector<int> adj[])
	{
	    vis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V]={0};
	    stack<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,vis,st,adj);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
