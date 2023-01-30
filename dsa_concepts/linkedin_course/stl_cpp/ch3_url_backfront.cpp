#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    deque<string> urls;
    int option = 0;
    string str;
    string url;
    int counter = 0;
    deque<string>::reverse_iterator it;

    while(option >= 0) {    
        cout << "[1] Enter url  [2] Go back  [3] Go Front" << endl;
        cin >> str;
        option = stoi(str);

        if(option == 1) {
            cout << "Enter url: " << endl;            
            cin >> url;
            urls.push_back(url);
            it = urls.rbegin();
        } else if(option==2) {
            cout << "Going back: " << endl;
            if(it!=urls.rend())
                ++it;
        } else if(option==3) {
            cout << "Going front: " << endl;
            if(it!=urls.rbegin())
                --it;
        }
        cout << "URL is: " << *it;
    }

    cout << "present state of deque is (in reverse order):" << endl;

    cout << "{ ";
    for(it=urls.rbegin(); it!=urls.rend(); it++)
        cout << *it << "  ";
    cout << "}";

    return 0;    
}
