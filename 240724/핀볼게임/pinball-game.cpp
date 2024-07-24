#include <iostream>
using namespace std;

int n;
int arr[101][101];

int dir_r[4] = {-1, 1, 0, 0};
int dir_c[4] = {0,0,-1,1};
int check[100][100];

int result = 0;

void clear_check() {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            check[i][j] = 0;
        }
    }
}

int pin_ball(int start_r, int start_c, int start_dir) {
    int time = 0;
    int current_r = start_r;
    int current_c = start_c;
    int current_dir = start_dir;
    clear_check();
    while(true) {
        
        time++;
        current_r = current_r + dir_r[current_dir];
        current_c = current_c + dir_c[current_dir];

        if(current_r<0 || current_r>=n || current_c<0 || current_c>=n) {
            break;
        }

        if(arr[current_r][current_c] == 1) {
            if(check[current_r][current_c] == 2) {
                return -1;
            } else {
                check[current_r][current_c] ++;
            }
            if(current_dir == 0) {
                current_dir =3;
            } else if(current_dir == 1) {
                current_dir =2;
            } else if(current_dir == 2) {
                current_dir =1;
            } else if(current_dir == 3) {
                current_dir =0;
            }
        } else if(arr[current_r][current_c] == 2) {
            if(check[current_r][current_c] == 2) {
                return -1;
            } else {
                check[current_r][current_c] ++;
            }
            if(current_dir == 0) {
                current_dir =2;
            } else if(current_dir == 1) {
                current_dir =3;
            } else if(current_dir == 2) {
                current_dir =0;
            } else if(current_dir == 3) {
                current_dir =1;
            }
        }
    }

    return time;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0 ; i<4 ; i++) {
        for(int j=0 ; j<n ; j++) {

        }
    }

    for(int i=0 ; i<n ; i++) {
        int temp = pin_ball(0,i,1);

        if(temp > result) {
            result = temp;
        }

        int temp2 = pin_ball(i,0,3);

        if(temp2 > result) {
            result = temp2;
        }

        int temp3 = pin_ball(n, i, 0);

        if(temp3 > result) {
            result = temp3;
        }

        int temp4 = pin_ball(i,n,2);

        if(temp4 > result) {
            result = temp4;
        }
    }

    cout << result << endl;


    return 0;
}