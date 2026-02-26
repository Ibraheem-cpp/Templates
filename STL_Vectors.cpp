#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


template<typename T>
void enter_vector(vector<T> &v , int s){
    T num;
    for(int i=0;i<s;i++){
        cout << "Enter Element : ";
        cin >> num;
        v.push_back(num);
    }
    cout << '\n';
}

template<typename T>
void display(const vector<T> &v){
    for(typename vector<T>::const_iterator it = v.begin() ; it != v.end() ; it++){
        cout << *it << " ";
    }
    cout << '\n';
}

template<typename T>
void display_reverse(const vector<T> &v){
    cout << "Reverse : ";
    for(int i=v.size()-1;i>=0;i--){
        cout << v[i] << " ";
    }
    cout << '\n';
}

template<typename T>
void sum_of_vector(const vector<T> &v){
    T sum = 0;
    for(int i=0;i<v.size();i++){
        sum = sum + v[i];
    }
    cout << "\n Sum : " << sum << '\n';
}

template<typename T>
void swapp(T& a , T& b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void remove_duplicates(vector<T> &v){
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(v[i] == v[j]){
                swapp(v[j],v[v.size()-1]);
                v.pop_back();
                j--;
            }
        }
    }
}

template<typename T>
void sort_vector(vector<T> &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v.size()-1;j++){
            if(v[j] > v[j+1]){
                swapp(v[j],v[j+1]);
            }
        }
    }
}

template<typename T>
void insert_at_position(vector<T> &v){
    typename vector<T> :: iterator it = v.begin();
    int index , num;
    cout << "Enter Index : ";
    cin >> index;
    cout << "Enter Number : ";
    cin >> num;
    v.insert(it+index,num);
}

template<typename T>
vector<T> merge_vectors(const vector<T> &v , const vector<T> &v1){
    std::vector<T> vec3;
    for(int i=0;i<v.size();i++){
        vec3.push_back(v[i]);
    }
    for(int i=0;i<v1.size();i++){
        vec3.push_back(v1[i]);
    }
    return vec3;
}

template<typename T>
void input_print_matrix(vector<vector<T>> &m , int R , int C){
    cout << "Enter Elements of matrix : \n";
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            
            cin >> m[i][j];
        }
    }
    cout << '\n';
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    // int size = 5;
    // std::vector<int> vec1;
    // enter_vector(vec1,size);
    // display(vec1);

    using Matrix = vector<vector<int>>;
    Matrix matrix(3,vector<int>(2));
    input_print_matrix(matrix,3,2);
        

    return 0;
}