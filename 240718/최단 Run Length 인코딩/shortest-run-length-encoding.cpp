#include <iostream>
#include <string>

using namespace std;

char arr[10];
int length;

int get_length() {
    char index = arr[0];
    int result = 2;
    int ten = 1;
    for(int i=1 ; i<length ; i++) {
        if(arr[i] != index) {
            index = arr[i];
            result += 2;
            ten = 1;
        } else {
            ten++;
        }
    }
    if(ten == 10) {
        result = result + 1;
    }


    return result;
}

void shift_arr() {
    char temp = arr[length-1];
    for(int i=length-1 ; i>0 ; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main() {
    // 여기에 코드를 작성해주세요.
    string a;
    cin >> a;
    length = 0;
    for(int i=0 ; i<a.length() ; i++) {
        arr[i] = a.at(i);
        length++;
    }

    int result = 20;

    for(int i=0 ; i<length ; i++) {
        shift_arr();
        int temp = get_length();
        if(temp < result) {
            result = temp;
        }
    }

    cout << result << endl;


    return 0;
}