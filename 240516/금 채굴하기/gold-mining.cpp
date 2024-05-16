#include <iostream>
#include <queue>
int arr[20][20];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
#define X first 
#define Y second
int dist[20][20];
using namespace std;
int Max=0;
int n,m;

int bfs(int i,int j,int k) {
    int num=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist[i][j]=-1;
        }
    }
    queue<pair<int,int>> q;
    q.push({i,j});
    dist[i][j]=0;
    if(arr[i][j]==1) num++;
    while(!q.empty()) {
        pair<int,int> cur=q.front();
        q.pop();
        if(dist[cur.X][cur.Y]==k)break;
        for(int idx=0;idx<4;idx++) {
            int nx=cur.X+dx[idx];
            int ny=cur.Y+dy[idx];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(dist[nx][ny]!=-1) continue;
            if(arr[nx][ny]==1) {
                num++;
            }
            q.push({nx,ny});
            dist[nx][ny]=dist[cur.X][cur.Y]+1;

        }
    }
    return num; //num: 채굴한 금 개수
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    int cnt=0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            if(arr[i][j]==1) cnt++;
        }
    }
    // int money=cnt*m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int k=2*(n-1);
            while(k>=0) {
                int cost=k*k+(k+1)*(k+1);
                int num=bfs(i,j,k--);
                int res=num*m-cost;
                if(res>=0) {
                    Max=max(num,Max);
                    break;
                }
            }
        }
    }
    cout<<Max;
    return 0;
}