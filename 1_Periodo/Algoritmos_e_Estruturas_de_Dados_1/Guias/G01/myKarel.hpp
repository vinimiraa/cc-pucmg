/*
   karel  - Karel robot definitions.
   @author  PUC-Minas - ICEI
   @version 0.1 - 2020

   Inspired by the original work (reference):
   Miroslav Binas <mirek.binas at tuke dot sk>
   (c) 2010, 2016
   https://git.kpi.fei.tuke.sk/kpi/karel-the-robot

   myKarel.hpp - v0.0. - 03 / 08 / 2023
   Author: Vinicius Miranda de Araujo - 812839

*/

#include "karel.hpp"

#ifndef _MYKAREL_HPP
#define _MYKAREL_HPP

using namespace std;

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
      // testar se o robo esta' ativo
      if (checkStatus())
      {
         // o agente que executar esse metodo
         // devera' virar tres vezes 'a esquerda
         turnLeft();
         turnLeft();
         turnLeft();
      } // end if
   }    // end turnRight ( )

   /**
      moveN - Metodo para mover certa quantidade de passos.
      @param steps - passos a serem dados.
    */
   void moveN(int steps)
   {
      // definir dado local
      int step = 0;
      // repetir contando e testando ate' atingir a quantidade de passos
      for (step = 1; step <= steps; step = step + 1) // outra forma de repetir
      {
         // dar um passo por vez
         move();
      } // end if
   }    // end moveN( )

   /**
      putBeepers - Metodo para colocar beepers.
   */
   void putBeepers(int n)
   {
      // incluir comandos extras
      for (int i = 0; i < n; i++)
         putBeeper();
   } // end putBeepers ( )

   /**
      pickBeepers - Metodo para pegar beepers.
   */
   void pickBeepers(int n)
   {
      // incluir comandos extras
      for (int i = 0; i < n; i++)
         pickBeeper();
   } // end putBeepers ( )

   /**
      doPartialTask - Metodo para descrever parte de uma tarefa.
   */
   void doPartialTask()
   {
      // especificar acoes dessa parte da tarefa
      moveN(3);
      turnLeft();
   } // end doPartialTask( )

   /**
      doTask - Relacao de acoes para qualquer robo executar.
   */
   void doTask()
   {
      // executar
      moveN(5);
      turnLeft();
      moveN(2);
      pickBeeper();
      moveN(4);
      turnLeft();
      moveN(4);
      turnLeft();
      move();
      pickBeepers(2);
      turnRight();
      turnRight();
      move();
      turnRight();
      moveN(3);
      pickBeepers(3);
      move();
      turnRight();
      move();
      turnRight();
      moveN(2);
      turnLeft();
      moveN(3);
      putBeepers(6);
      turnLeft();
      turnLeft();
      moveN(3);
      turnRight();
      moveN(2);
      turnRight();
      moveN(5);
      turnRight();
      moveN(5);
      turnRight();
      turnRight();
      // encerrar
      turnOff();
   } // end doTask ( )

}; // end class MyRobot

#endif