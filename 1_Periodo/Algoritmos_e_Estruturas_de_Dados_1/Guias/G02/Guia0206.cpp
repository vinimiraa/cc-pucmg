/*
 Guia_0206 - v0.0. - 07 / 08 / 2023
 Author: Vinicius Miranda de Araujo
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia0206 ./Guia0206.cpp
 No Windows: g++ -o Guia0206 Guia0206.cpp
 Para executar em uma janela de comandos (terminal):

 No Linux : ./Guia0206
 No Windows: Guia0206
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp" // para entradas e saídas
// --------------------------- definicoes de metodos
/**
 decorateWorld - Metodo para preparar o cenario.
 @param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld(const char *fileName)
{
    // colocar paredes no mundo
    world->set(4, 4, VWALL);
    world->set(4, 4, HWALL);
    // colocar um marcador no mundo
    world->set(4, 4, BEEPER);
    // salvar a configuracao atual do mundo
    world->save(fileName);
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
    void turnRight()
    {
        // definir dado local
        int step = 0;
        // testar se o robo esta' ativo
        if (checkStatus())
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            for (step = 1; step <= 3; step = step + 1)
            {
                turnLeft();
            } // end for
        }     // end if
    }         // end turnRight ( )

    /**
    moveN - Metodo para mover certa quantidade de passos.
    @param steps - passos a serem dados.
    */
    void moveN(int steps)
    {
        // definir dado local
        int step = 0;
        // testar se a quantidade de passos e' maior que zero
        for (step = steps; step > 0; step = step - 1)
        {
            // dar um passo
            move();
        } // end if
    }     // end moveN( )

    /**
    doPartialTask - Metodo para especificar parte de uma tarefa.
    */
    void doPartialTask()
    {
        // especificar acoes dessa parte da tarefa
        moveN(3);
        turnLeft();
    } // end doPartialTask( )

    /**
     * pickBeepers - Funcao para coletar marcadores.
     * @return quantidade de marcadores coletados
     */
    int pickBeepers()
    {
        // definir dado local
        int n = 0;
        // repetir (com teste no inicio)
        // enquanto houver marcador proximo
        while (nextToABeeper())
        {
            // coletar um marcador
            pickBeeper();
            // contar mais um marcador coletado
            n = n + 1;
        } // end while
        // retornar a quantidade de marcadores coletados
        return (n);
    } // end pickBeepers( )

    /**
     * doSquare - Metodo para especificar outro percurso.
     */
    void doSquare()
    {
        // definir dado local
        int step = 1;
        int n = 0;
        char msg[80];
        // especificar acoes da tarefa
        while (step <= 4)
        {
            // realizar uma parte da tarefa
            moveN(3);
            n = pickBeepers();
            // testar se quantidade maior que zero
            if (n > 0)
            {
                // montar a mensagem para a saida
                sprintf(msg, "Recolhidos = %d", n);
                // solicitar a exibicao da mensagem
                show_Text(msg);
            } // end if
            turnRight();
            // tentar passar 'a proxima
            step = step + 1;
        } // end while
        turnOff();
    } // end doSquare( )

    /**
     * execute - Metodo para executar um comando.
     * @param action - comando a ser executado
     */
    void execute(int option)
    {
        // executar a opcao de comando
        switch (option)
        {
        case 0: // terminar
            // nao fazer nada
            break;
        case 1: // virar para a esquerda
            if (leftIsClear())
            {
                turnLeft();
            } // end if
            break;
        case 2: // virar para o sul
            while (!facingSouth())
            {
                turnLeft();
            } // end while
            break;
        case 3: // virar para a direita
            if (rightIsClear())
            {
                turnRight();
            } // end if
            break;
        case 4: // virar para o oeste
            while (!facingWest())
            {
                turnLeft();
            } // end while
            break;
        case 5: // mover
            if (frontIsClear())
            {
                move();
            } // end if
            break;
        case 6: // virar para o leste
            while (!facingEast())
            {
                turnLeft();
            } // end while
            break;
        case 7: // pegar marcador
            if (nextToABeeper())
            {
                pickBeeper();
            } // end if
            break;
        case 8: // virar para o norte
            while (!facingNorth())
            {
                turnLeft();
            } // end while
            break;
        case 9: // colocar marcador
            if (beepersInBag())
            {
                putBeeper();
            } // end if
            break;
        default: // nenhuma das alternativas anteriores
            // comando invalido
            show_Error("ERROR: Invalid command.");
        } // end switch
    }     // end execute( )

    /**
     * moveI - Metodo para mover o robot interativamente.
     * Lista de comandos disponiveis:
     * 0 - turnOff
     * 1 - turnLeft      2 - to South
     * 3 - turnRight     4 - to West
     * 5 - move          6 - to East
     * 7 - pickBeeper    8 - to North
     * 9 - putBeeper
     */
    void moveI()
    {
        // definir dados
        int action;
        // repetir (com testes no fim)
        // enquanto opcao diferente de zero
        do
        {
            // ler opcao
            action = IO_readint("Command? ");
            // executar acao dependente da opcao
            execute(action);
        } while (action != 0);
    } // end moveI( )

    /**
    doTask - Relacao de acoes para o robo executar.
    */
    void doTask()
    {
        // definir dado local
        int step = 4;

        // especificar acoes da tarefa
        while (step > 0)
        {
            // realizar uma parte da tarefa
            doPartialTask();
            // tentar passar 'a proxima
            step = step - 1;
        } // end while
        // encerrar
        turnOff();
    } // end doTask( )

}; // end class MyRobot
// --------------------------- acao principal
/**
 Acao principal: executar a tarefa descrita acima.
*/
int main()
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create(""); // criar o mundo
    decorateWorld("Guia0206.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia0206.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(3);                // definir velocidade padrao
                                 // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, NORTH, 0, "Karel");
    // executar tarefa
    robot->moveI();
    // encerrar operacoes no ambiente
    world->close();
    // encerrar programa
    getchar();
    return (0);
} // end main ( )
  // -------------------------------------------- testes
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  ---------------------------------------------- historico
  Versao Data Modificacao
   0.1 __/__ esboco
  --------------------------------------------- testes
  Versao Teste
   0.1 01. ( OK ) identificacao de programa
   0.2 01. ( OK ) teste da repeticao para virar 'a direita
   0.3 01. ( OK ) teste da repeticao para percorrer um quadrado
  
  */
 