#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setprecision;

int main() {
    double sum = 0;
    double grade = 0;
    int count = 0;

    while( cin >> grade && grade>0) {
        sum += grade;
        count++;
    }

    const auto prec = cout.precision();
    cout << "Average grade is: " << setprecision(4) 
         << sum/count 
         << setprecision(prec) 
         << endl;

    return 0;
}