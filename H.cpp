#include<bits/stdc++.h>
using namespace std;
#define dd double
#define int long long
#define ull unsigned long long
#define ld long double
#define mx 1000005
#define mod 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define W 0
#define R 1
#define G 2
#define B 3
int n, k, a[mx], dp[4][mx];
string s1;
unordered_map <char,int> mp;

int norm(int x)
{
    if(x>=mod)
        x%=mod;
    if(x<0)
        x+=mod;
    return x;
}

int func(int prev, int pos)
{
    if(pos>=n)
        return 1;
    int &ret = dp[prev][pos];
    int sum = 0;
    if(ret!=-1)
        return ret;
    if(s1[pos] == 'W'){
        if(pos == 0){
            if(s1[pos+1] == 'R'){
                sum = func(G, pos+1);
                sum = norm(sum);
                sum+=func(B, pos+1);
                sum = norm(sum);
            }
            else if(s1[pos+1] == 'G'){
                sum = func(R, pos+1);
                sum = norm(sum);
                sum+=func(B, pos+1);
                sum = norm(sum);
            }
            else if(s1[pos+1] == 'B'){
                sum = func(R, pos+1);
                sum = norm(sum);
                sum+=func(G, pos+1);
                sum = norm(sum);
            }
            else{
                sum = func(G, pos+1);
                sum = norm(sum);
                sum+=func(B, pos+1);
                sum = norm(sum);
                sum+=func(R, pos+1);
                sum = norm(sum);
            }
        }
        else if(pos == n-1){
            if(prev == R){
                sum = func(G, pos+1);
                sum = norm(sum);
                sum+=func(B, pos+1);
                sum = norm(sum);
            }
            else if(prev == G){
                sum = func(R, pos+1);
                sum = norm(sum);
                sum+=func(B, pos+1);
                sum = norm(sum);
            }
            else if(prev == B){
                sum = func(G, pos+1);
                sum = norm(sum);
                sum+=func(R, pos+1);
                sum = norm(sum);
            }
        }
        else{
            if(s1[pos+1] == 'W'){
                if(prev == R){
                    sum = func(G, pos+1);
                    sum = norm(sum);
                    sum+=func(B, pos+1);
                    sum = norm(sum);
                }
                else if(prev == G){
                    sum = func(R, pos+1);
                    sum = norm(sum);
                    sum+=func(B, pos+1);
                    sum = norm(sum);
                }
                else if(prev == B){
                    sum = func(G, pos+1);
                    sum = norm(sum);
                    sum+=func(R, pos+1);
                    sum = norm(sum);
                }
            }
            else if(prev == mp[s1[pos+1]]){
                sum+=func(R, pos+1);
                sum = norm(sum);
                sum+=func(G, pos+1);
                sum = norm(sum);
            }
            else{
                sum+=func(R, pos+1);
                sum = norm(sum);
            }
        }
    }
    else{
        sum = func(mp[s1[pos]], pos+1);
        sum = norm(sum);
    }

    return ret = sum;
}

void solve(int kk)
{
    cin >> s1;
    n = (int)s1.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<4; j++)
            dp[j][i] = -1;
    }
    //memset(dp, -1, sizeof dp);
    cout << "Case " << kk << ": " << func(0, 0) << "\n";
}

int32_t main()
{
   fast;
   int t = 1;
   mp['W'] = 0;
   mp['R'] = 1;
   mp['G'] = 2;
   mp['B'] = 3;
   cin >> t;
   for(int i=1; i<=t; i++)
        solve(i);
   return 0;
}
