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
struct hello
{
   int s, tp;
   vector < int > penalty;
};
void solve(int kk)
{
    string S1 = "We respect our judges :)";
    string S2 = "Say no to rumour >:";
    cin >> n;
    vector < hello > v(n+10);

    int id, s, tp, m;
    for(int i=1; i<=n; i++){
        cin >> id >> s >> tp >> m;
        vector < int > vv;
        for(int i=1, x; i<=m; i++){
            cin >> x, vv.push_back(x);
        }
        reverse(vv.begin(), vv.end());
        v[id] = {s, tp, vv};
    }

    for(int i=1; i<=n; i++)
        cin >> a[i];

    if(n == 1){
        cout << "Case " << kk << ": " << S1 << "\n";
        return;
    }
    bool ok = 1;
    for(int i=n-1; i>=1; i--){

        int x = a[i], y = a[i+1];
        
        int s1 = v[x].s, s2 = v[y].s;
        int bak1 = v[x].penalty.size(), bak2 = v[y].penalty.size();
        int tp1 = v[x].tp, tp2 = v[y].tp;

        if(s1 > s2 || (s1 == s2 && tp1<=tp2))
            continue;
        int need = s2 - s1;
        if(need > bak1){
            ok = 0;
            break;
        }
        int sum = 0;
        vector <int> tem = v[x].penalty;
        for(int j=0; j<need && !v[x].penalty.empty(); j++){
            sum+=(v[x].penalty.back());
            v[x].penalty.pop_back();
        }
        v[x].s+=need;
        v[x].tp+=sum;
        if(v[x].tp <= v[y].tp)
            continue;
        v[x].s-=need;
        v[x].tp-=sum;
        v[x].penalty.clear();
        v[x].penalty = tem;
        need++;

        if(need > bak1){
            ok = 0;
            break;
        }
        sum = 0;
        for(int j=0; j<need && !v[x].penalty.empty(); j++){
            sum+=(v[x].penalty.back());
            v[x].penalty.pop_back();
        }
        v[x].s+=need;
        v[x].tp+=sum;
    }
    cout << "Case " << kk << ": " << (ok ? S1 : S2) << "\n";
    
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
