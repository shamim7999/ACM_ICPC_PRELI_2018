#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 30005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, m, cc, id[mx], par[mx];
vector <int> pre[mx], v[mx];
map <pair<int, int>, int> mp;
bitset <mx> b1, cyc;

void clr()
{
   for(int i=1; i<=n; i++){
      pre[i].clear();
      pre[i].push_back(0);
      v[i].clear(), b1[i] = 0, cyc[i] = 0, par[i] = 0, id[i] = 0;
   }
   mp.clear();
}

void dfs(int node, int baba, int level, int take)
{
   if(cyc[take])
      return;
   par[node] = take;
   if(id[node] == 0)
      id[node] = cc, cc++;
   if(b1[node])
      return;
   b1[node] = 1;
   pre[take].push_back(0);
   pre[take][level] = pre[take][level-1] + mp[{node, baba}];
   for(int child : v[node]){
      if(child!=baba){
         if(b1[child]){
            if(!cyc[take]){
               pre[take].push_back(0);
               pre[take][level+1] = pre[take][level] + mp[{node, child}];
            }
            cyc[take] = 1;
            return;
         }
         dfs(child, node, level+1, take);
      }
   }

}
void solve(int kk)
{
   cin >> n >> k;
   clr();
   for(int i=0,x,y,w; i<k; i++){
      cin >> x >> y >> w;
      mp[{x, y}] = w;
      mp[{y, x}] = w;
      v[x].push_back(y); v[y].push_back(x);
   }
   for(int i=1; i<=n; i++){
      cc = 1;
      if(v[i].size() == 1 && !b1[i]){
         dfs(i, -1, 1, i);
      }
   }
   for(int i=1; i<=n; i++){
      cc = 1;
      if(!b1[i])
         dfs(i, -1, 1, i);
   }
   cout << "Case " << kk << ":\n";
   cin >> m;
   while(m--){
      int x, y;
      cin >> x >> y;
      int l = id[x], r = id[y], p1 = par[x], p2 = par[y];
      if(p1!=p2){
         cout << "-1\n";
         continue;
      }
      if(l > r)
         swap(l, r), swap(x, y);
      if(!cyc[p1]){
         cout << pre[p1][r] - pre[p1][l] << "\n";
         continue;
      }
      if(x == p1){
         int a1 = pre[x][r] - pre[x][l];
         int a2 = pre[x].back() - pre[x][r];
         cout << min(a1, a2) << "\n";
         continue;
      }
      int a1 = pre[p1][r] - pre[p1][l];
      int a2 = pre[p1].back() - pre[p1][r] + pre[p1][l] - pre[p1][1];
      cout << min(a1, a2) << "\n";
   }
}

int32_t main()
{
   fast;
   int t = 1;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
