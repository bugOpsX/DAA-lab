#include <iostream>
using namespace std;

class Bubble{

public:
    int arr[100], size, i;

    void ArrayInputs(){             // taking input from user

        cout<<"Enter Size of Array: ";      //taking size of array
        cin>>size;

        cout<<"Enter Array Elements: ";     //for loop for elements
        for(i = 0; i<size; i++){
            cin>>arr[i];
        }
    }

    void ArrayElements(){
        cout<<"Array Elements are: \n";
        for(i = 0; i<size; i++){        // for loop for printing array elements
            cout<<arr[i];
        }
    }

    void sort(){        // logic of bubble sort
        for(i = 0; i<size-1; i++){
            for(int j = 0; j<size - 1; j++){
                if(arr[j]>arr[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

};

int main(){

    Bubble obj;

    obj.ArrayInputs();
    cout<<"Before Sorting ";
    obj.ArrayElements();
    obj.sort();
    cout<<"After Sorting: ";
    obj.ArrayElements();

    return 0;
}