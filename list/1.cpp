//  Создать двусвязный список, содержащий целые числа. Удалить все максимальные элементы
#include<iostream>
using namespace std;
struct list{
    int inf;
    list* next;
    list* prev;
};
void push(list*& h, list*& t, int x) {
    list* r = new list;
    r->inf = x;
    r->next = NULL;
    if (!h && !t) {
        r->prev = NULL;
        h = r;
    }
    else {
        t->next = r;
        r->prev = t;
    }
    t = r;
}
void print(list* h, list* t) {
    list* p = h;
    while (p){
        cout << p->inf << " ";
        p = p->next;
    }
}
list *find ( list *h, list *t, int x){ 
    list *p = h; 
    while (p){ 
        if (p->inf == x) break;
        p = p->next; 
    }
    return p;
}
void del_node(list*& h, list*& t, list* r){
    if (r == h && r == t) h = t = NULL;
    else if (r == h){
        h = h->next;
        h->prev = NULL;
    }
    else if (r == t){
        t = t->prev;
        t->next = NULL;
    }
    else{
        r->next->prev = r->prev;
        r->prev->next = r->next;
    }
    delete r;
}
void list_copy(list*& h1, list*& t1, list*& h, list*& t){
    list* p = h;
    while (p) {
        push(h1, t1, p->inf);
        p = p->next;
    }
}
int main(){
    setlocale(LC_ALL, "Rus");
    int n, x, max;
    cin >> n; max =0;
    list* h = NULL; list* t = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x; 
        push(h, t, x);
        if (x>max) max = x;
    }

    list* h1 = NULL; list* t1 = NULL;
    list_copy(h1, t1, h, t);
    cout << endl << "Введен список: "; print(h1, t1);
    h1 = NULL; t1 = NULL;

    list_copy(h1, t1, h, t);
    while(find(h1, t1, max)) del_node(h1, t1, find(h1, t1, max));
    cout << endl << "Удаление всех максимумов "; print(h1, t1);

    return 0;
}