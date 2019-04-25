#include <bits/stdc++.h>
using namespace std;
#define int long long

template<int M>
class Combination
{
public:
  int n;
  vector<int> fac, finv;

  Combination(int n_) : n(n_), fac(n_), finv(n_)
  {
    fac[0] = 1;
    for(int i = 1; i < n; i++) fac[i] = fac[i-1]*i%M;
    finv[n-1] = pow(fac[n-1], M-2);
    for(int i = n-1; i > 0; i--) finv[i-1] = finv[i]*i%M;
  }

  int pow(int a, int b)
  {
    if(b == 0) return 1; 
    return pow(a*a%M, b/2)*(b%2?a:1)%M;
  }

  int C(int a, int b)
  {
    if(b < 0 or a < b) return 0;
    return fac[a]*finv[a-b]%M*finv[b]%M;
  }

  int P(int a, int b)
  {
    if(b < 0 or a < b) return 0;
    return fac[a]*finv[a-b]%M; 
  }

  int H(int a, int b){
    if(a == 0 and b == 0) return 1;
    return C(a+b-1, b);
  }
};

signed main()
{
  const int mod = 1e9+7;
  Combination<mod> comb(1e7);

  int t;
  cin >> t;

  while(t--){
    string s;
    cin >> s;
    
    char m = s[0];
    int n = 0, k = 0;
    bool f = false;
    for(int i = 2; i < s.size()-1; i++){
      if(s[i] == ',') f = true;
      else if(!f) n = 10*n+s[i]-'0'; 
      else k = 10*k+s[i]-'0';
    }
    
    if(m == 'C') cout << comb.C(n, k) << endl;
    if(m == 'P') cout << comb.P(n, k) << endl;
    if(m == 'H') cout << comb.H(n, k) << endl;
  }

  return 0;
}

/*
  verified on 2019/03/13
  https://yukicoder.me/problems/no/117
*/
