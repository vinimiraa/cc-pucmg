# Computação Gráfica — Exercícios de Revisão Resolvidos (Prova 01)

## I) Transformações Geométricas

**1) Qual é a vantagem de usar coordenadas homogêneas?**

Permitem representar **todas** as transformações geométricas (translação, escala, rotação, cisalhamento, reflexão) da mesma forma: como multiplicação de matriz. Sem coordenadas homogêneas, a translação é uma soma e a escala/rotação são multiplicações — operações de naturezas diferentes que não podem ser combinadas numa única matriz. Com coordenadas homogêneas `(x,y)→(x,y,1)`, todas viram matrizes 3×3 (ou 4×4 em 3D), que podem ser **concatenadas** (multiplicadas entre si) numa única matriz composta *antes* de serem aplicadas aos vértices do objeto. Isso reduz drasticamente o número de cálculos quando se tem uma sequência de N transformações aplicada a M vértices: em vez de N×M operações, calcula-se 1 matriz composta e aplica-se 1 vez a cada vértice.

**2) A reflexão pode ser considerada rotação. Prove algebricamente em qual situação.**

Isso vale quando se aplica a reflexão **simultaneamente em relação aos dois eixos** (reflexão em relação à origem / "point reflection"), ou seja, `x'=-x, y'=-y`. Repare que essa reflexão dupla é a composição de refletir em x e depois em y:

```
RFx = | 1   0 |     RFy = | -1  0 |
      | 0  -1 |           |  0  1 |

RFx . RFy = | 1·(-1)+0·0   1·0+0·1  |  = | -1   0 |
            | 0·(-1)+(-1)·0  0·0+(-1)·1 |   |  0  -1 |
```

E a matriz de rotação de 180°:
```
R(180°) = | cos180°  -sen180° |  = | -1   0 |
          | sen180°   cos180° |    |  0  -1 |
```

Como `RFx.RFy = R(180°)`, a reflexão simultânea nos dois eixos é **algebricamente idêntica** a uma rotação de 180°. (Uma reflexão em um único eixo, sozinha, **não** é uma rotação: seu determinante é -1 — inverte a orientação/"lado" da figura — enquanto toda rotação tem determinante +1.)

**3) A rotação e a escala podem produzir uma movimentação do objeto se aplicadas diretamente. Como impedir essa movimentação?**

As matrizes de rotação `R(θ)` e escala `S(sx,sy)` sempre transformam **em relação à origem** do sistema de coordenadas. Se o objeto não estiver centrado na origem, girar ou escalar diretamente também o desloca (translada) para uma posição diferente, o que normalmente não é desejado (ex.: girar um objeto "no seu próprio lugar"). Para evitar isso, aplica-se a transformação em relação a um **ponto de referência** (pivot) do próprio objeto, em 3 passos:
1. Translada-se o ponto de referência até a origem: `T(-xref,-yref)`;
2. Aplica-se a rotação/escala normalmente;
3. Translada-se de volta à posição original: `T(xref,yref)`.
```
P' = T(xref,yref) . R(θ) (ou S(sx,sy)) . T(-xref,-yref) . P
```

**4) Ao criar a matriz resultante de várias transformações sequenciais, deve-se multiplicar da última transformação aplicada para a primeira nessa ordem. Justifique.**

Porque o ponto `P` é representado como um vetor **coluna** e a transformação é aplicada por multiplicação à esquerda, `P' = M.P`. Se quisermos aplicar primeiro `M1`, depois `M2`, depois `M3` (nessa ordem temporal), o resultado é:
```
P1 = M1.P
P2 = M2.P1 = M2.M1.P
P3 = M3.P2 = M3.M2.M1.P
```
Ou seja, a matriz composta é `M = M3.M2.M1` — a **primeira** transformação aplicada (`M1`) fica **mais próxima de `P`** (mais à direita), e a **última** aplicada (`M3`) fica **mais à esquerda**. Como a multiplicação de matrizes não é comutativa, essa ordem tem que ser respeitada — daí a regra "multiplica-se da última transformação para a primeira" (da esquerda para a direita no produto, mas da última para a primeira na ordem de aplicação).

**5) Triângulo A(-1,-3), B(-2,8), C(9,2). Calcule cada transformação a partir da posição original:**

*a. T(-1,5)* — soma-se (-1,5) a cada vértice:
```
A' = (-2, 2)      B' = (-3, 13)      C' = (8, 7)
```

*b. R(-30°)* (em torno da origem) — usando `x'=x.cos θ - y.sen θ`, `y'=x.sen θ + y.cos θ`, com θ=-30°:
```
A' ≈ (-2,366 ; -2,098)
B' ≈ ( 2,268 ;  7,928)
C' ≈ ( 8,794 ; -2,768)
```

*c. R(60°) com ponto B fixo* — aplica-se `T(Bx,By).R(60°).T(-Bx,-By)` a cada vértice (B permanece fixo, por definição):
```
A' ≈ ( 8,026 ;  3,366)
B' =  (-2 ; 8)            (fixo, não se move)
C' ≈ ( 8,696 ; 14,526)
```

*d. S(0,5 ; 3)* (em torno da origem) — multiplica-se x por 0,5 e y por 3:
```
A' = (-0,5 ; -9)      B' = (-1 ; 24)      C' = (4,5 ; 6)
```

*e. Reflexão em relação ao eixo x* — inverte-se o sinal de y:
```
A' = (-1, 3)      B' = (-2, -8)      C' = (9, -2)
```

---

## II) Rasterização de Retas

**6) O número de iterações é definido pelo maior valor de delta. Explique o porquê.**

Usar `max(|Δx|,|Δy|)` como número de passos garante que a variável que muda **mais rápido** (a dominante) seja incrementada em exatamente 1 unidade a cada passo — percorrendo, um por um, **todos** os pixels que ela precisa visitar, sem pular nenhum. A outra variável (a que muda mais devagar) avança uma fração `<1` a cada passo e é arredondada. Se usássemos o **menor** delta como número de passos, a variável dominante daria saltos maiores que 1 pixel por iteração, deixando buracos (gaps) na reta desenhada.

**7) O que diferencia o 1º caso do 2º caso?**

O que muda é **qual eixo é a variável de controle** (incrementada sempre de 1 em 1) e qual é a variável dependente (calculada e arredondada):
- 1º caso (`-1 ≤ m ≤ 1`, ou seja `|Δx| ≥ |Δy|`): x é a variável de controle (1 pixel por coluna), y é calculado.
- 2º caso (`|m| > 1`, ou seja `|Δy| > |Δx|`): y é a variável de controle (1 pixel por linha), x é calculado.

### DDA

**8) Por que os valores dos pontos inicial e final são arredondados apenas na visualização desses valores?**

Porque, internamente, o DDA acumula incrementos fracionários (`xinc`, `yinc`, que valem `Δx/passos` e `Δy/passos`) a cada iteração. Se arredondássemos a cada passo intermediário e continuássemos somando os incrementos a partir do valor **já arredondado**, o erro de arredondamento se acumularia passo a passo, desviando a reta calculada da reta real. Por isso as coordenadas reais (em ponto flutuante) são mantidas com precisão total durante todo o cálculo, e o arredondamento só é aplicado no momento de decidir **qual pixel acender** (a visualização/rasterização final).

**9) Qual(is) comando(s) diferenciam o 1º do 2º caso?**

É o teste condicional que compara `|Δx|` com `|Δy|` (equivalentemente, testa `passos = max(|Δx|,|Δy|)`) para decidir: se `|Δx| ≥ |Δy|`, x recebe incremento unitário (±1) e y recebe `m` por passo (1º caso); caso contrário, y recebe incremento unitário (±1) e x recebe `1/m` por passo (2º caso).

**10) Aplique o algoritmo DDA para os seguintes segmentos de reta:**

Fórmulas usadas: `Δx=x2-x1`, `Δy=y2-y1`, `passos=max(|Δx|,|Δy|)`, `xinc=Δx/passos`, `yinc=Δy/passos`.

*a. AB — A(-1,4) e B(5,7)*
`Δx=6, Δy=3 → passos=6, xinc=1, yinc=0,5`

| passo | x real | y real | pixel |
|---|---|---|---|
| 0 | -1 | 4 | (-1, 4) |
| 1 | 0 | 4,5 | (0, 5) |
| 2 | 1 | 5,0 | (1, 5) |
| 3 | 2 | 5,5 | (2, 6) |
| 4 | 3 | 6,0 | (3, 6) |
| 5 | 4 | 6,5 | (4, 7) |
| 6 | 5 | 7,0 | (5, 7) |

*b. BA — B(5,7) e A(-1,4)* (mesmo segmento, sentido invertido)
`Δx=-6, Δy=-3 → passos=6, xinc=-1, yinc=-0,5`
Pixels: (5,7) → (4,7) → (3,6) → (2,6) → (1,5) → (0,5) → (-1,4).
**Observação:** é exatamente o mesmo conjunto de pixels do item (a), percorrido em ordem inversa — a reta rasterizada não depende do sentido em que os pontos são percorridos.

*c. CD — C(-1,4) e D(3,8)*
`Δx=4, Δy=4 → passos=4, xinc=1, yinc=1` (reta a 45°, todos os passos "inteiros")
Pixels: (-1,4) → (0,5) → (1,6) → (2,7) → (3,8).

*d. EF — E(2,0) e F(6,0)*
`Δx=4, Δy=0 → passos=4, xinc=1, yinc=0` (reta horizontal)
Pixels: (2,0) → (3,0) → (4,0) → (5,0) → (6,0).

*e. GH — G(1,3) e H(1,6)*
`Δx=0, Δy=3 → passos=3, xinc=0, yinc=1` (reta vertical)
Pixels: (1,3) → (1,4) → (1,5) → (1,6).

### Bresenham

**11) Qual é a vantagem desse algoritmo em relação ao DDA?**

Bresenham usa **apenas aritmética inteira** (soma, subtração, comparação, e multiplicações por 2, que equivalem a deslocamentos de bit) para decidir o próximo pixel, evitando as divisões/multiplicações de ponto flutuante do DDA e o arredondamento a cada passo. Isso o torna mais rápido (mais barato computacionalmente) e livre de erro de arredondamento acumulado.

**12) Explique o porquê de delta sempre ser positivo.**

Nas fórmulas da variável de decisão, `Δx` e `Δy` entram sempre em **valor absoluto** (`dx=abs(x2-x1)`, `dy=abs(y2-y1)`); a fórmula da decisão depende apenas da **relação entre as inclinações** (qual delta é maior), não da direção do segmento. O sentido real do incremento (crescente ou decrescente em x e em y) é tratado à parte, pelas variáveis auxiliares `incrx` e `incry` (que valem +1 ou -1 dependendo do sinal original de `x2-x1` e `y2-y1`).

**13) A atualização de 'x' tem que ser feita antes da atualização da variável de decisão 'p' no 1º caso? E de 'y'? Explique.**

No 1º caso, **x é sempre incrementado a cada iteração** (é a variável de controle do laço — o `for` percorre exatamente `Δx` passos, um por coluna). A atualização de **y é condicional**: só acontece quando a decisão indica o ponto NE (`p ≥ 0`). A variável `p` é recalculada a cada passo a partir do seu próprio valor anterior e de uma constante (`p += 2Δy`, se ponto E; `p += 2Δy-2Δx`, se ponto NE) — essas fórmulas incrementais já **incorporam** o efeito de x ter avançado uma unidade, então não é preciso "esperar" x mudar para atualizar p; a ordem lógica é: incrementa x (sempre) → testa p → decide se incrementa y → atualiza p para a próxima iteração.

**14) Quando 'p' for positivo, o que ocorre com 'y'? Explique.**

`y` também é incrementado (o próximo pixel é o **NE**, acima-e-à-direita do atual). Isso vem diretamente do critério `d1 - d2 ≥ 0 → ponto NE`: quando `p` (que é proporcional a `d1-d2`) é positivo ou zero, significa que a reta real está mais próxima do pixel de cima (NE) do que do pixel da mesma linha (E).

**15) Aplique o algoritmo de Bresenham para os segmentos de reta a seguir:**

*a. AB — A(-1,4), B(5,7)*: `Δx=6, Δy=3` (1º caso, pois Δy<Δx). `p0 = 2Δy-Δx = 0`; `const1=2Δy=6`; `const2=2(Δy-Δx)=-6`.

| p antes | decisão | novo ponto | p depois |
|---|---|---|---|
| 0 | p≥0 → NE | (0,5) | -6 |
| -6 | p<0 → E | (1,5) | 0 |
| 0 | p≥0 → NE | (2,6) | -6 |
| -6 | p<0 → E | (3,6) | 0 |
| 0 | p≥0 → NE | (4,7) | -6 |
| -6 | p<0 → E | (5,7) | 0 |

Pixels: **(-1,4), (0,5), (1,5), (2,6), (3,6), (4,7), (5,7)** — idêntico ao resultado do DDA (item 10a). ✓

*b. BA — B(5,7), A(-1,4)*: por simetria (mesmo raciocínio de 12), o resultado é a mesma reta percorrida ao contrário: **(5,7), (4,6), (3,6), (2,5), (1,5), (0,4), (-1,4)**.
> Note que os pixels intermediários não são *exatamente* os mesmos de (a) percorridos ao contrário (aqui aparecem (4,6) e (2,5) em vez de (4,7) e (2,6)) — isso é o comportamento normal do Bresenham perto dos pontos "meio a meio" (p=0), onde a escolha entre E/NE pode variar conforme o sentido em que o algoritmo percorre a reta.

*c. CD — C(-1,4), D(3,8)*: `Δx=4, Δy=4`, caso especial `Δx=Δy` (45°): `p0=2Δx-Δy=4`, `const1=2Δx=8`, `const2=2(Δx-Δy)=0`. Como `p0=4 ≥ 0` sempre, todo passo é "diagonal": **(-1,4), (0,5), (1,6), (2,7), (3,8)** — igual ao DDA.

*d. EF — E(2,0), F(6,0)*: `Δy=0` → `p` sempre negativo → todos os passos são "E": **(2,0), (3,0), (4,0), (5,0), (6,0)**.

*e. GH — G(1,3), H(1,6)*: `Δx=0` → cai no 2º caso, `p` sempre negativo → todos os passos são "N" (incrementa só y): **(1,3), (1,4), (1,5), (1,6)**.

---

## III) Rasterização de Circunferências

**16) Apenas o 2º octante é calculado. Explique.**

A circunferência tem simetria de 8 vias: qualquer ponto `(x,y)` calculado em um octante tem 7 "espelhos" (trocando sinais de x/y e trocando x por y) que pertencem à circunferência nos outros 7 octantes. Assim, basta calcular 1/8 dos pontos (o octante entre 45° e 90°, onde a curva se comporta de forma parecida com o "1º caso" das retas, com inclinação entre -1 e 0) e obter o resto **por simetria**, sem cálculo adicional — economia de 7/8 do processamento.

**17) Qual comando identifica e restringe os cálculos ao 2º octante?**

A condição do laço **`enquanto x < y`**: essa é a faixa em que x cresce mais devagar que y decresce (45°-90°); quando `x` atinge ou ultrapassa `y`, o octante acabou e o laço para.

**18) A atualização de 'x' tem que ser feita antes da atualização da variável de decisão 'p'? E de 'y'? Explique.**

Sim, para x: assim como nas retas, **x é sempre incrementado em 1** a cada iteração do laço (é a variável de controle do octante 45°-90°). A atualização de **y é condicional**: só é decrementado quando a decisão indica o ponto **SE**. A variável `p` é recalculada a partir do valor anterior e dos termos `4x+6` (caso E) ou `4(x-y)+10` (caso SE) — fórmulas que já contemplam x ter avançado.

**19) Se o centro não for na origem, onde e como no algoritmo essa informação é considerada?**

O algoritmo sempre calcula `(x,y)` **relativos à origem** (a variável de decisão `p` depende apenas do raio `r`, nunca do centro). A posição real do centro `(xc,yc)` só é somada **no momento de plotar o pixel**: ponto absoluto = `(xc+x, yc+y)` — e o mesmo vale para os pontos simétricos (aplicam-se as trocas de sinal/eixo primeiro, depois soma-se o centro).

**20) Aplique o algoritmo de Bresenham para as circunferências e indique os simétricos do 3º ponto de cada uma:**

Fórmulas: `p0 = 3-2r`; ponto inicial `(x0,y0)=(0,r)`; enquanto `x<y`: se `p<0` → E (`x=x+1`, `p=p+4x+6`, usando o x **antes** de incrementar); se `p≥0` → SE (`x=x+1, y=y-1`, `p=p+4(x-y)+10`, com x,y **antes** de atualizar). Chamando os pontos da sequência de `P0=(0,r), P1, P2, P3, ...`, o "3º ponto" = `P2`.

*a. Centro (0,0), raio 5* — `p0 = 3-10 = -7`

| ponto | p (antes) | decisão | p (depois) |
|---|---|---|---|
| P0=(0,5) | -7 | — | — |
| P1=(1,5) | -7 | E | -1 |
| P2=(2,5) | -1 | E | 9 |
| P3=(3,4) | 9 | SE | 7 |
| P4=(4,3) | 7 | SE | 13 (fim: x=4 ≥ y=3) |

Octante: (0,5), (1,5), (2,5), (3,4), (4,3). **3º ponto: P2=(2,5)** (absoluto, pois o centro é a origem).
**8 simétricos de (2,5):** (2,5), (2,-5), (-2,5), (-2,-5), (5,2), (5,-2), (-5,2), (-5,-2).

*b. Centro (-1,2), raio 5* — mesma sequência **local** de (a) (a decisão só depende de r): P2 local = (2,5) → **absoluto = (-1+2, 2+5) = (1,7)**.
**8 simétricos** (aplicados no referencial local e só depois somando o centro (-1,2)):
(1,7), (1,-3), (-3,7), (-3,-3), (4,4), (4,0), (-6,4), (-6,0).

*c. Centro (3,4), raio 6* — `p0 = 3-12 = -9`

| ponto | p (antes) | decisão | p (depois) |
|---|---|---|---|
| P0=(0,6) | -9 | — | — |
| P1=(1,6) | -9 | E | -3 |
| P2=(2,6) | -3 | E | 7 |
| P3=(3,5) | 7 | SE | 1 |
| P4=(4,4) | 1 | SE | 3 (fim: x=4=y=4) |

Octante local: (0,6),(1,6),(2,6),(3,5),(4,4). **3º ponto local: P2=(2,6) → absoluto = (3+2, 4+6) = (5,10)**.
**8 simétricos** (local (2,6), depois soma do centro (3,4)):
(5,10), (5,-2), (1,10), (1,-2), (9,6), (9,2), (-3,6), (-3,2).

> Nota: chamamos de "1º ponto" o próprio `P0=(0,r)` (ponto inicial, ainda sem decisão), então "3º ponto" = `P2` (a 2ª decisão calculada). Se sua professora contar o 1º ponto **calculado** como `P1`, então o "3º ponto" seria `P3` — na tabela acima já estão todos os pontos do octante para você conferir qualquer uma das duas convenções.

---

## IV) Recorte

**21) A ordem dos recortes altera o resultado final? Explique.**

Não. Cada fronteira da janela (esquerda, direita, cima, baixo) define um semiplano, e a região visível final é a **interseção** desses 4 semiplanos com a primitiva — e interseção de conjuntos não depende da ordem em que é calculada. A ordem pode mudar os pontos de interseção *intermediários* calculados durante o processo (principalmente no Sutherland-Hodgman), mas o polígono/segmento final recortado é sempre o mesmo.

### Cohen-Sutherland (Algoritmo de Códigos)

**22) Por que os códigos 3 e 7 não são considerados no mapeamento das áreas externas?**

Código 3 = `0011` (bits Right e Left ativados ao mesmo tempo) e código 7 = `0111` (Top, Right e Left ativados). Isso exigiria que um ponto estivesse, simultaneamente, à esquerda **e** à direita da janela — impossível, pois `x` não pode ser ao mesmo tempo `< xmin` e `> xmax`. Como Left/Right (e, por raciocínio análogo, Top/Bottom) são mutuamente exclusivos, essas combinações de bits nunca ocorrem na prática.

**23) Quais são as condições de parada do algoritmo?**

(1) Os dois códigos são `0000` → segmento totalmente dentro → **aceita**. (2) O AND bit-a-bit dos dois códigos é diferente de zero → segmento totalmente fora → **rejeita**. Em qualquer um desses dois casos, o algoritmo termina (para aquele segmento).

**24) O ponto inicial pode ser atualizado mais de uma vez. Exemplifique.**

Sim — se, depois de mover um ponto para a interseção com uma fronteira, ele **ainda** viola outra fronteira, ele é recalculado de novo. Exemplo (ver questão 27, aresta AB): A(-1,-3) tem código `0100` (abaixo de ymin); ao ser movido para a interseção com `y=ymin`, vira A'≈(-1,36 ; 1), cujo código já é `0000` (não precisou de nova atualização neste caso). Mas se A' ainda estivesse, por exemplo, à esquerda da janela, ele seria recalculado outra vez para a fronteira esquerda — e assim sucessivamente até seu código chegar a `0000` ou até o segmento ser rejeitado.

**25) Por que a condição "c1 & c2 ≠ 0" estabelece que o segmento está fora?**

O AND bit-a-bit só é diferente de zero quando **existe um bit ativado em comum** nos dois códigos — ou seja, quando as **duas** extremidades violam a **mesma** fronteira (ex.: ambas estão à esquerda, ou ambas estão acima). Como a fronteira é uma reta que separa o plano em dois semiplanos e o segmento de reta é convexo, se os dois pontos extremos estão do lado de fora dessa mesma fronteira, **toda** a reta entre eles também está (não há como uma reta "escapar" e voltar cruzando a mesma fronteira só nas pontas).

**26) A atualização dos valores das coordenadas inicial e final é feita a cada iteração. O que ocorre com os valores originais da cena?**

Nada — eles permanecem intocados. O algoritmo de recorte trabalha sobre **variáveis de trabalho** (cópias locais dos extremos do segmento), que vão sendo substituídas pelas interseções a cada iteração. A estrutura de dados original da cena (as coordenadas reais dos objetos) não é modificada, o que permite reprocessar a cena inteira se, por exemplo, a janela de visualização mudar.

**27) Janela -2≤x≤5, 1≤y≤6; triângulo A(-1,-3), B(-2,8), C(9,2). Aplique Cohen-Sutherland (códigos, coordenadas, interseções a cada iteração).**

Códigos dos vértices (bits TBRL): `A=0100 (4)`, `B=1000 (8)`, `C=0010 (2)`.

*Aresta AB* — A(código 4, abaixo) × B(código 8, acima): `4 & 8 = 0` → não é trivial.
- Ponto fora: A (bit "abaixo"). Interseção com `y=ymin=1`: `x = -1 + (-2-(-1))·(1-(-3))/(8-(-3)) = -1 - 4/11 ≈ -1,3636`. Novo A' = (-1,3636 ; 1), código `0000`.
- Segmento A'–B: códigos `0000` e `1000` → ainda não trivial. Ponto fora: B (bit "acima"). Interseção com `y=ymax=6`: `x = -1,3636 + (-2-(-1,3636))·(6-1)/(8-1) ≈ -1,8182`. Novo B' = (-1,8182 ; 6), código `0000`.
- **Ambos 0000 → ACEITO:** segmento visível de **(-1,36 ; 1)** a **(-1,82 ; 6)**.

*Aresta BC* — B(código 8) × C(código 2): `8 & 2 = 0` → não é trivial.
- Ponto fora: B (acima). Interseção com `y=6`: `x = -2 + (9-(-2))·(6-8)/(2-8) ≈ 1,6667`. B' = (1,6667 ; 6), código `0000`.
- Segmento B'–C: `0000` e `0010` → não trivial. Ponto fora: C (direita). Interseção com `x=xmax=5`: `y = 6 + (2-6)·(5-1,6667)/(9-1,6667) ≈ 4,1818`. C' = (5 ; 4,1818), código `0000`.
- **Ambos 0000 → ACEITO:** segmento visível de **(1,67 ; 6)** a **(5 ; 4,18)**.

*Aresta CA* — C(código 2) × A(código 4): `2 & 4 = 0` → não é trivial.
- Ponto fora: C (direita). Interseção com `x=5`: `y = 2 + (-3-2)·(5-9)/(-1-9) = 2 - 2 = 0`. C' = (5 ; 0), código: y=0 < ymin=1 → `0100 (4)`.
- Segmento C'–A: códigos `0100` e `0100` → **`4 & 4 = 4 ≠ 0` → REJEITADO** (a aresta CA está totalmente fora da janela — ambos os extremos ficam abaixo de `ymin`).

**Resultado:** apenas as arestas AB e BC têm partes visíveis; a aresta CA é totalmente recortada (invisível).

### Liang-Barsky (Algoritmo Equação Paramétrica)

**28) A atualização das coordenadas inicial e final é feita apenas no final. Justifique.**

Porque o algoritmo não trabalha recortando fisicamente o segmento a cada fronteira (como o Cohen-Sutherland); ele apenas atualiza dois **parâmetros numéricos**, `u1` (maior valor de entrada) e `u2` (menor valor de saída), comparando-os contra as 4 fronteiras. Só depois de testar as 4 fronteiras é que se sabe, de fato, qual é o subintervalo `[u1,u2]` do parâmetro `u` que fica dentro da janela — e é só então que as coordenadas reais `(x,y)` dos dois pontos finais são calculadas, de uma vez, substituindo os valores originais.

**29) Explique o porquê de as estruturas condicionais serem aninhadas.**

Para cada uma das 4 fronteiras, há 3 casos possíveis, que precisam ser testados em sequência: (1) a reta é paralela a essa fronteira (`pk=0`) — dentro desse caso, testa-se ainda se está dentro ou fora (`qk` positivo ou negativo); (2) `pk<0` → a reta está entrando (atualiza `u1`); (3) `pk>0` → a reta está saindo (atualiza `u2`). Esse encadeamento ("primeiro veja se é paralelo; se não for, veja o sinal de p para saber se atualiza u1 ou u2") exige condicionais aninhados (`if pk==0 {...} else { if pk<0 {...} else {...} }`) para tratar corretamente os três casos em cada uma das 4 fronteiras.

**30) Os valores iniciais de u1 e u2 são 0 e 1, respectivamente. Mostre o porquê.**

Porque `u` parametriza o segmento **original**: em `u=0` está o ponto `P1`, em `u=1` está o ponto `P2` (`x=x1+u.Δx`, `y=y1+u.Δy`). Antes de qualquer recorte, o segmento inteiro (de `u=0` a `u=1`) é candidato a estar visível. `u1` guarda o maior "ponto de entrada" encontrado e `u2` o menor "ponto de saída"; iniciá-los em `0` e `1` garante que o intervalo final `[u1,u2]` nunca ultrapasse os limites do segmento original (não faz sentido "entrar" antes de `u=0` nem "sair" depois de `u=1`).

**31) Mesmo triângulo e janela da questão 27. Aplique Liang-Barsky (códigos/coeficientes, coordenadas e interseções a cada iteração).**

Para cada aresta, `Δx=x2-x1`, `Δy=y2-y1`, e os coeficientes `(pk,qk)`: esquerda `(-Δx, x1-xmin)`, direita `(Δx, xmax-x1)`, baixo `(-Δy, y1-ymin)`, cima `(Δy, ymax-y1)`.

*Aresta AB* (A→B): `Δx=-1, Δy=11`
| fronteira | p | q | r=q/p | ação |
|---|---|---|---|---|
| esquerda | 1 | 1 | 1,000 | p>0 → u2=min(1;1,000)=1,000 |
| direita | -1 | 6 | -6,000 | p<0 → u1=max(0;-6)=0,000 |
| baixo | -11 | -4 | 0,364 | p<0 → u1=max(0;0,364)=0,364 |
| cima | 11 | 9 | 0,818 | p>0 → u2=min(1;0,818)=0,818 |

`u1=0,364 ≤ u2=0,818` → **ACEITO**: de `(x1+u1Δx, y1+u1Δy)=(-1,36 ; 1)` a `(x1+u2Δx, y1+u2Δy)=(-1,82 ; 6)` — igual ao Cohen-Sutherland. ✓

*Aresta BC* (B→C): `Δx=11, Δy=-6`
| fronteira | p | q | r | ação |
|---|---|---|---|---|
| esquerda | -11 | 0 | 0,000 | p<0 → u1=max(0;0)=0,000 |
| direita | 11 | 7 | 0,636 | p>0 → u2=min(1;0,636)=0,636 |
| baixo | 6 | 7 | 1,167 | p>0 → u2=min(0,636;1,167)=0,636 |
| cima | -6 | -2 | 0,333 | p<0 → u1=max(0;0,333)=0,333 |

`u1=0,333 ≤ u2=0,636` → **ACEITO**: de `(1,67 ; 6)` a `(5 ; 4,18)` — igual ao Cohen-Sutherland. ✓

*Aresta CA* (C→A): `Δx=-10, Δy=-5`
| fronteira | p | q | r | ação |
|---|---|---|---|---|
| esquerda | 10 | 11 | 1,100 | p>0 → u2=min(1;1,1)=1,000 |
| direita | -10 | -4 | 0,400 | p<0 → u1=max(0;0,4)=0,400 |
| baixo | 5 | 1 | 0,200 | p>0 → u2=min(1;0,2)=0,200 |
| cima | -5 | 4 | -0,800 | p<0 → u1=max(0,4;-0,8)=0,400 |

`u1=0,400 > u2=0,200` → **REJEITADO** — igual ao Cohen-Sutherland: a aresta CA não tem nenhuma parte visível. ✓

### Sutherland-Hodgeman (Recorte de Polígonos)

**32) Qual é o propósito desse algoritmo?**

Recortar **polígonos** (não apenas segmentos isolados) contra uma janela convexa, produzindo uma **nova lista de vértices fechada** que representa só a parte visível do polígono original — diferente de recortar cada aresta separadamente (o que resultaria em segmentos soltos, sem formar uma área fechada).

**33) Explique os critérios de atualização da lista de vértices.**

Percorre-se o polígono aresta por aresta (vértice atual + vértice anterior), contra **uma fronteira** por vez:
- anterior **dentro**, atual **dentro** → adiciona só o vértice atual;
- anterior **dentro**, atual **fora** → adiciona só o ponto de interseção (a aresta está "saindo" da janela);
- anterior **fora**, atual **dentro** → adiciona o ponto de interseção **e** o vértice atual (a aresta está "entrando");
- anterior **fora**, atual **fora** → não adiciona nada.

Repete-se esse processo para cada uma das 4 fronteiras da janela, sempre usando a lista de saída de uma fronteira como lista de entrada da próxima.

**34) Mesmo triângulo/janela; aplique Sutherland-Hodgeman (lista de vértices a cada iteração), sentido horário, lista inicial {A(-1,-3); B(-2,8); C(9,2)}.**

Ordem de recorte usada: esquerda (`x≥-2`) → direita (`x≤5`) → baixo (`y≥1`) → cima (`y≤6`).

- **Lista inicial:** { A(-1,-3), B(-2,8), C(9,2) }
- **Após recorte à esquerda (x≥-2):** todos os três vértices já satisfazem `x≥-2` (B está exatamente em x=-2, considerado dentro) → lista **inalterada**: { A(-1,-3), B(-2,8), C(9,2) }
- **Após recorte à direita (x≤5):**
  - A(-1,-3) dentro, anterior C(9,2) fora → adiciona interseção CA∩(x=5) = (5,0)
  - A dentro → adiciona A(-1,-3)
  - B(-2,8) dentro, anterior A dentro → adiciona B(-2,8)
  - C(9,2) fora, anterior B dentro → adiciona interseção BC∩(x=5) = (5 ; 4,1818)
  - → lista: { (5,0), A(-1,-3), B(-2,8), (5 ; 4,1818) }
- **Após recorte embaixo (y≥1):**
  - (5,0) fora (y=0<1), anterior (5;4,1818) dentro → adiciona interseção = (5,1)
  - A(-1,-3) fora, anterior (5,0) fora → nada
  - B(-2,8) dentro, anterior A fora → adiciona interseção AB∩(y=1) = (-1,3636 ; 1) e depois B(-2,8)
  - (5;4,1818) dentro, anterior B dentro → adiciona (5;4,1818)
  - → lista: { (5,1), (-1,3636 ; 1), B(-2,8), (5 ; 4,1818) }
- **Após recorte em cima (y≤6):**
  - (5,1) dentro, anterior (5;4,18) dentro → adiciona (5,1)
  - (-1,3636;1) dentro, anterior (5,1) dentro → adiciona (-1,3636;1)
  - B(-2,8) fora (y=8>6), anterior (-1,3636;1) dentro → adiciona interseção AB∩(y=6) = (-1,8182 ; 6)
  - (5;4,1818) dentro, anterior B fora → adiciona interseção BC∩(y=6) = (1,6667 ; 6) e depois (5;4,1818)
  - → **lista final:** { (5,1), (-1,36 ; 1), (-1,82 ; 6), (1,67 ; 6), (5 ; 4,18) }

**Polígono final (pentágono):** (5,1) → (-1,36 ; 1) → (-1,82 ; 6) → (1,67 ; 6) → (5 ; 4,18) → fecha em (5,1). Ele corresponde exatamente às partes visíveis de AB e BC encontradas nas questões 27/31, fechadas pelas bordas da própria janela (o trecho de `x=5` entre y=4,18 e y=1, e o trecho de `y=1` entre x=5 e x=-1,36).

---

## Preenchimento de Áreas

**35) Conceitue e defina vantagens/desvantagens:**

*a. Boundary Fill* — Preenche recursivamente a partir de um ponto interno até encontrar pixels com a cor de **borda**. Vantagem: simples de implementar; funciona bem em regiões de contorno bem definido, mesmo com forma irregular, sem precisar conhecer a geometria (vértices) do objeto. Desvantagem: é recursivo/usa pilha — alto custo de memória e processamento em áreas grandes; falha se houver "vazamento" na borda (uma fresta); não funciona bem se a borda tiver mais de uma cor; comportamento precisa de atenção se a cor de preenchimento coincidir com a cor da borda (ver questão 37a).

*b. Flood Fill* — Preenche recursivamente todos os pixels conectados que compartilham a mesma cor de **interior** original, trocando-os pela nova cor. Vantagem: funciona mesmo que a borda tenha várias cores (o critério é a cor interna, não a borda); ideal para "balde de tinta" em regiões cujo contorno não é uniforme. Desvantagem: as mesmas limitações de recursão/pilha e de vazamento do Boundary Fill; se o interior não for uniforme, pode preencher parcialmente ou vazar.

*c. Scan Line* — Para cada linha de varredura, calcula as interseções com as arestas do polígono e preenche entre pares de interseções (regra de paridade). Vantagem: muito mais eficiente (sem recursão/pilha, aproveita coerência entre linhas sucessivas); ideal quando se conhece a geometria (vértices) do polígono; permite preencher com padrões/gradientes de forma controlada. Desvantagem: mais complexo de implementar (arestas horizontais, interseção exatamente em vértices, necessidade de ordenar arestas); precisa da definição geométrica do polígono (não parte de uma imagem já rasterizada).

**36) Quais são os possíveis problemas no uso de conectividade 4 e 8?**

- **Conectividade 4** (só cima/baixo/esquerda/direita): pode **vazar** através de uma borda fina que só se conecta na diagonal — a diagonal não é testada, então a tinta escapa por essa "fresta".
- **Conectividade 8** (inclui diagonais): resolve o vazamento diagonal, mas pode **invadir indevidamente** uma região vizinha que só toca a atual por um único ponto diagonal — duas regiões que deveriam ficar separadas acabam se misturando.

**37) Aplique cada algoritmo no preenchimento do polígono indicado na figura.**

> **Observação sobre a figura:** o enunciado traz um desenho com os pixels de borda de um polígono aproximadamente circular, entre `x=3` e `x=9`, `y=4` e `y=9` (os eixos mostram as marcas 3, 6, 8 em x e 4, 7 em y). Pela resolução da imagem no PDF não é possível garantir a leitura de cada pixel com 100% de exatidão; a leitura abaixo é a melhor aproximação a partir da figura — confira com o desenho impresso do seu exercício e ajuste as coordenadas se necessário. O **método** aplicado é o que importa e não muda.

Pontos de borda lidos (aproximados): topo (y=9): x=5,6,7,8,9; depois (4,8); (3,7) e (9,7); (4,6) e (9,6); (5,5) e (9,5); base (y=4): x=6,7,8,9.

*a. Boundary Fill, conectividade 4, cor da borda = preto, cor de preenchimento = preto, ponto inicial (6,8)*

Pseudocódigo do algoritmo:
```
boundaryFill4(x,y, corPreench, corBorda):
    se cor(x,y) ≠ corBorda  E  cor(x,y) ≠ corPreench:
        pinta(x,y, corPreench)
        boundaryFill4(x+1,y, ...); boundaryFill4(x-1,y, ...)
        boundaryFill4(x,y+1, ...); boundaryFill4(x,y-1, ...)
```
**Ponto importante desta questão:** a cor de preenchimento é **igual** à cor da borda (as duas são pretas). Isso poderia parecer um problema (um pixel já preenchido "parece" borda para as próximas chamadas), mas observe a condição de parada: `cor(x,y) ≠ corBorda E cor(x,y) ≠ corPreench`. Como `corBorda = corPreench = preto`, essa condição vira simplesmente `cor(x,y) ≠ preto`. Ou seja, o algoritmo continua se propagando por **todo** pixel branco (interior), e para exatamente quando encontra um pixel já preto — seja ele borda original ou um pixel já pintado por uma chamada anterior. **O algoritmo continua funcionando corretamente**: a partir de (6,8) (interior, branco), a recursão se espalha nas 4 direções, pixel a pixel, até tocar toda a fronteira preta original — resultado final: **todo o interior do polígono fica preto**, tornando-se visualmente indistinguível da borda (a figura toda vira uma "mancha" preta sólida).

*b. Flood-Fill, conectividade 4, recolore a cor branca para preto, ponto inicial (8,5)*

Pseudocódigo:
```
floodFill4(x,y, corPreench, corAntiga):
    se cor(x,y) = corAntiga:
        pinta(x,y, corPreench)
        floodFill4(x+1,y, ...); floodFill4(x-1,y, ...)
        floodFill4(x,y+1, ...); floodFill4(x,y-1, ...)
```
Aqui `corAntiga = branco` (interior) e `corPreench = preto`. A partir do ponto inicial (8,5) — interior, branco — a recursão se espalha (4-conectado) por todos os pixels brancos alcançáveis, pintando-os de preto, e **para automaticamente** ao encontrar qualquer pixel que não seja branco (os pixels de borda, que já são pretos). O resultado final é o mesmo do item (a) — todo o interior preenchido de preto — mas obtido por um mecanismo diferente: aqui o critério é "a cor atual é a cor-alvo (branco)?", e não depende de existir uma cor de borda separada (funcionaria igual mesmo que a borda tivesse várias cores, desde que nenhuma delas fosse branca).

*c. Para Scan-Line, indique apenas a lista de vértices (interseções) referente a cada linha do polígono*

Usando os pontos de borda lidos da figura, cada linha de varredura (`y`) cruza a fronteira do polígono em 2 pontos (esquerda e direita) — entre eles é que o interior é preenchido:

| y | interseção esquerda | interseção direita | pixels preenchidos |
|---|---|---|---|
| 9 | x=5 | x=9 | 5 a 9 |
| 8 | x=4 | x≈9 (por continuidade) | 4 a 9 |
| 7 | x=3 | x=9 | 3 a 9 |
| 6 | x=4 | x=9 | 4 a 9 |
| 5 | x=5 | x=9 | 5 a 9 |
| 4 | x=6 | x=9 | 6 a 9 |

(Onde a figura não deixa clara a interseção direita de uma linha específica — caso da linha y=8 — ela foi inferida por continuidade com as linhas vizinhas, já que o lado direito do polígono, pela figura, se mantém em x≈9 do topo à base.)

---

## Antialiasing

**38) Conceitue e defina vantagens e desvantagens para o uso de:**

*a. Superamostragem (pós-filtragem)* — calcula a intensidade do pixel em uma resolução mais alta (grid mais fino) e depois reduz para a resolução final (ex.: contando subpixels cobertos, ou fazendo média ponderada para cor). **Vantagem:** é o método mais popular por ser fácil de implementar. **Desvantagem:** é "força bruta" — exige mais espaço de armazenamento (grid extra) e mais tempo de processamento (muito mais pixels calculados que o necessário); é considerada "menos elegante".

*b. Amostragem por área (pré-filtragem)* — calcula a intensidade do pixel diretamente pelo **tamanho da área** de sobreposição entre o pixel e o objeto, sem precisar de um grid auxiliar em resolução maior. **Vantagem:** mais precisa e eficiente (não recalcula em resolução mais alta). **Desvantagem:** matematicamente mais complexa — exige calcular a área exata de interseção entre formas geométricas e o quadrado do pixel.

*c. Uso de máscaras (peso / média ponderada)* — a intensidade final é calculada a partir de uma distribuição de **pesos** sobre a vizinhança do pixel (não conta subpixels igualmente, dá mais peso ao centro, por exemplo). **Vantagem:** aproxima melhor a percepção visual, pode ser pré-computada (máscara fixa), eficiente em hardware. **Desvantagem:** é uma aproximação — a qualidade depende de bem escolher a máscara; ainda exige processar sub-regiões do pixel.

*d. Pixel Phasing* — desloca fisicamente a posição em que o feixe sensibiliza o monitor, aproximando-a do valor contínuo real (suaviza pelo deslocamento da posição de exibição, não pela cor/intensidade). **Vantagem:** não exige processamento adicional de cor. **Desvantagem:** depende de hardware específico capaz de deslocar fisicamente a posição dos pixels (ex.: certos monitores CRT); efeito limitado a pequenos deslocamentos e não se aplica a qualquer dispositivo raster padrão.
