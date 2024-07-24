#include <iostream>

using namespace std;

int n,m,k;
int arr[101][101];

int current_head_r = 1;
int current_head_c = 1;

int current_tail_r = 1;
int current_tail_c = 1;

// 1:up 2:down 3:left 4:right 5:head 6:apple
int dir_r[5] = {0,-1,1,0,0};
int dir_c[5] = {0,0,0,-1,1};

bool is_alive = true;

int up(int distance) {
    int time = 0;
    for(int i=0 ; i<distance ; i++) {
        if(current_head_r-1 <= 0) {
            is_alive = false;
            time++;
            return time;
        }

        arr[current_head_r][current_head_c] = 1;
        current_head_r--;
        if(arr[current_head_r][current_head_c] != 6) {
            int dir = arr[current_tail_r][current_tail_c];
            arr[current_tail_r][current_tail_c] = 0;

            current_tail_r += dir_r[dir];
            current_tail_c += dir_c[dir];
        }
        if(1<=arr[current_head_r][current_head_c] && arr[current_head_r][current_head_c]<=4) {
            is_alive = false;
            time++;
            return time;
        }
        arr[current_head_r][current_head_c] = 5;
        time++;
    }
    return time;
}

int down(int distance) {
    int time = 0;
    for(int i=0 ; i<distance ; i++) {
        if(current_head_r+1 > n) {
            is_alive = false;
            time++;
            return time;
        }

        arr[current_head_r][current_head_c] = 2;
        current_head_r++;
        if(arr[current_head_r][current_head_c] != 6) {
            int dir = arr[current_tail_r][current_tail_c];
            arr[current_tail_r][current_tail_c] = 0;

            current_tail_r += dir_r[dir];
            current_tail_c += dir_c[dir];
        }
        if(1<=arr[current_head_r][current_head_c] && arr[current_head_r][current_head_c]<=4) {
            is_alive = false;
            time++;
            return time;
        }
        arr[current_head_r][current_head_c] = 5;
        time++;
    }
    return time;
}

int left(int distance) {
    int time = 0;
    for(int i=0 ; i<distance ; i++) {
        if(current_head_c-1 <= 0) {
            is_alive = false;
            time++;
            return time;
        }

        arr[current_head_r][current_head_c] = 3;
        current_head_c--;
        if(arr[current_head_r][current_head_c] != 6) {
            int dir = arr[current_tail_r][current_tail_c];
            arr[current_tail_r][current_tail_c] = 0;

            current_tail_r += dir_r[dir];
            current_tail_c += dir_c[dir];
        }
        if(1<=arr[current_head_r][current_head_c] && arr[current_head_r][current_head_c]<=4) {
            is_alive = false;
            time++;
            return time;
        }
        arr[current_head_r][current_head_c] = 5;
        time++;
    }
    return time;
}

int right(int distance) {
    int time = 0;
    for(int i=0 ; i<distance ; i++) {
        if(current_head_c+1 > n) {
            is_alive = false;
            time++;
            return time;
        }

        arr[current_head_r][current_head_c] = 4;
        current_head_c++;
        if(arr[current_head_r][current_head_c] != 6) {
            int dir = arr[current_tail_r][current_tail_c];
            arr[current_tail_r][current_tail_c] = 0;

            current_tail_r += dir_r[dir];
            current_tail_c += dir_c[dir];
        }
        if(1<=arr[current_head_r][current_head_c] && arr[current_head_r][current_head_c]<=4) {
            is_alive = false;
            time++;
            return time;
        }
        arr[current_head_r][current_head_c] = 5;
        time++;
    }
    return time;
}


int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            arr[i][j] = 0;
        }
    }

    arr[0][0] = 5;

    for(int i=0 ; i<m ; i++) {
        int x,y;
        cin >> x >> y;
        arr[x][y] = 6;
    }

    int result = 0;

    for(int i=0 ; i<k && is_alive ; i++) {
        char command;
        int distance;
        cin >> command >> distance;

        if(command == 'U') {
            result += up(distance);
        } else if(command == 'D') {
            result += down(distance);
        } else if (command == 'L') {
            result += left(distance);
        } else if(command == 'R') {
            result += right(distance);
        }
//        cout << command << " " << distance << endl;
//        cout << current_head_r << " " << current_head_c << endl;
//        for(int j=1 ; j<=n ; j++) {
//            for(int l=1 ; l<=n ; l++) {
//                cout << arr[j][l] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
    }


    cout << result << endl;
    return 0;
}