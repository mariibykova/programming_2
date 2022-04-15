#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <numeric>

using namespace std;
bool odd1(int x) {
    return x % 2==0;
}
bool odd2(int x) {
    return x % 2!=0;
}
int main()
{
    int n, c, m;
    vector<int> a,b;
    cin >> n;  //длина первой последовательности 
    for (int i=0; i<n; i++){ // ввод первой последовательности
        cin >> c;
        a.push_back(c);
    }
    
    cin >> m;  //длина второй последовательности 
    for (int i=0; i<m; i++){ // ввод второй последовательности
        cin >> c;
        b.push_back(c);
    }

    cout << "Удаление чётных в первой последовательности" << endl;
    vector<int>::iterator it = remove_if(a.begin(), a.end(), odd1);
    a.erase( it , a.end());
    for(vector<int>::iterator iter = a.begin(); iter != a.end(); iter ++) cout << *iter << " ";
    cout << endl;
     
    cout << "Удаление нечётных во второй последовательности" << endl;
    vector<int>::iterator it2 = remove_if(b.begin(), b.end(), odd2);
    b.erase( it2 , b.end());
    for(vector<int>::iterator iter = b.begin(); iter != b.end(); iter ++) cout << *iter << " ";
    cout << endl;
    
    cout << "Сортировка первой последоватеьности" << endl;
    sort(a.begin(), a.end());
    for(vector<int>::iterator iter = a.begin(); iter != a.end(); iter ++) cout << *iter << " ";
    cout << endl;
    
    
    cout << "Сортировка второй последоватеьности" << endl;
    sort(b.begin(), b.end());
    for(vector<int>::iterator iter = b.begin(); iter != b.end(); iter ++) cout << *iter << " ";
    cout << endl;
    
    cout << "Объединение в один и сортировка" << endl;
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());
    for(vector<int>::iterator iter = a.begin(); iter != a.end(); iter ++) cout << *iter << " ";
    return 0;
}


/*
5      
2 3 1 4 5
6
2 4 3 6 5 1
*/














