#include<bits/stdc++.h>

using namespace std;

map<string, bool> isExist;
string val;
string S;
void printSol(){
    if(val != "" && !isExist[val]){
        cout<<val<<"\n";
        isExist[val] = true;
    }
}
void findSol(int pos){
    if(pos == S.size()){
        printSol();
        return;
    }
    val.push_back(S[pos]);
    findSol(pos + 1);
    val.pop_back();
    findSol(pos + 1);
}
int main(){
    freopen("1","r",stdin);
    ios::sync_with_stdio(0);
    cin>>S;
    val = "";
    findSol(0);
    return 0;
}
