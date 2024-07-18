#include <iostream>
using namespace std;

int n,m,q;
int board[101][101];

void move_left(int line) {
    int temp = board[line-1][m-1];
    for(int i=m-1 ; i>0 ; i--) {
        board[line-1][i] = board[line-1][i-1];
    }
    board[line-1][0] = temp;
}

void move_right(int line) {
    int temp = board[line-1][0];
    for(int i=0 ; i<m-1 ; i++) {
        board[line-1][i] = board[line-1][i+1];
    }
    board[line-1][m-1] = temp;
    
}

bool check(int line1, int line2) {
    if(line2 == 0 || line2 == n+1) {
        return false;
    }
    for(int i=0 ; i<m ; i++) {
        if(board[line1-1][i] == board[line2-1][i]) {
            return true;
        }
    }

    return false;
}

void tick(int line, char command) {
    char up_command, down_command;
    if(command == 'L') {
        up_command = 'R';
        down_command = 'R';
        move_left(line);
    } else {
        up_command = 'L';
        down_command = 'L';
        move_right(line);
    }

    int up_line = line - 1;
    while(check(up_line + 1, up_line)) {
        if(up_command == 'L') {
            up_command = 'R';
            move_left(up_line);
        } else {
            up_command = 'L';
            move_right(up_line);
        }
        up_line--;
    }

    int down_line = line + 1;
    while(check(down_line - 1, down_line)) {
        if(down_command == 'L') {
            down_command = 'R';
            move_left(down_line);
        } else {
            down_command = 'L';
            move_right(down_line);
        }
        down_line++;
    }



}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> m >> q;

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cin >> board[i][j];
        }
    }

    int line;
    char command;

    for(int i=0 ; i<q ; i++) {
        cin >> line >> command;
        tick(line, command);
    }

    for(int i=0 ; i<n ; i++) {
        for(int j=0 ; j<m ; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}