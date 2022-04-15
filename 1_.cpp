#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int A, B;
bool check(int x){
    return (x >= A && x <= B);
} 

int main(){
    int n, c;
    vector<int> a;
    cin >> n; // длина вектора
    for(int i = 0; i < n; i++){   // ввод вектора
        cin >> c;
        a.push_back(c);
    }
    cin >> A >> B;  // границы отрезка
    
    vector<int>::iterator it = remove_if(a.begin(), a.end(), check);
    a.erase(it, a.end());
    
    cout <<accumulate(a.begin(), a.end(), 0)<< " ";

    return 0;
}
