#include <iostream>
using namespace std;

int m,n;
int arr[101][101];
int check[101];

int check_garo(int index) {
    int current_num = arr[index][0];
    int count = 1;

    for(int i=1 ; i<n ; i++) {
        if(current_num == arr[index][i]) {
            count ++;
        } else {
            current_num = arr[index][i];
            count = 1;
        }
        if(count >= m) {
            return 1;
        }
    }
    return 0;
}

int check_sero(int index) {

    int current_num = arr[0][index];
    int count = 1;

    for(int i=1 ; i<n ; i++) {
        if(current_num == arr[i][index]) {
            count ++;
        } else {
            current_num = arr[i][index];
            count = 1;
        }
        if(count >= m) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 0;

    for(int i=0 ; i<n ; i++) {
        result += check_garo(i);
        result += check_sero(i);
    }

    cout << result << endl;

    return 0;
}