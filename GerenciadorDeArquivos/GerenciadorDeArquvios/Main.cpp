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

	//Regra 01
	if (nomeArquivo.find(".txt") > nomeArquivo.length()) { //trabalhos futuros: comparar com lista de extensões
		cout << "\nArquivo sem extensao e possui risco de ser corrompido." << endl; system("pause"); saida(1);
	}
	else if (nomeArquivo.find(32) > nomeArquivo.length()) { //não possui espaço
		cout << "\nO arquivo informado segue a Regra 01" << endl;
	}
	else {
		char *nomeTemp = NULL; int letras = 1, flag = 0;
		for (string::iterator it = nomeArquivo.begin(); it != nomeArquivo.end(); ++it) {
			if (*it != 32) {
				nomeTemp = (char*)realloc(nomeTemp, letras * sizeof(char));
				if (nomeTemp == NULL) saida(1);
				if (flag == 1)
					if (*it > 90)
						*it -= 32;
				nomeTemp[letras - 1] = *it;
				letras++;
				flag = 0;
			}
			else
				flag = 1; //encontrou espaço
		}
		char *nomeFinal = (char*)malloc(letras);
		if (nomeFinal == NULL) saida(1);

		for (int k = 0; k < letras - 1; k++)
			nomeFinal[k] = nomeTemp[k];
		nomeFinal[letras - 1] = '\0';

		cout << "\nNome sugerido: " << nomeFinal << endl;

		string comando = "ren \"" + nomeArquivo + "\" \"" + nomeFinal + "\"";
		system(comando.c_str());

		nomeArquivo = nomeFinal;
		free(nomeFinal);
		free(nomeTemp);
	}

	//Regra 02
	if ((nomeArquivo.find(33) > nomeArquivo.length()) && (nomeArquivo.find(34) > nomeArquivo.length())
		&& (nomeArquivo.find(35) > nomeArquivo.length()) && (nomeArquivo.find(36) > nomeArquivo.length())
		&& (nomeArquivo.find(37) > nomeArquivo.length()) && (nomeArquivo.find(38) > nomeArquivo.length())
		&& (nomeArquivo.find(39) > nomeArquivo.length()) && (nomeArquivo.find(40) > nomeArquivo.length())
		&& (nomeArquivo.find(41) > nomeArquivo.length()) && (nomeArquivo.find(42) > nomeArquivo.length())
		&& (nomeArquivo.find(43) > nomeArquivo.length()) && (nomeArquivo.find(44) > nomeArquivo.length())
		&& (nomeArquivo.find(47) > nomeArquivo.length()) && (nomeArquivo.find(58) > nomeArquivo.length())
		&& (nomeArquivo.find(60) > nomeArquivo.length()) && (nomeArquivo.find(61) > nomeArquivo.length())
		&& (nomeArquivo.find(62) > nomeArquivo.length()) && (nomeArquivo.find(63) > nomeArquivo.length())
		&& (nomeArquivo.find(64) > nomeArquivo.length())) {
		cout << "\nO arquivo informado segue a Regra 02" << endl;
	}
	else {
		char *nomeTemp = NULL; int letras = 1;
		for (string::iterator it = nomeArquivo.begin(); it != nomeArquivo.end(); ++it) {
			if (*it != 33 && *it != 34 && *it != 35 && *it != 36 && *it != 37 && *it != 38 && *it != 39
				&& *it != 40 && *it != 41 && *it != 42 && *it != 43 && *it != 44 && *it != 47 && *it != 58
				&& *it != 60 && *it != 61 && *it != 62 && *it != 63 && *it != 64) {
				nomeTemp = (char*)realloc(nomeTemp, letras * sizeof(char));
				if (nomeTemp == NULL) saida(1);
				nomeTemp[letras - 1] = *it;
				letras++;
			}
		}
		char* nomeFinal = (char*)malloc(letras);
		if (nomeFinal == NULL) saida(1);

		for (int k = 0; k < letras - 1; k++)
			nomeFinal[k] = nomeTemp[k];
		nomeFinal[letras - 1] = '\0';

		cout << "\nNome sugerido: " << nomeFinal << endl;

		string comando = "ren \"" + nomeArquivo + "\" \"" + nomeFinal + "\"";
		system(comando.c_str());

		nomeArquivo = nomeFinal;
		free(nomeFinal);
		free(nomeTemp);
	}
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