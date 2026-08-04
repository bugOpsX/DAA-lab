#include <iostream>
using namespace std;

class SelectionSort{

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

    void ArrayElements() { 
        for(i = 0; i < size; i++) { 
            cout << arr[i] << " "; 
        } 
        cout << endl;
    } 

    void logic(){
    for( i = 0; i<size-1; i++){
        int min = i;

        for(int j = i+1 ; j<size; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }

        if( min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    }
};

int main() { 
    SelectionSort obj; 
    
    obj.ArrayInputs(); 
    
    cout << "Original Array Elements: " << endl; 
    obj.ArrayElements(); 
    
    obj.logic(); 
    
    cout << "Sorted Array Elements: " << endl; 
    obj.ArrayElements(); 
    
    return 0; 
}
