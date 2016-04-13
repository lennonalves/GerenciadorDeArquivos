/* Gerenciador de Arquvios 
** @author: lennon alves
** @author: daniel paiva
*/

#include <iostream>
#include <string>
#include <vector>

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

	vector<string> extensoes;
	bool regra;

	//win
	extensoes.push_back(".txt"); extensoes.push_back(".exe");
	extensoes.push_back(".zip"); extensoes.push_back(".rar");

	//office
	extensoes.push_back(".doc"); extensoes.push_back(".docx"); 
	extensoes.push_back(".docm"); extensoes.push_back(".dotx");
	extensoes.push_back(".dotm"); extensoes.push_back(".ppt");
	extensoes.push_back(".pptx"); extensoes.push_back(".pptm");
	extensoes.push_back(".potx"); extensoes.push_back(".potm"); 
	extensoes.push_back(".ppam"); extensoes.push_back(".ppsx");
	extensoes.push_back(".ppsm"); extensoes.push_back(".sldx");
	extensoes.push_back(".sldm"); extensoes.push_back(".thmx");
	extensoes.push_back(".xls"); extensoes.push_back(".xlsm");
	extensoes.push_back(".xlsx"); extensoes.push_back(".xltx");
	extensoes.push_back(".xltm"); extensoes.push_back(".xlsb");
	extensoes.push_back(".xlam");

	//imagem
	extensoes.push_back(".bmp"); extensoes.push_back(".jpg"); 
	extensoes.push_back(".jpeg"); extensoes.push_back(".png");
	extensoes.push_back(".tiff"); extensoes.push_back(".gif");
	extensoes.push_back(".ico");

	extensoes.push_back(".psd"); extensoes.push_back(".cdr");

	//multimidia
	extensoes.push_back(".mp3"); extensoes.push_back(".mp4");
	extensoes.push_back(".wav"); extensoes.push_back(".mpeg");
	extensoes.push_back(".avi"); extensoes.push_back(".wmv");

	//Regra 01
	regra = false;
	for (unsigned int i = 0; i < extensoes.size(); ++i)
		if (nomeArquivo.find(extensoes[i]) < nomeArquivo.length())
			regra = true;

	if (regra == false) {
		cout << "\nArquivo sem extensao e possui risco de ser corrompido." << endl;
		system("pause");
		saida(1);
	}
	
	if (nomeArquivo.find(32) > nomeArquivo.length()) { //não possui espaço
		cout << "\nO arquivo informado nao possui espacos" << endl;
	}
	else {
		char *nomeTemp = NULL; int letras = 1; bool espaco = false;
		for (string::iterator it = nomeArquivo.begin(); it != nomeArquivo.end(); ++it) {
			if (*it != 32) { //verifica espaço
				//cout << "letter: " << *it << endl;
				nomeTemp = (char*)realloc(nomeTemp, letras * sizeof(char));
				if (nomeTemp == NULL) saida(1);
				if (espaco == true)
					if (*it > 90)
						*it -= 32;
				nomeTemp[letras - 1] = *it;
				letras++;
				espaco = false;
			}
			else
				espaco = true;
		}
		char *nomeFinal = (char*)malloc(letras);
		if (nomeFinal == NULL) saida(1);

		for (int k = 0; k < letras - 1; k++)
			nomeFinal[k] = nomeTemp[k];
		nomeFinal[letras - 1] = '\0';

		cout << "\nRegra 01: Nome com espacos." << endl;
		cout << "\nNome sugerido: " << nomeFinal << endl;

		string comando = "ren \"" + nomeArquivo + "\" \"" + nomeFinal + "\"";
		system(comando.c_str());

		nomeArquivo = nomeFinal;
		free(nomeFinal);
		free(nomeTemp);
	}

	vector<int> especiais;

	for (int n = 33; n <= 44; n++)
		especiais.push_back(n);
	for (int n = 60; n <= 64; n++)
		especiais.push_back(n);
	for (int n = 91; n <= 94; n++)
		especiais.push_back(n);
	for (int n = 155; n <= 159; n++)
		especiais.push_back(n);
	for (int n = 166; n <= 180; n++)
		especiais.push_back(n);

	especiais.push_back(47); especiais.push_back(58); especiais.push_back(96);
	especiais.push_back(126); especiais.push_back(145); especiais.push_back(184);	

	//Regra 02
	regra = false;
	for (unsigned int i = 0; i < especiais.size(); ++i)
		if (nomeArquivo.find(especiais[i]) < nomeArquivo.length())
			regra = true;

	if (regra == false) {
		cout << "\nO arquivo informado nao possui caracteres especiais." << endl;
	}
	else {
		char *nomeTemp = NULL; int letras = 1;
		for (string::iterator it = nomeArquivo.begin(); it != nomeArquivo.end(); ++it) {
			bool caractere = false;
			for (unsigned int k = 0; k < especiais.size(); ++k)
				if (*it == especiais[k])
					caractere = true;
			if (caractere == false)
			{
				//cout << "letter: " << *it << endl;
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

		cout << "Regra 02: Nome com caracteres especiais." << endl;
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
	cout << "[4] Verificar nome do arquivo.\n" << endl;

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