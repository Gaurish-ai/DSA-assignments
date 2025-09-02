#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  bool isBalanced(const string& s) {
    stack<char> st;
    for (char c : s) {
      if (c == '(' || c == '{' || c == '[') {
        st.push(c);
      } else if (c == ')' || c == '}' || c == ']') {
        if (st.empty()) return false;
        char top = st.top();
        if ((c == ')' && top != '(') ||
            (c == '}' && top != '{') ||
            (c == ']' && top != '[')) {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};

int main() {
  Solution s1; 

  vector<string> tests = {
      "{[()]}",
      "{[(])}",
      "{{[[(())]]}}",
      "([)]",
      "",
      "abc(def)[ghi]{jkl}",     
      "(()",                    
      "())",                   
  };

  for (const auto& t : tests) {
    cout << "Input: " << t << " -> "
         << (s1.isBalanced(t) ? "Balanced" : "Not Balanced") << '\n';
  }

  return 0;
}
