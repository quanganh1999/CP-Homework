#include<bits/stdc++.h>

using namespace std;

int ckSum;
int n;
string res;
void findSol(int pos){
    if(pos > n){
        if(ckSum == 0)cout<<res<<"\n";
        return;
    }
    if(ckSum < 0 || ckSum > n/2)return;
    //case 1:
    res.push_back('(');
    ckSum++;
    findSol(pos+1);
    ckSum--;
    //case 2:
    res.back() = ')';
    ckSum--;
    findSol(pos+1);
    ckSum++;
    res.pop_back();
}
int main(){
    cin>>n;
    n*=2;
    ckSum = 0;
    res = "";
    findSol(1);
}
