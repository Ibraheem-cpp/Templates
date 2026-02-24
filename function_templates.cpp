#include<iostream>
#include<fstream>
using namespace std;

template<typename T>
T add_numbers(T a , T b){
    return a+b;
}

template<typename T>
void swap_numbers(T& a , T& b);

template<typename T>
void print_arr(T arr[] , int s){
    cout << "{ ";
    for(int i=0;i<s;i++){
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

template<typename T>
void sort_arr(T arr[] , int s){
    for(int i=0;i<s;i++){
        for(int j=0;j<s-1;j++){
            if(arr[j] > arr[j+1]){
                swap_numbers(arr[j],arr[j+1]);
            }
        }
    }
}


int main(){

    float arr[5] = {1.2,4.33,1.43,3.4,3.1};
    sort_arr(arr,5);
    print_arr(arr,5);
    int arr2[4] = {3,21,4,5};
    sort_arr(arr2,4);
    print_arr(arr2,4);

    return 0;
}

template<typename T>
void swap_numbers(T& a , T& b){
    T temp = a;
    a = b;
    b = temp;
}