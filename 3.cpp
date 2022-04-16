#include <iostream>
#include <string>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <cctype> 
using namespace std;
int main()
{
    int k =0;
    multiset <string> slova;
    set <string> slova1;
    string s, s1, ch, s2;
    getline(cin, s);
    ch = "";

    for (int i=0;i<s.length()-1; i++){
        if (s[i]>='0' && s[i]<='9'){
            ch+=s[i];
            if (!(s[i+1]>='0' && s[i+1]<='9')) break;
        }
    }
    k = stoi(ch); 
    for (string::iterator it = s.begin(); it != s.end(); it++) if (!(isdigit(*it))) s1 += *it;
    
    for (int i=0;i<s.length()-1; i++){
        if (s[i]!=' ') s2+=s[i];
        else{
            slova.insert(s2);
            slova1.insert(s2);
            s2="";
        }
    }
    for (set<string>::iterator it = slova1.begin(); it != slova1.end(); it++)
    if (slova.count(*it)==k) cout << *it << " ";
    
    

    return 0;
}
    