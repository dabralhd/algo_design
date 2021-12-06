#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>
#include <ctime>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

class TestDataEmptyArray {
private:
public:
    static vector<int> get_array() {
	vector<int> vec;
	return vec;
    }

};

class TestDataUniqueValues {    
private:
        static const int max_size;
        static const int max_element_val;
	static int min_index;
public:
    TestDataUniqueValues() {
        //srand(time(NULL));
        srand(42);
     }

    static void set_min_index(int i) {
	   min_index = i;
    }
     
    static vector<int> get_array() {
        int count = 2 + rand()%(max_size-2);
        set<int> vals;      

        while(vals.size()!=count) {
            vals.insert(rand()%max_element_val);
        } 
        
        vector<int> x(vals.begin(), vals.end());
        vector<int> ret = x;
	set_min_index(minimum_index(ret));
        return ret;
    } 

    static int get_expected_result() {
        // complete this function
	return min_index;
	
    }

};

const int TestDataUniqueValues::max_size = 12;
const int TestDataUniqueValues::max_element_val = 100;
int TestDataUniqueValues::min_index = -1;

class TestDataExactlyTwoDifferentMinimums {
private:
  static TestDataUniqueValues values;
public:
   
    TestDataExactlyTwoDifferentMinimums() {}

    static vector<int> get_array() {        
        vector<int> arr = TestDataUniqueValues::get_array();
        int min_idx = TestDataUniqueValues::get_expected_result();
        arr.push_back(arr[min_idx]);
        return arr;
    }

    static int get_expected_result() {
	    return TestDataUniqueValues::get_expected_result();
    }

};


void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array();
        auto result = minimum_index(seq);
    } catch (invalid_argument& e) {
        return;
    }
    assert(false);
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}
