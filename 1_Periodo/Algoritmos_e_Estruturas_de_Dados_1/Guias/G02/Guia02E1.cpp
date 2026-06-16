/*
 Guia_02E1 - v0.0. - 07 / 08 / 2023
 Author: Vinicius Miranda de Araujo
 Para compilar em uma janela de comandos (terminal):

 No Linux : g++ -o Guia02E1 ./Guia02E1.cpp
 No Windows: g++ -o Guia02E1 Guia02E1.cpp
 Para executar em uma janela de comandos (terminal):

 No Linux : ./Guia02E1
 No Windows: Guia02E1
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
    // verticais
    world->set(2, 3, VWALL);
    world->set(3, 3, VWALL);
    world->set(4, 3, VWALL);
    world->set(5, 3, VWALL);
    world->set(2, 4, VWALL);
    world->set(3, 4, VWALL);
    world->set(4, 4, VWALL);
    world->set(5, 4, VWALL);
    world->set(2, 5, VWALL);
    world->set(3, 5, VWALL);
    world->set(4, 5, VWALL);
    world->set(5, 5, VWALL);
    world->set(2, 6, VWALL);
    world->set(3, 6, VWALL);
    world->set(4, 6, VWALL);
    world->set(5, 6, VWALL);
    world->set(2, 7, VWALL);
    world->set(3, 7, VWALL);
    world->set(4, 7, VWALL);
    world->set(5, 7, VWALL);
    world->set(2, 8, VWALL);
    world->set(5, 8, VWALL);

    // horizontais
    world->set(3, 2, HWALL);
    world->set(3, 8, HWALL);
    world->set(4, 2, HWALL);
    world->set(5, 2, HWALL);
    world->set(5, 8, HWALL);

    // colocar um marcador no mundo
    world->set(3, 3, BEEPER);
    world->set(4, 3, BEEPER);
    world->set(5, 3, BEEPER);
    world->set(4, 4, BEEPER);
    world->set(4, 4, BEEPER);
    world->set(5, 4, BEEPER);
    world->set(5, 4, BEEPER);
    world->set(5, 5, BEEPER);
    world->set(5, 5, BEEPER);
    world->set(5, 5, BEEPER);
    
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
    int pickBeepers( )
    {
        //definir dados
        int x, y;
        x = xAvenue();
        y = yStreet();
        char fileName[15] = "Tarefa02E1.txt";
        //definir arquivo para receber acrescimos ao final
        std::fstream archive (fileName, std::ios::app);
        
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
        archive << x << std::endl;
        archive << y << std::endl;
        //fechar arquivo
        //INDISPENSAVEL para a gravacao
        archive.close();
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
     * recordActions - Metodo para mover o robot interativamente
     * e guardar a descricao da tarefa em arquivo.
     * @param fileName - nome do arquivo
     */
    void recordActions(const char *fileName)
    {
        // definir dados
        int action;
        // definir arquivo onde gravar comandos
        std::ofstream archive(fileName);
        // ler acao
        action = IO_readint("Command? ");
        // repetir enquanto acao maior ou igual a zero
        while (action >= 0)
        {
            // testar se opcao valida
            if (0 <= action && action <= 9)
            {
                // executar comando
                execute(action);
                // guardar o comando em arquivo
                archive << action << "\n";
            } // end if
            // ler acao
            action = IO_readint("Command? ");
        } // end while
        // fechar o arquivo
        // INDISPENSAVEL para a gravacao
        archive.close();
    } // end recordActions ( )

    /**
     playActions - metodo para receber comandos de arquivo.
     @param fileName - nome do arquivo
    */
    void playActions(const char *fileName)
    {
        // definir dados
        int action;
        // definir arquivos de onde ler dados
        std::ifstream archive(fileName);
        // repetir enquanto houver dados
        archive >> action;     // tentar ler a primeira linha
        while (!archive.eof()) // testar se nao encontrado o fim
        {
            // mostrar mais um comando
            IO_print(IO_toString(action));
            delay(stepDelay);
            // executar mais um comando
            execute(action);
            // tentar ler a proxima linha
            archive >> action; // tentar ler a próxima linha
        }                      // end for
        // fechar o arquivo
        // RECOMENDAVEL para a leitura
        archive.close();
    } // end playActions ( )

    /**
     * dictionary - Metodo para traduzir um comando.
     * @param action - comando a ser traduzido
     */
    chars dictionary(int action)
    {
        // definir dado
        static char word[80];
        strcpy(word, ""); // palavra vazia
        // identificar comando
        switch (action)
        {
        case 1: // virar para a esquerda
            strcpy(word, "turnLeft( ); ");
            break;
        case 2: // virar para o sul
            strcpy(word, "faceSouth( ); ");
            break;
        case 3: // virar para a direita
            strcpy(word, "turnRight( ); ");
            break;
        case 4: // virar para o oeste
            strcpy(word, "faceWest( ); ");
            break;
        case 5: // mover
            strcpy(word, "move( ); ");
            break;
        case 6: // virar para o leste
            strcpy(word, "faceEast( ); ");
            break;
        case 7: // pegar marcador
            strcpy(word, "pickBeeper( );");
            break;
        case 8: // virar para o norte
            strcpy(word, "faceNorth( ); ");
            break;
        case 9: // colocar marcador
            strcpy(word, "putBeeper( ); ");
            break;
        } // end switch
        // retornar palavra equivalente
        return (&(word[0]));
    } // end dictionary( )

    /**
     translateActions - Metodo para receber comandos de arquivo e traduzi-los.
     @param fileName - nome do arquivo
    */
    void translateActions(const char *fileName)
    {
        // definir dados
        int action;
        // definir arquivo de onde ler dados
        std::ifstream archive(fileName);
        // repetir enquanto houver dados
        archive >> action;     // tentar ler a primeira linha
        while (!archive.eof()) // testar se nao encontrado o fim
        {
            // tentar traduzir um comando
            IO_print(dictionary(action));
            getchar();
            // guardar mais um comando
            execute(action);
            // tentar ler a proxima linha
            archive >> action; // tentar ler a proxima linha
        }                      // end for
                               // fechar o arquivo
                               // RECOMENDAVEL para a leitura
        archive.close();
    } // end translateActions ( )

    /**
     appendActions - Metodo para acrescentar comandos ao arquivo e traduzi-los.
     @param filename - nome do arquivo
    */
    void appendActions(const char *fileName)
    {
        // definir dados
        int action, count = 0;
        // definir arquivo para receber acrescimos ao final
        std::fstream archive(fileName, std::ios::app);
        // repetir enquanto acao diferente de zero
        do
        {
            // ler acao
            action = IO_readint("Command? ");
            // testar se opcao valida
            if (0 <= action && action <= 9)
            {
                // executar comando
                execute(action);
                // guardar o comando em arquivo
                archive << action << std::endl;
                // contador de linhas
                count++;

            } // end if
        } while (action != 0);
        // gravar no arquivo na ultima linha o tanto de linhas de arquivo
        archive << count << std::endl;
        // fechar o arquivo
        // INDISPENSAVEL para a gravacao
        archive.close();
    } // end appendActions ( )

    /*
     stepUpRight: um degrau para cima e à direita
    */
    void stepUpRight()
    {
        // acoes para subir um degrau pela direita
        while (!facingNorth())
        {
            turnLeft();
        }
        move();
        turnRight();
        move();
    } // fim stepUpRight( )

    /*
     stepDownRight: um degrau para baixo e à direita
    */
    void stepDownRight()
    {
        // acoes para descer um degrau pela direita
        while (!facingEast())
        {
            turnLeft();
        }
        move();
        turnRight();
        move();
    } // fim stepDownRight( )

    /*
     stepUpLeft: um degrau para cima e à esquerda
    */
    void stepUpLeft()
    {
        // acoes para subir um degrau pela esquerda
        while (!facingNorth())
        {
            turnLeft();
        }
        move();
        turnLeft();
        move();
    } // fim stepUpLeft( )

    /*
     stepDownLeft: um degrau para baixo e à esquerda
    */
    void stepDownLeft()
    {
        // acoes para subir um degrau pela esquerda
        while (!facingWest())
        {
            turnLeft();
        }
        move();
        turnLeft();
        move();
    } // fim stepDownLeft( )

    /*
     putBeepers: coloca uma certa quantidade de Beepers
    */
    void putBeepers(int beepers)
    {
            if (beepersInBag())
            {
                for (int i = 0; i < beepers; i++)
                {
                    putBeeper();
                }
            }
    }
    // fim putBeepers( )

    /**
     doTask - Relacao de acoes para o robo executar.
    */
    void doTask()
    {
        // executar tarefas
        
        //pegar o primeiro beeper (1)
        turnLeft( );
        moveN( 8 );
        turnRight( );
        moveN( 3 );
        turnRight( );
        move( );
        turnRight( );
        move( );
        turnLeft( );
        moveN( 5 );
        pickBeepers( );
        //pegar o segundo beeper (1)
        turnRight( );
        turnRight( );
        moveN( 5 );
        turnRight( );
        move( );
        turnRight( );
        moveN( 5 );
        pickBeepers( );
        //pegar o terceiro beeper (1)
        turnRight( );
        turnRight( );
        moveN( 5 );
        turnRight( );
        move( );
        turnRight( );
        moveN( 5 );
        pickBeepers( );
        // pegar o primeiro beeper (2)
        turnRight( );
        turnRight( );
        move( );
        pickBeepers( );
        // pegar o segundo beeper (2)
        moveN( 4 );
        turnLeft( );
        move( );
        turnLeft( );
        moveN( 4 );
        pickBeepers( );
        // pegar o primeiro beeper (3)
        turnRight( );
        turnRight( );
        moveN( 4 );
        turnRight( );
        move( );
        turnRight( );
        moveN( 3 );
        pickBeepers( );
        //colocar beepers em (X)
        turnRight( );
        turnRight( );
        moveN( 3 );
        turnLeft( );
        move( );
        turnRight( );
        move( );
        turnRight( );
        moveN( 3 );
        turnRight( );
        moveN( 8 );
        putBeepers( 10 );
        //voltar a posicao inicial
        turnRight( );
        moveN( 6 );
        turnRight( );
        turnRight( );
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
    decorateWorld("Guia02E1.txt");
    world->show();
    // preparar o ambiente para uso
    world->reset();              // limpar configuracoes
    world->read("Guia02E1.txt"); // ler configuracao atual para o ambiente
    world->show();               // mostrar a configuracao atual
    set_Speed(3);                // definir velocidade padrao
                                 // criar robo
    MyRobot *robot = new MyRobot();
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create(1, 1, EAST, 0, "Karel");
    // executar tarefa
    robot->appendActions("Tarefa02E1.txt");
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
 