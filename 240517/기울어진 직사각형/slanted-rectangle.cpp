// #include <iostream>
// int arr[20][20];
// using namespace std;
// int Max=0;
// int n;

// void find(int i,int j) {
//     int m1=min(i,n-1-j);
//     int m2=min(i,j);
//     int m3=min(n-1-i,j);
//     int m4=min(n-1-i,n-1-j);
//     if(m1==0||m2==0||m3==0||m4==0) return;
//     int l=min(m1,m3);
//     int h=min(m2,m4);
//     for(int a=1;a<=l;a++) {  //직사각형의 가로 길이
//         for(int b=1;b<=h;b++) {  //직사각형의 세로 길이
//             int sum=0;
//             int x=i,y=j; //직사각형의 가로, 세로가 각기 다른 경우의 수이므로 매번 초기화해줘야함. 인덱스 유의!!!!
//             int len=a;
//             while(len--) {
//                 x--; y++;
//                 sum+=arr[x][y];
//             }
//             int height=b;
//             while(height--) {
//                 x--; y--;
//                 sum+=arr[x][y];
//             }
//             len=a;
//             while(len--) {
//                 x++; y--;
//                 sum+=arr[x][y];
//             }
//             height=b;
//             while(height--) {
//                 x++; y++;
//                 sum+=arr[x][y];
//             }
//             Max=max(Max,sum);
//         }
//     }
// }

// int main() {
//     // 여기에 코드를 작성해주세요.
//     cin>>n;
//     for(int i=0;i<n;i++) 
//         for(int j=0;j<n;j++)
//             cin>>arr[i][j];

//     // for(int i=0;i<n;i++) {
//     //     for(int j=0;j<n;j++)
//     //         cout<<arr[i][j]<<' ';
//     //     cout<<'\n';
//     // }

//     for(int i=0;i<n;i++) {
//         for(int j=0;j<n;j++) {
//             find(i,j);
//         }
//     }
//     cout<<Max; 
//     return 0;
// }

#include <iostream>
using namespace std;
int arr[20][20];
int Max=0;
int n;

int getSum(int i, int j, int k, int l) {
    int sum=0;
    int dx[4]={-1,-1,1,1};
    int dy[4]={1,-1,-1,1};
    int move[4]={k,l,k,l};
    for(int a=0;a<4;a++) {
        for(int b=0;b<move[a];b++) {
            i+=dx[a]; //int nx=i+dx[a]; 로 해서 틀림. k만큼 인덱스가 계속 업데이트 되어야 하기 때문에 인덱스 설정을 이렇게 해야함.
            j+=dy[a]; //이 부분도 마찬가지!
            if(i<0||i>=n||j<0||j>=n) return 0;
            sum+=arr[i][j];
        }

    }
    return sum;
}

int main()
 {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) 
            cin>>arr[i][j];
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int k=1;k<n;k++) {
                for(int l=1;l<n;l++) {
                    int sum=getSum(i,j,k,l);
                    if(sum!=0) {
                        Max=max(Max,sum);
                    } 
                }
            }
        } 
            
    }
    cout<<Max;
        
 }