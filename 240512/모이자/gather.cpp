#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int arr[100];


int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int Min=INT_MAX;
    for(int i=0;i<n;i++) {
        int sum=0;
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            int k=abs(j-i);
            sum+=arr[j]*k;
        }
        Min=min(Min,sum);
    }
    cout<<Min;
    return 0;
}