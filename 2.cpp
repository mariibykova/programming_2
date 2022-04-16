#include <iostream>
#include <time.h>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <set>
#include <string>
using namespace std;
int main(){
    set <string> narrative, exclamation, interrogative;
    string s, s1, s2;
    getline(cin, s);
    s += ' ';
    for (int i=0; i<s.length(); i++){
        if (s[i]!='.' && s[i]!='!' && s[i]!='?'  ) s1+=s[i];
        else {
            if (s[i]=='.'){
                s1 += ' ';
                for (int j=0; j<s1.length(); j++){
                    if (s1[j]!=' ') s2+=s1[j];
                    else{
                        narrative.insert(s2);
                        s2="";}
                }
                s1=""; s2="";
            }
            if (s[i]=='!'){
                s1 += ' ';
                for (int j=0; j<s1.length(); j++){
                    if (s1[j]!=' ') s2+=s1[j];
                    else{
                        exclamation.insert(s2);
                        s2="";}
                }
                s1=""; s2="";
            }
            if (s[i]=='?'){
                s1 += ' ';
                for (int j=0; j<s1.length(); j++){
                    if (s1[j]!=' ') s2+=s1[j];
                    else{
                        interrogative.insert(s2);
                        s2="";}
                        
                }
                s1=""; s2="";
            }
            
        }
    }
    for (set<string>::iterator it = interrogative.begin(); it != interrogative.end(); ++it) narrative.erase(*it);
    for (set<string>::iterator it1 = exclamation.begin(); it1 != exclamation.end(); ++it1) narrative.erase(*it1);
    for (set<string>::iterator it2 = narrative.begin(); it2 != narrative.end(); ++it2) cout << *it2<<" ";
    
}

// cout ! put ? cout put nano.
