#include "matriz.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	Matriz Y;
	cout << Y;
	Matriz X(3, 1), A(3, 3, 2), C(3, 3, 1.13);
	cout << "Matriz X:\n" << X << "\n     Matriz A:\n" << A << "\n     Matriz C:\n" << C << "\n";
	Matriz W = C;
	cout << "     Matriz W:\n" << W << "\n";
	Matriz Z(A);
	cout << "     Matriz Z:\n" << W << "\n";
	int numeroLinhas = A.getRows();
	int numeroColunas = A.getCols();
	cout << "Numero de linhas da matriz A: " << numeroLinhas << "\n" << "Numero de colunas da matriz A:" << numeroColunas << "\n\n";
	Y = C;
	Y.unit();                                     // inicializa Y com a matriz identidade
	cout << "Matriz Y (ident):\n" << Y << "\n";
	A(2, 1) = 10;                               // altera o valor de uma posição de A
	cout << "Matriz A (alterada):\n" << A << "\n";
	Y.zeros();                                // modifica todos os elementos de Y para o valor zero
	cout << "Matriz Y (zerada):\n" << Y << "\n";
	C = A + A;                                  // Soma
	cout << "  Matriz C(A+A):\n" << C << "\n";
	C -= A;                                     // Subtração
	cout << "  Matriz C(C-A):\n" << C << "\n";
	A = C - A;                                  // Subtração
	cout << "  Matriz A(C-A):\n" << A << "\n";
	A += A;                                   // Soma
	cout << "  Matriz A(A+A):\n" << A << "\n";
	A = ~C;                                  // A é igual a transposta de C
	cout << "  Matriz A(~C):\n" << A << "\n";
	X.ones();                             // modifica todos os elementos de X com 1s
	cout << "  Matriz X(ums):\n" << X << "\n";
	X *= 2;                                   // multiplicação por uma constante
	cout << "  Matriz X(X*2):\n" << X << "\n";
	C = A * X;                                         // multiplicação de matrizes
	cout << "  Matriz C(A*X):\n" << C << "\n";
	cout << "Matriz C(C*X): ";
	C *= X;                                            // multiplicação de matrizes
	cout << "\n";
	if (A == C)     // verifica a igualdade entre A e C
		cout << "A == C \n\n";
	if (X != Y)                                  // verifica a desigualdade entre A e C
		cout << "C != Y \n\n";
	cin >> Y;            // entrada de valores
	cout << "\n" << "Matriz Y digitada:\n" << Y << "\n";
	
	int a;
	cin >> a;
}
