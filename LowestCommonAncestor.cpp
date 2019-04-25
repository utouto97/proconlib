#include <bits/stdc++.h>
using namespace std;
#define int long long

class LowestCommonAncestor
{
public:
  int n, h;
  vector<vector<int>> g, par;
  vector<int> dep;
  
  LowestCommonAncestor(){}

  LowestCommonAncestor(int n) : n(n), g(n), dep(n)
  {
    h = 1;
    while((1<<h) <= n) h++;
    par.assign(h, vector<int>(n, -1));
  }

  void add_edge(int u, int v)
  {
    g[u].push_back(v);
    g[v].push_back(u);
  }

  void dfs(int v, int p, int d)
  {
    par[0][v] = p;
    dep[v] = d;

    for(int u : g[v]){
      if(u != p) dfs(u, v, d+1);
    }
  }

  void build(int r = 0)
  {
    dfs(r, -1, 0);

    for(int k = 0; k+1 < h; k++){
      for(int v = 0; v < n; v++){
        if(par[k][v] < 0) par[k+1][v] = -1;
        else par[k+1][v] = par[k][par[k][v]];
      }
    }
  }

  int lca(int u, int v)
  {
    if(dep[u] > dep[v]) swap(u, v);

    for(int k = 0; k < h; k++){
      if((dep[v] - dep[u])>>k & 1){
        v = par[k][v];
      }
    }

    if(u == v) return u;

    for(int k = h-1; k >= 0; k--){
      if(par[k][u] != par[k][v]){
        u = par[k][u];
        v = par[k][v];
      }
    }

    return par[0][u];
  }

  int dist(int u, int v)
  {
    return dep[u]+dep[v]-dep[lca(u, v)]*2;
  }
};

signed main()
{
  int n;
  cin >> n;

  LowestCommonAncestor lca(n);

  for(int i = 0; i < n; i++){
    int k;
    cin >> k;

    for(int j = 0; j < k; j++){
      int c;
      cin >> c;
      lca.add_edge(i, c);
    }
  }

  lca.build();

  int q;
  cin >> q;

  while(q--){
    int u, v;
    cin >> u >> v;
    cout << lca.lca(u, v) << endl;
  }

  return 0;
}

/*
  verified on 2019/03/10
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C
*/
