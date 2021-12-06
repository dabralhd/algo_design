#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

class Number {
    public:
        Number() { }

        Number(string str) {
            const char * cstr = str.c_str();

            for(int i=0; i<strlen(cstr); ++i) { 
                if(!isdigit(cstr[i])) { 
                    return;        
                }
                char c = cstr[i];
                num.push_front(c - '0');
            }
        }

        void show_num() const {
           for(list<int>::const_reverse_iterator it=num.rbegin(); it!=num.rend(); ++it)   cout << *it;
           cout << endl;
        }

        const list<int>& get_num() { return num; }


        Number& operator+=(Number n) {
            int carry = 0;
            list<int>::iterator n_it = n.num.begin();
            list<int>::iterator it = num.begin();

            while(n_it!=n.get_num().end() && it!=num.end()) {
                int sum = *n_it + *it + carry;
                carry = sum / 10;
                sum = sum % 10;
                *it = sum;
                ++it;
                ++n_it;
            }

            list<int> new_list;

            while(n_it!=n.num.end()) {
                int sum = *n_it + carry;
                carry = sum / 10;
                sum = sum % 10;
                new_list.push_back(sum);
                ++n_it;
            }

            while(it!=num.end()) {
                int sum = *it + carry;
                carry = sum / 10;
                sum = sum % 10;
                *it = sum;
                ++it;
            }

            if(carry) new_list.push_back(carry);

            num.splice(num.end(), new_list);

            return *this;
        }

    private:
        list<int> num;
};

void test1() {
    Number n1 {"21"};
    Number n2 {"347"};

    n1.show_num();
    n2.show_num();    

    n1 += n2;

    n1.show_num();
    n2.show_num();
}


void test2() {
    Number n1 {"1234"};
    Number n2 {"347"};

    n1.show_num();
    n2.show_num();    

    n1 += n2;

    n1.show_num();
    n2.show_num();
}

int main() {

    test2();
    return 0;
}