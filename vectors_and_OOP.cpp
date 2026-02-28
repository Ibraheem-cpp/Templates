#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

class student{
    private:
        string name;
        int roll_no;
    public:
        student(){}

        student(string n , int r) : name(n) , roll_no(r) {}

        void display() const {
            cout << " Name    : " << name << '\n';
            cout << " Roll No : " << roll_no << '\n';
        }

        int get_rollno() const {
            return this->roll_no;
        }
};

class School{
    private:
        std::vector<student*> students;
    public:
        School(){}

        void add_student(){
            string n;
            int r;
            cin.ignore();
            cout << "Enter Name of Student : ";
            getline(cin,n);
            do{
            cout << "Enter Roll No : ";
            cin >> r;
            }while(!is_valid_rollno(r));
            students.emplace_back(new student(n,r));
        }

        bool is_valid_rollno(const int r){
            for(int i=0;i<students.size();i++){
                if(r == students[i]->get_rollno()){
                    cout << "Roll No# already Exists.\n";
                    return false;
                }
            }
            return true;
        }

        void see_all_students() const {
            if(students.size() == 0){cout << "School is Empty.\n"; return;}
            int i=0;
            for(std::vector<student*>::const_iterator it = students.begin() ; it != students.end(); ++it,i++){
                cout << i+1 << ". \n";
                (*it)->display();
            }
        }

        void search_student(){
            if(students.size() == 0){cout << "School is Empty.\n"; return;}
            int r;
            cout << "Enter Roll No of Student you want to Search : ";
            cin >> r;
            for(int i=0;i<students.size();i++){
                if( r == students[i]->get_rollno()){
                    cout << "Student Found.\n";
                    students[i]->display();
                    return;
                }
            }
            cout << "Student Not Found.\n";
        }

        void remove_student(){
            if(students.size() == 0){cout << "School is Empty.\n"; return;}
            int r;
            cout << "Enter Roll Number of Student you want to delete : ";
            cin >> r;
            for(int i=0;i<students.size();i++){
                if(r == students[i]->get_rollno()){
                    delete students[i];
                    students.erase(students.begin()+i);
                    break;
                }
            }
            cout << "Student Deleted.\n";
        }

        void start(){
            int ch;
            do{
                menu(ch);
            }while(ch != 0);
        }

        void menu(int& ch){
            cout << "\n\n";
            cout << "1. Add Student.\n"
                 << "2. See all Students.\n"
                 << "3. Delete a Student.\n"
                 << "4. Search a Student.\n"
                 << "0. Close School.\n"
                 << " Enter Choice : ";
            cin >> ch;
            cout << endl;
            switch (ch)
            {
            case 1:
                add_student();
                break;
            case 2:
                see_all_students();
                break;
            case 3:
                remove_student();
                break;
            case 4:
                search_student();
                break;
            case 0:
                cout << "\n Closing The School.\n";
                break;

            default:
                cout << "Invalid Choice. Enter Again.";
                break;
            }
        }

        ~School(){
            for(int i=0;i<students.size();i++){
                delete students[i];
            }
        }

};


int main(){
    cout << "\n           ===============================| BLACK KNIGHT SCHOOL |==============================";

    School school;
    school.start();

    cout << "______________________________________________________________________________________________";

    cout << '\n';

    return 0;
}