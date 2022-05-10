#include<iostream>
using namespace std;
struct stack{
	int inf;
	stack * next;
};
int pop(stack*& h) { 
	int i = h -> inf;
	stack * r = h;
	h = h -> next;
	delete r;
	return i;

}
void push(stack *&h, int x){
    stack *r = new stack;
    r->inf = x;
    r->next = h;
    h = r;
}

void reverse(stack*& h) { 
	stack * head1 = NULL;
	while (h) {
		push(head1, pop(h));
	}
	h = head1; 
	
}

int main() {
	int n, x; cin >> n; int max=-1000000;
	stack* h = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x>max) max=x;
		push(h, x);
	}

	stack* head1 = NULL;
	while (h) {
		int i = pop(h);
		if (i!=max) push(head1, i);

	}
	while (head1) cout << pop(head1) << " ";

}
