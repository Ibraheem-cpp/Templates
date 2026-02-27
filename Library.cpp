#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class libraryItem{
    protected:
        string Name;
        string ID;
    public:
        libraryItem() {}

        libraryItem(string name , string id) : Name(name) , ID(id) {}

        virtual void display_item() const = 0;

        const string& get_name() const {
            return this->Name;
        }

        const string& get_ID() const {
            return this->ID;
        }


        virtual ~libraryItem() = default;
};

class Book : public libraryItem{
    private:
        string Author_name;
        string Genre;
    public:
        Book() {}

        Book(string name , string id , string author , string genre) : 
            libraryItem(name,id) , Author_name(author) , Genre(genre) {}

        void display_item() const override {
            cout << setw(12) << "Book : " << Name << "  "
                             << "Author: " << Author_name << "  "
                             << "Genre: " << Genre << "  "
                             << "(ID : " << ID << ")\n";
        }
        static bool is_valid_id(string id){
            if(id.length() != 6){return false;}
            if(id[0] != 'B'){return false;}
            if(id[1] != '-'){return false;}
            for(int i=2;i<id.length();i++){
                if(id[i] < '0' || id[i] > '9'){return false;}
            }
            return true;
        }


        ~Book() = default;
        
};

class Magazine : public libraryItem{
    private:
        string Publisher;
    public:
        Magazine() {}

        Magazine(string name , string id , string publisher) : 
                libraryItem(name,id) , Publisher(publisher) {}

        void display_item() const override {
            cout << setw(12) << "Magazine : " << Name << "  "
                             << "Publisher: " << Publisher << "  "
                             << "(ID : " << ID << ")\n";
        }

        static bool is_valid_id(string id){
            if(id.length() != 6){return false;}
            if(id[0] != 'M'){return false;}
            if(id[1] != '-'){return false;}
            for(int i=2;i<id.length();i++){
                if(id[i] < '0' || id[i] > '9'){return false;}
            }
            return true;
        }


        ~Magazine() = default;

};

class DVD : public libraryItem{
    private:
        int duration;
    public:
        DVD() {}

        DVD(string name , string id , int time) : 
            libraryItem(name,id) , duration(time) {}

        void display_item() const override {
            cout << setw(12) << "DVD : " << Name << "  "
                             << "Duration: " << duration << " minutes" << "  "
                             << "(ID : " << ID << ")\n";
        }

        static bool is_valid_id(string id){
            if(id.length() != 6){return false;}
            if(id[0] != 'D'){return false;}
            if(id[1] != '-'){return false;}
            for(int i=2;i<id.length();i++){
                if(id[i] < '0' || id[i] > '9'){return false;}
            }
            return true;
        }


        ~DVD() = default;

};


class My_Library{
    private:
        std::vector<libraryItem*> library_items;
        
    public:
        My_Library() {}

        void display(){
            if(library_items.size() == 0){throw "Library is Empty.\n";}
            for(int i=0;i<library_items.size();i++){
                library_items[i]->display_item();
            }
        }

        

        void menu(int& ch){
            cout << '\n';
            cout << " 1. See all Items.\n"
                 << " 2. Add/Remove Book.\n"
                 << " 3. Add/Remove Magazine.\n"
                 << " 4. Add/Remove DVD.\n"
                 << " 5. Exit.\n"
                 << "Enter Choice : ";
            cin >> ch;
            cout << '\n';
            switch (ch)
            {
            case 1:
                display();
                break;
            case 2:
                add_remove_book();
                break;
            case 3:
                add_remove_Magazine();
                break;
            case 4:
                add_remove_DVD();
                break;
            case 5:
                cout << "\n Closing Library.\n";
                break;
            default:
                cout << "Invalid Choice !!\n";
                break;
            }
        }

        void add_remove_book(){
            int ch;
            cout << " 1. Add Book.\n"
                 << " 2. Remove Book.\n"
                 << "Enter Choice : ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                add_book();
                break;
            case 2:
                remove_book();
                break;
            default:
                cout << "Invalid Choice.\n";
                break;
            }

        }

        void add_remove_Magazine(){
            int ch;
            cout << " 1. Add Magazine.\n"
                 << " 2. Remove Magazine.\n"
                 << "Enter Choice : ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                add_Magazine();
                break;
            case 2:
                remove_Magazine();
                break;
            default:
                cout << "Invalid Choice.\n";
                break;
            }

        }

        void add_remove_DVD(){
            int ch;
            cout << " 1. Add DVD.\n"
                 << " 2. Remove DVD.\n"
                 << "Enter Choice : ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                add_DVD();
                break;
            case 2:
                remove_DVD();
                break;
            default:
                cout << "Invalid Choice.\n";
                break;
            }

        }

        void add_book(){
            string name,id,author,genre;
            cin.ignore();
            cout << "Enter Name of Book : ";
            getline(cin,name);
            do{
                cout << "Enter ID (B-0000) : ";
                getline(cin,id);
            }while(!(Book :: is_valid_id(id)) || !(is_duplicate_id(id)));
            cout << "Enter Author of Book : ";
            getline(cin,author);
            cout << "Enter Genre : ";
            getline(cin,genre);

            library_items.push_back(new Book(name,id,author,genre));
            cout << "\nBook Added Successfully.\n";
        }
        void remove_book(){
            if(library_items.size() == 0){throw "\nLibrary is Already Empty.\n";}
            string id;
            cin.ignore();
            cout << "Enter ID of Book You want to Remove : ";
            getline(cin,id);
            for(int i=0;i<library_items.size();i++){
                if(library_items[i]->get_name()[0] == 'B'){
                    if(id == library_items[i]->get_ID()){
                        delete library_items[i];
                        library_items.erase(library_items.begin()+i);
                        cout << "\nBook Removed.\n";
                        return;
                    }
                }
            } 
            cout << "\nBook Not Found.\n";
        }

        void add_Magazine(){
            string name,id,publisher;
            cin.ignore();
            cout << "Enter Name of Magazine : ";
            getline(cin,name);
            do{
                cout << "Enter ID (M-0000) : ";
                getline(cin,id);
            }while(!(Magazine :: is_valid_id(id)) || !(is_duplicate_id(id)));
            cout << "Enter Name of Publisher : ";
            getline(cin,publisher);

            library_items.push_back(new Magazine(name,id,publisher));
            cout << "\nMagazine Added Successfully.\n";
        }
        void remove_Magazine(){
            if(library_items.size() == 0){throw "\nLibrary is Already Empty.\n";}
            string id;
            cin.ignore();
            cout << "Enter ID of Magazine You want to Remove : ";
            getline(cin,id);
            for(int i=0;i<library_items.size();i++){
                if(library_items[i]->get_name()[0] == 'M'){
                    if(id == library_items[i]->get_ID()){
                        delete library_items[i];
                        library_items.erase(library_items.begin()+i);
                        cout << "\nMagazine Removed.\n";
                        return;
                    }
                }
            } 
            cout << "\nMagazine Not Found.\n";
        }

        void add_DVD(){
            string name,id;
            int time;
            cin.ignore();
            cout << "Enter Name of DVD : ";
            getline(cin,name);
            do{
                cout << "Enter ID (D-0000) : ";
                getline(cin,id);
            }while((!(DVD :: is_valid_id(id))) || !(is_duplicate_id(id)));
            cout << "Enter Duration (in minutes) : ";
            cin >> time;

            library_items.push_back(new DVD(name,id,time));
            cout << "\nDVD Added Successfully.\n";

        }
        void remove_DVD(){
            if(library_items.size() == 0){throw "\nLibrary is Already Empty.\n";}
            string id;
            cin.ignore();
            cout << "Enter ID of DVD You want to Remove : ";
            getline(cin,id);
            for(int i=0;i<library_items.size();i++){
                if(library_items[i]->get_ID()[0] == 'D'){
                    if(id == library_items[i]->get_ID()){
                        delete library_items[i];
                        library_items.erase(library_items.begin()+i);
                        cout << "\nDVD Removed.\n";
                        return;
                    }
                }
            } 
            cout << "\nDVD Not Found.\n";
        }

        bool is_duplicate_id(const string& id){
            for(int i=0;i<library_items.size();i++){
                if(id == library_items[i]->get_ID()){cout << "ID already Exists.\n"; return false;}
            }
            return true;
        }


        void open(){
            int ch;
            do{
                try{
                    menu(ch);
                }
                catch(const char* str){
                    cout << str;
                }
            }while(ch != 5);
            
        }

        ~My_Library(){
            for(int i=0;i<library_items.size();i++){
                delete library_items[i];
            }
        }
};

int main(){

    cout << "\n         ==============================| BLACK KNIGHT LIBRARY |==============================\n";

    My_Library library;
    library.open();

    cout << "\n___________________________________________________________________________________________________________\n";

    return 0;
}