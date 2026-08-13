# Resumo: Autovalores, Autovetores e Diagonalização

## 1. Objetivo

O objetivo da diagonalização é escrever uma matriz (A) na forma

$$  
\boxed{A=PDP^{-1}}  
$$

onde:

- (A) = matriz original;
    
- (P) = matriz formada pelos autovetores;
    
- (D) = matriz diagonal formada pelos autovalores.
    

A diagonalização simplifica diversos cálculos, como potências de matrizes ((A^n)), resolução de sistemas diferenciais, entre outros.

---

# 2. O que é um autovalor?

Um autovalor é um número (\lambda) para o qual existe um vetor não nulo (v) satisfazendo

$$  
\boxed{Av=\lambda v.}  
$$

Isso significa que a transformação linear representada por (A):

- **não muda a direção** do vetor (v);
    
- apenas multiplica seu comprimento por (\lambda).
    

O vetor (v) é chamado de **autovetor**.

---

# 3. Como encontrar os autovalores?

Partimos da definição

$$  
Av=\lambda v.  
$$

Como

$$  
\lambda v=\lambda Iv,  
$$

podemos escrever

$$  
Av-\lambda Iv=0.  
$$

Colocando (v) em evidência,

$$  
\boxed{(A-\lambda I)v=0.}  
$$

Até aqui apenas manipulamos a equação.

---

# 4. Quando esse sistema possui solução?

O sistema

$$  
(A-\lambda I)v=0  
$$

é um **sistema homogêneo**.

Ele sempre possui a solução trivial

$$  
v=0.  
$$

Entretanto, queremos um autovetor, ou seja,

$$  
v\neq0.  
$$

---

## Teorema importante

Um sistema homogêneo possui solução não trivial **se e somente se**

$$  
\boxed{\det(A-\lambda I)=0.}  
$$

Esse é o motivo de calcular o determinante.

---

# 5. Polinômio característico

Ao calcular

$$  
\det(A-\lambda I),  
$$

obtém-se um polinômio em (\lambda).

Esse polinômio recebe o nome de

$$  
\boxed{\text{Polinômio Característico}.}  
$$

Exemplo:

$$  
\lambda^3-5\lambda^2+8\lambda-4.  
$$

---

# 6. Encontrando as raízes do polinômio

Agora resolvemos

$$  
P(\lambda)=0.  
$$

As soluções dessa equação são os **autovalores**.

---

# 7. Teorema das Raízes Racionais

Quando o polinômio é de grau 3 ou superior, geralmente utiliza-se o Teorema das Raízes Racionais.

## Teorema

Se

$$  
P(x)=a_nx^n+\cdots+a_0,  
$$

então toda raiz racional possui a forma

$$  
\boxed{\pm\frac pq}  
$$

onde

- (p) divide o termo independente;
    
- (q) divide o coeficiente líder.
    

---

## Exemplo

Considere

$$  
2x^3-3x^2-8x+12.  
$$

Temos

- coeficiente líder = 2
    
- termo independente = 12
    

Divisores de 12:

$$  
1,2,3,4,6,12  
$$

Divisores de 2:

$$  
1,2.  
$$

Possíveis raízes:

$$  
\pm1,\pm2,\pm3,\pm4,\pm6,\pm12,  
\pm\frac12,\pm\frac32.  
$$

Esses são apenas candidatos.

---

# 8. Testando as raízes

Substitui-se cada candidato no polinômio.

Se

$$  
P(a)=0,  
$$

então (a) é uma raiz.

Caso contrário,

não é.

---

# 9. Teorema do Fator

Depois de encontrar uma raiz,

usa-se outro teorema importante.

## Teorema do Fator

Se

$$  
P(a)=0,  
$$

então

$$  
\boxed{(x-a)}  
$$

é fator do polinômio.

Exemplos:

|Raiz|Fator|
|---|---|
|2|((x-2))|
|5|((x-5))|
|-3|((x+3))|

---

# 10. Divisão do polinômio

Após encontrar uma raiz,

divide-se o polinômio por

$$  
(x-a).  
$$

Isso reduz o grau do polinômio.

Por exemplo,

de grau 3

↓

grau 2.

Normalmente utiliza-se o método de **Briot-Ruffini**.

---

# 11. Resolver o polinômio restante

Após a divisão,

obtém-se um polinômio de grau menor.

Ele pode ser resolvido por:

- fatoração;
    
- Bhaskara.
    

---

## Caso especial

Se

$$  
\Delta=0,  
$$

a equação possui uma **raiz dupla**.

Exemplo

$$  
x^2-4x+4=0.  
$$

Bhaskara fornece

$$  
x=2.  
$$

Mas como

$$  
\Delta=0,  
$$

essa raiz aparece duas vezes.

Escrevemos

$$  
(x-2)^2.  
$$

---

# 12. Multiplicidade algébrica

Quando um autovalor aparece repetido no polinômio característico,

dizemos que ele possui multiplicidade algébrica maior que 1.

Exemplo

$$  
(x-1)(x-2)^2.  
$$

Autovalores

$$  
1,;2,;2.  
$$

O autovalor 2 possui multiplicidade algébrica 2.

---

# 13. Encontrando os autovetores

Depois de encontrar cada autovalor,

substitui-se novamente na equação

$$  
(A-\lambda I)v=0.  
$$

Resolve-se o sistema homogêneo.

As soluções não nulas são os autovetores.

---

# 14. Diagonalização

Depois de encontrar todos os autovetores,

monta-se

$$  
P=  
\begin{bmatrix}  
|&|&&|\  
v_1&v_2&\cdots&v_n\  
|&|&&|  
\end{bmatrix}.  
$$

Cada coluna é um autovetor.

---

A matriz diagonal é

$$  
D=  
\begin{bmatrix}  
\lambda_1&&0\  
&\ddots&\  
0&&\lambda_n  
\end{bmatrix}.  
$$

Ou seja,

**os autovalores ficam na diagonal principal**, na mesma ordem em que os autovetores aparecem em (P).

---

# 15. Quando uma matriz é diagonalizável?

Nem toda matriz pode ser diagonalizada.

## Teorema

Uma matriz (n\times n) é diagonalizável **se possuir (n) autovetores linearmente independentes**.

---

### Exemplo

Uma matriz (3\times3)

precisa de

$$  
\boxed{3}  
$$

autovetores independentes.

Pode acontecer de um autovalor repetir.

Isso **não impede** a diagonalização.

O importante é haver autovetores suficientes.

---

# Fluxograma completo

```text
Matriz A
    │
    ▼
Escrever Av = λv
    │
    ▼
(A − λI)v = 0
    │
    ▼
det(A − λI) = 0
    │
    ▼
Polinômio Característico
    │
    ▼
Teorema das Raízes Racionais
    │
    ▼
Testar candidatos
    │
    ▼
Encontrou uma raiz?
    │
   Sim
    │
    ▼
Teorema do Fator
    │
    ▼
Divisão (Briot-Ruffini)
    │
    ▼
Resolver o polinômio restante
    │
    ▼
Encontrar todos os autovalores
    │
    ▼
Resolver (A − λI)v = 0
    │
    ▼
Encontrar os autovetores
    │
    ▼
Montar P (autovetores)
e D (autovalores)
    │
    ▼
A = PDP⁻¹
```

## Principais teoremas envolvidos

1. **Definição de autovalor e autovetor**  
    $$  
    Av=\lambda v.  
    $$
    
2. **Condição para existência de soluções não triviais de um sistema homogêneo**  
    $$  
    \det(A-\lambda I)=0.  
    $$
    
3. **Polinômio Característico**
    
    - É o polinômio obtido por (\det(A-\lambda I)).
        
4. **Teorema das Raízes Racionais**
    
    - Limita os possíveis candidatos a raízes racionais do polinômio característico.
        
5. **Teorema do Fator**
    
    - Se (P(a)=0), então ((x-a)) é fator de (P(x)).
        
6. **Briot-Ruffini (ou divisão polinomial)**
    
    - Permite reduzir o grau do polinômio após encontrar uma raiz.
        
7. **Critério de Diagonalização**
    
    - Uma matriz (n\times n) é diagonalizável se possuir (n) autovetores linearmente independentes.