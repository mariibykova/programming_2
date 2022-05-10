#include <iostream>             
#include <vector>              
#include <string>               
#include <fstream>              
using namespace std;

struct stack {   
	int inf;
	stack* next;
};
struct queue {      
	int inf;
	queue* next;
};

void push_stack(stack*& h, int x) {    
	stack* r = new stack;
	r->inf = x;
	r->next = h;
	h = r;
}
void push_queue(queue*& h, queue*& t, int x) {    
	queue* r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h and !t) {
		h = t = r;
	}
	else {
		t->next = r;
		t = r;
	}
}

int pop_stack(stack*& h) {   
	int i = h->inf;
	stack* r = h;
	h = h->next;
	delete r;
	return i;
}
int pop_queue(queue*& h, queue*& t) {     
	int i = h->inf;
	queue* r = h;
	h = h->next;
	if (!h)
		t = NULL;
	delete r;
	return i;
}

void GrBrTr(vector<vector<int>> Gr, int N, int*& A, int x) {    
	queue* head = NULL;                                          
	queue* tail = NULL;
	A[x] = 1;                             
	push_queue(head, tail, x);             
	cout << x << " ";                      
	while (head) {                                   
		pop_queue(head, tail);                         
		for (int i = 1; i < Gr[x].size(); ++i)         
			if (A[Gr[x][i]] == 0) {                       
				int y = Gr[x][i];
				A[y] = 1;                                   
				push_queue(head, tail, y);                  
				cout << y << " ";                            
			}
	}
	for (int i = 0; i < N; ++i)               
		if (A[i] == 0)
			GrBrTr(Gr, N, A, i);         
}

void GrDepthTr(vector<vector<int>> Gr, int N, int*& B, int x) {   // глубина   
	int y;
	stack* head = NULL;                                        
	B[x] = 1;                                                  
	push_stack(head, x);                                       
	cout << x << " ";                                         
	bool f1 = false;
	while (head) {                                        
		x = head->inf;                                        
		for (int i = 1; i < Gr[x].size(); ++i) {
			if (B[Gr[x][i]] == 0) {                             
				y = Gr[x][i];
				f1 = true;
				break;          
			}
		}

		if (f1) {         
			B[y] = 1;                  
			push_stack(head, y);       
			cout << y << " ";          
			f1 = false;
		}
		else pop_stack(head);     
	}

	for (int i = 0; i < N; ++i)       
		if (B[i] == 0)
			GrDepthTr(Gr, N, B, i);       
}

int main() {
	setlocale(LC_CTYPE, "russian");         
	int i = 0;
	vector<vector<int>> Gr;
	Gr.resize(1000);
	string str, x;
	ifstream in("input (2).txt");      

	while (getline(in, str)) {      
		x = "";
		for (int j = 0; j < str.length(); ++j) {
			if (str[j] != ' ')
				x += str[j];
			else {
				Gr[i].push_back(stoi(x));
				x = "";
			}
		}
		Gr[i].push_back(stoi(x));
		i++;
	}

	int* A = new int[i];              
	for (int j = 0; j < i; ++j)
		A[j] = 0;

	int* B = new int[i];              
	for (int j = 0; j < i; ++j)
		B[j] = 0;

	cout << "Обход графа в ширину: ";
	GrBrTr(Gr, i, A, 0);                
	
	cout << endl;

	cout << "Нерекурсивный обход графа в глубину: "; 
	GrDepthTr(Gr, i, B, 0);             

  

	return 0;
}
