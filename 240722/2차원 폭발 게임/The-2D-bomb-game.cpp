#include <iostream>
#include <cstring>
using namespace std;

int n,m,k;
int arr[201][201];
int temp_arr[201][201];

void delete_minus() {
    for(int c=0 ; c<n ; c++) {
        for(int r=n-1 ; r>=0 ; r--) {
            int start = -1;
            int end = -1;
            if(arr[r][c] == -1) {
                start = r;

                for(int i=start ; i>=0 ; i--) {
                    if(arr[i][c] != -1) {
                        end = i+1;
                        break;
                    }
                }

                if(end == -1) {
                    end = 0;
                }

                for(int i=start ; i>=0 ; i--) {
                    if(i-(start - end + 1)>=0) {
                        arr[i][c] = arr[i-(start - end + 1)][c];
                    } else {
                        arr[i][c] = 0;
                    }
                }
            }
        }
    }
}

void delete_zero() {
    for(int c=0 ; c<n ; c++) {
        for(int r=n-1 ; r>=0 ; r--) {
            int start = -1;
            int end = -1;
            if(arr[r][c] == 0) {
                start = r;

                for(int i=start ; i>=0 ; i--) {
                    if(arr[i][c] != 0) {
                        end = i+1;
                        break;
                    }
                }

                if(end == -1) {
                    end = 0;
                }

                for(int i=start ; i>=0 ; i--) {
                    if(i-(start - end + 1)>=0) {
                        arr[i][c] = arr[i-(start - end + 1)][c];
                    } else {
                        arr[i][c] = 0;
                    }
                }
            }


        }
    }
}


void rotate() {
    // 배열 90도 회전
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            temp_arr[j][n-1-i] = arr[i][j];

    // 배열 값 복사
    memmove(arr, temp_arr, sizeof(arr));

    delete_zero();
}

void bomb() {
    while(true) {
        int total = 0;
        for(int c=0 ; c<n ; c++) {
            int temp = arr[n-1][c];
            int count = 1;
            for(int r=n-2 ; r>=0 ; r--) {

                if(arr[r][c] == 0) {
                    continue;
                }

                if(temp == arr[r][c]) {
                    count ++;
                    if(count >= m) {
                        for(int i=0 ; i<count && arr[r-i][c] != -1; i++) {
                            arr[r+i][c] = -1;
                            total++;
                        }
                        // count ++;
                    }
                }
                else {
                    temp = arr[r][c];
                    count = 1;
                }
            }
        }

        if(total == 0) {
            break;
        } else {
            delete_minus();
        }
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> k;
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            cin >> arr[i][j];
        }
    }

    if(m==1) {
        cout << 0 << endl;
        return 0;
    }

    for(int i=0 ; i<k ; i++) {
        bomb();

        
        rotate();
        
    }
    bomb();

    int result = 0;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<n ; j++) {
            if(arr[i][j] != 0) {
                result ++;
            }
        }
    }
    cout << result << endl;
    return 0;
}