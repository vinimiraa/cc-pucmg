/*
   karel  - Karel robot definitions.
   @author  PUC-Minas - ICEI
   @version 0.1 - 2020

   Inspired by the original work (reference):
   Miroslav Binas <mirek.binas at tuke dot sk>
   (c) 2010, 2016
   https://git.kpi.fei.tuke.sk/kpi/karel-the-robot
 */

// import dependencies

// ------------------------------------ OS compatibility section

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <time.h>

// ------------------------------------ global definitions

#ifndef _KAREL_HPP_
#define _KAREL_HPP_

// global definitions
#define NORTH   0
#define EAST    1
#define SOUTH   2
#define WEST    3

#define HWALL  '_'
#define VWALL  '|'
#define BEEPER '1'
#define BOX    '#'

#define LIFO    0
#define FIFO    1

#define OPEN    0
#define CLOSED  1

// global constants
#define WIDTH   10
#define HEIGHT  10
#define DEPTH   20

#define MAX_AVENUES  WIDTH
#define MAX_STREETS  HEIGHT

#define MAX_COMMANDS 300

// global variables (application context)
#if defined (unix) || defined (_unix) || defined (_unix)
#define OS_DELAY 1000
#else
#define OS_DELAY 1
#endif

long baseDelay   =  100 ;
long stepDelay   =   1  ;

bool has_debug   = false;

bool has_Text    = false;

// ------------------------------------ global variables

#define NO_ERROR  0
char error_txt [ 40 ];

char debug_txt [ 40 ];

char message   [ 20 ];
char msg_txt   [ 20 ];
char msg_board [ 22 ][20];

// ------------------------------------ prototypes

void show_Text    ( const char* message );

// ------------------------------------ global I/O control definitions

/**
   clrscr - Clear screen.
   OBS: OS dependent !!!
 */
void clrscr ( )
{
#if defined (unix) || defined (_unix) || defined (_unix)
//     system ( "clear" );  // for Linux
//     system ( "reset" );  // for Linux
    printf ( "\033c" );
#else
    system ( "cls" );    // for Windows
#endif
} // end clrscr ( )

/**
   clreol - Clear till the end of line.
   OBS: DISABLED
 */
void clreol ( )
{
} // end clreol ( )

/**
   gotoxy - Move focus to screen coordinates.
   @param x - x-axis coordinate
   @param y - y-axis coordinate
   OBS: DISABLED
 */
void gotoxy ( int x, int y )
{
} // end gotoxy ( )

/**
   delay - Sleep for a given number of ticks.
   @param ticks - number of ticks to rest
   OBS.:  (ANSI-C compatible)
 */
void delay( clock_t ticks )
{
     clock_t now,
             stop = clock( ) + ticks;

     do
     {  now = clock( );   }
     while ( now <= stop );
} // end delay

/**
   setSpeed - Set new step delay base.
   @param newStepDelay - new base for time control
 */
void set_Speed ( int newStep )
{
  if ( 1 <= newStep && newStep < 1000 )
  {
     stepDelay = OS_DELAY * baseDelay * newStep;
  }
} // end setSpeed ( )

// ------------------------------------ global error treatment

/**
   error_code - Keep error code (global).
 */
int  error_code = NO_ERROR;

/**
   set_Error  - Set a new error code.
   @param code  to be set
 */
void set_Error ( int code )
{
     error_code = code;
} // end set_Error ( )

/**
   get_Error  - Copy current error code.
   @return current error code
 */
int  get_Error ( )
{
     return ( error_code );
} // end get_Error ( )

/**
   has_Error  - Test if there's any error code set.
   @return true, if there is an error code set;
           false, otherwise
 */
int  has_Error ( )
{
     return ( error_code != NO_ERROR );
}  // end has_Error ( )

/**
   show_Error  - Show error message.
   @param message corresponding to an error code set
 */
void show_Error ( const char* message )
{
    error_code = 1;
    show_Text ( message );
}  // end show_Error ( )

/**
   fatal_Error  - Show error message and finishes program.
   @param message corresponding to an fatal error code set
 */
void fatal_Error ( char* message )
{
  printf ( "\n%s\n", message );
  exit   ( error_code );
} // end fatal_Error ( )

// ------------------------------------ global type definitions

/**
   world  - World object definition.
 */
class World
{
  public:                   // world public container
    int   height;
    int   width;
    int   depth;
    char  name [20];        // identification
                            // object container
   char data [ HEIGHT ][ WIDTH ][ DEPTH ];

   World ( );               // constructor
 ~ World ( );               // destructor

   int    avenues     ( );
   int    streets     ( );
   bool   areValid    ( int avenue, int street );
   char   get         ( int avenue, int street );
   int    search      ( int avenue, int street, char object );
   int    has_slot    ( int avenue, int street );
   int    has_HWALL   ( int avenue, int street );
   int    has_VWALL   ( int avenue, int street );
   int    has_BEEPER  ( int avenue, int street );
   int    has_BEEPERS ( int avenue, int street );
   int    has_BOX     ( int avenue, int street );
   int    has_ROBOT   ( int avenue, int street, char symbol );
   void   show        ( );
   void   reset       ( );
   void   create      ( const char* name );
   void   save        ( const char* fileName );
   void   read        ( const char* fileName );
   void   set         ( int avenue, int street, char object );
   void   remove      ( int avenue, int street, int object );
   void   close       ( );

};

/**
   ref_world - Reference to a World object.
 */
typedef World* ref_World;   // reference
                            // create a global reference to an object
ref_World world = new World( );


/**
   box - Box object definition.
 */
class Box
{
  public:                   // box public container
    int   status;           // open (']') or closed ('[')

    int   avenue;           // x-axis position
    int   street;           // y-axis position
    int   direction;        // LIFO or FIFO
    int   beepers;          // in box

    char  symbol;           // badge
    char  name [20];        // identification

    void  create            ( int avenue   , int street ,
                              int direction, int beepers,
                              char* name   , int status );
    int   nbeepers          ( );
    int   isEmpty           ( );
    int   checkStatus       ( );
    void  open              ( );
    void  close             ( );
    int   pullBeeper        ( );
    void  pushBeeper        ( );

};

/**
   ref_box - Reference to a Box object.
 */
typedef Box* ref_Box;


/**
   robot     - Robot object definition.
 */
class Robot
{
  public:                   // robot public container
    int   status;           // is it running (1), or not (0)

    int   avenue;           // x-axis position
    int   street;           // y-axis position
    int   direction;        //
    int   beepers;          // in bag

    char  symbol;           // badge
    char  name [20];        // identification

    Robot( );               // constructor
   ~Robot( );               // destructor

    bool  checkStatus  ( );
    void  turnOn       ( );
    void  turnOff      ( );
    bool  frontIsClear ( );
    void  create       ( int avenue, int street, 
                         int direction, int beepers,
                         const char* name );
    void  set          ( int x, int y );
    void  move         ( );
    void  turnLeft     ( );
    void  pickBeeper   ( );
    void  putBeeper    ( );
    void  pickBeeperFromBox ( ref_Box box );
    void  putBeeperIntoBox  ( ref_Box box );

    bool  beepersInBag ( );
    int   nbeepers     ( );
    void  faceWest     ( );
    void  faceEast     ( );
    void  faceSouth    ( );
    void  faceNorth    ( );
    void  face         ( int direction );
    bool  facing       ( int direction );
    bool  facingWest   ( );
    bool  facingEast   ( );
    bool  facingSouth  ( );
    bool  facingNorth  ( );
    bool  rightIsClear ( );
    bool  leftIsClear  ( );
    bool  nextToARobot ( );
    bool  nextToABeeper( );
    bool  nextToABox   ( );
    int   xAvenue      ( );
    int   yStreet      ( );
    bool  areYouHere   ( int avenue, int street );

    void  debugOff     ( );
    void  debugOn      ( );
    void  debug        ( );

};

/**
   ref_robot - Reference to a Robot structure.
 */
typedef Robot* ref_Robot;


// ------------------------------------ global (public) context

// CAUTION: Use with care.
//          MUST be changed only if objects changes.

/**
   world_now - Current reference to a World structure.
 */
ref_World world_now = nullptr;
/**
   robot_now - Current reference to a Robot structure.
 */
ref_Robot robot_now = nullptr;
/**
   box_now   - Current reference to a Box   structure.
 */
ref_Box   box_now   = nullptr;

// ------------------------------------ input/output treatment

/**
   show_Text  - Show text message.
   @param message to be shown.
 */
void show_Text ( const char* message )
{
    char copy [80];                        // copy of original message
    if ( message != nullptr )
    {
       strcpy ( copy, message );
       copy [19] = '\0';                   // set message length limit=20
       strcpy ( msg_txt, copy );           // prepare message for exhibition
       has_Text = true;
       world->show ( );
    }
}  // end show_Text ( )

/**
   show_Board - Show basic robot board.
   @param line for the message.
   @param message to be shown.
 */
void show_Board ( int line, char* message )
{
    char copy [80];                        // copy of original message
    if ( message != nullptr &&
       (1 <= line && line <= 20) )
    {
       strcpy ( copy, message );
       copy [19] = '\0';                   // set message length limit=20
       strcpy ( msg_board[line+1], copy ); // prepare message for exhibition
       has_Text = true;
       world->show ( );
    }
}  // end show_Board ( )

/**
   show_Screen - Show 22x80 screen mirror.
   @param screen - symbol matrix to be shown
 */
void show_Screen ( char screen [ ][80] )
{
    int  x = 0;

    for ( x = 21; x >= 0; x-- )
    {
        printf ( "%s\n", screen [ x ] );
        msg_board [ x ][0] = '\0';
    }
//    getchar( );
    delay ( stepDelay );
    if ( has_debug || has_Error( ) || has_Text )
    {
       fflush (stdin);
       getchar ( );
       error_code   = NO_ERROR;
       error_txt[0] = '\0';
       msg_txt  [0] = '\0';
       message  [0] = '\0';
       has_Text     = false;
    }
} // end show_Screen ( )

// ------------------------------------ world definitions

World::World ()
{
}

World::~World ()
{
}

/**
   avenues - Retrieve current world number of avenues.
   @return number of avenues, if there is any;
           zero, otherwise
 */
int World::avenues ( )
{
  return ( width );
} // end avenues ( )

/**
   streets - Retrieve current world number of streets.
   @return number of streets, if there is any;
           zero, otherwise
 */
int World::streets ( )
{
  return ( height );
} // end streets ( )

/**
   areValid - Check if avenue and street are valid.
   @return true, if avenue and street are valid;
           false, otherwise
   @param avenue - slot (x)
   @param street - slot (y)
 */
bool World::areValid ( int avenue, int street )
{
  return ( (1 <= avenue && avenue <= avenues( ) ) &&
           (1 <= street && street <= streets( ) )  );
} // end areValid ( )

/**
   get_world - Retrieve top information of a world slot.
   @param avenue - slot (x)
   @param street - slot (y)
 */
char World::get ( int avenue, int street )
{
     char c = ' ';

     if ( areValid ( avenue, street ) )
     {
        c = data [ street-1 ][ avenue-1 ][ 0 ];
     }

     return ( c );
} // end get_World ( )

/**
   search_world - Search a world slot for an object.
   @param avenue - slot (x)
   @param street - slot (y)
   @param object - to be searched
 */
int World::search ( int avenue, int street, char object )
{
  int  result = -1;
  int  z      = -1;
  char c;

  if ( areValid ( avenue, street ) )
  {
       do
       {
          z = z + 1;
          c = data [ street-1 ][ avenue-1 ][ z ];
       }
       while ( z < depth-1 && c != object );
       if ( c == object )
          result = z;
  }
  return ( result );
} // end search_World ( )

/**
   has_slot - Retrieve a free space at a world slot.
   @return free space index, if there is one;
           (-1), otherwise
   @param avenue - slot (x)
   @param street - slot (y)
 */
int World::has_slot ( int avenue, int street )
{
  return ( search ( avenue, street, '.' ) );
} // end has_slot ( )

/**
   has_HWALL - Retrieve a horizontal wall index at a world slot.
   @return wall index, if there is one;
           zero, otherwise
   @param avenue - slot (x)
   @param street - slot (y)
 */
int World::has_HWALL  ( int avenue, int street )
{
  return ( search ( avenue, street, HWALL ) );
} // end has_HWALL ( )

/**
   has_VWALL - Retrieve a vertical wall index at a world slot.
   @return wall index, if there is one;
           zero, otherwise
   @param avenue - slot (x)
   @param street - slot (y)
 */
int World::has_VWALL  ( int avenue, int street )
{
  return ( search ( avenue, street, VWALL ) );
} // end has_VWALL ( )

/**
   has_BEEPER - Retrive a beeper index at a world slot.
   @return beeper index, if there is one;
           zero, otherwise
   @param avenue - slot (x)
   @param street - slot (y)
 */
int World::has_BEEPER ( int avenue, int street )
{
  return ( search ( avenue, street, BEEPER ) );
} // end has_BEEPER ( )

/**
   has_BEEPERS - Retrive number of beepers at a world slot.
   @return number of beepers
   @param avenue - slot (x)
   @param street - slot (y)
 */
int World::has_BEEPERS ( int avenue, int street )
{
  int  result = 0;
  int  z = -1;
  char c;

  if ( areValid ( avenue, street ) )
  {
       do
       {
          z = z + 1;
          c = data [ street-1 ][ avenue-1 ][ z ];
          if ( c == BEEPER )
          {
             result = result + 1;
          }
       }
       while ( z < depth-1 );
  }
  return ( result );
} // end has_BEEPER ( )

/**
   has_Box - Retrive a box index at a world slot.
   @return box index, if there is one;
           zero, otherwise
   @param avenue - slot (x)
   @param street - slot (y)
 */
int World::has_BOX ( int avenue, int street )
{
  int  result = 0;
  int  z = -1;
  char c;

  if ( areValid ( avenue, street ) )
  {
       do
       {
          z = z + 1;
          c = data [ street-1 ][ avenue-1 ][ z ];
          if ( 'a' <= c  && c <= 'z' )
          {
             result = c;
          }
       }
       while ( z < depth-1 );
  }
  return ( result );
} // end has_BOX ( )

/**
   has_ROBOT - Retrive if there is a specified robot at a world slot.
   @return robot index, if there is one;
           zero, otherwise
   @param avenue - slot (x)
   @param street - slot (y)
   @param symbol - robot badge symbol
 */
int World::has_ROBOT  ( int avenue, int street, char symbol )
{
  return ( search ( avenue, street, symbol ) );
} // end has_ROBOT ( )

/**
   show - Show current visible items in the world slots.
 */
void World::show ( )
{
    int  avenue, street;
    int  x, y, k;
    char c;
    char screen [23][80];
    char board  [23][80];

    strcpy ( board [21], "ST.+-------------------------------------------+ " );
    strcpy ( board [20], "10 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [19], "   |                                           | " );
    strcpy ( board [18], " 9 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [17], "   |                                           | " );
    strcpy ( board [16], " 8 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [15], "   |                                           | " );
    strcpy ( board [14], " 7 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [13], "   |                                           | " );
    strcpy ( board [12], " 6 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [11], "   |                                           | " );
    strcpy ( board [10], " 5 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [ 9], "   |                                           | " );
    strcpy ( board [ 8], " 4 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [ 7], "   |                                           | " );
    strcpy ( board [ 6], " 3 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [ 5], "   |                                           | " );
    strcpy ( board [ 4], " 2 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [ 3], "   |                                           | " );
    strcpy ( board [ 2], " 1 |   .   .   .   .   .   .   .   .   .   .   | " );
    strcpy ( board [ 1], "   +-------------------------------------------+ " );
    strcpy ( board [ 0], "AVE.   1   2   3   4   5   6   7   8   9   10    " );

    clrscr ( );

    strcpy ( screen [21], board [21] );
    strcpy ( screen [ 1], board [ 1] );
    strcpy ( screen [ 0], board [ 0] );

    for ( street = 1; street <= streets( ); street++ )
    {
        x = 2*street;
        strcpy ( screen [  x  ], board [  x  ] );
        strcpy ( screen [ x+1 ], board [ x+1 ] );

        for ( avenue = 1; avenue <= avenues( ); avenue++ )
        {
            y = 4*avenue;
            k = has_VWALL ( avenue, street );
            if ( k >= 0 && avenue < width )
            {
               screen [ x ][ y+5 ] = '|';
               if ( 1 < street && street < height )
               {
                  screen [ x-1 ][ y+5 ] = '|';
               }
            }
            k = has_HWALL ( avenue, street );
            if ( k >= 0 && street < height )
            {
               screen [ x+1 ][ y+2 ] = '_';
               screen [ x+1 ][ y+3 ] = '_';
               screen [ x+1 ][ y+4 ] = '_';
            }
            k = has_BEEPERS ( avenue, street );
            if ( k > 0 )
            {
               screen [  x  ][ y+2 ] = '(';
               if ( 0 <= k && k <= 9 )
               {  screen [  x  ][ y+3 ] = (char) ((int) '0' + k); }
               else
               {  screen [  x  ][ y+3 ] = '+'; }
               screen [  x  ][ y+4 ] = ')';
            }
            k = has_BOX ( avenue, street );
            if ( k > 0 )
            {
               screen [  x  ][ y+2 ] = '[';
               screen [  x  ][ y+3 ] =  k ;
               screen [  x  ][ y+4 ] = ']';
            }
            c = get ( avenue, street );
            if ( 'A' <= c && c <= 'Z' )
            {
               screen [  x  ][ y+3 ] =  c ;
            }
       }
       strcat ( screen [ street ], msg_board [ street ] );
    }

  // compose bottom lines
     strcat ( screen [21], name );
     debug_txt [19] = '\0';
     strcat ( screen [ 1], debug_txt     );
     msg_txt   [19] = '\0';
     strcat ( screen [ 0], msg_txt       );
     show_Screen ( screen );

} // end World::show ( )

/**
   reset - Clean up world slots.
 */
void World::reset ( )
{
  int x, y, z;

  for ( x=0; x < height; x++ )
  for ( y=0; y < width;  y++ )
  for ( z=0; z < depth;  z++ )
  {
      data [x][y][z] = '.';
  }
  for ( x = 0; x < 21; x = x+1 )
  {
      msg_board [ x ][0] = '\0';
  }
  debug_txt [0] = '\0';
  msg_txt   [0] = '\0';
} // end World::reset ( )

/**
   create - Set default world dimensions.
 */
void World::create ( const char* name )
{
  height  = HEIGHT;
  width   = WIDTH ;
  depth   = DEPTH ;

  if ( name != nullptr && strlen(name) > 0 )
  {
     strcpy ( this->name, name );
  }
  else
  {
     strcpy ( this->name, "Karel_Robot_-_v0.1" );
  }
  reset ( );
} // end World::create ( )

/**
   set - Install an object at a world slot.
   @param avenue - slot (x)
   @param street - slot (y)
   @param object - object badge symbol
 */
void World::set ( int avenue, int street, char object )
{
  int  x, y;

  if ( areValid ( avenue, street ) )
  {
       switch ( object )
       {
          case BEEPER:
            y = has_BOX  ( avenue, street );
            if ( y > 0 )
            {
               show_Error ( "ERROR: Use box." );
            }
            else
            {
               x = has_slot ( avenue, street );
               if ( x < 0 )
               {
                  show_Error ( "ERROR: No slot free." );
               }
               else
               {
                  data [ street-1 ][ avenue-1 ][ x ] = BEEPER;
               }
            }
            break;
          case BOX:
            x = has_slot ( avenue, street );
            if ( x < 0 )
            {
               show_Error ( "ERROR: No slot free." );
            }
            else
            {
               data [ street-1 ][ avenue-1 ][ x ] = BOX;
            }
            break;
          case HWALL:
            x = has_HWALL ( avenue, street );
            if ( x >= 0 )
            {
               show_Error ( "ERROR: HWall here" );
            }
            else
            {
               x = has_slot ( avenue, street );
               if ( x < 0 )
               {
                  show_Error ( "ERROR: No slot free." );
               }
               else
               {
                  data [ street-1 ][ avenue-1 ][ x ] = HWALL;
               }
            }
            break;
          case VWALL:
            x = has_VWALL ( avenue, street );
            if ( x >= 0 )
            {
               show_Error ( "ERROR: VWALL here." );
            }
            else
            {
               x = has_slot ( avenue, street );
               if ( x < 0 )
               {
                  show_Error ( "ERROR: No slot free." );
               }
               else
               {
                  data [ street-1 ][ avenue-1 ][ x ] = VWALL;
               }
            }
            break;
          default:
            if ( ('A' <= object && object <= 'Z') ||
                 ('a' <= object && object <= 'z') )
            {
                x = has_ROBOT ( avenue, street, object );
                if ( x >= 0 )
                {
                   show_Error ( "ERROR: Robot is here." );
                }
                else
                {
                   x = has_slot ( avenue, street );
                   if ( x < 0 )
                   {
                      show_Error ( "ERROR: No slot free." );
                   }
                   else
                   {
                      for ( y=depth-1; y>0; y-- )
                      {
                          data [ street-1 ][ avenue-1 ][ y ]
                        = data [ street-1 ][ avenue-1 ][ y-1 ];
                      }
                      data [ street-1 ][ avenue-1 ][ 0 ] = object;
                   }
                }
            }
       }
       show ( );
  }
} // end World::set ( )

/**
   remove  - Remove an object at a world slot.
   @param avenue - slot (x)
   @param street - slot (y)
   @param object - to be removed
 */
void World::remove ( int avenue, int street, int object )
{
  int x, y;

  x = search ( avenue, street, object );
  if ( x < 0 )
  {
     show_Error ( "ERROR: Object does not exist." );
  }
  else
  {
     for ( y = x; y < depth-1; y=y+1 )
     {
         data [ street-1 ][ avenue-1 ][ y   ]
       = data [ street-1 ][ avenue-1 ][ y+1 ];
     }
     data [ street-1 ][ avenue-1 ][ depth-1 ] = '.';
  }
} // end World::remove ( )

/**
   save - Write current world items to a file.
   @param fileName - file identification name
 */
void World::save ( const char* fileName )
{
    FILE* f_world;

    int   x, y, z;
    char  c;

    f_world = fopen ( fileName, "wt" );
 // save current name
    fprintf ( f_world, "%s\n", 
              name  );
 // save current boundaries
    fprintf ( f_world, "%d %d %d\n",
              height, width, depth  );
 // search for data and save them
    for ( x=0; x < height; x=x+1 )
    for ( y=0; y < width ; y=y+1 )
    {
        z=0;
        do
        {
            c = data [x][y][z];
            if ( (c == '|' || c == '_') ||
                 ('1' <= c && c <= '9')  )
            {
                 fprintf ( f_world, "%d %d %d %c\n", x, y, z, data[x][y][z] );
            }
            z = z + 1;
        }
        while ( z < depth && c != '.' );
    }
    fclose ( f_world );
} // end World::save ( )

/**
   read - Read a file to restore world items.
   @param fileName - file identification name
 */
void World::read ( const char* fileName )
{
  FILE* f_world;

  int   x, y, z;
  char  c;
  char  name[80];

  create ( "Karel_Robot_-_v0.1" );

  f_world = fopen ( fileName, "rt" );

  if ( f_world )
  {
     fscanf  ( f_world, "%s",
               name  );
     fscanf  ( f_world, "%d %d %d",
               &x, &y, &z  );
     if ( 0 < x && x <= HEIGHT &&
          0 < y && y <= WIDTH  &&
          0 < z && z <= DEPTH  )
     {
      // set world boundaries
         height = x;
         width  = y;
         depth  = z;
      // set world name
         if ( name != nullptr )
         {
            strcpy ( this->name, name );
         }
      // read data and fill world slots
         fscanf ( f_world, "%d %d %d %c", &x, &y, &z, &c );
         while ( ! feof ( f_world ) )
         {
               if ( 0 <= x && x < height &&
                    0 <= y && y < width  &&
                    0 <= z && z < depth   )
               {
                  data[x][y][z] = c;
               }
               fscanf ( f_world, "%d %d %d %c", &x, &y, &z, &c );
         }
     }
     fclose ( f_world );
  }
} // end World::read ( )

/**
   close - Close world and shutdown.
 */
void World::close ( )
{
   show_Error ( "Shutdown." );
} // end World::close ( )

// ------------------------------------ box definitions

/**
   create - Set box parameters.
   @param avenue    - slot (x)
   @param street    - slot (y)
   @param direction - in world coordinates
   @param beepers   - initial beeper number
   @param status    - if robot is active or not
 */
void Box::create ( int avenue, int street,
                   int direction, int beepers, char* name, int status )
{
  int x;

  if ( world->areValid ( avenue, street ) &&
       LIFO <= direction && direction <= FIFO &&
       beepers >= 0 &&
       OPEN <= status && status <= CLOSED )
  {
     this->status    = status;

     this->avenue    = avenue;
     this->street    = street;
     this->direction = street;
     this->beepers   = beepers;

     if ( name != nullptr &&
         (name[0] < 'a' || 'z' < name[0]) )
     {
         show_Error ( "ERROR: Use lowercase." );
     }
     else
     {
         strcpy ( this->name, name );
         this->symbol = this->name[0];

      // collect all beepers and store them
         x = world->has_BEEPERS ( this->avenue, this->street );
         if ( x > 0 && this->beepers + x < 9 )
         {
            this->beepers = this->beepers + x;
            do
            {
               world->remove ( this->avenue, this->street, BEEPER );
               x = x - 1;
            }
            while ( x > 0 );
         }
         world->set ( this->avenue, this->street, this->symbol );
     }
  }
} // end Box::create ( )

/**
   beepers - Retrieve number of beepers of current robot.
   @return number of beepers
 */
int Box::nbeepers ( )
{
    return ( beepers );
} // end Box::beepers ( )

/**
   isEmpty - Test if there is any beeper into the box.
   @return number of beepers
 */
int Box::isEmpty ( )
{
    int result = 1;

    if ( beepers > 0 )
    {
       result = 0;
    }
    return ( result );
} // end Box::isEmpty ( )

/**
   checkStatus - Check current box status.
   @return current box status
 */
int Box::checkStatus ( )
{
    return ( status );
} // end Box::checkStatus ( )

/**
   openBox - Open current box.
 */
void Box::open ( )
{
   status = OPEN;
} // end Box::openBox ( )

/**
   close - Close current box.
 */
void Box::close ( )
{
   status = CLOSED;
} // end Box::close ( )

/**
   pullBeeper - Retrieve all beepers in the current box.
   @return number of beepers
 */
int Box::pullBeeper ( )
{
    int result = 0;

    if ( beepers > 0 )
    {
       beepers = beepers - 1;
       result = 1;
    }
    return ( result );
}  // end Box::pullBeeper ( )

/**
   pushBeeper - Put a beeper into the box.
 */
void Box::pushBeeper ( )
{
   beepers = beepers + 1;
} // end Box::pushBeeper ( )

// ------------------------------------ robot definitions

Robot::Robot ( )
{
}

Robot::~Robot( )
{
}

/**
   debug - Show current robot information.
 */
void Robot::debug ( )
{
     delay ( stepDelay );

     debug_txt[0]='\0';
     sprintf( debug_txt,
              "(%c,%2c,%2d,%2d,%2c,%2d)",
              symbol,
             (status==false?'O':'|'),
              avenue, street,
             (direction==0?'N':
              direction==1?'E':
              direction==2?'S':
              direction==3?'W':'?'),
              beepers );

/*
     gotoxy(1,25); clreol( );
     gotoxy(1,25); printf ( "%s", debug_txt );
*/
     world->show ( );
} // end Robot::debug ( )

/**
   debug_On  - Set debug to show robot information.
 */
void Robot::debugOn ( )
{
  has_debug = true;
  debug ( );
} // end Robot::debugOn ( )

/**
   debugOff - Reset debug to omit robot information.
 */
void Robot::debugOff ( )
{
  has_debug = false;
} // end Robot::debugOff ( )

/**
   checkStatus - Retrieve current robot status.
   @return true , if robot is active;
           false, otherwise
 */
bool Robot::checkStatus ( )
{
     return ( status );
} // end Robot::checkStatus ( )

/**
   turnOn - Set current robot on.
 */
void Robot::turnOn  ( )
{
     status = true;

     debugOn ( );
} // end Robot::turnOn ( )

/**
   turnOff - Set current robot off.
 */
void Robot::turnOff ( )
{
     status = false;

     show_Error ( "Robot is inactive." );

     debugOff ( );
} // end Robot::turnOff ( )

/**
   create_Robot     - Set robot parameters.
   @param avenue    - slot (x)
   @param street    - slot (y)
   @param direction - in world coordinates
   @param beepers   - initial beeper number
   @param name s    - robot identification
 */
void Robot::create ( int avenue   , int street ,
                     int direction, int beepers, 
                     const char* name )
{
  if ( world->areValid ( avenue, street ) &&
       NORTH <= direction && direction <= WEST &&
       beepers >= 0 )
  {
     this->status    = true;

     this->avenue    = avenue;
     this->street    = street;
     this->direction = direction;
     this->beepers   = beepers;

     if ( name != nullptr &&
         (name[0] < 'A' || 'Z' < name[0]) )
     {
        show_Error ( "ERROR: Invalid name." );
     }
     else
     {
        strcpy ( this->name, name );
        symbol = this->name[0];
        world->set ( this->avenue, this->street, this->symbol );
        debug ( );
     }
  }
} // end Robot::create ( )

/**
   set  - Modify robot position at world coordinates.
   @param avenue    - slot (x)
   @param street    - slot (y)
 */
void Robot::set ( int x, int y )
{
    int  z;

    if ( checkStatus ( ) &&
       ( 1 <= avenue+x && avenue+x <= world->width  &&
         1 <= street+y && street+y <= world->height ) )
    {
       z = world->has_slot ( avenue+x, street+y );
       if ( z >= 0 )
       {
           world->remove ( avenue, street, symbol );
           avenue = avenue+x;
           street = street+y;
           world->set    ( avenue, street, symbol );
       }
       debug ( );
    }
} // end Robot::set ( )

/**
   turnLeft - Turn robot to the left of its current direction.
 */
void Robot::turnLeft ( )
{
    if ( checkStatus ( ) )
    {
       direction = (direction+3)%4;
       debug ( );
//     getchar( );
    }
} // end Robot::turnLeft ( )

// ------------------------------------ robot sensors

/**
   frontIsClear - Test if world slot ahead has free space for robot.
   @return true , if there is an free space;
           false, otherwise
 */
bool Robot::frontIsClear ( )
{
    int  result = true;

    switch ( direction )
    {
      case NORTH :
           if ( street+1 > world->height ||
                world->has_HWALL ( avenue  , street   ) >= 0 )
           {
                result = false;
           }
           break;
      case EAST  :
           if ( avenue+1 > world->width ||
                world->has_VWALL ( avenue  , street   ) >= 0 )
           {
              result = false;
           }
           break;
      case SOUTH :
           if ( street-1 <= 0 ||
                world->has_HWALL ( avenue  , street-1 ) >= 0 )
           {
              result = false;
           }
           break;
      case WEST    :
           if ( avenue-1 <= 0 ||
                world->has_VWALL ( avenue-1, street   ) >= 0 )
           {
              result = false;
           }
           break;
    }
    return ( result );
} // end Robot::frontIsClear ( )

/**
   leftIsClear - Test if world slot at left has free space for robot.
   @return true , if there is an free space;
           false, otherwise
 */
bool Robot::leftIsClear ( )
{
    int result = true;

    if ( checkStatus ( ) )
    {
       turnLeft ( );
       result = frontIsClear ( );
       turnLeft ( );  turnLeft ( );  turnLeft ( );
    }

    return ( result );
} // end Robot::leftIsClear ( )

/**
   rightIsClear - Test if world slot at right has free space for robot.
   @return true , if there is an free space;
           false, otherwise
 */
bool Robot::rightIsClear ( )
{
    int result = true;

    if ( checkStatus ( ) )
    {
       turnLeft ( );  turnLeft ( );  turnLeft ( );
       result = frontIsClear ( );
       turnLeft ( );
    }

    return ( result );
} // end Robot::rightIsClear ( )

/**
   facing - Test if current robot faces a given direction at world.
   @return true , if robot is facing the desired direction;
           false, otherwise
   @param  direction - to be tested
 */
bool Robot::facing ( int direction )
{
    bool result = false;

    if ( checkStatus ( ) )
    {
      result = ( this->direction == direction );
    }

    return ( result );
} // end Robot::facing ( )

/**
   facingNorth - Test if current robot faces North.
   @return true , if robot is facing the desired direction;
           false, otherwise
 */
bool Robot::facingNorth ( )
{
     return ( facing ( NORTH ) );
} // end Robot::facingNorth ( )

/**
   facingSouth - Test if current robot faces South.
   @return true , if robot is facing the desired direction;
           false, otherwise
 */
bool Robot::facingSouth ( )
{
     return ( facing ( SOUTH ) );
} // end Robot::facingSouth ( )

/**
   facingEast - Test if current robot faces East.
   @return true , if robot is facing the desired direction;
           false, otherwise
 */
bool Robot::facingEast ( )
{
     return ( facing ( EAST ) );
} // end Robot::facingEast ( )

/**
   facingWest - Test if current robot faces West.
   @return true , if robot is facing the desired direction;
           false, otherwise
 */
bool Robot::facingWest ( )
{
     return ( facing ( WEST ) );
} // end Robot::facingWest ( )


// ------------------------------------ robot actions


/**
   move - Move current robot one slot ahead.
 */
void Robot::move ( )
{
    if ( checkStatus ( ) &&
         frontIsClear ( ) )
    {
        switch ( direction )
        {
            case NORTH  :
              set (  0, +1 );
              break;
            case EAST  :
              set ( +1,  0 );
              break;
            case SOUTH :
              set (  0, -1 );
              break;
            case WEST  :
              set ( -1,  0 );
              break;
        }
    }
    else
    {
        show_Error ( "ERROR: Can't move." );
    }
} // end Robot::move ( )

/**
   face - Set a new direction to the current robot.
   @param direction - to be set
 */
void Robot::face ( int direction )
{
     if ( checkStatus ( ) &&
          NORTH <= direction && direction <= WEST )
     {
        this->direction = direction;
     }
} // end Robot::face ( )

/**
   faceNorth - Set north as the new direction of the current robot.
 */
void Robot::faceNorth ( )
{
     face ( NORTH );
} // end Robot::faceNorth ( )

/**
   faceSouth - Set south as the new direction of the current robot.
 */
void Robot::faceSouth ( )
{
     face ( SOUTH );
} // end Robot::faceSouth ( )

/**
   faceEast - Set east   as the new direction of the current robot.
 */
void Robot::faceEast ( )
{
     face ( EAST );
} // end Robot::faceEast ( )

/**
   faceWest - Set west   as the new direction of the current robot.
 */
void Robot::faceWest ( )
{
     face ( WEST );
} // end Robot::faceWest ( )

/**
   beepers - Retrive number of beepers in the current robot bag.
   @return number of beepers in robot bag
 */
int Robot::nbeepers ( )
{
    int result = 0;

    if ( checkStatus ( ) )
    {
      result = ( beepers );
    }

    return ( result );
} // end Robot::beepers ( )

/**
   beepersInBag - Test if there is any beeper in the current robot bag.
   @return true , if there is any beeper in robot bag;
           false, otherwise
 */
bool Robot:: beepersInBag ( )
{
    bool result = false;

    if ( checkStatus ( ) )
    {
      result = ( beepers > 0 );
    }

    return ( result );
} // end Robot::beepersInBag ( )

/**
   nextToARobot - Test if there is another robot at current world slot.
   @return true , if there is any robot at the same slot;
           false, otherwise
 */
bool Robot::nextToARobot ( )
{
    bool result = false;
    char c;
    int  k=0;

    if ( world != nullptr &&
         checkStatus ( )  )
    {
       do
       {
           k = k + 1;
           c = world->data [ street-1 ][ avenue-1 ][ k ];
       }
       while ( k+1 < world->depth &&
               ! ('A' <= c && c <= 'Z' ) );

       result = ( 'A' <= c && c <= 'Z' );
    }

    return ( result );
} // end Robot::nextToARobot ( )

/**
   nextToABeeper - Test if there is any beeper current world slot.
   @return true , if there is any beeper at the same slot;
           false, otherwise
 */
bool Robot::nextToABeeper ( )
{
    bool result = false;

    if ( world != nullptr &&
         checkStatus ( ) )
    {
       result = world->has_BEEPERS ( avenue, street ) > 0;
    }

    return ( result );
} // end Robot::nextToABeeper ( )

/**
   nextToABpx - Test if there is a box at current world slot.
   @return true , if there is any box at the same slot;
           false, otherwise
 */
bool Robot::nextToABox ( )
{
    bool result = false;
    int  k = 0;
    int  c;

    if ( world != nullptr &&
         checkStatus ( ) )
    {
       do
       {
           k = k + 1;
           c = world->data [ street-1 ][ avenue-1 ][ k ];
       }
       while ( k+1 < world->depth &&
               ! ( 'a' <= c && c <= 'z') );

       result = ( 'a' <= c && c <= 'z' );
    }

    return ( result );
} // end Robot::nextToABox ( )

/**
   pickBeeper - Pick a beeper at current world slot and keep it.
 */
void Robot::pickBeeper ( )
{
    int  x;

    if ( world != nullptr )
    {
         x = world->has_BEEPERS ( avenue, street );
         if ( x <= 0 )
         {
            show_Error ( "ERROR: No beeper." );
         }
         else
         {
            world->remove ( avenue, street, BEEPER );
            beepers = beepers + 1;
            debug ( );
         }
    }
} // end Robot::pickBeeper ( )

/**
   putBeeper - Put a beeper at current world slot.
 */
void Robot::putBeeper ( )
{
    int  x;

    if ( world != nullptr )
    {
       if ( beepers <= 0 )
       {
          show_Error ( "ERROR: No beeper." );
       }
       else
       {
          x = world->has_slot ( avenue, street );
          if ( x < 0 )
          {
             show_Error ( "ERROR: No slot free." );
          }
          else
          {
             beepers = beepers - 1;
             world->set ( avenue, street, '1' );
             debug ( );
          }
       }
    }
} // end Robot::putBeeper ( )

/**
   pickBeeperFromBox - Pick a beeper from box at current world slot and keep it.
 */
void Robot::pickBeeperFromBox ( ref_Box box )
{
    if ( world != nullptr &&
         nextToABox( ) )
    {
       if ( box->isEmpty ( ) )
       {
          show_Error ( "ERROR: Empty box." );
       }
       else
       {
          if ( checkStatus( ) == CLOSED )
          {
             show_Error ( "ERROR: Box closed." );
          }
          else
          {
             beepers = beepers + box->pullBeeper ( );
             debug ( );
          }
       }
    }
} // end Robot::pickBeeperFromBox ( )

/**
   putBeeperInBox - Push a beeper into a box at current world slot.
 */
void Robot::putBeeperIntoBox ( ref_Box box )
{
     if ( beepers <= 0 )
     {
        show_Error ( "ERROR: No beeper." );
     }
     else
     {
        if ( box->nbeepers ( ) + 1 >= 9 )
        {
           show_Error ( "ERROR: Box is full." );
        }
        else
        {
           if ( checkStatus( ) == CLOSED )
           {
              show_Error ( "ERROR: Box is closed." );
           }
           else
           {
              beepers = beepers - 1;
              box->pushBeeper ( );
              debug ( );
           }
      }
   }
} // end Robot::putBeeperInBox ( )

/**
   xAvenue - Retrieve robot location on avenue number.
   @return avenue number.
 */
int Robot::xAvenue ( )
{
    return ( avenue );
} // end xAvenue ( )

/**
   yStreet - Retrieve robot location at street number.
   @return street number.
 */
int Robot::yStreet ( )
{
    return ( street );
} // end yStreet ( )

/**
   areYouHere - Test robot location.
   @return true, if is the right location;
           false, otherwise.
   @param avenue    - slot (x)
   @param street    - slot (y)
 */
bool Robot::areYouHere ( int avenue, int street )
{
 // define local
    bool result = false;

    result = ( this->avenue == avenue ) && ( this->street == street );

    return ( result );
} // end Robot::areYouHere ( )

#endif
