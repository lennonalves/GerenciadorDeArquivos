/* Gerenciador de Arquvios 
** @author: lennon alves
** @author: daniel paiva
*/

#include <iostream>
#include <string>

using namespace std;

void saida() {
	cout << "Obrigado por utilizar nosso sistema.";
	cout << "D�vidas ou Sugest�es? Envie email para: lennonalvesdias@gmail.com";
	exit(0);
}

void verificaNome() {
	/*
	FILE	*arquivoEntrada, *arquivoSaida;
	
	arquivoEntrada = fopen("entrada.txt", "r");
	arquivoSaida = fopen("saida.txt", "w");
	fclose(arquivoEntrada);
	fclose(arquivoSaida);
	*/

	string caminho;

	cout << "[4] Verificar nome do arquivo";
	cout << "Informe o caminho do arquivo";
	cin >> caminho;
	cout << caminho;
}

int loop(int menu) {
	cout << "Selecione a op��o desejada:";
	cout << "[1] Verificar tamanho do caminho do arquivo"; // n�o implementado
	cout << "[2] Verificar arquivos com nomes duplicados"; // n�o implementado
	cout << "[3] Verificar caminhos redundantes"; // n�o implementado
	cout << "[4] Verificar nome do arquivo"; // em desenvolvimento
	cout << "[5] Sugest�o de caminho"; // n�o implementado
	cout << "[0] Sair";
	cin >> menu;
	return menu;
}

void main1() {
	int menu = 0;

	switch (menu) {
	case 0: saida(); break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: verificaNome(); break;
	case 5: break;
	}

	system("pause");
}