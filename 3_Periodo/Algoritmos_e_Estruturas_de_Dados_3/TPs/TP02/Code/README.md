# Organização de TP's

## Branch's

### Master

- Branch principal
- Contém a versão mais atualizada do projeto, a versao que vai ser entregue em cada TP

### Develop (dev)

- Branch de desenvolvimento
- Branch usada para teste de todas as partes do codigo feitas por cada um dos membros do grupo

### Personal Branch

- Branch de cada membro do grupo
- Branch usada para desenvolvimento de cada parte do codigo

#### Nomeclatura da branch

- Nome do membro do grupo

### TP Branch's

- Branch de cada TP, que sera realizada apos a entrada da data de entrega do TP

## Modelo de pastas e separação de TP's

- o codigo em java deve ser separado em pastas, de acordo com cada funcionalidade e cada propriedade da classe

```
Codigo
|_ src
    |_ main
        |_ java
        |   |_ app
        |   |  |_ Teste.java
        |   |_ interfaces
        |   |  |_ Registro.java
        |   |  |_ RegistroHashExtensivel.java
        |   |_ model
        |   |  |_ Tarefa.java
        |   |_ service
        |       |_ Arquivo.java
        |       |_ HashExtensivel.java
        |       |_ ParIDEndereco.java
        |_ data
            |_ Tarefas.db
            |_ Tarefas.db.c.idx
            |_ Tarefas.db.d.idx
```

- ### src/main/java

   - ### app

      A pasta `app` contém a aplicação/teste do projeto.

   - ### interfaces

      A pasta `interfaces` contém as interfaces do projeto.

   - ### model

      A pasta `model` contém os modelos de entidades do projeto.

   - ### service

      A pasta `service` contém os arquivos de gerenciamento do banco de dados em arquivo e outras funcionalidades de 
      serviço.

- ### src/main/data

    A pasta `data` contém todos os arquivos binários gerados pelo "SGBD".

## FIM
