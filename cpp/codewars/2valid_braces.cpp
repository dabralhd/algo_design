#include <stack>
#include <unordered_set>

using namespace std;

bool valid_braces(std::string braces) 
{
  unordered_map<char, char>  m { {'{', '}'}, 
                                    {'[',  ']'},
                                    {'(',  ')'}};
  
  stack<char> s;
  for(auto c : braces){
      if (m.find(c)!=m.end()) {
        s.push(c);
      } else if(!s.empty()) {
        auto t = s.top();
        s.pop();   
        if (m[t] != c)
          return false;        
      } else {
        return false;
      }
    }
  return true;
}