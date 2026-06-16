/**
 * Classe para tratar erro.
 */
#ifndef _ERRO_H_
#define _ERRO_H_

class Erro
{
    /**   
        Tratamento de erro.
        Codigos de erro: 0. Nao ha' erro.
    */

    /**
    * atributos privados.
    */
    private:
        int erro;

    protected:
    // ------------------------------------------- metodos para acesso restrito

    /** 
        Metodo para estabelecer novo codigo de erro.
        @param codigo de erro a ser guardado
    */
    void setErro ( int codigo )
    {
        erro = codigo;
    } // end setErro ( )
    /**
        definicoes publicas.
    */
    public:

    /**
        Destrutor.
    */
    ~Erro ( )
    { } // end destructor (padrão)

    /**
        Construtor padrao.
    */
    Erro ( )
    {
        // atribuir valor inicial
        erro = 0;
    } // end constructor (padrão)

    // ------------------------------------------- metodos para 
    
    /**
        Funcao para obter o codigo de erro.
        @return codigo de erro guardado
    */
    int getErro ( )
    {
        return ( erro );
    } // end getErro ( )
    
    /**
    * indicar a existencia de erro.
    */
    bool hasErro ( )
    {
        return ( getErro( ) != 0 );
    } // end hasErro ( )


}; // end class Erro

#endif