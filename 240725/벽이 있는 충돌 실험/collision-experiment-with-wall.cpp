#include <iostream>
using namespace std;

int t, n, m;
int arr[2][50][50];
int compare_board[50][50];

int dir_r[5] = {0,-1,1,0,0};
int dir_c[5] = {0,0,0,-1,1};

void clear_board(int page) {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            arr[page][i][j] = 0;
        }
    }
}

int get_result(int page) {
    int result = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(1<=arr[page][i][j] && arr[page][i][j]<=4) {
                result ++ ;
            }
        }
    }

    return result;
}

void update_board(int page) {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            compare_board[i][j] = arr[page][i][j];
        }
    }
}

bool check_board(int page) {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(compare_board[i][j] != arr[page][i][j]) {
                return false;
            }
        }
    }
    return true;
}

void tick(int from, int to) {
    clear_board(to);
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(1<=arr[from][i][j] && arr[from][i][j]<=4) {
                int next_r = i + dir_r[arr[from][i][j]];
                int next_c = j + dir_c[arr[from][i][j]];
                int next_dir = arr[from][i][j];

                if(next_r < 0) {
                    next_dir = 2;
                    next_r = next_r + 1;
                } else if (next_r >= n) {
                    next_dir = 1;
                    next_r = next_r - 1;
                } else if (next_c < 0) {
                    next_dir = 4;
                    next_c = next_c + 1;
                } else if (next_c >= n) {
                    next_dir = 3;
                    next_c = next_c - 1;
                }

                if(arr[to][next_r][next_c] == 0) {
                    arr[to][next_r][next_c] = next_dir;
                } else {
                    arr[to][next_r][next_c] = 6;
                }
            }
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> t;
    for(int test_case = 0 ; test_case<t ; test_case++) {
        clear_board(0);
        clear_board(1);
        cin >> n >> m;

        for(int i=0 ; i<m ; i++) {
            int r,c;
            char dir;
            cin >> r >> c >> dir;

            if(dir == 'U') {
                arr[0][r-1][c-1] = 1;
            } else if(dir == 'D') {
                arr[0][r-1][c-1] = 2;
            } else if(dir == 'L') {
                arr[0][r-1][c-1] = 3;
            } else {
                arr[0][r-1][c-1] = 4;
            }
        }

        bool is_stop = false;
        update_board(0);

        for(int i=1 ; !is_stop ; i++) {
            tick((i+1)%2, i%2);

//            cout << "t_Case : " << test_case << ", time : " << i << endl;
//            for(int j=0 ; j<n ; j++) {
//                for(int k=0 ; k<n ; k++) {
//                    cout << arr[i%2][j][k] << " ";
//                }
//                cout << endl;
//            }

            if(i%(n*2) == 0) {
                is_stop = check_board(i%2);

                if(!is_stop) {
                    update_board(i%2);
                }
            }
        }

        cout << get_result(0) << endl;
    }
    return 0;
}