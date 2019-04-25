#include <bits/stdc++.h> 
using namespace std;
#define int long long


class SqrtDecomposition
{
public:
  int n, k, d;
  vector<int> data, bucket, lazy;
  vector<bool> lazyflag;
  int block;

  SqrtDecomposition(int n_, int d_, int block_=512): n(n_), d(d_), block(block_)
  {
    k = (n+block-1) / block;
    data.assign(k*block, d);
    bucket.assign(k, d);
    lazy.assign(k, 0);
    lazyflag.assign(k, false);
  }

  void eval(int x)
  {
    if(lazyflag[x]){
      lazyflag[x] = false;
      for(int i = x*block; i < (x+1)*block; i++){
        data[i] = lazy[x];
      }
    }
  }

  void update(int s, int t, int x)
  {
    for(int i = 0; i < k; i++){
      int l = i*block, r = (i+1)*block;
      if(r <= s or t <= l) continue;
      if(s <= l and r <= t){
        bucket[i] = x;
        lazy[i] = x;
        lazyflag[i] = true;
      }else{
        eval(i); 
        for(int j = max(s, l); j < min(t, r); j++){
          data[j] = x;
        }
        bucket[i] = d;
        for(int j = l; j < r; j++){
          bucket[i] = min(bucket[i], data[j]);
        }
      }
    }
  }

  void update(int i, int x)
  {
    update(i, i+1, x);
  }

  int find(int s, int t)
  {
    int res = d;
    for(int i = 0; i < k; i++){
      int l = i*block, r = (i+1)*block;
      if(r <= s or t <= l) continue; 
      if(s <= l and r <= t){
        res = min(res, bucket[i]); 
      }else{
        eval(i);
        for(int j = max(s, l); j < min(t, r); j++){
          res = min(res, data[j]);
        }
      }
    }

    return res;
  }

  int find(int i)
  {
    return find(i, i+1);
  }
};

/*
  verified on 2019/03/11
  RMQ and RUQ
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
*/
void AOJ_DSL_2_F()
{
  int n, q;
  cin >> n >> q;
  
  SqrtDecomposition sd(n, INT_MAX);
  while(q--){
    int c, s, t, x;
    cin >> c >> s >> t;

    if(c == 0){
      cin >> x;
      sd.update(s, t+1, x);
    }else{
      cout << sd.find(s, t+1) << endl;
    }
  }
}

/*
  verified on 2019/03/11
  RMQ
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
*/
void AOJ_DSL_2_A()
{
  int n, q;
  cin >> n >> q;
  
  SqrtDecomposition sd(n, INT_MAX);
  while(q--){
    int c, s, t, x;
    cin >> c >> s >> t;

    if(c == 0){
      sd.update(s, t);
    }else{
      cout << sd.find(s, t+1) << endl;
    }
  }
}

/*
  verified on 2019/03/11
  RUQ
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
*/
void AOJ_DSL_2_D()
{
  int n, q;
  cin >> n >> q;
  
  SqrtDecomposition sd(n, INT_MAX);
  while(q--){
    int c, s, t, x;
    cin >> c >> s;

    if(c == 0){
      cin >> t >> x;
      sd.update(s, t+1, x);
    }else{
      cout << sd.find(s) << endl;
    }
  }
}

signed main()
{
//  AOJ_DSL_2_F();
//  AOJ_DSL_2_A();
  AOJ_DSL_2_D();

  return 0;
}
