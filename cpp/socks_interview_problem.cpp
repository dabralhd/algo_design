#include <iostream>
#include <vector>
#include <map>

// problem description => There is a large pile of socks that must be paired by color. 
// Given an array of integers representing the color of each sock, 
// determine how many pairs of socks with matching colors there are.

using namespace std;

int show_colors(vector<int> clr) {
    cout << "total number of colors: " << clr.size() << endl;
    for (int i=0; i<clr.size(); i++) {
        cout << "color[" << i <<"]: " << clr[i] << endl;
    }

    return 0;
}

int main() {

    unsigned int num_color = 0;
    vector<int> colors;

    cout << "enter number of colors" << endl;
    cin >> num_color;

    cout << "now enter the color codes" << endl;

    for(int i=0; i<num_color; i++) {
        int c;
        cin >> c;
        colors.push_back(c);
    }
    
    cout << "folloiwng input obtained:" << endl;
    show_colors(colors);

    map<int, int> c_count; // map holding count of each color code
    
    // count number of occurences of each color
    for(auto const& c:colors) {
        c_count[c] += 1;
    }           

   
    cout << "count of:" << endl;
    for(auto const& c:c_count) {
        cout << "count_of[" << c.first << "]:" << c.second << endl; 
    }        
 
    // now calculate pairs, by dividing by 2
    unsigned int total_pairs = 0;
    for(auto const& c:c_count) {
        c_count[c.first] = c.second/2;
        total_pairs += c_count[c.first];
    }          

    cout << "pair of:" << endl;
    for(auto const& c:c_count) {
        cout << "pairs_of[" << c.first << "]:" << c.second << endl; 
    }    
}