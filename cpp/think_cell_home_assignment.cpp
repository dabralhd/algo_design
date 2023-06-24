#include <map>
#include <iostream>

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.
	void assign( K const& keyBegin, K const& keyEnd, V const& val ) {
        if (keyBegin < keyEnd) {
            m_map[keyBegin] = val;
            const auto itr1 = m_map.upper_bound(keyBegin);
            auto itr2 = m_map.lower_bound(keyEnd);                    
            auto v = m_valBegin;
            if(itr2!=m_map.end()) {
                v = (--itr2)->second;
                itr2++;
            }
            m_map.erase(itr1, itr2);
            m_map[keyEnd] = v;
        }   
    }

    // look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};

void test1() {
    interval_map<int, char> imap('A');
    
    for(int i=-2; i<=5; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}

void test2() {
    interval_map<int, char> imap('A');
    
    imap.assign(1, 6, 'B');
    for(int i=-2; i<=10; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}

void test3() {
    interval_map<int, char> imap('A');
    
    imap.assign(1, 3, 'B');
    imap.assign(10, 5, 'C');    
    for(int i=-2; i<=5; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}

void test4() {
    std::cout << "test4" << std::endl;
    interval_map<int, char> imap('A');
    
    imap.assign(1, 6, 'B');
    imap.assign(6, 10, 'C');    
    for(int i=-2; i<=10; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}

void test5() {
    std::cout << "test5" << std::endl;
    interval_map<int, char> imap('A');
    
    imap.assign(1, 6, 'B');
    imap.assign(4, 8, 'C');    
    for(int i=-2; i<=10; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}

void test6() {
    std::cout << "test6" << std::endl;
    interval_map<int, char> imap('A');
    
    imap.assign(1, 6, 'B');
    imap.assign(4, 8, 'C');  
    imap.assign(6, 9, 'D'); 
    imap.assign(2, 9, 'E');           
    for(int i=-2; i<=10; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}

void test7() {
    std::cout << "test7" << std::endl;
    interval_map<int, char> imap('A');
    
    imap.assign(1, 6, 'B');
    imap.assign(4, 8, 'C');  
    imap.assign(6, 9, 'D'); 
    imap.assign(2, 9, 'E');       
    imap.assign(-1, 10, 'F');            
    for(int i=-2; i<=10; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}

void test8() {
    std::cout << "test8" << std::endl;
    interval_map<int, char> imap('A');
    
    imap.assign(1, 6, 'B');
    imap.assign(4, 8, 'C');  
    imap.assign(6, 9, 'D'); 
    imap.assign(2, 9, 'E');       
    imap.assign(-1, 10, 'F');  
    imap.assign(-10, 25, 'G');              
    for(int i=-12; i<=28; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}

void test9() {
    std::cout << "test9" << std::endl;
    interval_map<int, char> imap('A');
    
    imap.assign(1, 4, 'B');
    imap.assign(4, 8, 'C');  
    imap.assign(8, 12, 'D'); 
    imap.assign(12, 16, 'E');       
    imap.assign(16, 18, 'F');  
    imap.assign(5, 10, 'G');              
    for(int i=-12; i<=28; i++) {
        auto val = imap[i]; 
        std::cout << i << ": " << val << std::endl;
    }
    std::cout << std::endl;
}



void IntervalMapTest() {
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    test9();
}

int main() {
    IntervalMapTest();
}

