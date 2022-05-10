/* Создать двусвязный список, содержащий целые числа. 
Изменить список, переместив в начало четные числа, потом нечетные. */

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
    }

    list* H1 = NULL; list* T1 = NULL;
    list* h1 = NULL; list* t1 = NULL;
    list* h2 = NULL; list* t2 = NULL;
    list_copy(H1, T1, h, t);

    cout  << "Введен список: "; print(H1, T1);
    list* H2 = NULL; list* T2 = NULL;
    list_copy(H2, T2, h, t); 

    while(H2){
        if (H2->inf %2 ==0) push(h1, t1, H2->inf);
        else push(h2, t2, H2->inf);
        H2 = H2 -> next;
 
    }
    
    while(h2){
        push(h1, t1, h2->inf);
        h2 = h2 -> next;
    }
    cout << endl << "Изменение массива "; print(h1, t1);

    return 0;
}
