class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        // code here
         vector<pair<int,int>>adj[V];
        // node, weight

        for(auto edge: edges){
            int u = edge[0]-1;
            int v = edge[1]-1;
            int weight = edge[2];

            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }

        // V+E
        

        vector<int>dist(V,-1);
        dist[0] = 0;
        // min heap
        // pair<int,int> : {dist,node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;

        pq.push({0,0});
        vector<int>Parent(V,-1);

        // distance, node

        while(!pq.empty()){
            pair<int,int>element = pq.top();
            pq.pop();
            int node = element.second;
            int distance = element.first;

            if(distance > dist[node]){
                continue;
            }

            // look at all the neib of the node
            for(auto v: adj[node]){
                int neib = v.first;
                int wt = v.second;
                
                if(dist[neib]==-1 || (dist[neib]> dist[node]+wt)){
                    dist[neib] = dist[node]+wt;
                    Parent[neib] = node;
                    pq.push({dist[neib],neib});
                }

            }
        }

        
        // parent array

        vector<int>path;

        if(dist[V-1]==-1){
            path.push_back(-1);
            return path;
        }
        
        int curr = V-1;

        while(Parent[curr]!=-1){
            path.push_back(curr+1);
            curr = Parent[curr];
        }

        path.push_back(1);
        path.push_back(dist[V-1]);
        reverse(path.begin(),path.end());
        return path;
    }
};

// Using Int Max approach of dijkstra *****
class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        // code here
        vector<pair<int,int>>adj[V];
        for(auto edge: edges){
            int u=edge[0]-1;
            int v=edge[1]-1; // convert them to 0 based
            int wt=edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>dist(V,INT_MAX);
        vector<int>parent(V,-1);
        // queue<int>q;
        // q.push(src); for optimize use priority queue because less wt edges came first 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int distance=pq.top().first;
            pq.pop();
            // when distance is greater why we consider that edge
            if(distance > dist[node]){
                continue;
            }
            for(auto neigb: adj[node]){
            int edgewt=neigb.second;
            int currnode=neigb.first;
            if(edgewt+dist[node]<dist[currnode]){
                // update the dist
                dist[currnode]=edgewt+dist[node];
                pq.push({dist[currnode],currnode});
                parent[currnode]=node;
            }
            }
        }
        vector<int>path;
        
        if(dist[V-1]==INT_MAX){
            path.push_back(-1);
            return path;
        }
        int curr=V-1;
        while(parent[curr]!=-1){
            path.push_back(curr+1); // due to 1 indexing
            curr=parent[curr];
        }
        
        path.push_back(1);
        path.push_back(dist[V-1]);
        reverse(path.begin(),path.end());
        return path;
    }
};
