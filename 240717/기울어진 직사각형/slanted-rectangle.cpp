#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[21][21];
int dir_r[4] = {-1, -1 ,1, 1};
int dir_c[4] = {1,-1,-1,1};
int result;

void check(int r, int c, int current_r, int current_c, int move_1, int move_2,int dir, int amount) {
    if(current_c < 0 || current_r <0 || current_c >=n || current_r >= n) {
        return;
    }

    if(dir == 3) {
        // 값 결정 가능
        // 일단 1만큼 3번 위치에서 움직였을때 유효한 위치인지 확인.
        if(current_r+move_1 >= n || current_c-move_1 < 0) {
            return;
        }

        int temp = amount;

        for(int i=0 ; i<move_1 ; i++) {
            temp += arr[current_r+i][current_c-i];
        }

        for(int i=0 ; i<move_2 ; i++) {
            temp += arr[current_r+i][current_c+i];
        }

        if(temp > result) {
            result = temp;
        }
    }

    if(dir == 1) {
        check(r,c,current_r-1, current_c+1, move_1 + 1, move_2,1,amount+arr[current_r][current_c]);
        check(r,c,current_r-1, current_c-1, move_1, move_2+1,2,amount+arr[current_r][current_c]);
    } else if(dir == 2) {
        check(r,c,current_r-1, current_c-1, move_1, move_2+1,2,amount+arr[current_r][current_c]);
        check(r,c,current_r, current_c, move_1, move_2,3,amount);
    }


}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    result = 0;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            check(i,j,i-1,j+1,1,0,1,0);
        }
    }

    cout << result << endl;


    return 0;
}