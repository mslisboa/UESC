#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool analisadorLexico(const string& palavra) {
    char estado = false;

    for(char caracter : palavra) {
        switch(estado) {
            case false:
                if(caracter == '0' || caracter == '1') estado = true;

            case true:
                if(caracter != '0' && caracter != '1') {
                    estado = false;
                    return estado;
                }
        }
    }

    return estado;
}


int main() {
    ifstream arquivo; // Abre o arquivo
    string linha;
    arquivo.open("palavras.txt");

    if(arquivo.is_open()) { // Verifica se o arquivo foi aberto corretamente
        while (getline(arquivo, linha)) { // Lê cada linha do arquivo
            if(analisadorLexico(linha)) { // Chama a função analisadorLexico() para analisar a palavra
                cout << "Palavra " << linha << ": reconhecida" << endl;
            } else {
                cout << "Palavra " << linha << ": rejeitada" << endl;
            }
        }

        arquivo.close(); // Fecha o programa
    } else {
        cout << "Nao foi possivel abrir o arquivo." << endl;
    }
    
    return 0;
}