#include <iostream>
using namespace std;

int map[20][20];
int ball[2][20][20];
int n,m,t;

int dir_r[4] = {-1,1,0,0};
int dir_c[4] = {0,0,-1,1};

void clear_board(int page) {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            ball[page][i][j] = 0;
        }
    }
}

void tick(int from, int to) {
    clear_board(to);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(ball[from][i][j] == 1) {
                int temp_value = 0;
                int temp_dir = 0;

                for(int k=0 ; k<4 ; k++) {
                    int next_r = i+dir_r[k];
                    int next_c = j+dir_c[k];
                    if(next_r >=0 && next_r<n && next_c >=0 && next_c<n && map[next_r][next_c] > temp_value) {
                        temp_value = map[next_r][next_c];
                        temp_dir = k;
                    }
                }

                if(ball[to][i+dir_r[temp_dir]][j+dir_c[temp_dir]] == 0) {
                    ball[to][i+dir_r[temp_dir]][j+dir_c[temp_dir]] = 1;
                } else {
                    ball[to][i+dir_r[temp_dir]][j+dir_c[temp_dir]]++;
                }
            }
        }
    }
}

int get_result(int page) {
    int result = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(ball[page][i][j] == 1) {
                result ++;
            }
        }
    }

    return result;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> t;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> map[i][j];

            ball[0][i][j] = 0;
            ball[1][i][j] = 0;
        }
    }

    for(int i=0 ; i<m ; i++) {
        int r,c;
        cin >> r >> c;
        ball[0][r-1][c-1] = 1;
    }

    for(int i=0 ; i<t ; i++) {
        tick(i%2,(i+1)%2);
    }

    cout << get_result(t%2) << endl;

    return 0;
}