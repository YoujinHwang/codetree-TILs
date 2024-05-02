#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int arr[101][101];
bool isPos;
queue<pair<int,int>> q;

int vis[101][101];

int main() {
    // 여기에 코드를 작성해주세요.
    int n,k,r,c;
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>arr[i][j];
        }
    }
    cin>>r>>c;
    int cur_r=r;
    int cur_c=c;
    while(k--){
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                vis[i][j]=0;
            }
        }
        int ori_r=cur_r;
        int ori_c=cur_c;

        int Max=0;
        q.push({cur_r,cur_c});
        vis[cur_r][cur_c]=1;
        bool Moved=false;
        while(!q.empty()) {
            isPos=false;
            pair<int,int> cur=q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int nx=cur.X+dx[i];
                int ny=cur.Y+dy[i];
                if(nx<1||ny<1||nx>n||ny>n) continue;
                if(arr[nx][ny]>=arr[cur_r][cur_c]) continue;
                if(!vis[nx][ny]) {
                    if(Max<arr[nx][ny]) {
                        Max=arr[nx][ny];
                        cur_r=nx;
                        cur_c=ny;
                    }
                    else if(Max==arr[nx][ny]) {
                        if(cur_r>nx) {
                            cur_r=nx;
                        }
                        else if(cur_r==nx) {
                            if(cur_c>ny) {
                                cur_c=ny;
                            }
                        }
                    }
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                    Moved=true;
                }
                //isPos=true;
                
            }
            // if(!isPos) {
            //     r=cur.X;
            //     c=cur.Y;
            // }
        }
        if(!Moved) break;
        
    }
    cout<<cur_r<<' '<<cur_c;
    return 0;
}