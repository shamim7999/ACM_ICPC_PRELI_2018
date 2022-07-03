#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 20005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, tot[mx], par[mx];
vector < int > v[mx];
vector < pair<int, int> > vv;
map < pair<int,int>, int > cont, dis;
bitset < mx > b1;

void clr()
{
   for(int i=0; i<=n; i++){
      b1[i] = 0;
      v[i].clear();
      par[i] = -1;
      tot[i] = 0;
   }
   vv.clear();
   cont.clear();
   dis.clear();
}

int dfs(int node)
{
   if(b1[node])
      return 0;
   b1[node] = 1;
   tot[node] = 1;
   for(int child : v[node]){
      if(!b1[child]){
         tot[node]+=dfs(child);
         par[child] = node;
      }
   }
   return tot[node];
}

void solve(int kk)
{
   cin >> n;
   clr();
   for(int i=1, x, y, w; i<n; i++){
      cin >> x >> y >> w;
      v[x].push_back(y); v[y].push_back(x);
      par[x] = -1, par[y] = -1;
      if(x>y)
         swap(x, y);
      dis[{x, y}] = w;
      dis[{y, x}] = w;
   }
   dfs(1);
   par[1] = 1;
   int sum = 0;
   
   for(int i=2; i<=n; i++){
      int baba = par[i];
      int ace = tot[i], baki = n - ace;
      int totalCont = ace*baki;
      /// baba, child
      cont[{baba, i}] = totalCont*dis[{baba, i}];

      //cout << baba << " " << i << " -- " << totalCont << "\n";
      sum+=cont[{baba, i}];

      if(dis[{baba, i}] < 0){
         vv.push_back({dis[{baba, i}], totalCont});
      }
   }

   sort(vv.begin(), vv.end(),[&](auto v1, auto v2){
      if(v1.first > v2.first)
         return 1;
      if(v1.first == v2.first){
         if(v1.second > v2.second)
            return 1;
         return 0;
      }
      return 0;
   });

   int ans = 0;

   //for(auto )

   for(auto [val, cnt] : vv){

      //cout << val << " " << cnt << "\n";
      //continue;

      int x = val*cnt;
      int tem = sum - x;
      if(tem < 0){
         sum = tem;
         ans+=abs(val);
         //cout << ans << "\n";
         //return;
         //cout << sum << "\n";
         //return;
         continue;
      }
      int l = val, r = 0, take = 0;
      while(l<=r){
         int mid = (l+r)/2;
         tem = sum - x;
         tem+=(mid * cnt);
         //cout << mid << " " << tem << "\n\n";
         if(tem>=0){
            r = mid-1;
            take = mid;
         }
         else
            l = mid+1;
      }

      //cout << take << "\n";

      take = val - take;
      ans+=abs(take);
   }

   cout << "Case " << kk << ": " << ans << "\n";

   //for(int i=1; i<=n; i++)
   //   cout << i << " --- " << tot[i] << "\n";

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
/*

1. Wrong Ans? 
   Did u read the Statement properly?
   Did u miss any constraints?
   Did u miss any corner case?
   Are u sure about your Solution?

2. No Idea?
   Try Greedy..
   Try DP...
   First Try Recursive DP..
   Then Try Iterative DP..
   If memory exceeds, then try to reduce it..
   If not possible then, try to solve it using following way..
   Try to solve it using Permutation ans Combination..
   Try to find Sequence..
   Try to Solve it using Algebra..  
*/
