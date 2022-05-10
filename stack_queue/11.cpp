#include<iostream>
using namespace std;
struct queue {
    int inf;
    queue *next;
};
void push (queue *&h,queue *&t, int x){ 
    queue *r = new queue; 
    r->inf = x;
    r->next = NULL; 
    if (!h && !t) h = t = r; 
    else {
        t->next = r; 
        t = r;
    }
}
int pop (queue *&h, queue *&t){ 
    queue *r = h; 
    int i = h->inf; 
    h = h->next; 
    if (!h) t = NULL;
    delete r; 
    return i;
}
int main(){
    int n, x; cin >> n;
    queue *h = NULL; queue *t = NULL;
    for(int i = 0; i < n; i++){
        cin >> x;
        push(h, t, x);
    }
    queue *h1 = NULL; queue *t1 = NULL;
    queue *h_copy = NULL; queue *t_copy = NULL;
    while(h){
        int i=pop(h, t);
        if (i<0) push(h1, t1, i);
        if (i>=0) push(h_copy, t_copy, i);
    }
    while(h_copy){
        push(h1, t1, pop(h_copy, t_copy));
    }
    while(h1) cout << pop(h1, t1) << " ";
    return 0;
}


