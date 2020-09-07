#include<bits/stdc++.h>

using namespace std;

int n,k;
int sol[20];
bool used[20];
int arr[20];
int sumK;
int curSum = 0;
void ckSol(){
    int ckSum = 0;
    for(int i=1;i<=n;++i){
        ckSum += sol[i];
        cout<<sol[i]<<" ";
        if(ckSum == sumK){
            ckSum = 0;
            cout<<"\n";
        }
    }
    exit(0);
}
void findSol(int pos){
    if(pos > n && curSum == sumK){
        ckSol();
        return;
    }
    if(curSum > sumK) return;
    bool isChanged = false;
    if(curSum == sumK){
        curSum = 0;
        isChanged = true;
    }
    for(int i=1;i<=n;i++)if(!used[i]){
        sol[pos] = arr[i];
        used[i] = true;
        curSum += arr[i];
        findSol(pos+1);
        curSum -= arr[i];
        used[i] = false;
    }
    if(isChanged) curSum = sumK;
}
int main() {
    freopen("1","r",stdin);
    ios::sync_with_stdio(0);
    cin>>n>>k;
    int sum = 0;
    for(int i=1;i<=n;++i){
        used[i] = false;
        cin>>arr[i];
        sum += arr[i];
    }
    sort(arr+1, arr+n+1);
    if(sum%k==0){
        sumK = sum/k;
        findSol(1);
    }
    return 0;
}
