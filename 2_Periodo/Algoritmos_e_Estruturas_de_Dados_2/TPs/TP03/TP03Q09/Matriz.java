/*
 *  -------------------------- Documentacao
 *  
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP03Q09 - 01 / 06 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : javac Matriz.java
 *       Windows: javac Matriz.java
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : java Matriz
 *       Windows: java Matriz
 *   
*/

import java.util.Scanner;

/**
 *  Classe Célula: Célula da Matriz
 */
class Celula
{
    int elemento;
    Celula sup, dir, inf, esq; 

    public Celula ( )
    {
        this(0);
    } // end Celula ( )

    public Celula ( int elemento )
    {
        this( elemento, null, null, null, null );
    } // end Celula ( )

    public Celula ( int elemento, Celula sup, Celula dir, Celula inf, Celula esq )
    {
        this.elemento = elemento;
        this.sup = sup; // norte
        this.dir = dir; // leste
        this.inf = inf; // sul
        this.esq = esq; // oeste
    } // end Celula ( )

} // end class Celula

/**
 *  Classe Matriz : Matriz Flexivel
 */
public class Matriz
{
    Celula inicio;
    int linha;
    int coluna;

    static Scanner scan = new Scanner( System.in );

    public Matriz ( )
    {
        this( 3, 3 );
    } // end Matriz ( )

    public Matriz ( int linhas, int colunas ) 
    {   
        inicio = new Celula(0);    
        this.linha = linhas;    
        this.coluna = colunas;  
        Celula i = inicio;    
        for( int j = 1; j < this.coluna; j = j + 1 )
        {
            Celula nova = new Celula( 0 );
            i.dir = nova;
            nova.esq = i;
            i = nova;   
        } // end for
        Celula linhaAnterior = inicio;   
        for( int k = 1; k < this.linha; k = k + 1 )
        {
            Celula novaLinha = new Celula( 0 );
            linhaAnterior.inf = novaLinha;
            novaLinha.sup = linhaAnterior;  
            Celula celulaAtualLinha = novaLinha;
            Celula celulaAcima = linhaAnterior;
            for( int j = 1; j < this.coluna; j = j + 1 )
            {
                Celula novaCelula = new Celula( 0 );
                celulaAtualLinha.dir = novaCelula;
                novaCelula.esq = celulaAtualLinha;  
                celulaAcima = celulaAcima.dir;
                celulaAcima.inf = novaCelula;
                novaCelula.sup = celulaAcima;   
                celulaAtualLinha=novaCelula;
            } // end for
            linhaAnterior = novaLinha;  
        } // end for
    } // end Matriz ( )

    public void ler ( )
    {
        for( Celula linha = inicio; linha != null; linha = linha.inf )
        {
            for( Celula coluna = linha; coluna != null; coluna = coluna.dir )
            {
                if( scan.hasNextInt( ) )
                {
                    coluna.elemento = scan.nextInt( );
                } // end if
            } // end for
        } // end for
    } // end ler ( )

    public void mostrar ( )
    {
        for( Celula linha = this.inicio; linha != null; linha = linha.inf )
        {
            for( Celula coluna = linha; coluna != null; coluna = coluna.dir )
            {
                System.out.print( coluna.elemento + " " );
            } // end for
            System.out.println( "" );
        } // end for
    } // end mostrar ( )

    public boolean eQuadrada ( )
    {
        return ( this.linha == this.coluna );
    } // end eQuadrada ( )

    public Matriz soma ( Matriz other )
    {
        Matriz resultado = null;
        if( this.linha != other.linha && this.coluna != other.coluna  ) {
            System.err.println( "ERRO: Matrizes com dimensoes diferentes!" );
        }
        else
        {
            resultado = new Matriz( this.linha, this.coluna );
            // A = atual, O = outra, N = nova
            for( Celula linA = this.inicio, linO = other.inicio, linN = resultado.inicio;
                        linA != null     && linO != null      && linN != null; 
                        linA = linA.inf   , linO = linO.inf    , linN = linN. inf )
            {
                for( Celula colA = linA    , colO = linO    , colN = linN;
                            colA != null  && colO != null  && colN != null;
                            colA = colA.dir, colO = colO.dir, colN = colN.dir )
                {
                    colN.elemento = colA.elemento + colO.elemento;
                } // end for
            } // end for
        } // end if
        return ( resultado );
    } // end soma ( )

    public Matriz multiplicacao ( Matriz other )
    {
        Matriz resultado = null;
        if( this.coluna != other.linha ) {
            System.err.println( "ERRO: atual.coluna != other.linha" );
        }
        else
        {
            resultado = new Matriz( this.linha, other.coluna );
            for( Celula linA = this.inicio, linN = resultado.inicio; linA != null; linA = linA.inf, linN = linN.inf ) 
            {
                for( Celula colO = other.inicio, colN = linN; colO != null; colO = colO.dir, colN = colN.dir ) 
                {
                    int soma = 0;
                    for( Celula colA = linA, linO = colO; colA != null && linO != null; colA = colA.dir, linO = linO.inf ) 
                    {
                        soma = soma + colA.elemento * linO.elemento;
                    } // end for
                    colN.elemento = soma;
                } // end for
            } // end for
        } // end if
        return ( resultado );
    } // end multiplicacao ( )

    public void mostrarDiagonalPrincipal ( )
    {
        if( this.eQuadrada( ) == true )
        {
            Celula temp = inicio;
            for( int i = 0; i < this.linha; i = i + 1 )
            {
                System.out.print( temp.elemento + " " );
                if(  temp.inf != null && temp.dir != null )
                {
                    temp = temp.inf.dir;
                } // end if
            } // end for
            System.out.println( );
        } // end ir
    } // end mostrarDiagonalPrincipal ( )

    public void mostrarDiagonalSecundaria ( )
    {
        if( this.eQuadrada( ) == true )
        {
            Celula temp = inicio;
            while( temp.dir != null ) 
            {
                temp = temp.dir;
            } // end while
            for( int i = 0; i < this.linha; i = i + 1 )
            {
                System.out.print( temp.elemento + " " );
                if( temp.inf != null && temp.esq != null )
                {
                    temp = temp.inf.esq;
                } // end if
            } // end for
            System.out.println( );
        } // end ir
    } // end mostrarDiagonalPrincipal ( )

    public static void main ( String [] args ) throws Exception
    {
        int numCasos = 0;
        int linha = 0;
        int coluna = 0;

        numCasos = scan.nextInt( );
        for( int i = 0; i < numCasos; i = i + 1 )
        {
            linha = scan.nextInt( );
            coluna = scan.nextInt( );
            Matriz m1 = new Matriz( linha, coluna );
            m1.ler( );

            linha = scan.nextInt( );
            coluna = scan.nextInt( );
            Matriz m2 = new Matriz( linha, coluna );
            m2.ler( );

            m1.mostrarDiagonalPrincipal( );
            m1.mostrarDiagonalSecundaria( );

            Matriz soma = m1.soma( m2 );
            soma.mostrar( );

            Matriz mult = m1.multiplicacao( m2 );
            mult.mostrar( );
        } // end for
        scan.close( );
    } // end main ( )

} // end class Matriz

