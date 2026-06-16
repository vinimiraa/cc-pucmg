# Trabalho Prático AEDs 3 - Parte 4 (final)

## Descrição  

Este trabalho prático envolve a implementação de um sistema de **backup compactado** para os arquivos de dados e índices 
do projeto de tarefas. A funcionalidade principal consiste em buscar todos os arquivos de dados e índices, compactá-los 
utilizando o algoritmo **LZW** e armazená-los em um único arquivo em uma pasta de backup. O objetivo é permitir a 
compactação eficiente de todos os arquivos usando um único dicionário de 12 bits, além de possibilitar a recuperação dos arquivos para versões específicas.

### Funcionalidades principais:
1. **Compactação dos arquivos**: Todos os arquivos de dados e índices são tratados como vetores de bytes e compactados 
usando o algoritmo **LZW**.
2. **Armazenamento organizado**: Os backups compactados são salvos em pastas nomeadas com a data/versão do backup.
3. **Descompactação e recuperação**: O sistema permite recuperar os arquivos de uma versão específica escolhida pelo usuário.

## Estrutura do Projeto  

### Diretórios  

- **`controller`**:  
   Gerencia as operações de backup, compactação e descompactação, além de lidar com a interação com os arquivos do sistema.  
   - **Classes principais**:  
     - `Backup`: Classe principal que realiza a compactação, descompactação e gestão dos backups.  

- **`model`**:  
   Contém a implementação do algoritmo de compressão **LZW** e outras estruturas necessárias.  
   - **Classes principais**:  
     - `LZW`: Implementa o algoritmo de compactação e descompactação.  

- **`view`**:  
   Interação com o usuário para exibir informações e realizar operações de backup e recuperação.  
   - **Classes principais**:  
     - `BackupView`: Interface para o usuário iniciar backups, listar versões e recuperar arquivos.  

## Fluxo de Operações  

1. **Criação do Backup**:  
   - Todos os arquivos de dados e índices são lidos como vetores de bytes.  
   - O algoritmo **LZW** compacta os arquivos utilizando um único dicionário compartilhado.  
   - Os dados compactados são salvos em um único arquivo com os seguintes campos para cada arquivo:
     - Nome do arquivo.
     - Tamanho do vetor de bytes compactado.
     - Vetor de bytes compactados.  
   - O arquivo compactado é armazenado em uma pasta identificada pela data/versão do backup.  

2. **Recuperação dos Arquivos**:  
   - O sistema permite ao usuário selecionar a versão do backup a ser restaurada.  
   - Os arquivos compactados são lidos, descompactados e restaurados para o estado original.  

## Classes e Métodos  

### **Backup**
Gerencia o processo de backup e recuperação.  
- **Métodos principais**:  
  - `createBackup( )`: Cria o backup compactado de todos os arquivos de dados e índices.  
  - `recoverBackup( )`: Recupera os arquivos de uma versão específica.  
  - `byte[] readFile( )`: Lê um arquivo como vetor de bytes.  
  - `void writeFile( )`: Escreve um vetor de bytes em um arquivo.  
  - `void createDirectory( )`: Cria um diretório, caso não exista.  

### **LZW**
Implementa o algoritmo de compressão e descompressão.  
- **Métodos principais**:  
  - `byte[] codifica( )`: Compacta os dados fornecidos usando o algoritmo LZW.  
  - `byte[] decodifica( )`: Descompacta os dados fornecidos para o estado original.  

## Experiência e Desafios  

O desenvolvimento deste trabalho apresentou os seguintes desafios:  
1. **Compactação em fluxo**: Garantir que os arquivos fossem lidos e compactados como um fluxo contínuo de bytes, sem 
sobrecarregar a memória.  
2. **Gerenciamento do dicionário do LZW**: Usar um único dicionário de 12 bits para compactar múltiplos arquivos foi uma 
etapa desafiadora, especialmente para manter a eficiência da compressão.  
3. **Organização dos backups**: Estruturar os backups de forma que permitisse a recuperação exata dos arquivos, com os 
metadados corretos, foi um ponto crítico do desenvolvimento.  

Apesar desses desafios, todos os requisitos foram implementados com sucesso, e os resultados atingiram as expectativas.  

## Checklist

- Há uma rotina de compactação usando o algoritmo LZW para fazer backup dos arquivos?  
    ```
    SIM
    ```

- Há uma rotina de descompactação usando o algoritmo LZW para recuperação dos arquivos?  
    ```
    SIM
    ```

- O usuário pode escolher a versão a recuperar?  
    ```
    SIM
    ```

- Qual foi a taxa de compressão alcançada por esse backup?  
    ```
    56,34%
    ```

- O trabalho está funcionando corretamente?  
    ```
    SIM
    ```

- O trabalho está completo?  
    ```
    SIM
    ```

- O trabalho é original e não a cópia de um trabalho de um colega?  
    ```
    SIM
    ```

## Integrantes

- [Breno Pires](https://www.linkedin.com/in/brenopiressantos/)
- [Caio Faria](https://www.linkedin.com/in/caiofdiniz)
- [Giuseppe Cordeiro](https://www.linkedin.com/in/giuseppecordeiro/)
- [Vinicius Miranda](https://www.linkedin.com/in/vinimiraa/)

## FIM