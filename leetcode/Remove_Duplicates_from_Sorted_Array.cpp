#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(vector<int> & vec) {
    cout << "remove_duplicates>>>>" << endl;
    vector<int>::iterator first = vec.begin();
    vector<int>::iterator second = vec.begin();  

    while(next(second)!=vec.end() && next(first)!=vec.end()) {
        if (*second == *next(second)) {
           ++second;
        } else {
            *++first = *++second;                       
        }
        
    }

    cout << "remove_duplicates<<<<" << endl;
    return 0;
}


void print_vector(vector<int> v, const string desc) {
    cout << "vector length: " << v.size() <<endl;
    cout << desc << ": ";


    vector<int>::iterator itr = v.begin();
    while(itr!=v.end()) {
        cout << *itr << " ";
        itr++;
    }
    cout << endl;
    return;
}

void test1() {
    cout << "test1" << endl;    
    vector<int> A {1,2,5,5,6,7,8,9,9,9,15,87,87,87,87,87,87};

    print_vector(A, "unsqeezed");
    remove_duplicates(A);
    print_vector(A, "  sqeezed");
}

void test2() {
    cout << "test2" << endl; 
    vector<int> A {1, 1, 2, 2};

    print_vector(A, "unsqeezed");
    remove_duplicates(A);
    print_vector(A, "  sqeezed");
}

void test3() {
     cout << "test3" << endl;   
    vector<int> A {1, 1};

    print_vector(A, "unsqeezed");
    remove_duplicates(A);
    print_vector(A, "  sqeezed");
}

void test4() {
    cout << "test4" << endl;
    vector<int> A {1, 2};

    print_vector(A, "unsqeezed");
    remove_duplicates(A);
    print_vector(A, "  sqeezed");
}


int main() {
    test1();  
    test2();  
    test3();  
    test4();  

    return 0;
}