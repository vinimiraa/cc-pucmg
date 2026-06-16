/*
 *  -------------------------- Documentacao
 *   
 *  Pontificia Universidade Catolica de Minas Gerais
 *  Curso de Ciencia da Computacao
 *  Algoritmos e Estruturas de Dados II
 *   
 *  TP03Q08 - 10 / 04 / 2024
 *  Author: Vinicius Miranda de Araujo
 *   
 *  Para compilar em terminal (janela de comandos):
 *       Linux : gcc -o ListaDuplaFlex ListaDuplaFlex.c
 *       Windows: gcc -o ListaDuplaFlex ListaDuplaFlex.c
 *   
 *  Para executar em terminal (janela de comandos):
 *       Linux : ./ListaDuplaFlex
 *       Windows: ListaDuplaFlex
 *   
*/

// ---------------------------------- Dependências

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <wchar.h>   
#include <locale.h>
#include <stdarg.h>

// ---------------------------------- Tratamento de Erro

void errx ( int eval, const char *fmt, ... )
{
    va_list args;
    va_start( args, fmt );
    vfprintf( stderr, fmt, args );
    va_end( args );
    fprintf( stderr, "\n" );
    exit( eval );
} // end errx ( )

// ---------------------------------- Struct Timer

typedef struct s_Timer
{
    clock_t startTime;
    clock_t endTime  ;
    double  totalTime;
} Timer;

Timer new_Timer( )
{
    Timer timer;
    timer.startTime = 0;
    timer.endTime = 0;
    timer.totalTime = 0;
    return ( timer );
} // end new_Timer ( )

void start_Timer( Timer* time ) {
    time->startTime = clock( );
} // end startTime ( )

void end_Timer( Timer* time ) {
    time->endTime = clock( );
} // end endTime ( )

double total_Timer( Timer* time ) {
    time->totalTime = difftime( time->endTime, time->startTime ) * 1000;
    return ( time->totalTime );
} // end timeTotal ( )

// ---------------------------------- Struct Log

typedef struct s_Log
{
    int comparacoes;
    int movimentacoes;
} Log;

Log new_Log( )
{
    Log log;
    log.movimentacoes = 0;
    log.comparacoes = 0;
    return ( log ); 
} // end new_Log ( )

void registro( char* filename, Timer* time, Log* log )
{
    FILE *file = fopen( filename, "wt" );
    fprintf( file, "812839\tComparacoes: %d\tMovimentacoes: %d\tTempo de Execucao(ms): %lf\n",
                        log->comparacoes, log->movimentacoes, total_Timer( time ) );
    fclose( file );
} // end registro ( )

// ---------------------------------- Struct Pesonagem

typedef struct s_Personagem
{
    char*   id              ; 
    char*   name            ; 
    char*   alternateNames  ;
    char*   house           ; 
    char*   ancestry        ; 
    char*   species         ; 
    char*   patronus        ; 
    bool    hogwartsStaff   ;  
    bool    hogwartsStudent ;  
    char*   actorName       ; 
    bool    alive           ;
    char*   alternateActors ; 
    char*   dateOfBirth     ; 
    int     yearOfBirth     ; 
    char*   eyeColour       ; 
    char*   gender          ; 
    char*   hairColour      ; 
    bool    wizard          ; 
} Personagem;

// ---------------------------------- Funções

/**
 *  Verificar existencia de espaço para o Personagem.
*/
bool exist_Personagem( Personagem *perso )
{
    bool exist = false;
    if( perso != NULL && 
        perso->id != NULL && perso->name != NULL && perso->alternateNames != NULL && perso->house != NULL &&
        perso->ancestry != NULL && perso->species != NULL && perso->patronus != NULL && perso->actorName != NULL &&
        perso->alternateActors != NULL && perso->dateOfBirth != NULL && perso->eyeColour != NULL && 
        perso->gender != NULL && perso->hairColour != NULL )
    {
        exist = true;
    } // end if
    return ( exist );
} // end exist_Personagem ( )

/**
 *  Alocar o espaço de memória para o Personagem.
*/
Personagem* new_Personagem( void )
{
    Personagem *perso = (Personagem*) malloc ( 1 * sizeof(Personagem) );
    if( perso != NULL )
    {
        perso->id              = (char*) calloc (  50, sizeof(char) );
        perso->name            = (char*) calloc (  50, sizeof(char) );
        perso->alternateNames  = (char*) calloc ( 300, sizeof(char) );
        perso->house           = (char*) calloc (  50, sizeof(char) );
        perso->ancestry        = (char*) calloc (  50, sizeof(char) );
        perso->species         = (char*) calloc (  50, sizeof(char) );
        perso->patronus        = (char*) calloc (  50, sizeof(char) );
        perso->hogwartsStaff   = false                               ; 
        perso->hogwartsStudent = false                               ; 
        perso->actorName       = (char*) calloc (  50, sizeof(char) );
        perso->alive           = false                               ; 
        perso->alternateActors = (char*) calloc ( 255, sizeof(char) );
        perso->dateOfBirth     = (char*) calloc (  50, sizeof(char) );
        perso->yearOfBirth     = -1                                  ; 
        perso->eyeColour       = (char*) calloc (  50, sizeof(char) );
        perso->gender          = (char*) calloc (  50, sizeof(char) );
        perso->hairColour      = (char*) calloc (  50, sizeof(char) );
        perso->wizard          = false                               ; 

        if( !exist_Personagem( perso ) )
        {
            printf( "\n%s\n", "ERROR: Unable to alloc memory for \'Personagem\'." );
        } // end if
    } // end if
    return ( perso );
} // end new_Personagem ( )

/**
 *  Desalocar o espaço de momória do personagem.
*/
void delete_Personagem( Personagem *perso )
{
    if( perso != NULL )
    {
        if( exist_Personagem( perso ) ) 
        {
            free( perso->id              ); perso->id              = NULL;
            free( perso->name            ); perso->name            = NULL;
            free( perso->alternateNames  ); perso->alternateNames  = NULL;
            free( perso->house           ); perso->house           = NULL;
            free( perso->ancestry        ); perso->ancestry        = NULL;
            free( perso->species         ); perso->species         = NULL;
            free( perso->patronus        ); perso->patronus        = NULL;
            free( perso->actorName       ); perso->actorName       = NULL;
            free( perso->alternateActors ); perso->alternateActors = NULL;
            free( perso->dateOfBirth     ); perso->dateOfBirth     = NULL;
            free( perso->eyeColour       ); perso->eyeColour       = NULL;
        }
        free( perso ); perso = NULL;  
    } // end if
} // end delete_Personagem ( )

/**
 *  Funções GET.
*/
char* getId              ( Personagem *perso ) { return ( perso->id              ); }
char* getName            ( Personagem *perso ) { return ( perso->name            ); }
char* getAlternateNames  ( Personagem *perso ) { return ( perso->alternateNames  ); }
char* getHouse           ( Personagem *perso ) { return ( perso->house           ); }
char* getAncestry        ( Personagem *perso ) { return ( perso->ancestry        ); }
char* getSpecies         ( Personagem *perso ) { return ( perso->species         ); }
char* getPatronus        ( Personagem *perso ) { return ( perso->patronus        ); }
bool  getHogwartsStaff   ( Personagem *perso ) { return ( perso->hogwartsStaff   ); }
bool  getHogwartsStudent ( Personagem *perso ) { return ( perso->hogwartsStudent ); }
char* getActorName       ( Personagem *perso ) { return ( perso->actorName       ); }
bool  getAlive           ( Personagem *perso ) { return ( perso->alive           ); }
char* getAlternateActors ( Personagem *perso ) { return ( perso->alternateActors ); }
char* getDateOfBirth     ( Personagem *perso ) { return ( perso->dateOfBirth     ); }
int   getYearOfBirth     ( Personagem *perso ) { return ( perso->yearOfBirth     ); }
char* getEyeColour       ( Personagem *perso ) { return ( perso->eyeColour       ); }
char* getGender          ( Personagem *perso ) { return ( perso->gender          ); }
char* getHairColour      ( Personagem *perso ) { return ( perso->hairColour      ); }
bool  getWizard          ( Personagem *perso ) { return ( perso->wizard          ); }

/**
 *  Funções SET.
*/
void setId              ( Personagem *perso, char* id              ) { strcpy( perso->id              , id             ) ; }
void setName            ( Personagem *perso, char* name            ) { strcpy( perso->name            , name           ) ; }
void setAlternateNames  ( Personagem *perso, char* alternateNames  ) { strcpy( perso->alternateNames  , alternateNames ) ; } 
void setHouse           ( Personagem *perso, char* house           ) { strcpy( perso->house           , house          ) ; }
void setAncestry        ( Personagem *perso, char* ancestry        ) { strcpy( perso->ancestry        , ancestry       ) ; }
void setSpecies         ( Personagem *perso, char* species         ) { strcpy( perso->species         , species        ) ; }
void setPatronus        ( Personagem *perso, char* patronus        ) { strcpy( perso->patronus        , patronus       ) ; }
void setHogwartsStaff   ( Personagem *perso, bool  hogwartsStaff   ) {         perso->hogwartsStaff   = hogwartsStaff    ; }
void setHogwartsStudent ( Personagem *perso, bool  hogwartsStudent ) {         perso->hogwartsStudent = hogwartsStudent  ; }
void setActorName       ( Personagem *perso, char* actorName       ) { strcpy( perso->actorName       , actorName      ) ; }
void setAlive           ( Personagem *perso, bool  alive           ) {         perso->alive           = alive            ; }
void setAlternateActors ( Personagem *perso, char* alternateActors ) { strcpy( perso->alternateActors , alternateActors) ; }
void setDateOfBirth     ( Personagem *perso, char* dateOfBirth     ) { strcpy( perso->dateOfBirth     , dateOfBirth    ) ; }
void setYearOfBirth     ( Personagem *perso, int   yearOfBirth     ) {         perso->yearOfBirth     = yearOfBirth      ; }
void setEyeColour       ( Personagem *perso, char* eyeColour       ) { strcpy( perso->eyeColour       , eyeColour      ) ; }
void setGender          ( Personagem *perso, char* gender          ) { strcpy( perso->gender          , gender         ) ; }
void setHairColour      ( Personagem *perso, char* hairColour      ) { strcpy( perso->hairColour      , hairColour     ) ; }
void setWizard          ( Personagem *perso, bool  wizard          ) {         perso->wizard          = wizard           ; }

/**
 *  Função para inicializar um Personagem com valores.
*/
void init_Personagem ( Personagem *perso,
                        char* id             , char* name       , char* alternateNames , char* house          , 
                        char* ancestry       , char* species    , char* patronus       , bool  hogwartsStaff  ,
                        bool  hogwartsStudent, char* actorName  , bool  alive          , char* alternateActors, 
                        char* dateOfBirth    , int   yearOfBirth, char* eyeColour      , char* gender         , 
                        char* hairColour     , bool wizard )
{
    if( exist_Personagem( perso ) ) 
    {
        setId              ( perso, id              );
        setName            ( perso, name            );
        setAlternateNames  ( perso, alternateNames  );
        setHouse           ( perso, house           );
        setAncestry        ( perso, ancestry        );
        setSpecies         ( perso, species         );
        setPatronus        ( perso, patronus        );
        setHogwartsStaff   ( perso, hogwartsStaff   );
        setHogwartsStudent ( perso, hogwartsStudent );
        setActorName       ( perso, actorName       );
        setAlive           ( perso, alive           );
        setAlternateActors ( perso, alternateActors );
        setDateOfBirth     ( perso, dateOfBirth     );
        setYearOfBirth     ( perso, yearOfBirth     );
        setEyeColour       ( perso, eyeColour       );
        setGender          ( perso, gender          );
        setHairColour      ( perso, hairColour      );
        setWizard          ( perso, wizard          );
    }
    else {
        printf( "\n%s\n", "ERROR: Unable to inicialize the \'Personagem\'." );
    } // end if
} // end init_Personagem ( )

/**
 *  Função para clonar um Personagem.
*/
Personagem* clone( Personagem *perso )
{
    Personagem *copy = new_Personagem( );
    if( exist_Personagem ( perso ) && exist_Personagem( copy ) )
    {
        init_Personagem(copy,
                        getId              ( perso ),
                        getName            ( perso ),
                        getAlternateNames  ( perso ),
                        getHouse           ( perso ),
                        getAncestry        ( perso ),
                        getSpecies         ( perso ),
                        getPatronus        ( perso ),
                        getHogwartsStaff   ( perso ),
                        getHogwartsStudent ( perso ),
                        getActorName       ( perso ),
                        getAlive           ( perso ),
                        getAlternateActors ( perso ),
                        getDateOfBirth     ( perso ),
                        getYearOfBirth     ( perso ),
                        getEyeColour       ( perso ),
                        getGender          ( perso ),
                        getHairColour      ( perso ),
                        getWizard          ( perso )  );
    } 
    else {
        printf( "\n%s\n", "ERROR: Unable to clone the \'Personagem\'." );    
    }// end if
    return ( copy );
} // end clone ( )

/**
 *  Função para imprimir um Personagem.
*/
void imprimir ( Personagem *perso )
{
    printf( "[%s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %s ## %d ## %s ## %s ## %s ## %s]\n",
            getId              ( perso ),
            getName            ( perso ),
            getAlternateNames  ( perso ),
            getHouse           ( perso ),
            getAncestry        ( perso ),
            getSpecies         ( perso ),
            getPatronus        ( perso ),
            getHogwartsStaff   ( perso ) ? "true" : "false",
            getHogwartsStudent ( perso ) ? "true" : "false",
            getActorName       ( perso ),
            getAlive           ( perso ) ? "true" : "false",
            getDateOfBirth     ( perso ),
            getYearOfBirth     ( perso ),
            getEyeColour       ( perso ),
            getGender          ( perso ),
            getHairColour      ( perso ),
            getWizard          ( perso ) ? "true" : "false" ); 
} // end imprimir ( )

/**
 *  Função para tratamento das cadeia de caracteres "booleana"
*/
char* tratamentoBool( char* strbool )
{
    char* tratada = strbool;
    tratada[strcspn(tratada,"\n")] = '\0';
    tratada[strcspn(tratada,"\r")] = '\0';
    return ( tratada );
} // end tratamentoBool ( )

/**
 *  Função para tratamento da formatação da Data.
*/
char* tratamentoData( char* dateOfBirth )
{
    char *tratada = dateOfBirth;
    int len = strlen( dateOfBirth );
    if( len < 10 )
    {
        tratada = (char*) calloc ( 11, sizeof(char) );
        strcpy( tratada, dateOfBirth );
        for( int x = len; x > 3; x = x - 1 )
        {
            tratada[x] = tratada[x-1];
        }
        tratada[3] = '0';
    } // end if
    return ( tratada );
} // end tratamentoData ( )

/**
 *  Função para ler os personagens de um arquivo.
*/
Personagem* ler( char* filename, char* id_procurado ) 
{
    Personagem *perso = new_Personagem( );
    FILE* file = fopen( filename, "rt" );

    if( file == NULL || !exist_Personagem( perso ) ) {
        printf( "\n%s\n", "ERROR: Unable to read.");
    }
    else
    {
        char line[500];
        bool idFound = false;

        // Ignora a linha de cabeçalho
        fgets( line, sizeof(line), file );
        // Lê as demais linhas do arquivo
        while( fgets( line, sizeof(line), file ) != NULL && !idFound ) 
        {
            char* token = strtok( line, ";" );
            char *atributos[18];
            int index = 0;
            while( token != NULL ) 
            {
                atributos[index++] = strdup( token );
                token = strtok( NULL, ";" );
            } // end while

            // Tratamento do atributo 'alternateNames'
            char temp[500] = {0};
            int pos = 0;
            int len = strlen( atributos[2] );
            for( int x = 0; x < len; x = x + 1 ) 
            {
                if( atributos[2][x] == '[' ) {
                    temp[pos] = '{';
                } else if( atributos[2][x] == ']' ) {
                    temp[pos] = '}';
                } else if( atributos[2][x] == '\'' ) {
                    continue; 
                } else {
                    temp[pos] = atributos[2][x];
                }
                pos++; 
            }
            temp[pos] = '\0'; 
            // Desalocar o atributo 'alternateNames' e atribuir a string tratada
            free( atributos[2] ) ; atributos[2] = strdup(temp);

            // Verificar se os atributos são iguais
            if( strcmp(atributos[0], id_procurado) == 0 ) 
            {
                idFound = true;
                // inicializar o Personagem com os dados lidos
                if( index < 18 )
                {
                    if( index > 16 ) 
                    {
                        init_Personagem(perso,
                                        atributos[0], atributos[1], atributos[2], atributos[3],
                                        atributos[4], atributos[5], "" ,
                                 strcmp(atributos[6], "VERDADEIRO") == 0,
                                 strcmp(atributos[7], "VERDADEIRO") == 0,
                                        atributos[8], 
                                 strcmp(atributos[9], "VERDADEIRO") == 0,
                                        atributos[10], 
                         tratamentoData(atributos[11]),
                                   atoi(atributos[12]), 
                                        atributos[13], atributos[14],atributos[15], 
                                 strcmp(tratamentoBool(atributos[16]), "VERDADEIRO") == 0 );
                    } 
                    else
                    {
                        init_Personagem(perso,
                                        atributos[0], atributos[1], atributos[2], atributos[3],
                                        atributos[4], atributos[5], "" ,
                                 strcmp(atributos[6], "VERDADEIRO") == 0,
                                 strcmp(atributos[7], "VERDADEIRO") == 0, "", 
                                 strcmp(atributos[8], "VERDADEIRO") == 0,
                                        atributos[9],
                         tratamentoData(atributos[10]),
                                   atoi(atributos[11]), atributos[12], 
                                        atributos[13],atributos[14], 
                                 strcmp(tratamentoBool(atributos[15]), "VERDADEIRO") == 0 );
                    } // end if
                }
                else
                {
                    init_Personagem(perso,
                                    atributos[0], atributos[1], atributos[2], atributos[3],
                                    atributos[4], atributos[5], atributos[6],
                             strcmp(atributos[7], "VERDADEIRO") == 0,
                             strcmp(atributos[8], "VERDADEIRO") == 0,
                                    atributos[9], 
                             strcmp(atributos[10], "VERDADEIRO") == 0,
                                    atributos[11], 
                     tratamentoData(atributos[12]),
                               atoi(atributos[13]), 
                                    atributos[14], atributos[15],
                                    atributos[16], 
                             strcmp(tratamentoBool(atributos[17]), "VERDADEIRO") == 0 );
                } // end if
            } // end if
            // Libera memória alocada para atributos
            for (int x = 0; x < index; x++) {
                free(atributos[x]);
            } // end for
        } // end while 
        fclose(file);
    } // end if
    return ( perso );
} // end ler ( )

// ---------------------------------- Struct Célula

typedef struct s_Celula
{
    Personagem* perso;
    struct s_Celula* ante;
    struct s_Celula* prox;
} Celula;

Celula* new_Celula ( Personagem* personagem )
{
    Celula* nova = (Celula*) malloc ( sizeof(Celula) );
    if( nova != NULL )
    {
        nova->perso = personagem;
        nova->ante = nova->prox = NULL;
    } // end if
    return ( nova );
} // end new_Celula ( )

// ---------------------------------- Struct Lista Dupla

typedef struct s_Lista
{
    Celula* primeiro;
    Celula* ultimo;
    int tamanho;
} Lista;

// ---------------------------------- Funções de Ordenação

/**
 *  Função para trocar dois personagens no arranjo de Personagem.
*/
void swap ( Celula* i, Celula* j )
{
    Personagem *temp = i->perso;
    i->perso = j->perso;
    j->perso = temp;
    temp = NULL;
} // end swap ( )

bool exist ( Celula* i, Celula* j )
{
    bool result = false;
    while( i != NULL && !result )
    {
        if( i == j ) {
            result = true;
        } // end if
        i = i->prox;
    } // end while 
    return ( result );
} // end exist ( )

/**
 *  QuickSort.
*/
void quicksortRec( Celula* esq, Celula* dir, Log* log ) 
{
    if( esq != dir && esq != dir->prox ) 
    {
        Celula* i = esq;
        Celula* j = dir;
        Celula* pivo = i;
        char* pivoHouse = getHouse( pivo->perso );
        
        while( exist( i, j ) ) 
        {
            while( strcmp(getHouse(i->perso), pivoHouse) < 0 ) 
            {
                i = i->prox;
                log->comparacoes++;
            } // end while
            while( strcmp(getHouse(j->perso), pivoHouse) > 0 ) 
            {
                j = j->ante;
                log->comparacoes++;
            } // end while
            if( exist( i, j ) ) 
            {
                swap( i, j );
                log->movimentacoes += 3;
                i = i->prox;
                j = j->ante;
            } // end if
            log->comparacoes++;
        } // end while  
        quicksortRec( esq, j, log );
        quicksortRec( i, dir, log );
    } // end if
} // end quicksortRec ( )

/**
 *  Insercao para ordenar por Name o arranjo já ordenado por House de Personagem.
*/
void sortByName( Lista* lista, Log* log )
{
    for( Celula* i = lista->primeiro->prox; i != NULL; i = i->prox )
    {
        Celula* menor = i;
        for( Celula* j = i->prox; j != NULL; j = j->prox )
        {
            if( strcmp( getHouse(menor->perso), getHouse(j->perso) ) == 0 &&
                strcmp( getName(menor->perso), getName(j->perso) ) > 0 )
            {
                menor = j;
                log->comparacoes++;
            } // end if
            log->comparacoes++;
        } // end for
        swap( menor, i );
        log->movimentacoes += 3;
    } // end for
} // end sortByName ( )

/**
 *  Função de Chamada da Função Recursiva.
*/
void quicksort( Lista* lista, Log * log ) 
{
    if( lista != NULL )
    {
        quicksortRec( lista->primeiro->prox, lista->ultimo , log );
        sortByName( lista, log );
    }
} // end quicksort ( )

// ---------------------------------- Funções - Lista Dupla

Lista* new_Lista ( )
{
    Lista* lista = (Lista*) malloc ( sizeof(Lista) );
    if( lista != NULL )
    {
        lista->primeiro = new_Celula( NULL );
        lista->ultimo = lista->primeiro;
    } // end if
    return ( lista );
} // end new_Lista ( )

void delete_Lista ( Lista* lista )
{
    if( lista != NULL )
    {
        for( Celula* i = lista->primeiro->prox; i != NULL; i = i->prox )
        {
            delete_Personagem( i->perso );
        } // end for
        free( lista ); lista = NULL;
    } // end if
} // end delete_Lista ( )

void inserirInicio ( Lista* lista, Personagem* personagem )
{
    Celula* temp = new_Celula( personagem );
    temp->ante = lista->primeiro;
    temp->prox = lista->primeiro->prox;
    if( lista->primeiro == lista->ultimo ) {                    
        lista->ultimo = temp;
    } else {
        temp->prox->ante = temp;
    } // end if
    lista->tamanho++;
} // end inserirInicio ( )

void inserirFim ( Lista* lista, Personagem* personagem )
{
    lista->ultimo->prox = new_Celula( personagem );
    lista->ultimo->prox->ante = lista->ultimo;
    lista->ultimo = lista->ultimo->prox;
} // end inserirFim ( )

Personagem* removerInicio ( Lista* lista ) 
{
    if( lista->primeiro == lista->ultimo ) {
        errx( 1, "Erro ao remover (vazia)!" );
    } // end if
    Celula* temp = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;
    Personagem* perso = lista->primeiro->perso;
    temp->prox = lista->primeiro->ante = NULL;
    free( temp );
    temp = NULL;
    lista->tamanho--;
    return ( perso );
} // end removerInicio ( )

Personagem* removerFim ( Lista* lista ) 
{
    if( lista->primeiro == lista->ultimo ) {
        errx( 1, "Erro ao remover (vazia)!" );
    } // end if
    Personagem* perso = lista->ultimo->perso;
    lista->ultimo = lista->ultimo->ante;
    lista->ultimo->prox->ante = NULL;
    free(lista->ultimo->prox);
    lista->ultimo->prox = NULL;
    lista->tamanho--;
    return ( perso );
} // end removerFim ( )

void inserir ( Lista* lista, Personagem* personagem, int index ) 
{
    if( index < 0 || index > lista->tamanho ) {
        errx( 1, "Erro ao remover (posicao %d/%d invalida!", index, lista->tamanho );
    } else if( index == 0 ) {
        inserirInicio( lista, personagem );
    } else if( index == lista->tamanho ) {
        inserirFim( lista, personagem );
    } 
    else 
    {
        Celula* i = lista->primeiro;
        int j = 0;
        for( j = 0; j < index; j = j + 1, i = i->prox );   
        Celula* temp = new_Celula( personagem );
        temp->ante = i;
        temp->prox = i->prox;
        temp->ante->prox = temp->prox->ante = temp;
        temp = i = NULL;
        lista->tamanho++;
    } // end if
} // end inserir ( )

Personagem* remover( Lista* lista, int index ) 
{
    Personagem* perso;
    if( lista->primeiro == lista->ultimo ) {
        errx( 1, "Erro ao remover (vazia)!" );
    } else if( index < 0 || index >= lista->tamanho ) {
        errx( 1, "Erro ao remover (posicao %d/%d invalida!", index, lista->tamanho );
    } else if( index == 0 ) {
        perso = removerInicio( lista );
    } else if( index == lista->tamanho - 1 ) {
        perso = removerFim( lista );
    } 
    else 
    {
        Celula* i = lista->primeiro->prox;
        int j = 0;
        for( j = 0; j < index; j = j + 1, i = i->prox );   
        i->ante->prox = i->prox;
        i->prox->ante = i->ante;
        perso = i->perso;
        i->prox = i->ante = NULL;
        free( i );
        i = NULL;
        lista->tamanho--;
    } // end if
    return ( perso );
} // end remover ( )

void mostrar ( Lista* lista )
{
    for( Celula* i = lista->primeiro->prox; i != NULL; i = i->prox ) 
    {
        imprimir( i->perso );
    } // end for
} // end mostrar

/**
 *  Função Principal.
*/
int main ( void )
{
    setlocale( LC_CTYPE, "UTF-8" ); // setCharset

    Lista* lista = new_Lista ( );
    Timer timer = new_Timer ( );
    Log   log   = new_Log   ( );

    char id  [81] = { '\0' };
    char nome[81] = { '\0' };
    char* filename = "/tmp/characters.csv"; 
    // filename = "C:\\Users\\vinic\\Desktop\\CC-PUCMG\\AEDs\\AEDs_II\\TPs\\TP02\\characters.csv";
    
    scanf( "%s", id ); getchar( );
    while( strcmp( id,"FIM" ) != 0 )
    {
        inserirFim( lista, ler( filename, id ) );
        scanf( "%s", id ); getchar( );
    } // end while

    start_Timer( &timer );
    quicksort( lista, &log );
    end_Timer( &timer );
    registro( "812839_quicksort.txt", &timer, &log );
    
    mostrar( lista );

    delete_Lista ( lista );

    return ( 0 );
} // end main ( )
