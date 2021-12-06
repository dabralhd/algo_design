#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << __cplusplus;
    
    unsigned int iters[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(const auto& i: iters) {
        cout << n << " x " << i << " = " << n*i << endl;
    }    

    return 0;
}
