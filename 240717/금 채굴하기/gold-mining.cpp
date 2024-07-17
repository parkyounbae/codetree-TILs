#include <iostream>
using namespace std;

int n,m;
int arr[21][21];
int max_k;

bool check_boundry(int r, int c) {
    return r >= 0 && c >= 0 && r<n && c<n;
}

int check_point(int r, int c) {
    int gold = 0;
    int result = 0;

    if(arr[r][c] == 1) {
        gold = 1;
        result = 1;
    }

    if(max_k >= 1) {
        int temp_gold = 0;
        int up_r = r-1;
        int down_r = r+1;
        int left_c = c-1;
        int right_c = c+1;

        if(check_boundry(up_r,c) && arr[up_r][c] == 1) {
            temp_gold++;
        }

        if(check_boundry(r, left_c) && arr[r][left_c] == 1) {
            temp_gold++;
        }

        if(check_boundry(r, right_c) && arr[r][right_c] == 1) {
            temp_gold++;
        }

        if(check_boundry(down_r, c) && arr[down_r][c] == 1) {
            temp_gold++;
        }
        gold += temp_gold;
        if(gold*m >= 5) {
            result = gold;
        }
    }

    for(int k=2 ; k<=max_k ; k++) {
        int temp_gold = 0;
        int up_r = r-k;
        int down_r = r+k;
        int left_c = c-k;
        int right_c = c+k;
        int cost = k*k + (k+1)*(k+1);

        if(check_boundry(up_r,c) && arr[up_r][c] == 1) {
            temp_gold++;
        }

        if(check_boundry(r, left_c) && arr[r][left_c] == 1) {
            temp_gold++;
        }

        if(check_boundry(r, right_c) && arr[r][right_c] == 1) {
            temp_gold++;
        }

        if(check_boundry(down_r, c) && arr[down_r][c] == 1) {
            temp_gold++;
        }

        for(int i=1 ; i<k ; i++) {
            if(check_boundry(up_r+i,c+i) && arr[up_r+i][c+i] == 1) {
                temp_gold++;
            }

            if(check_boundry(up_r+i,c-i) && arr[up_r+i][c-i] == 1) {
                temp_gold++;
            }

            if(check_boundry(down_r-i,c+i) && arr[down_r-i][c+i] == 1) {
                temp_gold++;
            }

            if(check_boundry(down_r-i,c-i) && arr[down_r-i][c-i] == 1) {
                temp_gold++;
            }
        }

        gold += temp_gold;
        if(gold*m >= cost) {
            result = gold;
        }

    }



    return result;

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    int total_gold = 0;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
            if(arr[i][j]) {
                total_gold++;
            }
        }
    }

    int total_point = total_gold*m;
    max_k = 0;
    while(true) {
        int temp_k = max_k+1;
        if(temp_k*temp_k + (temp_k+1)*(temp_k+1) > total_point) {
            break;
        } else {
            max_k ++;
        }
    }

    int max_point = 0;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            int temp_point = check_point(i,j);
            if(max_point < temp_point) {
                max_point = temp_point;
            }
        }
    }

    
    cout << max_point << endl;

    return 0;
}