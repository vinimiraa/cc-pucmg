# Álgebra Linear: Fundamentos, Transformações e Propriedades de Matrizes

## Resumo

Compreender a Álgebra Linear por meio de três perspectivas principais:

1. **Fundamentos Algébricos:** A definição de espaços vetoriais e subespaços governados por dez axiomas específicos de adição e multiplicação por escalar.
    
2. **Componentes Estruturais:** Os conceitos de independência linear (L.I.), bases e dimensão, que determinam o "tamanho" e a representação dos espaços.
    
3. **Dinâmica Operacional:** O comportamento das transformações lineares, incluindo interpretações geométricas (reflexões, rotações), associações com matrizes e as condições para injetividade e diagonalização.
    

Os principais pontos incluem a utilidade do processo de Gram-Schmidt para criar bases ortonormais, a relação entre a invertibilidade de uma matriz e operadores injetivos, e o uso de autovalores e autovetores para obter a diagonalização de matrizes.

---

# 1. Espaços Vetoriais e Subespaços

Um **espaço vetorial** $V$ é um conjunto não vazio governado pelas operações de adição e multiplicação por escalar. A natureza dos "vetores" é ampla; elementos como matrizes, polinômios e números reais podem funcionar como vetores desde que satisfaçam os axiomas exigidos.

## 1.1 Axiomas de Espaço Vetorial

Para ser considerado um espaço vetorial real, o conjunto $V$ deve satisfazer os dez axiomas a seguir:

| Categoria                         | Tipo de Axioma     | Definição Formal                                                      |
| --------------------------------- | ------------------ | --------------------------------------------------------------------- |
| **Adição $A$**                   | Fechamento         | $u + v \in V$ para todo $u, v \in V$                              |
|                                   | Comutatividade     | $u + v = v + u$                                                     |
|                                   | Associatividade    | $u + (v + w) = (u + v) + w$                                         |
|                                   | Elemento neutro    | Existe um vetor nulo $0 \in V$ tal que $u + 0 = u$                |
|                                   | Inverso            | Existe $-u \in V$ tal que $u + (-u) = 0$                          |
| **Multiplicação por escalar (M)** | Fechamento         | $\alpha \cdot u \in V$ para todo $u \in V$, $\alpha \in \mathbb{R}$ |
|                                   | Associatividade    | $\alpha \cdot (\beta \cdot u) = (\alpha \cdot \beta) \cdot u$       |
|                                   | Distributividade 1 | $(\alpha + \beta) \cdot u = \alpha \cdot u + \beta \cdot u$         |
|                                   | Distributividade 2 | $\alpha \cdot (u + v) = \alpha \cdot u + \alpha \cdot v$            |
|                                   | Identidade         | $1 \cdot u = u$                                                     |

## 1.2 Subespaços

Um subconjunto $S$ é um **subespaço** de $V$ se ele próprio for um espaço vetorial sob as mesmas operações.

Um subconjunto não vazio $S$ é confirmado como subespaço se satisfizer apenas duas condições:

- Está fechado sob adição $(u + v \in S)$.
    
- Está fechado sob multiplicação por escalar $(\alpha \cdot u \in S)$.
    

---

# 2. Independência Linear, Base e Dimensão

A estrutura de um espaço vetorial é definida pela forma como seus vetores interagem e por quantos deles são necessários para representar todo o espaço.

## 2.1 Definições

- **Combinação Linear:** Um vetor $V$ é uma combinação de $\{v_1, \dots, v_n\}$ se  
    $v = c_1v_1 + \dots + c_nv_n$
    
- **Independência Linear (L.I.):** Um conjunto de vetores é L.I. se a equação  
    $c_1v_1 + \dots + c_nv_n = 0$  

    possuir apenas a solução trivial $c_1 = c_2 = \dots = c_n = 0$. Se existir uma solução não trivial, o conjunto é Linearmente Dependente (L.D.).
    
- **Conjunto Gerador:** Um conjunto $G$ gera $V$ se todo vetor de $V$ puder ser escrito como combinação linear dos vetores de $G$.
    
- **Base:** Um conjunto $B$ é uma base se for simultaneamente L.I. e gerador de $V$. Uma base representa um espaço de maneira única e eficiente.
    

## 2.2 Dimensão

A **dimensão** $\dim V$ é o número de vetores que compõem sua base.

- **Determinando a dimensão:** Um método prático para encontrar a dimensão de um subespaço consiste em contar o número de variáveis livres em seu vetor genérico.
    
- **Dimensões padrão:**
    
    - $\dim \mathbb{R}^n = n$
        
    - $\dim P_n = n+1$
        
    - $\dim M_{m \times n} = m \cdot n$
        

---

# 3. Transformações Lineares e Operadores

Uma transformação $T: V_A \rightarrow V_B$ associa vetores de um domínio a um contradomínio. Quando domínio e contradomínio são iguais, $T$ é chamado de **operador linear**.

## 3.1 Linearidade e Associação com Matrizes

Uma transformação é linear se preserva as operações de adição e multiplicação por escalar.

- **Representação Matricial:** Toda transformação linear pode ser associada a uma matriz canônica $A$. Essa matriz pode ser encontrada aplicando $T$ aos vetores da base canônica do domínio (por exemplo, $A = [T(1,0)\ \dots\ T(0,1)]$).
    
- **Exemplos de Não Linearidade:** Transformações que envolvem expoentes (por exemplo, $x^2$) ou constantes (por exemplo, $+1$ em $2x-y+1$) são não lineares.
    

## 3.2 Transformações Geométricas em $\mathbb{R}^2$ e $\mathbb{R}^3$

Os materiais destacam diversos operadores geométricos específicos:

- **Reflexão:** $T(x, y) = (-x, y)$ representa a reflexão em relação ao eixo $y$; $T(x, y, z) = (x, -y, z)$ representa a reflexão em relação ao plano $xz$.
    
- **Rotação:** Uma rotação positiva de $90^\circ$ em $\mathbb{R}^2$ utiliza a matriz  
    $$
    \begin{bmatrix}  
    0 & -1 \\
    1 & 0  
    \end{bmatrix}
    $$
    
- **Projeção:** A projeção ortogonal de $u$ sobre $V$ é dada por  
    $$p = \left(\frac{u \cdot v}{|v|^2}\right)v$$
    

## 3.3 Injetividade e Composição

- **Injetividade:** $T$ é injetiva se entradas distintas produzem imagens distintas. Um operador linear é injetivo se sua matriz associada é invertível $(\det \neq 0)$.
    
- **Composição:** A composição de duas transformações $(T_1 \circ T_2)$ é equivalente ao produto de suas respectivas matrizes $(A \cdot B)$.
    

---

# 4. Autovalores, Autovetores e Diagonalização

A análise espectral estuda vetores especiais que não mudam de direção quando uma matriz é aplicada.

## 4.1 Definições Fundamentais

- **Autovalor $\lambda$:** Um escalar tal que  
    $$AX = \lambda X$$
    para algum vetor não nulo $X$
    
- **Autovetor (X):** O vetor não nulo associado ao autovalor $\lambda$. Enquanto a maioria dos vetores muda de direção quando multiplicada por $A$, os autovetores permanecem paralelos à sua direção original.
    
- **Equação Característica:** Os autovalores são encontrados resolvendo  
    $$\det(A - \lambda I) = 0$$
    

## 4.2 Similaridade de Matrizes e Diagonalização

- **Matrizes Semelhantes:** $A$ é semelhante a $B$ $(A \sim B)$ se existir uma matriz invertível $P$ tal que  
    $$A = PBP^{-1}$$
    
    Matrizes semelhantes possuem os mesmos autovalores.
    
- **Diagonalização:** Uma matriz $A$ é diagonalizável se for semelhante a uma matriz diagonal $D$. Isso ocorre se, e somente se, $A$ possuir $(n)$ autovetores linearmente independentes.
    
- **Estrutura de $P$ e $D$:** As colunas de $P$ são os autovetores de $A$, enquanto os elementos da diagonal de $D$ são os autovalores correspondentes, na mesma ordem.
    

---

# 5. Bases Ortonormais e Processo de Gram-Schmidt

Em $\mathbb{R}^n$, uma **base ortonormal** é um conjunto de vetores que são simultaneamente ortogonais (mutuamente perpendiculares, $v_i \cdot v_j = 0$) e unitários ($|v| = 1$).

## 5.1 Normalização

O processo de transformar um vetor $V$ em um vetor unitário ($u$) (seu versor) é chamado de **normalização**:

$$u = \frac{v}{|v|}$$ 

## 5.2 O Processo de Gram-Schmidt

Esse método constrói uma base ortonormal $\{u_1, \dots, u_n\}$ a partir de qualquer base $\{v_1, \dots, v_n\}$:

1. **Passo 1:** Defina $w_1 = v_1$.
    
2. **Passo 2:** Calcule  
    $$w_2 = v_2 - \operatorname{proj}_{w_1}v_2$$
    
3. **Passo 3:** Calcule $w_3$ subtraindo as projeções de $v_3$ sobre $w_1$ e $w_2$.
    
4. **Passo Final:** Normalize todos os vetores $w_i$ obtidos para formar o conjunto ortonormal $\{u_i\}$.
    

A fórmula geral para o $i$-ésimo vetor ortogonal é:

$$w_i = v_i - \sum_{j=1}^{i-1} \left( \frac{v_i \cdot w_j}{|w_j|^2} \right)w_j$$
