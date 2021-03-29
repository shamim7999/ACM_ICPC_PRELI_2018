#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 100005
#define ll long long
#define mod 1000000007
#define ld long double

int n, a[mx];

ll f(ll x)
{
    ll aa = sqrtl(x);
    x/=2;
    ll bb = sqrtl(x);

    return (aa+bb);
}

void solve(int kk)
{
    ll aa, bb;
    cin >> aa >> bb;
    cout << "Case " << kk << ": " << f(bb)-f(aa-1) << "\n";


}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t=1;
  //scanf("%d",&t);
  cin >> t;
  for(int i=1; i<=t; i++)
    solve(i);
  return 0;
}
