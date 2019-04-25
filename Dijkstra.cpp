#include <bits/stdc++.h> 
using namespace std;
#define int long long
const int inf = 1LL<<60;

vector<int> Dijkstra(int s, vector<vector<pair<int,int>>>& g)
{
  using P = pair<int, int>;
  int n = g.size();
  vector<int> dist(n, inf);
  priority_queue<P, vector<P>, greater<P>> que;

  dist[s] = 0;
  que.push({0, s});
  while(!que.empty()){
    P p = que.top();
    que.pop();
    int v = p.second;
    if(dist[v] < p.first) continue;
    for(auto e : g[v]){
      if(dist[e.first] > dist[v] + e.second){
        dist[e.first] = dist[v] + e.second;
        que.push({dist[e.first], e.first});
      }
    }
  }

  return dist;
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

  vector<int> dist = Dijkstra(r, g);

  for(int i = 0; i < n; i++){
    if(dist[i] == inf) cout << "INF" << endl;
    else cout << dist[i] << endl;
  }

  return 0;
}

/*
  verified on 2019/03/12
  https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
*/
