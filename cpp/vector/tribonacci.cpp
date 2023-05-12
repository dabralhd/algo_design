#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

std::vector<int> tribonacci(std::vector<int> signature, int n)
{
  std::vector<int> result;
  result.resize(signature.size());
  copy_n(signature.begin(), std::min(n, (int)signature.size()), result.begin());

  if(signature.size()==3 && n>=2) {   
     
    for(int k=3;k<n; k++) 
      {
        result.insert(result.begin()+k, result[k-3] + result[k-2] + result[k-1]);        
      }
    }
  return result;
}

void test1() {
        std::vector<int> signature = { 1, 1, 1 };
        std::vector<int> expected = { 1, 1, 1, 3, 5, 9, 17, 31, 57, 105 };
        auto result = tribonacci(signature, 10);
        assert(std::equal(result.begin(), result.end(), expected.begin()));
}

void test2() {
        std::vector<int> signature = { 1, 2};
        std::vector<int> expected = { 1, 2};
        auto result = tribonacci(signature, 10);
        for_each(result.begin(), result.end(), [](int x){std::cout<<x << " ";});
        std::cout << std::endl;
        assert(std::equal(result.begin(), result.end(), expected.begin()));
}

int main() {
    //test1();
    test2();    
}