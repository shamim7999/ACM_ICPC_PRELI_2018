/// TRIE DATA-STRUCTURE

#include<bits/stdc++.h>
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define mx 201005
#define ll long long
#define mod 1000000007
#define ld long double

int n, m;
ll a[mx];//, m;

int cur[mx], node[mx*30][30], tot_nodes=1;
map < vector <int>, ll > mp[mx*26], smart;
//map < vector<int>, int > smart;
ll ans = -1;

void clr()
{
    memset(node, 0, sizeof node);
    
    smart.clear();
    for(int i=0; i<=tot_nodes; i++)
      mp[i].clear();
    ans = -1;
    tot_nodes = 1;
}

void add_string(string &s1, vector<int> freq, int pos)
{
    int now=1;
    //cout << "Now is: " << now << "\n";
    //cur[now]++;
    for(int i=0; s1[i]; i++){
        int id = s1[i]-'a';
        if(!node[now][id])
            node[now][id] = ++tot_nodes;
        now = node[now][id];
        mp[now][freq] = max(mp[now][freq], a[pos]);
        //cur[now]++;
    }
}

void query(int now, string s2,  int len, vector<int> freq)
{
    
    if(s2[len-1] == '\0')
        return;
    int id = s2[len-1]-'a';
    
    if(node[now][id] == 0)
        return;
        now = node[now][id];
        
        ans = max(ans, len+(mp[now][freq]));
        
        query(now, s2, len+1, freq);

}

void solve(int kk)
{
    clr();

    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++){
        string s1;
        cin >> s1;

        vector < int > freq(26, 0);

        for(int i=0; s1[i]; i++){
            freq[s1[i]-'a']++;
        }

        add_string(s1, freq, i);

        smart[freq] = max(smart[freq], a[i]);
    }
    cin >> m;
    while(m--){
        string s1;
        cin >> s1;

        vector < int > freq(26, 0);

        for(int i=0; s1[i]; i++){
            freq[s1[i]-'a']++;
        }
       
        ans = smart[freq];

        query(1,s1,1, freq);

        cout << ans << "\n";
    }

}

signed main()
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
