link- https://practice.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number_of_provinces
//
//

class Solution {
  public:
  void dfs(int i,vector<int> adjl[],int vis[])
  {
      vis[i]=1;
      for(auto it:adjl[i])
      {
          if(!vis[it])
          {
              dfs(it,adjl,vis);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> adjl[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1 && i!=j)
                {
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        int vis[V]={0};
        int cnt=0;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,adjl,vis);
            }
        }
        return cnt;
    }
};
