/* Gerenciador de Arquvios 
** @author: lennon alves
** @author: daniel paiva
*/

#include <iostream>
#include <string>

#include <sys/types.h>
#include "dirent.h"

using namespace std;

void saida(int n) {
	system("cls");
	cout << "Obrigado por utilizar nosso sistema." << endl;
	cout << "Duvidas ou Sugestoes? Envie email para: lennonalvesdias@gmail.com\n" << endl;
	exit(n);
}

void regrasNomeArquivo(string nomeArquivo) {
	system("cls");
	cout << "Arquivo informado: " << nomeArquivo << endl;
	cout << "\nRegra 01: Nome com espacos" << endl;
	cout << "Regra 02: Nome com caracteres especiais" << endl;
	int letras = 1, noespace = 0; char *nomeTemp = NULL;

	//Regra 01
	if (nomeArquivo.find(".txt") > nomeArquivo.length()) { //trabalhos futuros: comprar com lista de extensões
		cout << "\nArquivo sem extensao e possui risco de ser corrompido." << endl; system("pause"); saida(1);
	}
	else if (nomeArquivo.find(" ") > nomeArquivo.length()) { //não possui espaço
		cout << "\nO arquivo informado segue a Regra 01" << endl; system("pause"); saida(1);
	}
	else {
		for (string::iterator it = nomeArquivo.begin(); it != nomeArquivo.end(); ++it) {
			if (*it != *" ") {
				//cout << "letra: " << *it << endl;
				nomeTemp = (char*)realloc(nomeTemp, letras * sizeof(char));
				if (nomeTemp == NULL) saida(1);
				nomeTemp[letras - 1] = *it;
				//cout << "letra: " << nomeTemp[letras-1] << endl;
				letras++;
			}
		}
		char *nomeFinal = (char*)malloc(letras);
		if (nomeFinal == NULL) saida(1);

		for (int k = 0; k < letras - 1; k++)
			nomeFinal[k] = nomeTemp[k];
		nomeFinal[letras - 1] = '\0';

		cout << "\nNome sugerido: " << nomeFinal << endl;

		string comando = "ren \"" + nomeArquivo + "\" \"" + nomeFinal + "\"";
		system(comando.c_str());

		if (nomeFinal != NULL)
			free(nomeFinal);
	}

	if (nomeTemp != NULL)
	free(nomeTemp);

	//Regra 02
}

void listaDiretorio() {
	system("cls");
	cout << "Arquivos do diretorio:\n" << endl;
	DIR *dp;
	struct dirent *ep;

	dp = opendir("./");
	if (dp != NULL)
	{
		while (ep = readdir(dp))
			puts(ep->d_name);

		(void)closedir(dp);
	}
	else
		perror("Erro ao listar diretorio.\n\n");
}

void verificaNome() {
	system("cls");
	cout << "[4] Verificar nome do arquivo\n" << endl;

	/*
	FILE	*arquivoEntrada, *arquivoSaida;
	
	arquivoEntrada = fopen("entrada.txt", "r");
	arquivoSaida = fopen("saida.txt", "w");
	fclose(arquivoEntrada);
	fclose(arquivoSaida);
	*/

	string nomeArquivo;

	int menu = 0;
	cout << "Selecione a opcao desejada:" << endl;
	cout << "[1] Verificar todos os arquivos" << endl;
	cout << "[2] Verificar unico arquivo" << endl;
	cout << "[0] Sair\n" << endl;
	cin.ignore(); cin >> menu;

	if (menu != 1 && menu != 2) saida(0);
	else if (menu == 1) {
		cout << "\nVerificando todos os arquivos." << endl;
	}
	else {
		listaDiretorio();
		cout << "\nInforme o nome do arquivo: ";
		cin.ignore(); getline(cin, nomeArquivo);
		regrasNomeArquivo(nomeArquivo);
	}
}

int loop(int menu) {
	system("cls");
	cout << "Selecione a opcao desejada:" << endl;
	cout << "[1] Verificar tamanho do caminho do arquivo" << endl; // não implementado
	cout << "[2] Verificar arquivos com nomes duplicados" << endl; // não implementado
	cout << "[3] Verificar caminhos redundantes" << endl; // não implementado
	cout << "[4] Verificar nome do arquivo" << endl; // em desenvolvimento
	cout << "[5] Sugestao de caminho" << endl; // não implementado
	cout << "[0] Sair\n" << endl;
	cin >> menu;
	return menu;
}

void main() {
	int menu = 0;

	menu = loop(menu);
	switch (menu) {
	case 0: saida(0); break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: verificaNome(); break;
	case 5: break;
	}

	cout << "\n";
}