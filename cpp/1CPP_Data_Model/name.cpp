#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class Name {
    public:
        explicit Name(string s) {
            cout << "- one argument constructor" << endl;
            vector<string> parts;
            auto start = 0;
            auto stop = 0;
            while((stop = s.find(" ", start)) != string::npos) {                
                parts.push_back(s.substr(start, stop-start));
                start = stop + 1;
            }
            parts.push_back(s.substr(start));
            fname = parts[0];
            if (parts.size() > 2) {
                mname = parts[1];
                lname = parts[2];
            } else if (parts.size()==2) {
                lname = parts[1];
            }
        }

        Name(string f, string m, string l) : fname {f}, mname {m}, lname {l} {
                        cout << "- three argument constructor" << endl;
        }
        Name(string f, string l) : fname {f}, mname {}, lname {l} {
            cout << "- two argument constructor" << endl;
        }
        string getName() const {
            return fname + get_name_part(mname) + get_name_part(lname);
        }
        Name(const Name& other) {
            //cout << "copy constructor: " << endl;
            fname = other.fname;
            mname = other.mname;
            lname = other.lname;
        }

        //add a construcor from int just for demo
        Name(int i) : fname{to_string(i)} {
            cout << "- constructing from int" << endl;
        }

        string get_fname() const { return fname; }
        string get_lname() const { return lname; }

    private:
        string fname;
        string mname;
        string lname;
        inline string get_name_part(string word) const {
            return word.empty()? word : string(" ") + word;
        }
        static const unsigned int k_max_name_length = 100;

};

class FirstNameComp {
    public:
        bool operator()(const Name& first, const Name& second) const {
            return first.get_fname() < second.get_fname();
        }
};

class LastNameComp {
    public:
        bool operator()(const Name& first, const Name& second) const {
            return first.get_lname() < second.get_lname();
        }
};

vector<Name> get_names_from_file(string file_name) {
    ifstream ifs(file_name, ios::in);
    vector<Name> vn;

    if (!ifs) {
        cerr << "error while reading file: " << file_name << endl;
        return vn;
    }

    string s;
    while (getline(ifs, s)) {
        Name nm(s);
        //clog << nm.getName() << endl;
        vn.push_back(nm);    
    }

    ifs.close();
    return vn;    
}

void read_and_sort_test() {
    auto vn = get_names_from_file("names.txt");
    cout << "list of names read from file" << endl;
    for(const auto& n : vn)
        cout << n.getName() << endl;

    cout << endl << "sorting on the basis of first name: " << endl;
    sort(vn.begin(), vn.end(), FirstNameComp());
    for(const auto& n : vn)
        cout << n.getName() << endl;

    cout << endl << "sorting on the basis of last name: " << endl;
    sort(vn.begin(), vn.end(), LastNameComp());
    for(const auto& n : vn)
        cout << n.getName() << endl;
}

void f(Name nm) {
    cout << nm.getName() << endl;
}

void constructor_test() {
    Name nm {"Hem Dutt Dabral"};
    cout << nm.getName() << endl;
    //nm = string("Vinod singh");
    //cout << nm.getName() << endl;
    Name num {1};
    cout << num.getName() << endl;
    num = 2;
    cout << num.getName() << endl;
}
 

int main() {
    //read_and_sort_test();
    constructor_test();
    
    return 0;  
}