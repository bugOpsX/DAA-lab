// #include<iostream>
// using namespace std;

// int main(){

//     for (int d = 1; d<n-1; d++){
//         for (int i = 1; i<n-d; i++){
//             j = i+d;
//             min = 32.767;

//             for (int k = 1; k<j-1; k++){
//                 q = c[i][k] + c[k+1][j]+p[i-1]*p[k]+p[j];

//                 if(q<min){
//                     min = q;
//                     k[i][j] = k;
//                 }
//             }
//             c[i][j] = min;
//         }
//     }
// }


// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;

// int main() {
//     int n = 5;

//     int p[6];        // Array 1: matrix dimensions
//     int c[6][6] = {}; // Array 2: cost
//     int k[6][6] = {}; // Array 3: split position

//     // Generate random dimensions
//     srand(time(0));

//     cout << "Dimensions: ";
//     for (int i = 0; i <= n; i++) {
//         p[i] = 2 + rand() % 9;
//         cout << p[i] << " ";
//     }

//     // Matrix Chain Multiplication
//     for (int d = 1; d < n; d++) {
//         for (int i = 1; i < n - d + 1; i++) {
//             int j = i + d;
//             int min = 999999;

//             for (int x = i; x < j; x++) {
//                 int q = c[i][x] + c[x + 1][j]
//                       + p[i - 1] * p[x] * p[j];

//                 if (q < min) {
//                     min = q;
//                     k[i][j] = x;
//                 }
//             }

//             c[i][j] = min;
//         }
//     }

//     cout << "\n\nMinimum cost = " << c[1][n] << endl;

//     cout << "\nCost table:\n";
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             cout << c[i][j] << "\t";
//         }
//         cout << endl;
//     }

//     cout << "\nSplit table:\n";
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             cout << k[i][j] << "\t";
//         }
//         cout << endl;
//     }

//     return 0;
// }


#include <iostream>
using namespace std;

int main(){
    int n = 5;

    int p[] = {5, 10, 3, 12, 5, 50};

    int c[10][10] = {0};
    int k[10][10] = {0};

    for(int d = 1; d < n; d++){
        for(int i = 1; i <= n-d; i++){
            int j = i + d;
            int min = 99999;

            for(int x = i; x < j; x++){
                int q = c[i][x] + c[x+1][j]
                      + p[i-1] * p[x] * p[j];

                if(q < min){
                    min = q;
                    k[i][j] = x;
                }
            }
            c[i][j] = min;
        }
    }

    cout << "\nMinimum cost = " << c[1][n]<<endl;

    return 0;
}