#include <iostream>
using namespace std;
int arr[20][20];
int coin(int r,int c) {
    int cnt=0;
    for(int i=r;i<r+3;i++) {
        for(int j=c;j<c+3;j++) {
            if(arr[i][j]==1) cnt++;
        }
    }
    return cnt;
}
int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    int Max=0;
    cin>>n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<=n-3;i++) {
        for(int j=0;j<=n-3;j++) {
            int num=coin(i,j);
            Max=max(num,Max);
        }
    }
    cout<<Max;
    return 0;
}