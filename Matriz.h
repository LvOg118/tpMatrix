#ifndef MATRIX_H
#define MATRIX_H
#include <fstream>
#include <iostream>

class Matriz {
private:
	int numLinhas, numColunas; // Atributos da matrix
	double** MatrizPointer; // Ponteiro, aponta para os valores do objeto amtriz criado
public:
	/// Construtores e destrutores
	Matriz(const int = 0, const int = 0, const double& = 0.); // Construtor 
	Matriz(const Matriz&); // Construtor de cópia
	~Matriz() ; // Destrutor

	/// Métodos padrão da classe
	int getRows() const {return numLinhas;} ; // Método que retorna o número de linhas da matriz
	int getCols() const {return numColunas;} ; // Método que retorna o número de colunas da matriz
	void unit(); // Método que transforma a matriz em uma matriz identidade
	void zeros(); // Método que "zera" toda a matriz
	void ones(); // Método que modifica todos os termos da matriz para "1"

	/// Sobrecarga de operadores
	Matriz operator+ (const Matriz&) const; // Sobrecarga do operador "+" (soma duas matrizes e retorna o resultado)
	Matriz operator- (const Matriz&) const; // Sobrecarga do operador "-" (subtrai duas matrizes e retorna o resultado)
	Matriz operator* (const Matriz&) const; // Sobrecarga do operador "*" (multiplica duas matrizes e retorna o resultado)
	Matriz& operator= (const Matriz&); // Sobrecarga do operador "=" (altera a matriz da esquerda para ser igual a da direita)
	bool operator== (const Matriz&) const; // Sobrecarga do operador "==" (retorna "true" caso as matrizes sejam iguais)
	bool operator!= (const Matriz&) const;  // Sobrecarga do operador "!=" (retorna "true" caso as matrizes sejam diferentes)
	void operator*= (const double&); // Sobrecarga do operador "*=" (multiplica a matriz de chamada por uma constante, e devolve o resultado a mesma matriz)
	void operator*= (const Matriz&); // Sobrecarga do operador "*=" (multiplica a matriz de chamada por outra matriz, e devolve o resultado a mesma matriz)
	void operator+= (const Matriz&); // Sobrecarga do operador "+=" (soma a matriz de chamada a outra matriz, e devolve o resultado a matriz de chamada)
	void operator-= (const Matriz&); // Sobrecarga do operador "-=" (subtrai uma matriz da matriz de chamada, e devolve o resultado a matriz de chamada)
	Matriz operator~ ();  // Sobrecarga do operador "~" (retorna a matriz transposta da matriz de chamada)
	double& operator() (const int line, const int colum) const {return  MatrizPointer[line - 1][colum - 1];} ; // Sobrecarga do operador "()" (retorna o ponteiro da matriz na posição desejada)
	friend std::ostream& operator<< (std::ostream&, const Matriz&); // Sobrecarga do operador ">>" (imprime a matriz do argumento da saída padrão)
	friend std::istream& operator>> (std::istream&, Matriz&); // Sobrecarga do operador "<<" (le valores da entrada padrão e joga na matriz do argumento)
};

#endif // MATRIX_H 
