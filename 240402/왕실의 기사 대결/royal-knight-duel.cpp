#include <iostream>
#include <queue>
using namespace std;

int board[41][41];
// pair<int,int> knight[31];
int ph[31];
int dmg[31];

// pair<int,int> area[31];
// #define X first;
// #define Y second;
// bool isDead[31];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
bool is_moved[31];
int nr[31],nc[31],r[31],c[31];
int h[31],w[31];
int bef_ph[31];
int l,n;

// void count(int x) {
//     int cnt=0;
//     for(int i=r;i<r+area[x].X;i++) {
//         for(int j=c;j<c+area[x].Y;j++) {
//             if(board[i][j]==1) {
//                 cnt++;
//             }
//         }
//     }
// }
bool tryMove(int idx,int dir) {
    for(int i=1;i<=n;i++) {
        dmg[i]=0;
        is_moved[i]=false;
        nr[i]=r[i];
        nc[i]=c[i];
    }
    queue<int> q;
    q.push(idx);
    is_moved[idx]=true;
    while(!q.empty()) {
        int x=q.front(); q.pop();
        nr[x]+=dx[dir];
        nc[x]+=dy[dir];

        if(nr[x]<1||nc[x]<1||nr[x]+h[x]-1>l||nc[x]+w[x]-1>l)
            return false;
        for(int i=nr[x];i<=nr[x]+h[x]-1;i++) {
            for(int j=nc[x];j<=nc[x]+w[x]-1;j++) {
                if(board[i][j]==1) dmg[x]++;
                if(board[i][j]==2) return false;
            }
        }
        
        for(int i=1;i<=n;i++) {
            if(is_moved[i]||ph[i]<=0) continue;
            if(r[i] > nr[x] + h[x] - 1 || nr[x] > r[i] + h[i] - 1) //이부분 주의-기사의 젤 윗부분이 움직이는 기사의 맨 아랫부분보다 아래인지/움직이는 기사의 맨 윗부분이 원래 기사의 맨 아래보다 아래인지
                continue;
            if(c[i] > nc[x] + w[x] - 1 || nc[x] > c[i] + w[i] - 1) //주의-
                continue;
            is_moved[i]=true;
            q.push(i);
        }
    }
    dmg[idx]=0; //명령받은 기사는 데미지 안입음
    return true;
}

void Move(int idx, int dir) {
    if(ph[idx]<=0) return;
    if(tryMove(idx,dir)) {
        for(int i=1;i<=n;i++) {
            r[i]=nr[i];
            c[i]=nc[i];
            ph[i]-=dmg[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int q;
    cin>>l>>n>>q;
    for(int i=1;i<=l;i++) {
        for(int j=1;j<=l;j++) {
            cin>>board[i][j];
        }
    }
    
    for(int i=1;i<=n;i++) {
        cin>>r[i]>>c[i]>>h[i]>>w[i]>>ph[i];
        bef_ph[i]=ph[i];
    }
    int idx,dir;
    while(q--) {
        cin>>idx>>dir;
        Move(idx,dir);
    }
    long long ans=0;
    for(int i=1;i<=n;i++) {
        if(ph[i]>0) ans+= bef_ph[i]-ph[i];
    }
    cout<<ans;
    
    return 0;
}