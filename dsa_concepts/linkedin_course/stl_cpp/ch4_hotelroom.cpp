#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string input_str;
    int room_num = 0;
    string guest_name;
    map<pair<int, int>, string> guest_info;

    while(room_num>=0) {
        cout << "Enter room number: " << endl;
        getline(cin, input_str);
        room_num = stoi(input_str);
        int floor_num = room_num / 100;
        if(room_num>=100) {  
            room_num = room_num % 100;
            if(room_num>0 && room_num<=15) {
                pair<int, int> room_id;
                room_id.first = floor_num;
                room_id.second = room_num;
                cout << "Enter guest name: " << endl;
                getline(cin, guest_name);
                guest_info[room_id] = guest_name;
            }
        }
    }

    cout << "Now showing information:" << endl;

    cout << "{ ";
    for(map<pair<int, int>, string>::iterator it=guest_info.begin(); it != guest_info.end(); ++it) {
        cout << "floor: " << it->first.first << ", room: " << it->first.second << ": guest name: " << it->second ;
    }
    cout << " }";


    return 0;
}