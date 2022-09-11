#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int n, k, a[mx] , r, c;
int seed;
char maze[2021][2021];
int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
vector < pair<int,int> > g[1000004];
bitset <1000004> color;
int dis[1000004];

int node,edge;

bool ok(int x, int y)
{
    if(x>=1 && x<=r && y>=1 && y<=c)
        return 1;
    return 0;
}

namespace Dijkstra
{
    void dijkstra(int src)
    {
       for(int i=1; i<=node; i++) dis[i] = INT_MAX, color[i] = 0;
        dis[src] = 0;

        set < pair<int,int> > s;
        s.insert({0,src});
        while(!s.empty()){

            auto it = s.begin();
            int Node = it->second;
            s.erase(it);

            color[Node]=1;

            for(int i=0; i<g[Node].size(); i++){
                int n1 = g[Node][i].first;
                int cost = g[Node][i].second+dis[Node];

                if(cost<dis[n1] && !color[n1]){
                    auto f = s.find({dis[n1],n1});


                    if(f!=s.end()){
                        s.erase(f);

                    }

                    dis[n1] = cost;
                    s.insert({dis[n1],n1});
                    //Edge[n1] = {Node,n1};

                    //p.insert({})
                }

            }



        }



    }
};
using namespace Dijkstra;

void update_seed()
{
    seed = (seed * 1000003 + 10007) % 1000000009;
}
void gen_maze(int N, int M, int Cx, int Cy, int Mx, int My)
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if ((i==Cx && j==Cy) || (i==Mx && j==My))
            {
                maze[i][j] = '.';
                continue;
            }
            update_seed();
            int power = seed % 63;
            if (power == 0)
                maze[i][j] = '.';
            else if (power <= 26)
                maze[i][j] = power - 1 + 'a';
            else if (power <= 52)
                maze[i][j] = power - 27 + 'A';
            else
                maze[i][j] = power - 53 + '0';
        }
    }
}

int calc(int x, int y)
{
    char cc = maze[x][y];
    int xx = 0;
    if(cc>='A' && cc<='Z'){
        xx = 27+(cc-'A');
    }
    else if(cc>='a' && cc<='z'){
        xx = 1+(cc-'a');
    }
    else if(cc>='0' && cc<='9'){
        xx = 53+(cc-'0');
    }
    return xx;
}

void solve(int kk)
{
    int N, M, CX, CY, MX, MY;
    cin >> N >> M >> CX >> CY >> MX >> MY;
    cin >> seed;
    //update_seed();
    gen_maze(N, M, CX, CY, MX, MY);
    r = N, c = M;
    map <pair<int,int>,int> mp;
    int id = 1;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            mp[{i,j}] = id;
            id++;
        }
    }
    node = id;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            int xx = mp[{i,j}];

            for(int ii=0; ii<4; ii++){
                int x = dx[ii]+i, y = dy[ii]+j;
                if(ok(x, y)){
                    int yy = mp[{x,y}];
                    int c1 = calc(i, j)+1, c2 = calc(x, y)+1;
                    g[xx].push_back({yy, c2});
                    g[yy].push_back({xx, c1});
                }
            }
        }
    }

    dijkstra(1);
    cout << "Case " << kk << ": " << dis[mp[{MX, MY}]] << "\n";
    for(int i=1; i<=node; i++)
        g[i].clear();
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
