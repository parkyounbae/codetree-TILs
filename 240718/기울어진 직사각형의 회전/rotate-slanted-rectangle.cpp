#include <iostream>
using namespace std;

int n;
int arr[101][101];

void move1(int r, int c, int m1, int m2, int m3, int m4) {
    int index_r = r;
    int index_c = c;

    int temp1 = arr[index_r-m1][index_c+m1];
    for(int i=m1 ; i>0 ; i--) {
        arr[index_r-i][index_c+i] = arr[index_r-i+1][index_c+i-1];
    }

    index_r = index_r-m1;
    index_c = index_c+m1;

    int temp2 = arr[index_r-m2][index_c-m2];
    for(int i=m2 ; i>1 ; i--) {
        arr[index_r-i][index_c-i] = arr[index_r-i+1][index_c-i+1];
    }
    arr[index_r-1][index_c-1] = temp1;

    index_r = index_r-m2;
    index_c = index_c-m2;

    int temp3 = arr[index_r+m3][index_c-m3];
    for(int i=m3 ; i>1 ; i--) {
        arr[index_r+i][index_c-i] = arr[index_r+i-1][index_c-i+1];
    }
    arr[index_r+1][index_c-1] = temp2;

    index_r = index_r+m3;
    index_c = index_c-m3;

    for(int i=m4 ; i>1 ; i--) {
        arr[index_r+i][index_c+i] = arr[index_r+i-1][index_c+i-1];
    }
    arr[index_r+1][index_c+1] = temp3;
}

void move2(int r, int c, int m1, int m2, int m3, int m4) {
    int index_r = r;
    int index_c = c;

    int temp2 = arr[index_r-m2][index_c-m2];
    for(int i=m2 ; i>0 ; i--) {
        arr[index_r-i][index_c-i] = arr[index_r-i+1][index_c-i+1];
    }

    index_r = index_r-m2;
    index_c = index_c-m2;

    int temp1 = arr[index_r-m1][index_c+m1];
    for(int i=m1 ; i>0 ; i--) {
        arr[index_r-i][index_c+i] = arr[index_r-i+1][index_c+i-1];
    }
    arr[index_r-1][index_c+1] = temp2;

    index_r = index_r-m1;
    index_c = index_c+m1;

    int temp4 = arr[index_r+m4][index_c+m4];
    for(int i=m4 ; i>1 ; i--) {
        arr[index_r+i][index_c+i] = arr[index_r+i-1][index_c+i-1];
    }
    arr[index_r+1][index_c+1] = temp1;

    index_r = index_r+m4;
    index_c = index_c+m4;

    for(int i=m3 ; i>1 ; i--) {
        arr[index_r+i][index_c-i] = arr[index_r+i-1][index_c-i+1];
    }
    arr[index_r+1][index_c-1] = temp4;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cin >> arr[i][j];
        }
    }

    int r,c,m1,m2,m3,m4,dir;
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

    if(dir == 0) {
        move1(r,c,m1,m2,m3,m4);
    } else {
        move2(r,c,m1,m2,m3,m4);
    }

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=n ; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }




    return 0;
}