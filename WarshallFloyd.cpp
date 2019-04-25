#include <bits/stdc++.h> 
using namespace std;
#define int long long
const int inf = 1LL<<60;

vector<vector<int>> WarshallFloyd(vector<vector<int>> g)
{
  int n = g.size();
  for(int i = 0; i < n; i++) g[i][i] = 0;

  for(int k = 0; k < n; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(g[i][k] == inf or g[k][j] == inf) continue;
        g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
      }
    }
  }

  return g;
}

signed main()
{
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n, vector<int>(n, inf));
  for(int i = 0; i < m; i++){
    int s, t, d;
    cin >> s >> t >> d;
    g[s][t] = d;
  }

  vector<vector<int>> dist = WarshallFloyd(g);
  for(int i = 0; i < n; i++){
    if(dist[i][i] < 0){
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(dist[i][j] == inf) cout << "INF";
      else cout << dist[i][j];
      cout << " \n"[j==n-1];
    }
  }

  return 0;
}

/*
  verified on 2019/03/12
  https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
*/
