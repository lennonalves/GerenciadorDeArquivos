/* Gerenciador de Arquvios 
** @author: lennon alves
** @author: daniel paiva
*/

#include <iostream>
#include <string>

using namespace std;

void saida() {
	cout << "Obrigado por utilizar nosso sistema.";
	cout << "Dúvidas ou Sugestões? Envie email para: lennonalvesdias@gmail.com";
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
	cout << "Selecione a opção desejada:";
	cout << "[1] Verificar tamanho do caminho do arquivo"; // não implementado
	cout << "[2] Verificar arquivos com nomes duplicados"; // não implementado
	cout << "[3] Verificar caminhos redundantes"; // não implementado
	cout << "[4] Verificar nome do arquivo"; // em desenvolvimento
	cout << "[5] Sugestão de caminho"; // não implementado
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