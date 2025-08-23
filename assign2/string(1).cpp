#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string s1;
    string s2;
    cout<<"enter 1st string: ";
    getline(cin,s1);
    cout<<"enter 2nd string: ";
    getline(cin,s2);
   cout<<"concatenated string: ";
    s1+=s2;
    cout<<s1;
    // reverse a string
    reverse(s1.begin(),s1.end());
    cout<<endl;
    cout<<"reversed string is : "<<s1;
    

}
