 /*Создать двусвязный список, содержащий целые числа. 
 Отсортировать список, используя сортировку пузырьком.*/
 
#include <iostream>
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
 void list_copy(list*& h1, list*& t1, list*& h, list*& t){
    list* p = h;
    while (p) {
        push(h1, t1, p->inf);
        p = p->next;
    }
}  

void bubbleSort(list* h, list* t){
    int s, i;
    list* p;
    if (h == NULL) return;
    do{
        s = 0;
        p = h;
        while (p->next){
            if (p->inf > p->next->inf){ 
                swap(p->inf, p->next->inf);
                s = 1;
            }
            p = p->next;
        }
      
    } while (s);
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
    list* h1 = NULL; list* t1 = NULL;
    list_copy(h1, t1, h, t);
    cout << endl << "Введен список: "; print(h1, t1);
    
    return 0;
}

