#include "Matriz.h"
#include <fstream>
#include <iostream>

Matriz::Matriz(const int Linhas, const int Colunas, const double& valor) {
	numLinhas = Linhas;
	numColunas = Colunas;
	if (Linhas == 0 && Colunas == 0) {
		MatrizPointer = NULL;
	}
	else {
		MatrizPointer = new double*[Linhas];
		for (int i = 0; i < Linhas; i++) {
			MatrizPointer[i] = new double[Colunas];
			for (int j = 0; j < Colunas; j++) {
				MatrizPointer[i][j] = valor;
			}
		}
	}
}

Matriz::Matriz(const Matriz& matrizCopy){
	numLinhas = matrizCopy.numLinhas;
	numColunas = matrizCopy.numColunas;
	MatrizPointer = new double*[matrizCopy.numLinhas];
	for (int i = 0; i < matrizCopy.numLinhas; i++) {
		MatrizPointer[i] = new double[matrizCopy.numColunas];
		for (int j = 0; j < matrizCopy.numColunas; j++) {
			MatrizPointer[i][j] = matrizCopy.MatrizPointer[i][j];
		} 
	}
}

Matriz::~Matriz() {
	for (int i = 0; i < numLinhas; i++) {
		delete[] MatrizPointer[i];
	}
	delete[] MatrizPointer;
}

void Matriz::unit(){
	if (numLinhas == numColunas) {
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < numColunas; j++) {
				if (i == j)
					MatrizPointer[i][j] = 1;
				else
					MatrizPointer[i][j] = 0;
			}
		}
	}
	else
		std::cout << "A matriz precisa ser quadrada para ser transformada em identidade!!! \n";
}

void Matriz::zeros(){
	for (int i = 0; i < numLinhas; i++) {
		for (int j = 0; j < numColunas; j++) {
				MatrizPointer[i][j] = 0;
		}
	}
}

void Matriz::ones(){
	for (int i = 0; i < numLinhas; i++) {
		for (int j = 0; j < numColunas; j++) {
				MatrizPointer[i][j] = 1;
		}
	}
}

Matriz Matriz::operator+ (const Matriz& matrizPlus) const {
	if ((numLinhas == matrizPlus.numLinhas) && (numColunas == matrizPlus.numColunas)) {
		Matriz aux(numLinhas, numColunas);
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < numColunas; j++) {
				aux.MatrizPointer[i][j] = MatrizPointer[i][j] + matrizPlus.MatrizPointer[i][j];
			}
		}
		return aux;
	}
	else {
		std::cout << "As matrizes precisam ter as mesmas dimensoes para serem somadas!!!\n";
		Matriz aux;
		return aux;
	}
}

Matriz Matriz::operator- (const Matriz& matrizMinus) const {
	if ((numLinhas == matrizMinus.numLinhas) && (numColunas == matrizMinus.numColunas)) {
		Matriz aux(numLinhas, numColunas);
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < numColunas; j++) {
				aux.MatrizPointer[i][j] = MatrizPointer[i][j] - matrizMinus.MatrizPointer[i][j];
			}
		}
		return aux;
	}
	else {
		std::cout << "As matrizes precisam ter as mesmas dimensoes para serem subtraidas!!!\n";
		Matriz aux;
		return aux;
	}
}

Matriz Matriz::operator* (const Matriz& matrizMult) const {
	if (numColunas == matrizMult.numLinhas) {
		Matriz aux(numLinhas, matrizMult.numColunas);
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < matrizMult.numColunas; j++) {
				for (int k = 0; k < numColunas; k++) {
					aux.MatrizPointer[i][j] += MatrizPointer[i][k] * matrizMult.MatrizPointer[k][j];
				}
			}
		}
		return aux;
	}
	else {
		std::cout << "O numero de colunas da primeira matriz deve ser igual ao numero de linhas da segunda para que possam ser multiplicadas!!!\n";
		Matriz aux;
		return aux;
	}
}

Matriz& Matriz::operator= (const Matriz& matrizCopy){
	numLinhas = matrizCopy.numLinhas;
	numColunas = matrizCopy.numColunas;
	if (matrizCopy.numLinhas == 0 && matrizCopy.numColunas == 0) {
		MatrizPointer = NULL;
		return *this;
	}
	else {
		MatrizPointer = new double*[matrizCopy.numLinhas];
		for (int i = 0; i < matrizCopy.numLinhas; i++) {
			MatrizPointer[i] = new double[matrizCopy.numColunas];
			for (int j = 0; j < matrizCopy.numColunas; j++) {
				MatrizPointer[i][j] = matrizCopy.MatrizPointer[i][j];
			}
		}
		return *this;
	}
}

bool Matriz::operator== (const Matriz& matrizVerif) const {	
	if ((numLinhas != matrizVerif.numLinhas) || (numColunas != matrizVerif.numColunas))
		return false;
	else {
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < numColunas; j++) {
				if (MatrizPointer[i][j] != matrizVerif.MatrizPointer[i][j])
					return false;
			}
		}
	}
	return true;
}

bool Matriz::operator!= (const Matriz& matrizVerif) const {	
	if ((numLinhas != matrizVerif.numLinhas) || (numColunas != matrizVerif.numColunas))
		return true;
	else {
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < numColunas; j++) {
				if (MatrizPointer[i][j] != matrizVerif.MatrizPointer[i][j])
					return true;
			}
		}
	}
	return false;
}

void Matriz::operator*= (const double& valor){	
	for (int i = 0; i < numLinhas; i++) {
		for (int j = 0; j < numColunas; j++) {
			MatrizPointer[i][j] *= valor;
		}
	}
}

void Matriz::operator*= (const Matriz& matrizMult){	
	if (numColunas == matrizMult.numLinhas) {
		Matriz aux(numLinhas, matrizMult.numColunas);
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < matrizMult.numColunas; j++) {
				for (int k = 0; k < numColunas; k++) {
					aux.MatrizPointer[i][j] += MatrizPointer[i][k] * matrizMult.MatrizPointer[k][j];
				}
			}
		}
		*this = aux;
	}
	else
		std::cout << "O numero de colunas da primeira matriz deve ser igual ao numero de linhas da segunda para que possam ser multiplicadas!!!\n";
}

void Matriz::operator+= (const Matriz& matrizPlus){	
	if ((numLinhas == matrizPlus.numLinhas) && (numColunas == matrizPlus.numColunas)) {
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < numColunas; j++) {
				MatrizPointer[i][j] += matrizPlus.MatrizPointer[i][j];
			}
		}
	}
	else
		std::cout << "As matrizes precisam ter as mesmas dimensoes para serem somadas!!!\n";
}

void Matriz::operator-= (const Matriz& matrizMinus){	
	if ((numLinhas == matrizMinus.numLinhas) && (numColunas == matrizMinus.numColunas)) {
		for (int i = 0; i < numLinhas; i++) {
			for (int j = 0; j < numColunas; j++) {
				MatrizPointer[i][j] -= matrizMinus.MatrizPointer[i][j];
			}
		}
	}
	else
		std::cout << "As matrizes precisam ter as mesmas dimensoes para serem subtraidas!!!\n";
}

Matriz Matriz::operator~ (){
	Matriz aux(numLinhas, numColunas);
	for (int i = 0; i < numLinhas; i++) {
		for (int j = 0; j < numColunas; j++) {
			aux.MatrizPointer[j][i] = MatrizPointer[i][j];
		}
	}
	return aux;
}

std::ostream& operator<< (std::ostream& op, const Matriz& matrizPrint){
	for (int i = 0; i < matrizPrint.numLinhas; i++) {
		for (int j = 0; j < matrizPrint.numColunas; j++) {
			op << matrizPrint.MatrizPointer[i][j] << '\t';
		}
		op << std::endl;
	}
	return op;
}

std::istream& operator>> (std::istream& op, Matriz& matrizIn) {
	for (int i = 0; i < matrizIn.numLinhas; i++) {
		delete[] matrizIn.MatrizPointer[i];
	}
	delete[] matrizIn.MatrizPointer;
	std::cout << "Digite o numero de linhas da matriz: ";
	op >> matrizIn.numLinhas;
	std::cout << "Digite o numero de Colunas da matriz: ";
	op >> matrizIn.numColunas;
	matrizIn.MatrizPointer = new double*[matrizIn.numLinhas];
	for (int i = 0; i < matrizIn.numLinhas; i++) {
		matrizIn.MatrizPointer[i] = new double[matrizIn.numColunas];
		for (int j = 0; j < matrizIn.numColunas; j++) {
			std::cout << "Digite o valor da posicao " << i+1 << "," << j+1 << " da matriz: " ;
			op >> matrizIn.MatrizPointer[i][j];
		}
	}
	return op;
}