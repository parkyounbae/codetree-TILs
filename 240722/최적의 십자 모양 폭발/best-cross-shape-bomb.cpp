#include <iostream>
#include <cstring>
using namespace std;

int n;
int arr[50][50];
int arr_copy[50][50];
int arr_gravity[50][50];
int result;

void clear_copy() {
    memmove(arr_copy, arr, sizeof(arr));
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            arr_gravity[i][j] = 0;
        }
    }
}

int check_pair() {
    int temp_result = 0;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n-1 ; j++) {
            if(arr_gravity[i][j] == arr_gravity[i][j+1] && arr_gravity[i][j]!=0) {
                temp_result++;
            }

            if(arr_gravity[j][i] == arr_gravity[j+1][i] && arr_gravity[j][i]!=0) {
                temp_result++;
            }
        }
    }
    return temp_result;
}

int bomb(int r, int c){
    int power = arr[r][c];

    arr_copy[r][c] = -1;

    if(power > 1) {
        for(int i=1 ; i<power  ; i++) {
            if(r+i < n) {
                arr_copy[r+i][c] = -1;
            }

            if(r-i >= 0) {
                arr_copy[r-i][c] = -1;
            }

            if(c+i < n) {
                arr_copy[r][c+i] = -1;
            }

            if(c-i >= 0) {
                arr_copy[r][c-i] = -1;
            }
        }
    }

    for(int i=0 ; i<n ; i++) {
        int index = n-1;
        for(int j=n-1 ; j>=0 ; j--) {
            if(arr_copy[j][i] != 0 && arr_copy[j][i] != -1) {
                arr_gravity[index--][i] = arr_copy[j][i];
            }
        }
    }

    return check_pair();

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    result = 0;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            clear_copy();
            int temp = bomb(i,j);

            // for(int i=0 ; i<n ; i++) {
            // for(int j=0 ; j<n ; j++) {
            //     cout << arr_gravity[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";


            if(result < temp) {
                result = temp;
            }
        }
    }

    cout << result << endl;

    

    return 0;
}