#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, a[mx], dis[mx], cost[mx], podd[mx], peven[mx];
vector < int > v[mx], odd, even;
void bfs(int node)
{
    queue < int > q;
    q.push(node);
    dis[node] = 0;
    while(!q.empty()){
        int xx = q.front();
        q.pop();
        for(int child : v[xx]){
            if(dis[child] == -1){
                dis[child] = 1+dis[xx];
                q.push(child);
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(dis[i]%2 == 0)
            even.push_back(cost[i]);
        else
            odd.push_back(cost[i]);
    }
    even.push_back(0);
    odd.push_back(0);
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());


    for(int i=1; i<even.size(); i++)
        peven[i] = peven[i-1]+even[i];
    for(int i=1; i<odd.size(); i++)
        podd[i] = podd[i-1]+odd[i];   
}

void clr()
{
    for(int i=1; i<=n; i++){
        v[i].clear();
        dis[i] = -1;
        odd.clear();
        even.clear();
        podd[i] = 0;
        peven[i] = 0;
    }
}

void solve(int kk)
{
    cin >> n;
    clr();
    for(int i=1; i<=n; i++)
        cin >> cost[i];
    for(int i=1, x, y; i<n; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);
    int s1 = even.size(), s2 = odd.size();
    int mm = -1e17, node = 1e17;
    for(int i=1; i<=n; i++){
        int sum = 0, sub = 0;
        auto f1 = upper_bound(even.begin(), even.end(), cost[i]) - even.begin();
        auto f2 = upper_bound(odd.begin(), odd.end(), cost[i]) - odd.begin();
       
        if(dis[i]%2 == 0){
            int a1 = peven[f1-1];
            int a2 = 0;
            if(f1 < s1){
               a2 = peven[s1-1] - peven[f1-1];
            }

            int choto = f1 - 1;
            int boro = s1 - f1;
            int t1 = choto*cost[i];

            t1 = t1 - a1;
            int t2 = boro*cost[i];

            t2 = t2 - a2;
            sum = t1+t2;

            a1 = podd[f2-1];
            a2 = 0;
            if(f2 < s2){
               a2 = podd[s2-1] - podd[f2-1];
            }

            choto = f2 - 1;
            boro = s2 - f2;
            t1 = choto*cost[i];
            t1 = a1 - t1;

            t2 = boro*cost[i];
            t2 = a2 - t2;
            sum += (t1+t2);
        }
        else{
         
            int a1 = peven[f1-1];
            int a2 = 0;
            if(f1 < s1){
               a2 = peven[s1-1] - peven[f1-1];
            }
            int choto = f1 - 1;
            int boro = s1 - f1;
            int t1 = choto*cost[i];
            t1 = a1 -t1;
            int t2 = boro*cost[i];

            t2 = a2 - t2;
            sum = t1+t2;
            a1 = podd[f2-1];
            a2 = 0;
            if(f2 < s2){
               a2 = podd[s2-1] - podd[f2-1];
            }

            choto = f2 - 1;
            boro = s2 - f2;
            t1 = choto*cost[i];
            t1 = t1 - a1;

            t2 = boro*cost[i];
            t2 = t2 - a2;
            sum += (t1+t2);
        }
        if(sum>=mm){
          if(sum == mm){
            node = min(node, i);
          }
          else{
            node = i;
          }
          mm = sum;
        }
    }

    cout << "Case " << kk << ": " << node << "\n";

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
