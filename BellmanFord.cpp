#include <bits/stdc++.h> 
using namespace std;
#define int long long
const int inf = 1LL<<60;

bool BellmanFord(int s, vector<vector<pair<int,int>>>& g, vector<int>& dist)
{
  int n = g.size();
  dist.assign(n, inf);

  dist[s] = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(dist[j] == inf) continue;
      for(auto e : g[j]){
        if(dist[e.first] > dist[j] + e.second){
          dist[e.first] = dist[j] + e.second;
          if(i == n-1) return true;
        }
      }
    }
  }

  return false;
}

signed main()
{
  int n, m, r;
  cin >> n >> m >> r;

  vector<vector<pair<int,int>>> g(n);
  for(int i = 0; i < m; i++){
    int s, t, d;
    cin >> s >> t >> d;
    g[s].push_back({t, d});
  }

  vector<int> dist;
  if(BellmanFord(r, g, dist)){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    for(int i = 0; i < n; i++){
      if(dist[i] == inf) cout << "INF" << endl;
      else cout << dist[i] << endl;
    }
  }

  return 0;
}

/*
  verified on 2019/03/12
  https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
*/
