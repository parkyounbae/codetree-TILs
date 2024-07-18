#include <iostream>
using namespace std;

int n,t;
int line1[201];
int line2[201];
int line3[201];

void tick() {
    int line1_temp = line1[n-1];
    int line2_temp = line2[n-1];
    int line3_temp = line3[n-1];

    for(int i=n-1 ; i>=0 ; i--) {
        line1[i] = line1[i-1];
        line2[i] = line2[i-1];
        line3[i] = line3[i-1];
    }

    line1[0] = line3_temp;
    line2[0] = line1_temp;
    line3[0] = line2_temp;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n >> t;
    for(int i=0 ; i<n ; i++) {
        cin >> line1[i];
    }
    for(int i=0 ; i<n ; i++) {
        cin >> line2[i];
    }
    for(int i=0 ; i<n ; i++) {
        cin >> line3[i];
    }

    for(int i=0 ; i<t ; i++) {
        tick();
    }

    for(int i=0 ; i<n ; i++) {
        cout << line1[i] << " ";
    }
    cout << "\n";
    for(int i=0 ; i<n ; i++) {
        cout << line2[i] << " ";
    }
    cout << "\n";
    for(int i=0 ; i<n ; i++) {
        cout << line3[i] << " ";
    }

    return 0;
}