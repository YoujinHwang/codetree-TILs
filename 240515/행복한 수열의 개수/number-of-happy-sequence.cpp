#include <iostream>
using namespace std;
int arr[100][100];

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    int ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) 
            cin>>arr[i][j];

    for(int i=0;i<n;i++) {
        int cnt=1;
        for(int j=1;j<n;j++) {
            if(arr[i][j]==arr[i][j-1]) {
                cnt++;
            }
            else cnt=1;
            if(cnt==m) {
                ans++;
                break;
            }
        }
        cnt=1;
        for(int j=1;j<n;j++) {
            if(arr[j][i]==arr[j-1][i]) {
                cnt++;
            }
            else cnt=1;
            if(cnt==m) {
                ans++;
                break;
            }
        }

    }
    cout<<ans;
    return 0;
}