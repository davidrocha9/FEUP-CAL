/*
 * Sudoku.cpp
 *
 */

#include "Sudoku.h"
#include <vector>
#include <iostream>

using namespace std;

/** Inicia um Sudoku vazio.
 */
Sudoku::Sudoku()
{
	this->initialize();
}

/**
 * Inicia um Sudoku com um conteúdo inicial.
 * Lança excepção IllegalArgumentException se os valores
 * estiverem fora da gama de 1 a 9 ou se existirem números repetidos
 * por linha, coluna ou bloc 3x3.
 *
 * @param nums matriz com os valores iniciais (0 significa por preencher)
 */
Sudoku::Sudoku(int nums[9][9])
{
	this->initialize();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (nums[i][j] != 0)
			{
				int n = nums[i][j];
				numbers[i][j] = n;
				lineHasNumber[i][n] = true;
				columnHasNumber[j][n] = true;
				block3x3HasNumber[i / 3][j / 3][n] = true;
				countFilled++;
			}
		}
	}
}

void Sudoku::initialize()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			for (int n = 0; n < 10; n++)
			{
				numbers[i][j] = 0;
				lineHasNumber[i][n] = false;
				columnHasNumber[j][n] = false;
				block3x3HasNumber[i / 3][j / 3][n] = false;
			}
		}
	}

	this->countFilled = 0;
}

/**
 * Obtem o conteúdo actual (só para leitura!).
 */
int** Sudoku::getNumbers()
{
	int** ret = new int*[9];

	for (int i = 0; i < 9; i++)
	{
		ret[i] = new int[9];

		for (int a = 0; a < 9; a++)
			ret[i][a] = numbers[i][a];
	}

	return ret;
}

/**
 * Verifica se o Sudoku já está completamente resolvido
 */
bool Sudoku::isComplete()
{
	return countFilled == 9 * 9;
}



/**
 * Resolve o Sudoku.
 * Retorna indicação de sucesso ou insucesso (sudoku impossível).
 */
bool Sudoku::solve(){
    if (isComplete()) return true;

    pair <int, int> pos = findEmpty();

    for (int i = 1; i < 10; i++){
        if (valid(numbers, pos, i)) {
            int x = pos.first, y = pos.second;
            numbers[x][y] = i;
            countFilled++;
            lineHasNumber[x][i] = true;
            columnHasNumber[y][i] = true;
            block3x3HasNumber[x/3][y/3][i] = true;

            if (solve())
                return true;

            numbers[x][y] = 0;
            countFilled--;
            lineHasNumber[x][i] = false;
            columnHasNumber[y][i] = false;
            block3x3HasNumber[x/3][y/3][i] = false;
        }
    }
    return false;
}



/**
 * Imprime o Sudoku.
 */
void Sudoku::print()
{
	for (int i = 0; i < 9; i++)
	{
		for (int a = 0; a < 9; a++)
			cout << this->numbers[i][a] << " ";

		cout << endl;
	}
}

pair<int, int> Sudoku::findEmpty() {
    pair<int, int> result;

    for (int x = 0; x < 9; x++){ // Percorrer a linha
        for (int y = 0; y < 9; y++){ // Percorrer cada numero da linha
            if (numbers[x][y] == 0){ // Se for 0 retorna as coordenadas no sudoku
                result.first = x;
                result.second = y;
                return result;
            }
        }
    }
    return result;
}

bool Sudoku::valid(int (*numbers)[9], pair<int, int> pos, int nr){
    // Verifica a linha
    if (lineHasNumber[pos.first][nr]) return false;

    // Verifica a coluna
    if (columnHasNumber[pos.second][nr]) return false;

    // Verifica a coluna
    if (block3x3HasNumber[pos.first/3][pos.second/3][nr]) return false;

    return true;
}


