/* ----------------------------------------------------------------<Header>-
 Name: Main.cpp
 Group: TI-81
 Students: Slavskyy S.V., Dubrov B.Y.
 Written: 
 Revised: 
 Description:. 
    
 ------------------------------------------------------------------</Header>-*/
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
class stack {
	double *stck;
	int tos;
public:
	stack(double x);
	~stack();
	void push(double x);
	double pop();
	void show();
};
stack::stack(double x) {
	stck = (double *)malloc(sizeof(double));
	if(!stck) {
		cout << "Allocation Error!";
		exit(1);
	}
	stck[0] = x;
	tos = 1;
}
stack::~stack() {
	free(stck);
}
void stack::push(double x) {
	stck = (double *)realloc(stck, tos + 1);
	if (!stck) {
		cout << "Allocation Error!";
	}
	stck[tos] = x;
	tos++;
}
double stack::pop() {
	if(tos == 0){
		cout << "Stack is empty";
		return 0;
	}
	stck = (double *)realloc(stck, tos - 1);
	if (!stck) {
		cout << "Allocation Error!";
	}
	tos--;
	return stck[tos];
}
void stack::show() {
	for (int i = 0; i < tos; i++) {
		cout << stck[i] << " ";
	}	
}
void DUP(stack &s) {
	double tmp = s.pop();
	s.push(tmp);
	s.push(tmp);
}
void MUL(stack &s) {
	double x1, x2, mult;
	x1 = s.pop();
	x2 = s.pop();
	mult = x1 * x2;
	s.push(mult);
}
void SWAP(stack &s) {
	double x1, x2;
	x1 = s.pop();
	x2 = s.pop();
	s.push(x1);
	s.push(x2);
}
void ADD(stack &s) {
	double x1, x2, add;
	x1 = s.pop();
	x2 = s.pop();
	add = x1 + x2;
	s.push(add);
}
void OVER(stack &s) {
	double x1, x2;
	x1 = s.pop();
	x2 = s.pop();
	s.push(x2);
	s.push(x1);
	s.push(x2);
}
void SIN(stack &s) {
	double x = sin(s.pop());
	s.push(x);
}
void COS(stack &s) {
	double x = cos(s.pop());
	s.push(x);
}
void choise(char *func, stack &s) {
	if ( strstr(func, "DUP") ) {
		cout << "DUP ";	//test
		DUP(s);
		cout << endl;	//test
	} else if ( strstr(func, "MUL") ) {
		cout << "MUL ";	//test
		MUL(s);
		cout << endl;	//test
	} else if ( strstr(func, "SWAP") ) {
		cout << "SWAP ";	//test
		SWAP(s);
		cout << endl;	//test
	} else if ( strstr(func, "ADD") ) {
		cout << "ADD ";	//test
		ADD(s);
		cout << endl;	//test
	} else if ( strstr(func, "OVER")) {
		cout << "OVER ";	//test
		OVER(s);
		cout << endl;	//test
	} else if ( strstr(func, "SIN")) {
		cout << "SIN ";	//test
		SIN(s);
		cout << endl;	//test
	} else if ( strstr(func, "COS")) {
		cout << "COS ";	//test
		COS(s);
		cout << endl;	//test
	} else {
		cout << "INCORECT ENTER!";
	}
}
void function(char *str, stack &s) {
	char *func;
	func = new char[20];
	for (int i = 0, k = 0; i <= (int)strlen(str); i++, k++) {
		if (str[i] == ' ' || str[i] == '\0') {
			choise(func, s);
			k = 0;
		} else {
			func[k] = str[i];
		}
	}
}
int main() {
 	cout<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|Опервция|                        Назначение                        |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  DUP   |        Копировать верхний объект стека(A->AA)            |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  MUL   |      Перемножить два врхних елемента стека(5 2->10)      |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  SWAP  |   Поменять местами два верхних элемента стека (AB->BA)   |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  ADD   |        Сложить два верхних элемента стека (5 2->7)       |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  OVER  |Cкопироват второй сверху объект стека на вершину (AB->BAB)|\n"<<
 	"|-------------------------------------------------------------------|\n"<<
 	"|  SIN   |   Заменить верхний обЪект строки на его синус (3.14->0)  |\n"<<
 	"|-------------------------------------------------------------------|\n"<<
	"|  COS   |  Заменить верхний обЪект строки на его косинус (-3.14->0)|\n"<<
	"|-------------------------------------------------------------------|\n";
	char func_arr[100] = "DUP SIN SWAP COS ADD";
	stack s(M_PI);
		function(func_arr, s);
	s.show();
	// for (int i = 0; i < 5; i++){	//test
	// 	stack s(i);
	// 	s.push(i+1);
	// 	s.show();
	// 	function(func_arr, s);
	// 	s.show();
	// 	cout << endl;
	// }
	return 0;
}
/* ---------------------------------------------------------------------[<]-
Test1 output:
---------------------------------------------------------------------[>]-*/