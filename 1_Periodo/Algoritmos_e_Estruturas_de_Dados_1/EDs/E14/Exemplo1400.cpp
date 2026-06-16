/*
    Exemplo1400 - v0.0. - 22 / 11 / 2023
    Author: Vinicius Miranda de Araujo
 */

// ----------------------------------------------- preparacao

// dependencias

#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha

#include <iomanip>
using std::setw; // para definir espacamento

#include <string>
using std::string; // para cadeia de caracteres

#include <fstream>
using std::ifstream; // para ler    arquivo
using std::ofstream; // para gravar arquivo

// outras dependencias

void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl << std::endl;
} // end pause ( )

// ----------------------------------------------- classes

#include "libs/Erro.hpp" // classe para tratar erros

class MyString : public Erro
{
public:
    /**
     * Funcao para obter mensagem
     * relativa ao código de erro.
     * @return mensagem sobre o erro
     */
    std::string getErroMsg()
    {

        return (NO_ERROR); // COMPLETAR A DEFINICAO

    } // end getErroMsg ( )

}; // end classe MyString

// ----------------------------------------------- definicoes globais

using namespace std;

// ----------------------------------------------- metodos

/**
    Method_00 - nao faz nada.
 */
void method_00()
{
    // nao faz nada
} // end method_00 ( )

/**
    Method_01 - Testar definicoes da classe.
 */
void method_01()
{
    // definir dados
    MyString *s = new MyString();

    // identificar
    cout << "\nMethod_01 - v0.0\n" << endl;

    cout << endl << s->getErroMsg( ) << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
} // end method_01 ( )

// ----------------------------------------------- acao principal

/**
    Funcao principal.
    @return codigo de encerramento
*/
int main( void )
{
    // definir dado
    int x = 0; // definir variavel com valor inicial

    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1401 - Programa - v0.0\n " << endl;

        // mostrar opcoes
        cout << "Opcoes     " << endl;
        cout << " 0 - parar    " << endl;
        cout << " 1 - testar definicoes  " << endl;

        // ler do teclado
        cout << endl << "Entrar com uma opcao: ";
        cin >> x;

        // escolher acao
        switch (x)
        {
        case 0:
            method_00();
            break;
        case 1:
            method_01();
            break;
        default:
            cout << endl << "ERRO: Valor invalido." << endl;
        } // end switch
    } while (x != 0);

    // encerrar
    pause("Apertar ENTER para terminar");
    return (0);
} // end main ( )

/*
---------------------------------------------- documentacao complementar

---------------------------------------------- notas / observacoes / comentarios

---------------------------------------------- previsao de testes

---------------------------------------------- historico

Versao Data      Modificacao
0.1   __/__      esboco

---------------------------------------------- testes

Versao Teste
0.1 01. ( OK )  identificacao de programa

*/