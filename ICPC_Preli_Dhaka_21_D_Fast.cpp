#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, a[mx], b = 397, tot;
string s1;
vector <int> v[mx];

int p1[mx], inv[mx];

int norm(int x)
{
   if(x>=mod)
      x%=mod;
   if(x<0)
      x+=mod;
   return x;
}
int bigmod(int e, int x)
{
    if(!x)return 1;
    int p=bigmod(e,x/2);
    p= norm(norm(p)*norm(p));
    if(x%2)
      p = norm(norm(p)*norm(e));
    return norm(p);
}
int ModInverse(int x){return bigmod(x,mod-2)%mod;}

void calc()
{
   p1[0] = 1;
   for(int i=1; i<mx-2; i++){
        p1[i] = p1[i-1]*b;
        p1[i] = norm(p1[i]);
   }
    inv[0] = 1;
    for (int i = 1; i < mx-2; ++i) {
        inv[i] = ModInverse(p1[i]);
    }
}

void dfs(int node, int par, int lvl, int &sum, int lvl2, int &sum2)
{
   int x = (int)s1[node];
   int aa = p1[lvl];
   aa*=x;
   aa = norm(aa);
   sum+=aa;
   sum = norm(sum);

   int bb = p1[lvl2];
   int cc = bb;
   cc = inv[lvl2];
   bb*=x;
   bb = norm(bb);
   sum2+=bb;
   sum2 = norm(sum2);

   int tem = sum2;
   tem*=cc;
   tem = norm(tem);
   tot+=(tem == sum);
   //cout << node << " ---> " << sum << " , " << tem << "\n";
   if(tem == sum){
        cout << node+1 << "\n";
   }

   for(int child : v[node]){
      if(child!=par){
         dfs(child, node, lvl+1, sum, lvl2-1, sum2);
      }
   }
   sum-=aa;
   sum = norm(sum);
   sum2-=bb;
   sum2 = norm(sum2);
}

void clr()
{
    for(int i=0; i<=n; i++){
        v[i].clear();
    }
    tot = 0;
}

void solve(int kk)
{
   cin >> n >> s1;
   clr();
   for(int i=0; i<n; i++)
      s1[i] = tolower(s1[i]);
   for(int i=1,x,y; i<n; i++){
      cin >> x >> y;
      x--,y--;
      v[x].push_back(y);v[y].push_back(x);
   }
   int sum = 0, sum2 = 0;
   dfs(0,-1,0,sum,n,sum2);
   int gc = __gcd(tot, n);
   tot/=gc, n/=gc;
   cout << "Case " << kk << ": " << tot << "/" << n << "\n";
}

int32_t main()
{
   fast;
   calc();
   int t = 1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
