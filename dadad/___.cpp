#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
#include<iterator>
#include <string>
using namespace std;
void sort_P(vector <string> a,vector <string> b,vector <string> c, vector <int> e,  vector <int> d, int f, int l){
    int i =f; int j= l;
    int x, t = e[(f+l)/2];
    do{ while (e[i]<x) i++;
    while (e[j]>x) j--;
    if (i<=j){
        if (i<j){
            swap(a[i], a[j]);
            swap(b[i], b[j]);
            swap(c[i], c[j]);
            swap(d[i], d[j]);
            swap(e[i], e[j]);
        }
        i++; j--;}}
        while(i<=j);
        if (i<l) sort_P(a,b,c,d,e,i,l);
        if (f<j) sort_P(a,b,c,d,e,f,j);
    }
int main(){
    int n, m; 
    string s, s1, s2;
    cin >> n;
    vector <string> a, b, c;
    vector <int> d, e;
    for (int i=0; i<n; i++){
        cin >> s1; a.push_back(s1); // фамилия
        cin >> s1; b.push_back(s1); // должность
        cin >> s1; c.push_back(s1); // дата рождения
        cin >> m; d.push_back(m);   // стаж
        cin >> m; e.push_back(m);   // зарплата
    }
    for (int i=0; i<n; i++) cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << " " << e[i] << " " << endl;
    sort_P(a,b,c,d,e,0,n-1);
    cout << "DFG ";
    for (int i=0; i<n; i++) cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << " " << e[i] << " " << endl;
    return 0;
}