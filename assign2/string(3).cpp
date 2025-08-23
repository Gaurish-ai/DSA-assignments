#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
string s;
cout<<"enter the string: ";
getline(cin,s);
sort(s.begin(),s.end());
cout<<"sorted string is : ";
cout<<s<<endl;

// to lower
for(int i=0;i<s.size();i++)
{
   s[i]=tolower(s[i]);
}
cout<<s;
}