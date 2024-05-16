#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[200][200];
int Max=0;


int rec1(int a,int b) {
    int sum=0;
    vector<int> v;
    for(int i=a;i<a+2;i++) {
        for(int j=b;j<b+2;j++) {
            v.push_back(arr[i][j]);
        }
    }
    sort(v.begin(),v.end());
    for (int i=1;i<v.size();i++) {
        sum+=v[i];
    }
    return sum;
}

int rec2(int a,int b) {
    int sum=0;
    for(int i=b;i<b+3;i++) {
        sum+=arr[a][i];
    }
    return sum;
}
int rec3(int a,int b) {
    int sum=0;
    for(int i=b;i<b+3;i++) {
        sum+=arr[i][b];
    }
    return sum;
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    int Sum=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<m-1;j++) {
            Sum=rec1(i,j);
            Max=max(Max,Sum);
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m-2;j++) {
            Sum=rec2(i,j);
            Max=max(Max,Sum);
        }
    }
    for(int i=0;i<n-2;i++) {
        for(int j=0;j<m;j++) {
            Sum=rec2(i,j);
            Max=max(Max,Sum);
        }
    }
    cout<<Max;
    return 0;
}