#include <iostream>

using namespace std;

class Example {
  private:
    static int obj_count;
    int m_x;

  public:
    Example(int x=10) {
        m_x = 10;
        m_y = 10;
    }
    int m_y;
    void set_x(int x) {
        m_x = x;
    }
    
    int get_x();

    static int get_obj_count() {
        return Example::obj_count;
    }

};

int Example::obj_count;

int Example::get_x() {
    return m_x;
}

Example e() {
    return Example();
}

int main() {
    Example s;

    #if 0
    // test static
    s.set_x(7);
    cout << s.get_x() << endl;
    cout << "obj count is: " << Example::get_obj_count() << endl;
    #endif

    #if 1
    /* test the diff between:
    Example e;
    and 
    Example e();
    */

    Example e();
    cout << e().get_x() << endl;

    e().set_x(100);
    cout << e().get_x() << endl;
        
    #endif   

}