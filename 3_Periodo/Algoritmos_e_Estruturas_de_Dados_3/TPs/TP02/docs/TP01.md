# Trabalho Pratico AEDs 3 - Parte 1

## Descrição

Este projeto tem como objetivo a implementação de um CRUD (Create, Read, Update, Delete) genérico em Java, capaz de manipular entidades armazenadas em arquivos. O foco inicial do projeto é gerenciar tarefas, incluindo operações como inclusão, leitura, atualização e exclusão de registros.

Cada tarefa possui os seguintes atributos:

- **Nome**: Descrição da tarefa.
- **Data de Criação**: Data em que a tarefa foi criada.
- **Data de Conclusão**: Data em que a tarefa foi concluída.
- **Status**: Estado atual da tarefa (Pendente, Em Progresso, Concluída, etc.).
- **Prioridade**: Nível de prioridade da tarefa.

## Estrutura do Registro

Os registros no arquivo são compostos por três partes:

1. **Lápide**: Byte que indica se o registro é válido ou foi excluído.
2. **Indicador de Tamanho**: Número inteiro que indica o tamanho do registro em bytes.
3. **Vetor de Bytes**: Dados da entidade convertidos em bytes.

### Operações Implementadas

As operações de CRUD são realizadas por uma classe genérica `Arquivo<T>` que pode manipular qualquer entidade que implemente a interface `Registro`. A interface `Registro` define os métodos necessários para que uma entidade possa ser armazenada e manipulada no arquivo.

### Índice Direto

O projeto utiliza um índice direto baseado em tabela hash extensível para gerenciar os registros. Este índice armazena a chave primária (ID) e o endereço do registro, facilitando as operações de busca, inserção, atualização e exclusão.

## Estrutura do Projeto

### Classes Principais

- Arquivo`<T extends Registro>`: Classe genérica que gerencia as operações de CRUD no arquivo de dados.
- Tarefa: Classe que representa a entidade Tarefa, implementando a interface Registro.
- Teste: Classe principal que realiza testes das operações CRUD utilizando a entidade Tarefa.

### Métodos Principais

- create(T objeto): Insere um novo registro no arquivo e retorna o ID gerado.
- read(int id): Lê um registro do arquivo com base no ID e retorna o objeto correspondente.
- update(T objeto): Atualiza um registro existente no arquivo com base no ID do objeto.
- delete(int id): Marca um registro como excluído no arquivo.

## Experiência de Desenvolvimento

Durante o desenvolvimento do projeto, implementamos todas as funcionalidades básicas necessárias para o CRUD de tarefas. 
A primeira etapa envolveu a implementação conjunta da classe Tarefa, seguida pela atribuição das funções do CRUD à classe 
Arquivo para cada membro da equipe.

Conseguimos integrar a classe HashExtensivel sem problemas. A principal dificuldade foi entender o funcionamento global do
sistema, mas uma vez que esse entendimento foi alcançado, o restante do trabalho fluiu de maneira tranquila.

Além de atender aos requisitos da disciplina, o projeto também proporcionou um aprofundamento significativo no uso do Git,
devido à estrutura de gerenciamento de branches que adotamos. Essa experiência foi valiosa, pois nos permitiu aplicar 
conceitos teóricos em um contexto prático e desenvolver habilidades importantes tanto na programação quanto na colaboração 
em equipe.

## Checklist

- O trabalho possui um índice direto implementado com a tabela hash extensível?
   ````
   SIM
   ````
- A operação de inclusão insere um novo registro no fim do arquivo e no índice e retorna o ID desse registro?
   ````
   SIM
   ````

- A operação de busca retorna os dados do registro, após localizá-lo por meio do índice direto?
   ````
   SIM
   ````
- A operação de alteração altera os dados do registro e trata corretamente as reduções e aumentos no espaço do registro?
   ````
   SIM
   ````
- A operação de exclusão marca o registro como excluído e o remove do índice direto?
   ````
   SIM
   ````
- O trabalho está funcionando corretamente?
   ````
   SIM
   ````
- O trabalho está completo?
   ````
   SIM
   ````
- O trabalho é original e não a cópia de um trabalho de outro grupo?
   ````
   SIM
   ````

## Integrantes

- [Breno Pires](https://www.linkedin.com/in/brenopiressantos/)
- [Caio Faria](https://www.linkedin.com/in/caiofdiniz)
- [Giuseppe Cordeiro](https://www.linkedin.com/in/giuseppecordeiro/)
- [Vinicius Miranda](https://www.linkedin.com/in/vinimiraa/)

## FIM
