#include <iostream>
using namespace std;

int n,m,r,c;
int arr[101][101];

int dice[6] = {6,3,1,4,2,5};

void U() {
    int temp = dice[5];

    dice[5] = dice[2];
    dice[2] = dice[4];
    dice[4] = dice[0];
    dice[0] = temp;
}

void D() {
    int temp = dice[4];

    dice[4] = dice[2];
    dice[2] = dice[5];
    dice[5] = dice[0];
    dice[0] = temp;
}

void L() {
    int temp = dice[3];

    dice[3] = dice[2];
    dice[2] = dice[1];
    dice[1] = dice[0];
    dice[0] = temp;
}

void R() {
    int temp = dice[1];

    dice[1] = dice[2];
    dice[2] = dice[3];
    dice[3] = dice[0];
    dice[0] = temp;
}


bool check(int a, int b) {
    if(a<=0 || a>n || b<=0 || b>n ) {
        return false;
    } else {
        return true;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> r >> c;

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            arr[i][j] = 0;
        }
    }

    int current_r = r;
    int current_c = c;
    int current_num = 6;
    char command;

    int result = 6;
    arr[r][c] = 6;

    for(int i=0 ; i<m ; i++) {
        cin >> command;
        if(command == 'U' && check(current_r-1, current_c)) {
             current_r--;
             if(arr[current_r][current_c] != 0) {
                 result -= arr[current_r][current_c];
             }
             U();
             current_num = dice[0];
             arr[current_r][current_c] = current_num;
             result += current_num;
        } else if(command == 'D' && check(current_r+1, current_c)) {
            current_r++;
            if(arr[current_r][current_c] != 0) {
                result -= arr[current_r][current_c];
            }
            D();
            current_num = dice[0];
            arr[current_r][current_c] = current_num;
            result += current_num;
        } else if(command == 'L' && check(current_r, current_c-1)) {
            current_c--;
            if(arr[current_r][current_c] != 0) {
                result -= arr[current_r][current_c];
            }
            L();
            current_num = dice[0];
            arr[current_r][current_c] = current_num;
            result += current_num;
        } else if (command == 'R' && check(current_r, current_c+1)){
            current_c++;
            if(arr[current_r][current_c] != 0) {
                result -= arr[current_r][current_c];
            }
            R();
            current_num = dice[0];
            arr[current_r][current_c] = current_num;
            result += current_num;
        }
    }

    


    cout << result << endl;

    return 0;
}