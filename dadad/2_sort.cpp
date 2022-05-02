#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
void CountingSort(vector<int> a, int n){
    vector<int> c;
    int k=15;
    for (int i = 0; i < k; i++) 
        c[i] = 0;

    for (int i = 0; i < n; i++) 
        c[a[i]] = c[a[i]] + 1;


    for (int i = 0; i< k; i++) 
        for (int j=0; j<i; j++) cout << i << " ";
}
int main(){
    int n, m, c; cin >> n >> m;
    vector < vector <int> > a(n, vector <int> (m) ); 
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >>a[i][j];
    
    cout << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;cout << endl;
    
    for (int i=0; i<n; i++) {
        cout <<"FG";
        CountingSort(a[i], m);
        cout <<"FG";
        cout << endl;
        
    }
        
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
 
    return 0;
}

