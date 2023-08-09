Link: https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dst(V);
        for(int i=0;i<V;i++)
        dst[i]=1e9;
        dst[S]=0;
        pq.push({0,S});
        
        
        while(!pq.empty())
        {
            int ds=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node])
            {
                int edgeweight=it[1];
                int adjnode= it[0];
                
                if(ds+edgeweight < dst[adjnode])
                {
                    dst[adjnode]=ds+edgeweight;
                    pq.push({dst[adjnode],adjnode});
                }
            }
        }
        return dst;
    }
