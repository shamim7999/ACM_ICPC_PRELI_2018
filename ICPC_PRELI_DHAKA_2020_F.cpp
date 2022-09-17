#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, a, b;
const int N = 1000001;
int lp[N+1];
vector<int> pr;

void Linear_Sieve()
{
  for (int i=2; i<=N; ++i) {
      if (lp[i] == 0) {
          lp[i] = i;
          pr.push_back (i);
      }
      for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
          lp[i * pr[j]] = pr[j];
  }

}
int func(int x)
{
   int tot = (a+n)/x - (a-1)/x;
   return tot;
}

vector<int> PrimeFactorize(int x)
{
   vector <int> v;
   for(int i=0; pr[i]*pr[i]<=x && i<pr.size(); i++){
      while(x%pr[i] == 0){
         v.push_back(pr[i]);
         x/=pr[i];
      }
   }
   if(x>1)
      v.push_back(x);
   return v;
}

void solve(int kk)
{
   cin >> a >> b >> n;
   if(a == b){
      cout << "Case " << kk << ": " << "0\n";
      return;
   }
   if(a>b)
      swap(a, b);
   b-=a;
   vector <int> v = PrimeFactorize(b);
   int sum = 0, sz = v.size();
   unordered_map <int,bool> vis;
   vis[0] = 1;
   vis[1] = 1;
   for(int i=0; i<(1LL<<sz); i++){
      int mul = 1, taken = 0;
      for(int pos = 0; pos<sz; pos++){
         bool ok = (i & (1LL<<pos));
         if(ok)
            mul*=v[pos], taken++;
      }
      if(vis[mul])
         continue;
      vis[mul] = 1;
      int ace = func(mul);
      (taken%2 == 0) ? sum-=ace : sum+=ace;
   }

   cout << "Case " << kk << ": " << (n+1) - sum << "\n";

}

int32_t main()
{
   fast;
   int t = 1;
   Linear_Sieve();
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
