#include<bits/stdc++.h>

using namespace std;

int a[9][9];
int dd[9];
int dig1[20];
int dig2[20];
int sumMax = 0;
int curSum = 0;
void findSum(int pos){
    if(pos == 9){
        sumMax = max(sumMax, curSum);
        return;
    }
    for(int i=1;i<=8;++i)if(dd[i]==0 && dig1[pos - i + 8]==0 && dig2[pos+i]==0){
        curSum += a[pos][i];
        dd[i] = 1;
        dig1[pos-i+8] = 1;
        dig2[pos+i] = 1;
        findSum(pos+1);
        dd[i] = 0;
        dig1[pos-i+8] = 0;
        dig2[pos+i] = 0;
        curSum -= a[pos][i];
    }
}
int main(){
    //freopen("1","r",stdin);
    ios::sync_with_stdio(0);
    for(int i=1;i<=8;++i)
        for(int j=1;j<=8;++j)cin>>a[i][j];
    findSum(1);
    cout<<sumMax;
    return 0;
}
