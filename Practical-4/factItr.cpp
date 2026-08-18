#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number for factorial : ";
    cin>>n;
    cout<<" ";

    long long  fact = 1;

    for(int i = 1; i<n; i++){
        fact = fact*i;
    }
    cout<<"Factorial is "<<fact<<endl;

    return 0;
}