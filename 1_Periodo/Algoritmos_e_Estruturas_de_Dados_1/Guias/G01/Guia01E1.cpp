/*
 Guia01E1 - v0.0. - 03 / 08 / 2023
 Author: Vinicius Miranda de Araujo
 Para compilar em uma janela de comandos (terminal):
 
 No Linux : g++ -o Guia01E1 ./Guia01E1.cpp
 No Windows: g++ -o Guia01E1 Guia01E1.cpp
 Para executar em uma janela de comandos (terminal):
 No Linux : ./Guia01E1
 No Windows: Guia01E1
*/
// lista de dependencias
#include "karel.hpp" // comentário: necessario estar na mesma pasta
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
 // colocar paredes no mundo
 world->set ( 3, 2, HWALL ); // horizontal
 world->set ( 4, 2, HWALL ); // horizontal
 world->set ( 5, 2, HWALL ); // horizontal
 world->set ( 5, 3, VWALL ); // vertical
 world->set ( 5, 4, VWALL ); // vertical
 world->set ( 5, 5, VWALL ); // vertical
 world->set ( 3, 6, HWALL ); // horizontal
 world->set ( 4, 6, HWALL ); // horizontal
 world->set ( 5, 6, HWALL ); // horizontal
 world->set ( 2, 3, VWALL ); // vertical
 world->set ( 2, 4, VWALL ); // vertical
 world->set ( 2, 5, VWALL ); // vertical
 world->set ( 2, 6, VWALL ); // vertical
 // colocar um marcador no mundo
 world->set ( 2, 6, BEEPER );
 world->set ( 2, 6, BEEPER );
 world->set ( 5, 7, BEEPER );
 world->set ( 5, 7, BEEPER );
 world->set ( 5, 7, BEEPER );
 world->set ( 6, 3, BEEPER );
 // salvar a configuracao atual do mundo
 world->save( fileName );
} // decorateWorld ( )
/**
 Classe para definir robo particular (MyRobot),
 a partir do modelo generico (Robot)
 Nota: Todas as definicoes irao valer para qualquer outro robo
 criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
 public:
 /**
 turnRight - Procedimento para virar 'a direita.
 */
 void turnRight ( )
 {
 // testar se o robo esta' ativo
 if ( checkStatus ( ) )
 {
 // o agente que executar esse metodo
 // devera' virar tres vezes 'a esquerda
 turnLeft ( );
 turnLeft ( );
 turnLeft ( );
 } // end if
 } // end turnRight ( )

 /**
 moveN - Metodo para mover certa quantidade de passos.
 @param steps - passos a serem dados.
 */
 void moveN( int steps )
 {
 // definir dado local
 int step = 0;
 // repetir contando e testando ate' atingir a quantidade de passos
 for ( step = 1; step <= steps; step = step + 1 ) // outra forma de repetir
 {
 // dar um passo por vez
 move( );
 } // end if
} // end moveN( )

/**
 doPartialTask - Metodo para descrever parte de uma tarefa.
*/
void doPartialTask( )
{
 // especificar acoes dessa parte da tarefa
 moveN( 3 );
 turnLeft( );
} // end doPartialTask( )

/**
 putBeepers - Metodo para colocar beepers.
*/
void putBeepers ( int n )
{
 // incluir comandos extras
 while( n > 0)
 {
    putBeeper( );
    n = n - 1;
 }
} // end putBeepers ( )

/**
 pickBeepers - Metodo para pegar beepers.
*/
void pickBeepers ( int n )
{
 // incluir comandos extras
 while ( n > 0)
 {
    pickBeeper( );
    n--;
 }
} // end putBeepers ( )

/**
 doTask - Relacao de acoes para qualquer robo executar.
*/
void doTask ( )
{
 // executar
 moveN( 5 );
 turnLeft( );
 moveN( 2 );
 pickBeeper( );
 moveN( 4 );
 turnLeft( );
 moveN( 4 );
 turnLeft( );
 move( );
 pickBeepers( 2 );
 turnRight( );
 turnRight( );
 move( );
 turnRight( );
 moveN( 3 );
 pickBeepers( 3 );
 move( );
 turnRight( );
 move( );
 turnRight( );
 moveN( 2 );
 turnLeft( );
 moveN( 3 );
 putBeepers( 6 );
 turnLeft( );
 turnLeft( );
 moveN( 3 );
 turnRight( );
 moveN( 2 );
 turnRight( );
 moveN( 5 );
 turnRight( );
 moveN( 5 );
 turnRight( );
 turnRight( );
 // encerrar
 turnOff ( );
 } // end doTask ( )

}; // end class MyRobot

// --------------------------- acao principal

/**
 Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
// definir o contexto
// criar o ambiente e decorar com objetos
// OBS.: executar pelo menos uma vez,
// antes de qualquer outra coisa
// (depois de criado, podera' ser comentado)
 world->create ( "" ); // criar o mundo
 decorateWorld ( "Guia01E1.txt" );
 world->show ( );
// preparar o ambiente para uso
 world->reset ( ); // limpar configuracoes
 world->read ( "Guia01E1.txt" );// ler configuracao atual para o ambiente
 world->show ( ); // mostrar a configuracao atual
 set_Speed ( 3 ); // definir velocidade padrao
// criar robo
 MyRobot *robot = new MyRobot( );
// posicionar robo no ambiente (situacao inicial):
// posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
 robot->create ( 1, 1, EAST, 0, "Karel" );
// executar tarefa
 robot->doTask ( );
// encerrar operacoes no ambiente
 world->close ( );
// encerrar programa
 getchar ( );
 return ( 0 );
} // end main ( )

// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
 0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
 0.1 01. ( OK ) identificacao de programa
 0.2 01. ( OK ) teste da tarefa
 0.3 01. ( OK ) teste da tarefa parcial
 0.4 0.1 ( OK ) teste do apanhar marcador
 0.5 01. ( OK ) teste do colocar marcador
 0.6 01. ( OK ) teste da repeticao do movimento
 0.7 01. ( OK ) teste com marcador na posicao (4,4)
     02. ( OK ) teste sem marcador na posicao (4,4)
 0.8 01. ( OK ) teste com a quantidade de marcadores
 0.9 01. ( OK ) teste com outra forma de repeticao
 1.0 01. ( OK ) teste com outra forma de alternativa
*/