#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int numD = 0;
    int valK = k;
    while(valK){
        numD++;
        valK /= 10;
    }
    if(numD > n)cout<<"NO";else
    if(numD == n)cout<<k;else
    {
        long long minNum = 1;
        for(int i=1;i<n;++i)minNum*=10;
        if(minNum%k == 0)cout<<minNum;
        else cout<<(long long)(minNum/k+1)*k;
    }
    return 0;
}
