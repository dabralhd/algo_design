#include <array>
#include <iostream>
#include <stdexcept>


template <typename T>
class MyStack {
 protected:
  const int maxSize;
  T* s;
  int stackTop;

 public:
  MyStack() : maxSize{100}, stackTop{-1}, s{new T[100]} {}

  MyStack(const MyStack& s1) = delete;

  MyStack& operator=(const MyStack& s1) = delete;

  void push(T x) {
    if (stackTop != maxSize - 1) {
      s[++stackTop] = x;
      return;
    }

    throw std::overflow_error("stack is full!");
  }

  const T& top() {
    if (!empty()) {
      return s[stackTop];
    }

    throw std::underflow_error("stack is empty!");
  }

  void pop() {
    if (!empty()) {
      --stackTop;
      return;
    }

    throw std::underflow_error("stack is empty!");
  }

  bool empty() {
    if (stackTop == -1) return true;
    return false;
  }
};

template <typename T>
class NodeWithMin {
  private:
    T data;
    T min;

  public:
    NodeWithMin(T d, T prev_min) : data(d) {
      if(m<min)
        min = m;
      return min;
    }

    const T& min() {
      return min;
    }

    const T& data() {
      return data;
    }   

};

template <typename T>
class MyStackWithMin : public MyStack {
    private:

    


};

void testStack() {
    MyStack<int> s1;

  s1.push(1);
  s1.push(2);

  while (!s1.empty()) {
    std::cout << s1.top() << " ";
    s1.pop();
  }

  std::cout << "\n";
}

void testStackWithMin() {
  MyStack<NodeWithMin> s2;

  s2.push(NodeWithMin(5));
  s2.push(NOde)
}

int main() {

  return 0;
}