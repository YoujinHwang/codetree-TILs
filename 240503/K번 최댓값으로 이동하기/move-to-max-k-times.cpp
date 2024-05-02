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
        
        while(!q.empty()) {
            
            pair<int,int> cur=q.front();
            q.pop();
            
            for(int i=0;i<4;i++) {
                int nx=cur.X+dx[i];
                int ny=cur.Y+dy[i];
                if(nx<1||ny<1||nx>n||ny>n) continue;
                if(arr[nx][ny]>=arr[ori_r][ori_c]) continue; //arr[nx][ny]>=arr[cur_r][cur_c]로 잘못 작성해서 오류 한참 찾음. cur_r,cur_c는 최댓값의 위치로 업데이트 되는 값이므로 이동 전의 원래 값을 기준으로 더 큰 값을 재껴야함
                if(!vis[nx][ny]) {
                    if(Max<arr[nx][ny]) {
                        Max=arr[nx][ny];
                        cur_r=nx;
                        cur_c=ny;
                    }
                    else if(Max==arr[nx][ny]) {
                        // cout<<nx<<' '<<ny<<'\n';
                        if(cur_r>nx) {
                            cur_r=nx;
                            cur_c=ny;
                        }
                        else if(cur_r==nx) {
                            if(cur_c>ny) {
                                cur_c=ny;
                                // cout<<nx<<' '<<ny<<'\n';
                            }
                        }
                    }
                    q.push({nx,ny});
                    // cout<<nx<<' '<<ny<<'\n';
                    vis[nx][ny]=1;
                   
                }
                
            }
            
        }
        if(cur_r==ori_r&&cur_c==ori_c) break;
        // cout<<cur_r<<' '<<cur_c<<'\n';
        // cout<<Max<<'\n';
        
    }
    cout<<cur_r<<' '<<cur_c;
    return 0;
}