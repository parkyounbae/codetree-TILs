#include <iostream>
using namespace std;

int arr[5][5];
int result[5][5];

int main() {
    // 여기에 코드를 작성해주세요.
    for(int i=1 ; i<=4 ; i++) {
        for(int j=1 ; j<=4 ; j++) {
            cin >> arr[i][j];
            result[i][j] = 0;
        }
    }

    char command;
    cin >> command;

    if(command == 'R') {
        for(int i=1 ; i<=4 ; i++) {
            int index_of_result = 4;
            int temp = arr[i][4];
            result[i][index_of_result--] = temp;
            for(int j=3 ; j>0 ; j--) {
                if(arr[i][j] == 0) {
                    continue;
                } else if(arr[i][j] == temp) {
                    result[i][index_of_result+1] = arr[i][j]*2;
                    temp = -1;
                } else {
                    result[i][index_of_result--] = arr[i][j];
                    temp = arr[i][j];
                }
            }
        }
    } else if(command == 'L') {
        for(int i=1 ; i<=4 ; i++) {
            int index_of_result = 1;
            int temp = arr[i][1];
            result[i][index_of_result++] = temp;
            for(int j=2 ; j<5 ; j++) {
                if(arr[i][j] == 0) {
                    continue;
                } else if(arr[i][j] == temp) {
                    result[i][index_of_result-1] = arr[i][j]*2;
                    temp = -1;
                } else {
                    result[i][index_of_result++] = arr[i][j];
                    temp = arr[i][j];
                }
            }
        }
    } else if(command == 'U') {
        for(int i=1 ; i<=4 ; i++) {
            int index_of_result = 1;
            int temp = arr[1][i];
            result[index_of_result++][i] = temp;
            for(int j=2 ; j<5 ; j++) {
                if(arr[j][i] == 0) {
                    continue;
                } else if(arr[j][i] == temp) {
                    result[index_of_result-1][i] = arr[j][i]*2;
                    temp = -1;
                } else {
                    result[index_of_result++][i] = arr[j][i];
                    temp = arr[j][i];
                }
            }
        }
    } else {
        for(int i=1 ; i<=4 ; i++) {
            int index_of_result = 4;
            int temp = arr[4][i];
            result[index_of_result--][i] = temp;
            for(int j=3 ; j>0 ; j--) {
                if(arr[j][i] == 0) {
                    continue;
                } else if(arr[j][i] == temp) {
                    result[index_of_result+1][i] = arr[j][i]*2;
                    temp = -1;
                } else {
                    result[index_of_result--][i] = arr[j][i];
                    temp = arr[j][i];
                }
            }
        }
    }

    for(int i=1 ; i<=4 ; i++) {
        for(int j=1 ; j<=4 ; j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}