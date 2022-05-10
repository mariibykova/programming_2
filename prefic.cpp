#include<iostream>
#include<string>
using namespace std;
struct stack {
    char inf;
    stack* next;
};
void push(stack*& h, char x) {
    stack * r = new stack;
    r-> inf = x;
    r-> next = h;
    h = r;
}
char pop(stack*& h) {
    char i = h-> inf;
    stack * r = h;
    h = h-> next;
    delete r;
    return i;
}

int prior(char x) {
    if (x == '*' || x == '/')
    return 1;
    if (x == '+' || x == '-')
    return 0;
}

int main() {
    stack* pref = NULL;
    stack* operators = NULL;
    string s;
    getline(cin, s);
    
    int n = s.length();
    for (int i = n-1; i >=0; i--) {
        if (s[i] >= 'A' && s[i] <= 'Z') push(pref, s[i]);
        else{
            if (operators == NULL) push(operators, s[i]);
            else{
                if (prior(operators->inf) <= prior(s[i])) push(operators, s[i]);
                else {
                    while (operators&&prior(s[i]) < prior(operators->inf)) push(pref, pop(operators));
                    push(operators, s[i]);
                    
                }
            }
        }
    }
    while (operators) push(pref, pop(operators)); 
    while (pref) cout << pop(pref);
    return 0;
    
} 
