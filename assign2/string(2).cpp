#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int n = (int)s.size();
    for (int i = 0; i < n; ) {
        char c = s[i];
        bool isVowel =
            c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U';
        if (isVowel) {
            // shift left from i+1
            for (int j = i + 1; j < n; ++j) {
                s[j - 1] = s[j];
            }
            --n;          
        } else {
            ++i;
        }
    }
    s.resize(n);  // apply the shrink once at the end
    cout << "string without vowels is : " << s << '\n';
    return 0;
}
