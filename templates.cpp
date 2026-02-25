#include<iostream>
#include<fstream>
#include<memory>
using namespace std;

template<class T>
class complex{
    private:
        T real;
        T imag;
    public:
        complex(T r , T i) : real(r) , imag(i) {}

        void display(){
            cout << real << " + " << imag << "i" << endl;
        }
        T sum_real(const complex& other){
            return this->real + other.real;
        }    
        T sum_imag(const complex& other){
            return this->imag + other.imag;
        }   
};

template<typename T = int>
class ptr_template{
    private:
        T* a;
        T* b;
    public:
        ptr_template(){
            a = new T;
            b = new T;
        }
        ptr_template(const ptr_template& other){
            this->a = new T;
            this->b = new T;
            *(this->a) = *(other.a);
            *(this->b) = *(other.b);
        }
        void set_values(T a , T b){
            *(this->a) = a;
            *(this->b) = b;
        }
        void display(){
            cout << *(this->a) << " " << *(this->b) << endl;
        }
        ~ptr_template(){
            delete a;
            a = nullptr;
            delete b;
            b = nullptr;
        }
};

template<typename T>
void swapp(T& a , T& b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T , int N>
class Array{
    private:
        T arr[N];
    public:
        Array(){}

        void enter_data();
        void print_arr();
        void sort_arr();
        int binary_search(int n);

        void getsize() const { cout << N << endl;}
};



template<typename T , int N>
void Array<T,N> :: enter_data(){
     cout << "Enter " << N << " Elements.\n";
            for(int i=0;i<N;i++){
                cout << "Enter " << "Element " << i+1 << " : ";
                cin >> arr[i];
            }
            cout << "\n";
}

template<typename T , int N>
void Array<T,N> :: print_arr(){
            cout << "{ ";
            for(int i=0;i<N;i++){
                cout << arr[i] << " ";
            }
            cout << "}" << endl;
}

template<typename T , int N>
void Array<T,N> :: sort_arr(){
            for(int i=0;i<N;i++){
                for(int j=0;j<N-1;j++){
                    if(arr[j] > arr[j+1]){
                        swapp(arr[j],arr[j+1]);
                    }
                }
            }
}

template<typename T , int N>
int Array<T,N> :: binary_search(int n){
    sort_arr();
    int start = 0 , mid = n/2 , end = N-1;
    
}


int main(){
    
    Array<int,5>arr;
    arr.enter_data();
    arr.print_arr();
    arr.sort_arr();
    arr.print_arr();

    ptr_template<float> ptr;
    ptr.set_values(4.5,5.4);
    ptr.display();

    return 0;
}