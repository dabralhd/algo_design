#include <iostream>
#include <vector>

using namespace std;

class Rectangle {
    private:
        int length, breadth;
    public:
        Rectangle(int len, int br) : length { len }, breadth { br }
        {
            cout << "creating object: len=" << length << ", br=" << breadth << endl;
        }

        Rectangle() : Rectangle(0, 0)
        {
            cout << "creating object: 2" << endl;
        }

        // copy constructor
        Rectangle(const Rectangle& rec) : length { rec.length }, breadth { rec.breadth }
        { 
            cout << "copy constructor" << endl;
        }

        // copy assignment
        Rectangle& operator=(const Rectangle& rhs) {
            length = rhs.length;
            breadth = rhs.breadth;
            cout << "copy-assignment operator" << endl;
            return *this;
        }

        void transform() {
            length *= 2;
        }

};

void transform(Rectangle r) {
    r.transform();
}

int main() {
    #if 0
        //Rectangle r1;
        Rectangle r1(1, 2);    
        transform(r1);
    #endif 

    #if 0
        //Rectangle r1;
        Rectangle r1(1, 2);    
        transform(r1);
    #endif 

    #if 0
        vector<Rectangle> vr;
        Rectangle r1(1, 2);    
        vr.push_back(r1);         
        transform(vr[0]);
    #endif 

    #if 1
        vector<Rectangle> vr;
        //Rectangle r1(1, 2);    
        //vr.push_back(r1);  
        vr.push_back(Rectangle { 2,2 });
        vr[0].transform();
        //transform(vr[0]);
    #endif 

    return 0;
}