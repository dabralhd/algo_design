#include <unordered_set>
#include <map>
#include <string>
#include <iostream>

class PrimeDecomp
{
  static std::unordered_set<int> cache;
  static bool is_prime(int n) {
     if (cache.find(n)!=cache.end())
       return true;
    
      for (int i=2; i<n; i++) {
        if (n % i == 0)
          return false;
      }
    
    cache.insert(n);
    return true;
  }
  
public:
    static std::string factors(int lst) {
      std::string ret;
      std::map<int, int> m;
      for(int i=2; i<=lst; i++) {
        if(is_prime(i) && lst%i==0) {
          m[i] = 0;
          
          while (lst%i==0) {            
            lst /= i;
            m[i] += 1;   
           }
        }
      }
        
        for(auto& p : m) {
          if(p.second==1)
            ret = ret + "(" + std::to_string(p.first) + ")";
          else            
            ret += "(" + std::to_string(p.first) + "**" + std::to_string(p.second) + ")";
        }
        return ret;           
    }
};
std::unordered_set<int> PrimeDecomp::cache;


int main() {
    auto num = 10;
    std::cout << "given number " << num << ": " << PrimeDecomp::factors(num) << std::endl;

    num = 20;
    std::cout << "given number " << num << ": " << PrimeDecomp::factors(num) << std::endl;

    num = 25;
    std::cout << "given number " << num << ": " << PrimeDecomp::factors(num) << std::endl;        
}