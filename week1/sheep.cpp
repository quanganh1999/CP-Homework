#include<bits/stdc++.h>

using namespace std;

int N, L;
int dd[9];
vector<int> setDig;
bool isFound = false;
int numDig;
vector<int> digits;
int totalNum;
void enumarate(int pos){
    if(isFound)return;
    if(pos==numDig){
        totalNum++;
        if(totalNum == N){
            isFound = true;
            for(auto val: digits)cout<<val;
        }
        return;
    }
    for(auto val: setDig){
        if(pos == 0 && val == 0)continue;
        digits[pos] = val;
        enumarate(pos+1);
    }
}
int main(){
    ios::sync_with_stdio(0);
    freopen("1","r",stdin);
    cin>>N>>L;
    int val;
    for(int i=1;i<=L;++i){
        cin>>val;
        dd[val] = 1;
    }
    for(int i=0;i<=9;++i)if(dd[i] == 0)setDig.push_back(i);
    numDig = 1;
    while(true){
        if(isFound)break;
        digits.resize(numDig);
        enumarate(0);
        numDig++;
    }
}
