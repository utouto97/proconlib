#include <bits/stdc++.h> 
using namespace std;
#define int long long

template<class T>
class BinaryIndexedTree
{
public:
  int n;
  vector<T> bit;

  BinaryIndexedTree():n(-1){}

  BinaryIndexedTree(int n_, T d):n(n_),bit(n_+1,d){}

  T sum(int i)
  {
    T s = 0;
    while(i > 0){
      s += bit[i];
      i -= i&-i;
    }
    return s;
  }

  void add(int i, T x)
  {
    if(i == 0) return;
    while(i <= n){
      bit[i] += x;
      i += i&-i;
    }
  }

  T sum0(int i)
  {
    return sum(i+1);
  }

  void add0(int i, T x)
  {
    add(i+1, x);
  }

  T query(int l, int r)
  {
    return sum(r-1)-sum(l-1);
  }

  T query0(int l, int r)
  {
    return sum(r)-sum(l);
  }
};

signed main()
{
  int n, q;
  cin >> n >> q;

  BinaryIndexedTree<int> bit(n, 0);
  while(q--){
    int c, x, y;
    cin >> c >> x >> y;
    
    if(c == 0){
      bit.add(x, y);
    }else{
      cout << bit.query(x, y+1) << endl;
    }
  }

  return 0;
}

/*
  verified on 2019/03/11
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
*/
