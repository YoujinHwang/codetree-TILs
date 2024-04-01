// #include <iostream>
// #include <cmath>
// #include <tuple>
// using namespace std;
// // pair<int,int> pos[31];
// #define X first
// #define Y second
// bool rest[31];
// int arr[51][51];
// int dis[31];
// vector<tuple<int,int,int>> pos;
// int dx[8]=[1,-1,0,0,-1,-1,1,1];
// int dy[8]=[0,0,1,-1,-1,1,-1,1];

// int getDis(pair<int,int> x, pair<int,int> y) {
//     return pow(x.X-y.X,2)+pow(x.Y-y.Y,2);
// }

// int main() {
//     int n,m,p,c,d;
//     cin>>n>>m>>p>>c>>d;
//     int r_x,c_y;
//     cin>>r_x>>c_y;
//     arr[r_x][c_y]=2; //루돌프 위치
//     for(int i=1;i<=p;i++) {
//         int idx,x,y,d;
//         cin>>idx>>x>>y;
//         arr[x][y]=1; //산타 위치
//         d=getDis({x,y},{r_x,c_y});
//         tuple<int,int,int> tup=make_tuple(d,x,y);
//         pos.push_back(tup);
//         tie(d,x,y)=tup;
//         // cout<<d<<' '<<x<<' '<<y<<'\n';

//     }
//     sort(pos.begin(),pos.end());
//     int mind=5000;
//     while(m--) {
//         for(int i=0;i<8;i++) {
//             int nx=r_x+dx[i];
//             int ny=r_y+dy[i];
//             if(nx<=0||ny<=0||nx>n||ny>n) continue;
//             int dist=getDis({nx,ny},pos[0]);
//             if(mind>dist) {
//                 mind=dist;

//             }
//             mind=min(mind,getDis({nx,ny},pos[0]));
//         }
//     }



//     return 0;
// }

#include <iostream>

using namespace std;

#define MAX_N 51
#define MAX_P 31

int n, m, p, c, d;
int points[MAX_P];
pair<int, int> pos[MAX_P];
pair<int, int> rudolf;

int board[MAX_N][MAX_N];
bool is_live[MAX_P];
int stun[MAX_P];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

bool is_inrange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int main() {
    cin >> n >> m >> p >> c >> d; 
    cin >> rudolf.first >> rudolf.second;
    board[rudolf.first][rudolf.second] = -1;  

    for(int i = 1; i <= p; i++) {
        int id;
        cin >> id;
        cin >> pos[id].first >> pos[id].second;
        board[pos[id].first][pos[id].second] = id; 
        is_live[id] = true;  
    }

    for(int t = 1; t <= m; t++) {
        int closestX = 10000, closestY = 10000, closestIdx = 0;

        for(int i = 1; i <= p; i++) {
            if(!is_live[i]) continue;

            pair<int, pair<int, int>> currentBest = { (closestX - rudolf.first) * (closestX - rudolf.first) + (closestY - rudolf.second) * (closestY - rudolf.second), {-closestX, -closestY}};
            pair<int, pair<int, int>> currentValue = {(pos[i].first - rudolf.first) * (pos[i].first - rudolf.first) + (pos[i].second - rudolf.second) * (pos[i].second - rudolf.second), {-pos[i].first, -pos[i].second}};
            
            if(currentValue < currentBest) {
                closestX = pos[i].first;
                closestY = pos[i].second;
                closestIdx = i;
            }
        }

        
        if(closestIdx) {
            pair<int, int> prevRudolf = rudolf;
            int moveX = 0;
            if(closestX > rudolf.first) moveX = 1;
            else if(closestX < rudolf.first) moveX = -1;

            int moveY = 0;
            if(closestY > rudolf.second) moveY = 1;
            else if(closestY < rudolf.second) moveY = -1;

            rudolf.first += moveX;
            rudolf.second += moveY;
            board[prevRudolf.first][prevRudolf.second] = 0;

            if(rudolf.first == closestX && rudolf.second == closestY) {
                int firstX = closestX + moveX * c;
                int firstY = closestY + moveY * c;
                int lastX = firstX;
                int lastY = firstY;

                stun[closestIdx] = t + 1;

                while(is_inrange(lastX, lastY) and board[lastX][lastY] > 0) {
                    lastX += moveX;
                    lastY += moveY;
                }
                
                while(!(lastX == firstX and lastY == firstY)) {
                    int beforeX = lastX - moveX;
                    int beforeY = lastY - moveY;

                    if(!is_inrange(beforeX, beforeY)) break;

                    int idx = board[beforeX][beforeY];

                    if(!is_inrange(lastX, lastY)) {
                        is_live[idx] = false;
                    }
                    else {
                        board[lastX][lastY] = board[beforeX][beforeY];
                        pos[idx] = {lastX, lastY};
                    }

                    lastX = beforeX;
                    lastY = beforeY;
                }

                points[closestIdx] += c;
                pos[closestIdx] = {firstX, firstY};
                if(is_inrange(firstX, firstY)) {
                    board[firstX][firstY] = closestIdx;
                }
                else {
                    is_live[closestIdx] = false;
                }
            }
        }

        board[rudolf.first][rudolf.second] = -1;

        for(int i = 1; i <= p; i++) {
            if(!is_live[i] || stun[i] >= t) continue;

            int minDist = (pos[i].first - rudolf.first) * (pos[i].first - rudolf.first) + (pos[i].second - rudolf.second) * (pos[i].second - rudolf.second);
            int moveDir = -1;
            
            for(int dir = 0; dir < 4; dir++) {
                int nx = pos[i].first + dx[dir];
                int ny = pos[i].second + dy[dir];
                
                if(!is_inrange(nx, ny) || board[nx][ny] > 0) continue;

                int dist = (nx - rudolf.first) * (nx - rudolf.first) + (ny - rudolf.second) * (ny - rudolf.second);
                if(dist < minDist) {
                    minDist = dist;
                    moveDir = dir;
                }
            }

            if(moveDir != -1) {
                int nx = pos[i].first + dx[moveDir];
                int ny = pos[i].second + dy[moveDir];

        
                if(nx == rudolf.first && ny == rudolf.second) {
                    stun[i] = t + 1;

                    int moveX = -dx[moveDir];
                    int moveY = -dy[moveDir];

                    int firstX = nx + moveX * d;
                    int firstY = ny + moveY * d;
                    int lastX = firstX;
                    int lastY = firstY;

                    if(d == 1) {
                        points[i] += d;
                    }
                    else {
                    
                        while(is_inrange(lastX, lastY) and board[lastX][lastY] > 0) {
                            lastX += moveX;
                            lastY += moveY;
                        }

                        
                        while(!(lastX == firstX and lastY == firstY)) {
                            int beforeX = lastX - moveX;
                            int beforeY = lastY - moveY;

                            if(!is_inrange(beforeX, beforeY)) break;

                            int idx = board[beforeX][beforeY];

                            if(!is_inrange(lastX, lastY)) {
                                is_live[idx] = false;
                            }
                            else {
                                board[lastX][lastY] = board[beforeX][beforeY];
                                pos[idx] = {lastX, lastY};
                            }

                            lastX = beforeX;
                            lastY = beforeY;
                        }

                        points[i] += d;
                        board[pos[i].first][pos[i].second] = 0;
                        pos[i] = {firstX, firstY};
                        if(is_inrange(firstX, firstY)) {
                            board[firstX][firstY] = i;
                        }
                        else {
                            is_live[i] = false;
                        }
                    }
                }
                else {
                    board[pos[i].first][pos[i].second] = 0;
                    pos[i] = {nx, ny};
                    board[nx][ny] = i;
                }
            }
        }

        for(int i = 1; i <= p; i++) 
            if(is_live[i]) points[i]++;
    }

    for(int i = 1; i <= p; i++) 
        cout << points[i] << " ";
}