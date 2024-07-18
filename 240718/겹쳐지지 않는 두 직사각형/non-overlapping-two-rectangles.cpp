#include <iostream>
using namespace std;

int n,m;
int **arr;
int **board;

int result;

void clear_board() {
    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            board[i][j] = 0;
        }
    }
}

void mark_board(int r1, int c1, int r2, int c2) {
    for(int i=r1 ; i<=r2 ; i++) {
        for(int j=c1; j<=c2 ; j++) {
            board[i][j] = 1;
        }
    }
}


bool check_board(int r1, int c1, int r2, int c2) {
    for(int i=r1 ; i<=r2 ; i++) {
        for(int j=c1; j<=c2 ; j++) {
            if(board[i][j]) {
                return true;
            }
        }
    }

    return false;
}

int get_sum_rect(int r1, int c1, int r2, int c2) {
    int sum = 0;

    for(int i=r1 ; i<=r2 ; i++) {
        for(int j=c1; j<=c2 ; j++) {
            sum += arr[i][j];
        }
    }
    return sum;
}

void set_second_rect(int r, int c, int amount) {
    for(int i=r ; i<n ; i++) {
        for(int j=c ; j<m ; j++) {
            if(!check_board(r,c,i,j)) {
                int temp = get_sum_rect(r,c,i,j);
                if(result < temp + amount) {
                    result = temp+amount;
                }
            }
        }
    }
}

void set_first_rect(int r, int c) {
    for(int i=r ; i<n ; i++) {
        for(int j=c ; j<m ; j++) {
            mark_board(r,c,i,j);
            for(int k=0 ; k<n ; k++) {
                for(int l=0 ; l<m ; l++) {
                    set_second_rect(k,l,get_sum_rect(r,c,i,j));
                }
            }
            clear_board();
        }
    }
}



int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m;
    arr = new int*[n];
    board = new int*[n];
    for(int i=0 ; i<n ; i++) 
    {
        arr[i] = new int[m]; 
        board[i] = new int[m];
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> arr[i][j];
        }
    }

    result = arr[0][0] + arr[0][1];

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            set_first_rect(i,j);
        }
    }


    cout << result << endl;


    return 0;
}