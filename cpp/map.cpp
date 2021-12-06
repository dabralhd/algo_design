#include <iostream>
#include <map>

using namespace std;

int experiment_1() {
        map<int, int> dict;

    dict[10] = 1;
    dict[20] = 2;
    dict[30] = 3;
    dict[40] = 4;

    auto size = dict.size();

    for(int i=0; i<size+2; i++) {
        cout << dict[i*10+10] << endl; 
    }

    return 0;
}

int experiment_2() {
        map<int, int> dict;

    dict[0] = 0;
    dict[1] = 0;

    dict[2] = dict[3] + 1;
    dict[3]++;

    auto size = dict.size();

    for(int i=0; i<size; i++) {
        cout << dict[i] << endl; 
    }
    return 0;
}


int main() {
    //experiment_1();
    experiment_2();

    return 0;
}