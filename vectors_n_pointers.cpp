#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

template<typename T>
void enter_elements(vector<T*> &v){
    T n;
    for(int i=0;i<v.size();i++){
        cout << "Enter Element : ";
        cin >> n;
        v[i] = new T(n);
    }
}

template<typename T>
void print_vector(const vector<T*> &v){
    for(int i=0;i<v.size();i++){
        cout << *(v[i]) << " ";
    }
    cout << '\n';
}

template<typename T>
void delete_vector(vector<T*> &v){
    for(int i=0;i<v.size();i++){
        delete v[i];
        v[i] = nullptr;
    }
}

int main(){

    int n;
    cout << "Enter Size of Vector : ";
    cin >> n;
    cout << '\n';

    std::vector<int*> vec1(n,nullptr);
    enter_elements(vec1);
    print_vector(vec1);
    delete_vector(vec1);

   
    

    return 0;
}