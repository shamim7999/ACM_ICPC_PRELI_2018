#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, a[mx];
const int N = 10000000;
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
int norm(int x)
{
	if(x>=mod)
		x%=mod;
	if(x<0)
		x+=mod;
	return x;
}
void solve(int kk)
{
	cin >> n;
	if(n == 0)
		exit(0);
	int ans = 1;
    for(int i=0; i<pr.size() && pr[i]<=n; i++){
    	int cnt = 0, cc = pr[i];
    	while(cc<=n){
    		cnt+=(n/cc);
    		cc*=pr[i];
    	}
    	//cout << pr[i] << " --- " << cnt << "\n";
    	int tot = ((cnt+1)*(cnt+2))/2;
    	//cout << tot << "\n";
    	tot = norm(tot);
    	ans*=tot;
    	ans = norm(ans);
    }
    cout << ans << "\n";
}

int32_t main()
{
   fast;
   int t = 1;
   Linear_Sieve();
   //cin >> t;
   for(int i=1; ; i++)
        solve(i);
   return 0;
}
