#include<bits/stdc++.h>

using namespace std;

vector<int> digits;
int n;
long long findMin(int sumDig){
    int curSum = sumDig;
    digits.clear();
    for(int i=1;i<=n;++i){
        for(int j=0;j<=9;++j){
            if(i==1&&j==0)continue;
            if(curSum < j)continue;
            if(curSum - j > 9*(n-i))continue;
            curSum -= j;
            digits.push_back(j);
            break;
        }
    }
    long long res= 0;
    for(auto val: digits)res = res*10 + val;
    return res;
}

long long findMax(int sumDig){
    int curSum = sumDig;
    digits.clear();
    for(int i=1;i<=n;++i){
        for(int j=9;j>=0;--j){
            if(i==1&&j==0)continue;
            if(curSum < j)continue;
            if(curSum - j > 9*(n-i))continue;
            curSum -= j;
            digits.push_back(j);
            break;
        }
    }
    long long res= 0;
    for(auto val: digits)res = res*10 + val;
    return res;
}
int main() {
    ios::sync_with_stdio(0);
    cin>>n;
    long long res = 0LL;
    long long numMin,numMax;
    if(n!=1){
        for(int i=1;i<=n*9;i++){
            if(res < findMax(i) - findMin(i)){
                res = findMax(i) - findMin(i);
                numMin = findMin(i);
                numMax = findMax(i);
            }
        }
    }
    cout<<res<<" "<<numMin<<" "<<numMax;
    return 0;
}
