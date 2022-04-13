//Guilherme, Rodrigo,Luiz
#include <iostream>
#include <time.h>
#include <iomanip>
#include <string>
#include <stdlib.h>

using namespace std;

string** cartaDoJogo;
string** cartasComJogador;
int y = 0;
int c = 0;

int carta_inedita(string x, string** matriz)
{
	int c, j;
	j = 0;
	do
	{
		c = 0;
		do
		{
			if (matriz[j][c] == x)
			{
				c = 11;
				j = 4;
			}
			c++;
		} while (c < 11);
		++j;
	} while (j < 4);
	return (j == 4);
}

void embaralahndoCarta() {
	int contador = 0;
	string organizar;
	srand(time(0));
	while (contador <= 44) {
		y = 0;
		do
		{
			c = 0;
			do {
				int bar = rand() % (2 + 1 - 1) + 1;
				int carta = rand() % (52 + 1 - 1) + 1;

				organizar = cartaDoJogo[bar - 1][carta - 1];

				if (carta_inedita(organizar, cartasComJogador)) 
				{
					cartasComJogador[y][c] = organizar;
					contador++;
					c++;
				}
			}
			while (c < 11);
			++y;

		}
		while (y < 4);

	}

	for (int y = 0; y<= 3; y++) {
		cout << "Jogador " << y + 1 << endl; 
		for (int c = 0; c < 11; c++) {
			cout << cartasComJogador[y][c] << endl;
		}
		cout << endl;
	}
}
void mostrarCarta() {
	
	int carta = 0;
	for (int baralho = 0; baralho < 2; baralho++) {
		for (int n = 0; n <= 3; n++) {
			for (int t = 0; t < 13; t++) {
				cartaDoJogo[baralho][carta] = to_string(n + 1) + "-" + to_string(t + 1) + "-" + to_string(baralho + 1);
				++carta;
				if (carta > 51)
				{
					carta = 0;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	
	int i;
	cartaDoJogo = new string*[2];

	for (int i = 0; i < 2; i++) {
		cartaDoJogo[i] = new string[52];
	}

	cartasComJogador = new string * [4];
	for (i = 0; i <= 3; i++) {
		cartasComJogador[i] = new string[11];
		}


	mostrarCarta();
	embaralahndoCarta();


}
