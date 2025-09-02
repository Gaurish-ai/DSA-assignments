#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s; 
    stack<char> st;
    for (size_t i = 0; i < s.size(); ++i) {
        st.push(s[i]);
    }
for (size_t i = 0; i < s.size(); ++i) {
        s[i] = st.top();
        st.pop();
    }

    cout << "reversed string is : " << s << '\n';
    return 0;
}
