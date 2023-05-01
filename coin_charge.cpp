#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using ld=long double;
#define vec vector
constexpr ll inf=1e18;
using H=pair<ll,ll>;
#define fs first
#define sc second
#define rng(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) rng(i,0,(n))
ll dp[100000];
signed main(){
    int n,m; cin>>n>>m;
    vi c(m);
    rep(i,m) cin>>c[i];
    rep(i,n+1) dp[i]=inf;
    dp[0]=0;
    rep(i,m)for(int j=0;j<=n;j++){
        if(j+c[i]<=n) dp[j+c[i]]=min(dp[j+c[i]],dp[j]+1);
    }
    cout<<dp[n]<<endl;
}