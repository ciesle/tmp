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
ld dp[105][105];
signed main(){
    int n,t,l,b;
    while(cin>>n>>t>>l>>b&&n+t+l+b>0){
        rep(i,n+1) rep(j,t+1) dp[j][i]=0;
        dp[0][0]=1;
        vi type(n+1,0);
        rep(i,l){
            int t;cin>>t;
            type[t]=1;
        }
        rep(i,b){
            int t;cin>>t;
            type[t]=2;
        }
        rep(i,t) rep(j,n){
            if(type[j]==0||type[j]==1){
                rng(k,1,7){
                    int t=j+k;
                    if(t>n) t=n-(t-n);
                    dp[i+1+type[j]][t]+=dp[i][j]/6;
                }
            }
            else{
                rng(k,1,7){
                    int t=k;
                    if(t>n) t=n-(t-n);
                    dp[i+1][t]+=dp[i][j]/6;
                }
            }
        }

        ld sum=0;
        rep(i,t+1) sum+=dp[i][n];
        printf("%.20LF\n",sum);
    }
}