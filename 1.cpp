#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int n, c; 
    set <int> b; // описали сет
    cin >> n; // длина послдовательности
    vector <int> a; 
    for (int i=0; i<n; i++){
        cin >> c;
        a.push_back(c);
    }
     for(vector<int>::iterator it = a.begin(); it != a.end(); it ++) 
     if (*it>9 && *it<100){
         b.insert(*it%10);
         b.insert(*it/10);
     }
    
    
    
    for(set<int>::iterator it1 = b.begin(); it1 != b.end(); it1 ++) cout << *it1 << " ";
    cout << endl;
    return 0;
}
