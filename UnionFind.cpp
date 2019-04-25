#include <bits/stdc++.h> 
using namespace std;
#define int long long

class UnionFind
{
public:
  int n;
  vector<int> par, rnk;

  UnionFind(int n_)
  {
    n = n_;
    par.resize(n);
    rnk.resize(n);
    for(int i = 0; i < n; i++){
      par[i] = i;
      rnk[i] = 0;
    }
  }

  int find(int x)
  {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
  }

  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if(x == y) return;

    if(rnk[x] < rnk[y]){
      par[x] = y;
    }else{
      par[y] = x; 
      if(rnk[x] == rnk[y]) rnk[x]++;
    }
  }

  bool same(int x, int y)
  {
    return find(x) == find(y);
  }
};

signed main()
{
  int n, q;
  cin >> n >> q;

  UnionFind uf(n);
  while(q--){
    int c, x, y;
    cin >> c >> x >> y;

    if(c == 0){
      uf.unite(x, y);
    }else{
      cout << uf.same(x, y) << endl;
    }
  }

  return 0;
}

/*
  verified on 2019/03/11
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
*/
