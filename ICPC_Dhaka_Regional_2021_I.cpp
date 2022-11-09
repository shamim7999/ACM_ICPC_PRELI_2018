#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, a[mx], b[mx], sum[mx], need,cnt=1;
vector <int> v[mx], vv[mx];
vector <pair<int,int>> ans;

bool f = true;
bool ok = true;

void clr()
{
    for(int i=0; i<=n; i++)
        v[i].clear(), vv[i].clear(), sum[i] = 0;
    f = true;
    cnt = 1;
    ok = true;
    ans.clear();
}

int dfs(int node, int par)
{
    for(int child : v[node]){
        if(child!=par){
            sum[node]+=dfs(child, node);
        }
    }
    return sum[node];
}

void bfs(int node)
{
    queue <int> q;
    q.push(node);
    bitset <mx> vis;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 1;
        vector <pair<int,int>> tem;
        for(int child : v[x]){
            if(!vis[child]){
                q.push(child);
                vis[child] = 1;
                tem.push_back({sum[child], child});
            }
        }
        sort(tem.rbegin(), tem.rend());
        for(auto [val, node] : tem){
            vv[x].push_back(node);
        }
    }
}

void Print(int node, int par, int &ace)
{
    
    int sub = 0;
    if(a[node]>=need){
        sub = a[node] - need;
        ans.push_back({node, -sub});
        a[node] = need;
        ace+=sub;
    }
    else{
        if(a[node]+ace>=need){
            sub = need - a[node];
            a[node] = need;
            ace-=sub;
            ans.push_back({node, sub});
        }
        else{
            a[node]+=ace;
            ans.push_back({node, ace});
            ace = 0;
        }
    }
    for(int child : vv[node]){
        if(child!=par){
            Print(child, node, ace);
                    if(a[node]>=need){
                        sub = a[node] - need;
                        ans.push_back({node, -sub});
                        a[node] = need;
                        ace+=sub;
                    }
                    else{
                        if(a[node]+ace>=need){
                            sub = need - a[node];
                            a[node] = need;
                            ace-=sub;
                            ans.push_back({node, sub});
                        }
                        else{
                            a[node]+=ace;
                            ans.push_back({node, ace});
                            ace = 0;
                        }
                    }
        }
    }
}

void solve(int kk)
{
   cin >> n >> need;
   clr();
   for(int i=1,x,y; i<n; i++){
        cin >> x >> y;
        v[x].push_back(y); v[y].push_back(x);
   }
   int st = 1, mm = -1;
   for(int i=1; i<=n; i++){
        cin >> a[i];
        sum[i] = a[i] - need;
   }
   dfs(1, -1);
   bfs(1);
   int mama = 0;
   Print(1,-1,mama);
   cout << "Case " << kk << ": ";
   if(!ok){
        cout << "NO\n";
        return;
   } 
   cout << "YES\n";
   for(auto [node, val] : ans)
        cout << node << " " << val << "\n";
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
