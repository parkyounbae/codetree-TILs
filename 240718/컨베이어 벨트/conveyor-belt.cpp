#include <iostream>
using namespace std;

int n,t;
int line1[100];
int line2[100];

void tick() {
    int line1_temp = line1[n-1];
    int line2_temp = line2[0];

    for(int i=1 ; i<n ; i++) {
        line1[n-i] = line1[n-i-1];
        line2[i-1] = line2[i];
    }

    line1[0] = line2_temp;
    line2[n-1] = line1_temp;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    for(int i=0 ; i<n ; i++) {
        cin >> line1[i];
    }
    for(int i=n-1 ; i>=0 ; i--) {
        cin >> line2[i];
    }

    for(int i=0 ; i<t ; i++) {
        tick();
    }

    for(int i=0 ; i<n ; i++) {
        cout << line1[i] << " ";
    }
    cout << "\n";
    for(int i=n-1 ; i>=0 ; i--) {
        cout << line2[i] << " ";
    }




    return 0;
}