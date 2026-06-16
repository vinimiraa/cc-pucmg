# Compile And Run

1. Ir para o caminho:

```bash
cd code/src/main/java
```

2. Compilar: 

  - ```bash
    # Primeira Maneira
    javac -d bin ./app/*.java ./interfaces/*.java ./model/*.java ./service/*.java
    ```

  - ```bash
    # Segunda Maneira
    javac -d bin **/*.java 
    ```

3. Rodar:

```bash
java ./app/IO.java
```

## FIM