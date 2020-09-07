#include<bits/stdc++.h>

using namespace std;

char sol[30];
int n;
void printSol(){
    for(int i=1;i<=n;++i)cout<<sol[i];
    cout<<"\n";
}
void findSol(int pos){
    if(pos>n){printSol();return;}
    sol[pos] = 'A';
    findSol(pos+1);
    if(pos > 1 && sol[pos-1]== 'B')return;
    sol[pos] = 'B';
    findSol(pos+1);
}
int main() {
    ios::sync_with_stdio(0);
    cin>>n;
    findSol(1);
    return 0;
}
