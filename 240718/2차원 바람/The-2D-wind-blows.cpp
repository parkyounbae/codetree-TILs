#include <iostream>
using namespace std;

int n,m,q;
int arr[2][101][101];

int get_avg(int r, int c, int page) {
    int count = 1;
    int sum = arr[page][r][c];

    if(r-1>0) {
        count ++;
        sum+=arr[page][r-1][c];
    }
    if(c+1 < m+1) {
        count++;
        sum += arr[page][r][c+1];
    }
    if(c-1 > 0) {
        count++;
        sum += arr[page][r][c-1];
    }

    if(r+1 < n+1) {
        count++;
        sum += arr[page][r+1][c];
    }

    return sum/count;
}

void tick(int r1,int c1,int r2,int c2,int page) {
    int temp1 = arr[page][r1][c2];
    for(int i=c2 ; i>c1 ; i--) {
        arr[page][r1][i] = arr[page][r1][i-1];
    }

    
    int temp2 = arr[page][r2][c2];
    for(int i=r2 ; i>r1+1 ; i--) {
        arr[page][i][c2] = arr[page][i-1][c2];
    }
    arr[page][r1+1][c2] = temp1;

    
    int temp3 = arr[page][r2][c1];
    for(int i=c1 ; i<c2-1 ; i++) {
        arr[page][r2][i] = arr[page][r2][i+1];
    }
    arr[page][r2][c2-1] = temp2;

    for(int i=r1 ; i<r2 ; i++) {
        arr[page][i][c1] = arr[page][i+1][c1];
    }
    arr[page][r2-1][c1] = temp3;

    if(page == 0) {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=m ; j++) {
                arr[1][i][j] = arr[0][i][j];
            }
        }
        for(int i=r1 ; i<=r2 ; i++) {
            for(int j=c1 ; j<=c2 ; j++) {
                arr[1][i][j] = get_avg(i,j,0);
            }
        }
    } else {
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=m ; j++) {
                arr[0][i][j] = arr[1][i][j];
            }
        }
        for(int i=r1 ; i<=r2 ; i++) {
            for(int j=c1 ; j<=c2 ; j++) {
                arr[0][i][j] = get_avg(i,j,1);
            }
        }
    }

}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> q;
    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cin >> arr[0][i][j];
            arr[1][i][j] = 0;
        }
    }

    int r1,c1,r2,c2;
    int current_page = 0;
    for(int i=0 ; i<q ; i++) {
        cin >> r1 >> c1 >> r2 >> c2;
        tick(r1,c1,r2,c2,current_page);
        if(current_page == 0) {
            current_page = 1;
        } else {
            current_page = 0;
        }
    }

    for(int i=1 ; i<=n ; i++) {
        for(int j=1 ; j<=m ; j++) {
            cout << arr[current_page][i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}