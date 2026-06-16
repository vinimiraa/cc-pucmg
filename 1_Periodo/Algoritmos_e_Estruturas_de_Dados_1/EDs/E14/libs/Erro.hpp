/**
 * Classe para tratar erro.
 */
#ifndef _ERRO_H_
#define _ERRO_H_

#include <string>

/**
    Tratamento de erro.
    Codigos de erro: 0. Nao ha' erro.
*/
class Erro
{
private:
    int erro;

protected:
    /**
        Metodo para estabelecer novo codigo de erro.
        @param codigo de erro a ser guardado
    */
    void setErro(int codigo)
    {
        erro = codigo;
    } // end setErro ( )

public:
    ~Erro()
    {
    } // end destructor (padrão)

    Erro()
    {
        // atribuir valor inicial
        erro = 0;
    } // end constructor (padrão)

    static const std::string NO_ERROR;

    /**
     *   Funcao para obter o codigo de erro.
     *   @return codigo de erro guardado
     */
    int getErro()
    {
        return ( erro ); // valor provisorio, precisara' ser definido futuramente
    } // end getErro ( )

    /**
     * indicar a existencia de erro.
     */
    bool hasErro()
    {
        return (getErro() != 0);
    } // end hasErro ( )

    /**
     *   Funcao para obter mensagem relativa ao código de erro.
     *   @return mensagem sobre o erro
     */
    virtual std::string getErroMsg()
    {
        return ("");
    } // end getErroMsg ( )

}; // end class Erro

const std::string Erro::NO_ERROR = "[ERRO] Nao ha' erro."; // definir o valor da constante

#endif