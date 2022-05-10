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
	int n, x; cin >> n;
	stack* h = NULL;
	for (int i = 0; i < n; i++) {
		cin >> x;
		push(h, x);
	}

	stack* head_copy = NULL;
	stack* head1 = NULL;

	while (h) {
		int i = pop(h);
		if (i % 2 != 0) push(head1, i);
		if (i % 2 == 0) push(head_copy, i);
	}

	reverse(head_copy);

	while (head_copy) push(head1,pop(head_copy));

	while (head1) cout << pop(head1) << " ";

}
