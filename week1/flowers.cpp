#include<bits/stdc++.h>
#define maxn 10000

using namespace std;

int height[maxn];
int main(){
    ios::sync_with_stdio(0);
    freopen("1","r",stdin);
    int n,q;
    cin>>n;
    int maxH = 0;
    for(int i=1;i<=n;++i){
        cin>>height[i];
        maxH = max(maxH, height[i]);
    }
    cin>>q;
    long long res = 0;
    for(int i=1;i<=n;++i)res+=(long long)(maxH-height[i])*q;
    cout<<res;
    return 0;
}
