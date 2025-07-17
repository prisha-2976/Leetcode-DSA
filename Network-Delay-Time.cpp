class Solution {
public:
  void create_adj(unordered_map<int, vector<pair<int,int>>> &adj, vector<vector<int>> &times){
      for(auto time:times){
          int src=time[0];
          int dist=time[1];
          int w=time[2];
          adj[src].push_back({dist,w});

      
  }
  }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        create_adj(adj,times);
        
        // create a dist array with infinite values
        vector<int> dist(n+1, INT_MAX);
        // make distance of source node equals to 0
        dist[k]=0;
        // make a minheap_priority queue
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        
        // push{0,src} into the priority queue
        pq.push({0,k});
        // until your pq becomes empty perform relaxation 
        while(!pq.empty()){
        int u=pq.top().second;
        int curr_dist=pq.top().first;
        pq.pop();
        if(curr_dist>dist[u]) continue;
        for(pair<int,int> neigh: adj[u]){
            int v=neigh.first;
            int w=neigh.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }

}
int ans=0;
for(int i=1;i<=n;i++){
    if(dist[i]==INT_MAX) return -1;
    ans=max(ans, dist[i]);

}
return ans;
    }
};