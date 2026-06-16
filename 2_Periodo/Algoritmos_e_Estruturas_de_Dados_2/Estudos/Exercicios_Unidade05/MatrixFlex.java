class CelulaMat
{
    public int elemento;
    public CelulaMat dir;
    public CelulaMat esq;
    public CelulaMat sup;
    public CelulaMat inf;

    
    public CelulaMat(){
        this.elemento = 0;
        this.dir = null;
        this.esq = null;
        this.sup = null;
        this.inf = null;
    }

    public CelulaMat(int x){
        this.elemento = x;
        this.dir = null;
        this.esq = null;
        this.sup = null;
        this.inf = null;
    }
} // end class

public class MatrixFlex
{
    private CelulaMat inicio;
    private int linha,coluna;
    
    public MatrixFlex( ){
        this(3,3);
    } // end MatrixFlex ( )

    public MatrixFlex( int linhas, int colunas )
    {
        inicio = new CelulaMat(0);
        this.linha = linhas;
        this.coluna = colunas;
        CelulaMat i = inicio;
        for(int j = 1; j< this.coluna; j++){
            CelulaMat nova = new CelulaMat(0);
            i.dir = nova;
            nova.esq = i;
            i = nova;
        }

        CelulaMat linhaAnterior = inicio;
        for(int k = 1; k<this.linha; k++)
        {
            CelulaMat novaLinha = new CelulaMat( );
            linhaAnterior.inf = novaLinha;
            novaLinha.sup = linhaAnterior;

            CelulaMat celulaAtualLinha = novaLinha;
            CelulaMat celulaAcima = linhaAnterior;
            for(int j = 1; j<this.coluna; j++)
            {
                CelulaMat novaCelula = new CelulaMat( );
                celulaAtualLinha.dir = novaCelula;
                novaCelula.esq = celulaAtualLinha;

                celulaAcima = celulaAcima.dir;
                celulaAcima.inf = novaCelula;
                novaCelula.sup = celulaAcima;

                celulaAtualLinha=novaCelula;
            }
            linhaAnterior = novaLinha;
        }
    } // end MatrixFlex ( )

    public void mostrar( ) 
    {
        CelulaMat linhaAtual = inicio;
        while( linhaAtual != null ) 
        {
            CelulaMat colunaAtual = linhaAtual;
            while( colunaAtual != null ) 
            {
                System.out.print(colunaAtual.elemento + " ");
                colunaAtual = colunaAtual.dir;
            } // end while
            System.out.println();
            linhaAtual = linhaAtual.inf;
        } // end while
    } // end mostrar ( )

    /* A revisar. Ainda tem um errinho */
    private void diagonalPrincipal( CelulaMat i )
    {
        CelulaMat j = i;
        while( j != null )
        {
            System.out.println(j.elemento);
            j = j.inf.dir;
        } // end while
    } // end diagonalPrincipal ( )
    
    public void diagonalPrincipal(  ) {
        diagonalPrincipal(inicio);
    } // end diagonalPrincipal ( )

    /* Testes */
    public static void main(String[] args) {
        MatrixFlex matriz = new MatrixFlex( 4, 4 );
        matriz.mostrar();
        // matriz.diagonalPrincipal();
    } // end main ( )
} // end class