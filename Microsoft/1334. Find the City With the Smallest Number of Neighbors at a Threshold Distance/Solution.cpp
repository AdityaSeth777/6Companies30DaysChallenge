class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj[n];
        for(int i=0;i<edges.size();i++){
          adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        vector<int>city(n);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
          int count=0;
        vector<int>dis(n,-1);
        pq.push({0,i});
        //Aditya Seth.
        while(!pq.empty()){
          int node=pq.top().second;
          int step=pq.top().first;
          pq.pop();
          if(dis[node]!=-1){
            continue;
          }
          dis[node]=step;
          if(step<=distanceThreshold && step!=0){
            count++;
          }
          for(int j=0;j<adj[node].size();j++){
            if(dis[adj[node][j][0]]==-1){
              pq.push({step+adj[node][j][1],adj[node][j][0]});
            }
          }
        }
        city[i]=count;
        }
        vector<int>ans;
        int mini=*min_element(city.begin(),city.end());
        for(int i=0;i<city.size();i++){
          if(city[i]==mini){
            ans.push_back(i);
          }
        }
        return ans[ans.size()-1];
    }
};