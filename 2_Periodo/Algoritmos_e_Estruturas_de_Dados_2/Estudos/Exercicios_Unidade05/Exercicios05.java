class Contato
{
    // atributos
    String nome;
    String telefone;
    String email;
    int    cpf;

    // construtores
    Contato ( )
    {
        this.nome = this.telefone = this.email = "";
        this.cpf = 0;
    }

    Contato ( String nome, String telefone, String email, int cpf )
    {
        this.nome     = nome;
        this.telefone = telefone;
        this.email    = email;
        this.cpf      = cpf;
    }

    public String toString ( )
    {
        return ( "( Nome= " + nome + ", Telefone= " + telefone + ", Email= " + email + ", CPF= " + cpf + " )" );
    }
} // end class

class Celula
{
    // atributos
    Contato contato;
    Celula  prox;

    // construtores
    Celula ( )
    {
        this.contato = new Contato ( );
        this.prox = null;
    }

    Celula ( Contato novo )
    {
        this.contato = novo;
        this.prox = null;
    }
} // end class

class No
{
    // atributos
    char letra;
    No   esq;
    No   dir;
    Celula primeiro;
    Celula ultimo;

    // contrutores
    No ( )
    {
        this.letra = 0;
        this.esq = this.dir = null;
        this.primeiro = this.ultimo = new Celula( );
    }
    
    No ( char letra )
    {
        this.letra = letra;
        this.esq = this.dir = null;
        this.primeiro = this.ultimo = new Celula( );
    }
} // end class

class Agenda 
{
    // atributos
    private No raiz;

    // contrutor
    Agenda ( )
    {
        criarArvore( 'A', 'Z' );
    }

    // arvore binaria
    void inserirNo( char c ) 
    {
        raiz = inserirNo( c, raiz );
    }

    private No inserirNo( char c, No i ) 
    {
        if( i == null ) {
            i = new No( c );
        } else if( c < i.letra ) {
            i.esq = inserirNo( c, i.esq );
        } else if( c > i.letra ) {
            i.dir = inserirNo( c, i.dir );
        } else {
            System.err.println( "Erro: Insercao!" );
        }
        return ( i );
    }

    private void criarArvore ( char inicio, char fim )
    {
        if( inicio < fim )
        {
            char meio = (char)( (inicio+fim) / 2 );
            inserirNo( meio );
            criarArvore( inicio, meio );
            criarArvore( (char)(meio+1), fim );
        }
    }

    // agenda
    void inserir ( Contato contato )
    {
        raiz = inserir( contato, raiz );
    }

    private No inserir ( Contato contato, No i )
    {
        if( i == null ) {
            System.out.println( "Erro: Inserir Contato!" );
        }
        else if( contato.nome.charAt(0) < i.letra ) {
            i.esq = inserir(contato, i.esq );
        }
        else if( contato.nome.charAt(0) > i.letra ) {
            i.dir = inserir(contato, i.dir);
        }
        else {
            i.ultimo.prox = new Celula( contato );
            i.ultimo = i.ultimo.prox;
        }
        return ( i );
    }

    boolean pesquisar ( String nome ) 
    { 
        return ( pesquisar( nome, raiz ) );
    }

    private boolean pesquisar ( String nome, No i ) 
    {
        boolean found = false;
        if( i == null ) {
            found = false;
        } else if( nome.charAt(0) < i.letra ) {
            found = pesquisar( nome, i.esq );
        } else if( nome.charAt(0) > i.letra ) {
            found = pesquisar( nome, i.dir );
        } else {
            for( Celula j = i.primeiro.prox; (!found && j != null); j = j.prox ) {
                if( j.contato.nome.equals(nome) == true ) {
                    found = true;
                }
            }
        }
        return ( found );
    }

    boolean pesquisar ( int cpf ) 
    { 
        return ( pesquisar( cpf, raiz ) );
    }

    private boolean pesquisar ( int cpf, No i ) 
    {
        boolean found = false;
        if( i == null ) {
            found = false;
        } else if( cpf < i.letra ) {
            found = pesquisar( cpf, i.esq );
        } else if( cpf > i.letra ) {
            found = pesquisar( cpf, i.dir );
        } else {
            for( Celula j = i.primeiro.prox; (!found && j != null); j = j.prox ) {
                if( j.contato.cpf == cpf ) {
                    found = true;
                }
            }
        }
        return ( found );
    }

    void caminhar ( )
    {
        System.out.println( "" );
        caminhar( raiz );
        System.out.println( "" );
    }

    private void caminhar ( No i )
    {
        if( i != null )
        {
            caminhar( i.esq );
            System.out.print( " " + i.letra + ": " );
            System.out.print( "{" );
            for( Celula j = i.primeiro.prox; j != null; j = j.prox )
            {
                System.out.print( " " + j.contato.nome + " " );
            }
            System.out.println( "}" );
            caminhar( i.dir );
        }
    }
} // end class

public class Exercicios05 
{
    public static void main(String[] args) 
    {
        System.out.println("\nTestes\n" );
        Contato [] pessoas1 = new Contato[26];
        Contato [] pessoas2 = new Contato[26];
        Agenda agenda = new Agenda( );

        agenda.caminhar( );

        for( int i = 0; i < 26; i++ )
        {
            int c = 65+i;
            pessoas1[i] = new Contato( (char) c + "nome", "", "", 0 );
            pessoas2[i] = new Contato( (char) c + "NOME", "", "", 0 );
            // System.out.println( pessoas1[i].toString( ) );
        }
        for( int i = 0; i < 26; i++ )
        {
            agenda.inserir( pessoas1[i] );
            agenda.inserir( pessoas2[i] );
            // System.out.println( i );
        }
        agenda.caminhar( );

        System.out.println( "Resultado da Pesquisa Por Nome \"Mnome\" : " + agenda.pesquisar( "Mnome" ) );
        System.out.println( "Resultado da Pesquisa Por Nome \"hnome\" : " + agenda.pesquisar( "hnome" ) );
        System.out.println( "" );
        System.out.println( "Resultado da Pesquisa Por CPF \"123456789\" : " + agenda.pesquisar( 123456789 ) );
        System.out.println( "Resultado da Pesquisa Por CPF \"987654321\" : " + agenda.pesquisar( 987654321 ) );
        System.out.println( "" );
    } // end main ( )
} // end class
