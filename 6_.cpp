#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int X;
bool odd(int x) {
    return x % X;
}
bool is_duo(int element) {
    return !(element % 2);
}

int main(){
    int c, S, n;
    vector<int> a, b;
    cin >> n; // длина вектора
    for(int i = 0; i < n; i++){   // ввод вектора
        cin >> c;
        b.push_back(c);
    }
    cin >> X;  // элемент X
    a =b;
    // Сумма кратных
    vector<int>::iterator it = remove_if(a.begin(), a.end(), odd);
    a.erase( it , a.end());
    cout << "Сумма " << accumulate(a.begin(), a.end(), 0) << endl;
    a =b;
    // Минимум
    cout << "Минимальный элемент " <<*min_element(a.begin(), a.end()) << endl;
    a=b;
    // Максимум
    int max = *max_element(a.begin(), a.end());
    replace_if(a.begin(), a.end(), is_duo, max);
    cout << "Новая посследовательность " << endl;
    for(vector<int>::iterator iter = a.begin(); iter != a.end(); iter ++) cout << *iter << " ";
    
    return 0;
}