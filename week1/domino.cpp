#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> II;
vector<II> dominos;
int N;
int res = -1;
vector<bool> isRev;
void getSol(){
    int sumUp = 0, sumDown = 0;
    int u,v;
    for(int i=0;i<N;++i){
        u = dominos[i].first;
        v = dominos[i].second;
        if(isRev[i])swap(u,v);
        sumUp+=u;
        sumDown+=v;
    }
    if(res==-1)res = abs(sumUp-sumDown);
    res = min(res, abs(sumUp-sumDown));
}
void findSol(int pos){
    if(pos==N){
        getSol();
        return;
    }
    isRev[pos] = false;
    findSol(pos+1);
    isRev[pos] = true;
    findSol(pos+1);
}
int main(){
    ios::sync_with_stdio(0);
    freopen("1","r",stdin);
    cin>>N;
    dominos.resize(N);
    isRev.resize(N);
    for(int i=0;i<N;++i){
        cin>>dominos[i].first>>dominos[i].second;
    }
    findSol(0);
    cout<<res;
    return 0;
}
