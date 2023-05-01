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
H dp[33][33][33][33];
int wa[33][33];
int u[33][33];
int h,w,s,mn;
int getsum(int s,int t,int x,int y){
    return wa[s+x-1][t+y-1]-(s>0?wa[s-1][t+y-1]:0)-(t>0?wa[s+x-1][t-1]:0)+(s>0&&t>0?wa[s-1][t-1]:0);
}
H solve(int s,int t,int x,int y){
    if(dp[s][t][x][y].fs>0) return dp[s][t][x][y];
    dp[s][t][x][y].fs=1;
    dp[s][t][x][y].sc=getsum(s,t,x,y)-mn;
    for(int i=1;i<x;i++){
        if(getsum(s,t,i,y)>=mn&&getsum(s+i,t,x-i,y)>=mn){
            if(dp[s][t][x][y].fs<solve(s,t,i,y).fs+solve(s+i,t,x-i,y).fs||
            dp[s][t][x][y].fs==solve(s,t,i,y).fs+solve(s+i,t,x-i,y).fs&&
            dp[s][t][x][y].sc<min(solve(s,t,i,y).sc,solve(s+i,t,x-i,y).sc)){
                dp[s][t][x][y].fs=solve(s,t,i,y).fs+solve(s+i,t,x-i,y).fs;
                dp[s][t][x][y].sc=min(solve(s,t,i,y).sc,solve(s+i,t,x-i,y).sc);
            }
        }
    }
    for(int i=1;i<y;i++){
        if(getsum(s,t,x,i)>=mn&&getsum(s,t+i,x,y-i)>=mn){
            if(dp[s][t][x][y].fs<solve(s,t,x,i).fs+solve(s,t+i,x,y-i).fs||
            dp[s][t][x][y].fs==solve(s,t,x,i).fs+solve(s,t+i,x,y-i).fs&&
            dp[s][t][x][y].sc<min(solve(s,t,x,i).sc,solve(s,t+i,x,y-i).sc)){
                dp[s][t][x][y].fs=solve(s,t,x,i).fs+solve(s,t+i,x,y-i).fs;
                dp[s][t][x][y].sc=min(solve(s,t,x,i).sc,solve(s,t+i,x,y-i).sc);
            }
        }
    }
    return dp[s][t][x][y];
}
signed main(){
    while(cin>>h>>w>>s&&h+w+s>0){
    rep(i,h)rep(j,w) {
        cin>>u[i][j];
        wa[i][j]=u[i][j];
        rep(x,h+1)rep(y,w+1) dp[i][j][x][y]=H{0,1000000};
    }
    rep(i,h)rep(j,w) {
        if(i>0) wa[i][j]+=wa[i-1][j];
        if(j>0) wa[i][j]+=wa[i][j-1];
        if(i>0&&j>0) wa[i][j]-=wa[i-1][j-1];
    }
    mn=wa[h-1][w-1]-s;
    cout<<solve(0,0,h,w).fs<<" "<<solve(0,0,h,w).sc<<endl;
    }
}