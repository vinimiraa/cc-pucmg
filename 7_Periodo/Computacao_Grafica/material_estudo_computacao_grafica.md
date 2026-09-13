# Computação Gráfica — Material de Estudo (Prova 01)

> Organizado a partir dos slides da disciplina
>
> Para cada assunto: **o que é** (conceito), **por que existe** (contexto/problema) e **para que serve** (objetivo), seguido das fórmulas e do raciocínio que os slides desenvolvem.

---

## 1. Transformações Geométricas 2D

### Contexto e objetivo
Em Computação Gráfica, os objetos são descritos por coordenadas (vértices). Para animar, posicionar ou redimensionar esses objetos numa cena, é preciso alterar essas coordenadas de forma sistemática. As **transformações geométricas** são o mecanismo que permite mudar posição, orientação, tamanho e forma dos objetos em um plano (2D), sem redesenhar o objeto do zero.

### As três transformações básicas

**Translação** — desloca um objeto segundo um vetor:
```
x' = x + tx
y' = y + ty        (ou  P' = P + T)
```

**Escala** — altera o tamanho multiplicando as coordenadas por uma constante:
```
x' = sx * x
y' = sy * y
```
- constante < 1 → reduz; constante > 1 → aumenta; `sx = sy` → aumento/redução uniforme (mantém proporção).

**Rotação** — desloca o objeto circularmente em torno de um ponto (em geral a origem).

### Coordenadas homogêneas — o problema que elas resolvem
Aplicar sequências de transformações (ex.: rotacionar, depois escalar, depois transladar) diretamente nas coordenadas (x,y) exige, para cada transformação, uma operação diferente (translação é soma; escala e rotação são multiplicação por matriz). Isso gera **cálculos em excesso** (número de transformações × número de vértices), porque cada transformação tem que ser aplicada individualmente e em separado a cada vértice.

**Solução:** representar o ponto com uma coordenada extra, `(x, y) → (x, y, 1)` (usando h = 1), e escrever **todas** as transformações — inclusive a translação — como multiplicação de matrizes 3×3. Essa é a vantagem central das coordenadas homogêneas: unifica translação, escala e rotação em uma única operação (multiplicação de matriz), o que permite **compor várias transformações em uma única matriz** antes de aplicá-la a cada vértice.

Formas gerais em coordenadas homogêneas (vetor coluna, `P' = M.P`):

- Translação `T(tx,ty)`:
```
| 1  0  tx |
| 0  1  ty |
| 0  0  1  |
```
- Escala `S(sx,sy)`:
```
| sx  0  0 |
| 0  sy  0 |
| 0   0  1 |
```
- Rotação `R(θ)` (sentido anti-horário, ângulo θ):
```
| cosθ  -senθ  0 |
| senθ   cosθ  0 |
|  0      0    1 |
```

### Composição de transformações
Com as matrizes acima, qualquer sequência de transformações pode ser reduzida a **uma única matriz composta**, obtida pela **concatenação** (multiplicação) das matrizes individuais. A multiplicação de matrizes é **associativa, mas não comutativa** — ou seja, a ordem importa (girar-depois-transladar ≠ transladar-depois-girar, em geral).

Propriedades úteis (compostas e inversas):
- Translação: `T(tx2,ty2).T(tx1,ty1) = T(tx1+tx2, ty1+ty2)`; inversa `T⁻¹(tx,ty) = T(-tx,-ty)`.
- Escala: `S(sx2,sy2).S(sx1,sy1) = S(sx1·sx2, sy1·sy2)`; inversa `S⁻¹(sx,sy) = S(1/sx, 1/sy)`.
- Rotação: `R(θ2).R(θ1) = R(θ1+θ2)`; inversa `R⁻¹(θ) = R(-θ)`.

### Reflexão e Cisalhamento (Shear)
- **Reflexão**: gera a imagem "espelhada" de um objeto em relação a um eixo (ex.: refletir em x inverte o sinal de y).
- **Cisalhamento**: distorce o objeto deslocando suas coordenadas proporcionalmente a outra coordenada (efeito de "inclinar" a figura).

### Transformação em torno de um ponto de referência (não a origem)
Girar ou escalar diretamente (matrizes acima) sempre acontece **em relação à origem**. Se o objeto não estiver na origem, o resultado inclui um deslocamento indesejado do objeto além da rotação/escala. Para transformar em torno de um ponto de referência arbitrário `(xref, yref)`, usa-se a sequência de 3 passos (translação → transformação → translação inversa):
1. Transladar o ponto de referência até a origem: `T(-xref,-yref)`
2. Aplicar a rotação ou escala desejada
3. Transladar de volta à posição original: `T(xref,yref)`

```
P' = T(xref,yref) . R(θ) . T(-xref,-yref) . P
```

### Mudança de sistema de referência
É comum precisar expressar as coordenadas de um objeto em outro sistema de referência (outro conjunto de eixos). Faz-se isso deslocando um referencial até coincidir com o outro:
- Translação da origem dos eixos: `P' = T(-tx,-ty).P`
- Alinhamento dos eixos (rotação dos eixos): `R'(θ) = R(-θ)` (nota o sinal invertido: girar o *referencial* de +θ equivale a girar os *pontos* de -θ).

---

## 2. Transformações Geométricas 3D

### Contexto e objetivo
As mesmas ideias das transformações 2D se estendem para o espaço 3D, agora usando **coordenadas homogêneas de dimensão 4** — `(x, y, z) → (x, y, z, 1)` — e matrizes 4×4. O objetivo continua sendo o mesmo: representar translação, escala e rotação (e reflexão, cisalhamento) como multiplicação de matriz, permitindo compor sequências de transformações em uma única matriz.

### Translação 3D
```
x' = x + tx
y' = y + ty
z' = z + tz
```
Matriz `T(tx,ty,tz)` (vetor coluna):
```
| 1  0  0  tx |
| 0  1  0  ty |
| 0  0  1  tz |
| 0  0  0  1  |
```
- Inversa: `T⁻¹(tx,ty,tz) = T(-tx,-ty,-tz)`
- Composição: `T(tx2,ty2,tz2).T(tx1,ty1,tz1) = T(tx1+tx2, ty1+ty2, tz1+tz2)`

### Escala 3D
```
x' = Sx.x ; y' = Sy.y ; z' = Sz.z
```
- Inversa: `S⁻¹(Sx,Sy,Sz) = S(1/Sx, 1/Sy, 1/Sz)`
- Composição: `S(Sx2,Sy2,Sz2).S(Sx1,Sy1,Sz1) = S(Sx1·Sx2, Sy1·Sy2, Sz1·Sz2)`

**Escala em função de um ponto de referência** (mesmo princípio do 2D):
1. Translação do ponto de referência para a origem.
2. Escala.
3. Translação de volta.
```
P' = T(xref,yref,zref).S(Sx,Sy,Sz).T(-xref,-yref,-zref).P
```

### Rotação 3D (em torno dos eixos coordenados)
Diferente do 2D (só existe uma rotação, em torno de um ponto), em 3D a rotação é sempre **em torno de um eixo**. As três rotações elementares:

- `Rz(θ)` (em torno do eixo z — a "rotação 2D" clássica, agora em 3D):
```
| cosθ  -senθ  0  0 |
| senθ   cosθ  0  0 |
|  0      0    1  0 |
|  0      0    0  1 |
```
- `Rx(θ)` (em torno do eixo x):
```
| 1   0      0     0 |
| 0  cosθ  -senθ  0 |
| 0  senθ   cosθ  0 |
| 0   0      0     1 |
```
- `Ry(θ)` (em torno do eixo y):
```
| cosθ   0  senθ  0 |
|  0     1   0    0 |
| -senθ  0  cosθ  0 |
|  0     0   0    1 |
```
Propriedades: `R⁻¹(θ) = R(-θ)`; `R(θ2).R(θ1) = R(θ1+θ2)` (para rotações em torno do **mesmo** eixo).

### Rotação em torno de um eixo arbitrário
Problema: girar em torno de um eixo qualquer (não um dos eixos coordenados). Solução, em 5 passos:
1. Translação para que o eixo passe pela origem: `T(-x1,-y1,-z1)`.
2. Rotações (`Rx`, `Ry`) para alinhar o eixo com um dos eixos coordenados (ex.: z).
3. Realizar a rotação `Rz(θ)` desejada sobre esse eixo coordenado.
4. Aplicar as rotações inversas (`Ry⁻¹`, `Rx⁻¹`) para devolver o eixo à orientação original.
5. Aplicar a translação inversa `T(x1,y1,z1)` para devolver o eixo à posição original.

```
P' = T(x1,y1,z1).Rx(-α).Ry(-β).Rz(θ).Ry(β).Rx(α).T(-x1,-y1,-z1).P
```

### Reflexão e Cisalhamento (Shear) 3D
- Reflexão em relação ao plano `xy` (inverte z): `x'=x, y'=y, z'=-z`.
- Reflexão em relação à origem (inverte os três eixos): `x'=-x, y'=-y, z'=-z` — matriz `diag(-1,-1,-1,1)`.
- Shear (em z, por exemplo): `x' = x + shx.z`, `y' = y + shy.z`, `z' = z` — distorce o objeto numa direção proporcionalmente a outra coordenada.

### Transformação entre sistemas de coordenadas
Para converter coordenadas de um referencial para outro, dado um novo sistema definido por um **ponto origem** e um **vetor unitário por eixo**:
1. Translação do novo referencial para a origem do antigo: `P' = T(-x0,-y0,-z0).P`
2. Rotação: os vetores unitários do novo referencial formam as linhas da matriz de rotação `R` (a submatriz 3×3 é ortogonal — vetores linha/coluna ortogonais entre si).
```
P' = R.T(-x0,-y0,-z0).P
```
Transformação inversa: `P' = T(x0,y0,z0).R⁻¹.P'`

---

## 3. Primitivas de Saída — Rasterização de Retas

### Conceito e contexto
Uma **primitiva de saída** é a estrutura geométrica básica a partir da qual se constroem estruturas mais complexas (ponto, linha, círculo, curva, caractere...). O **problema a resolver** aqui é: como desenhar uma linha reta (definida por dois pontos com coordenadas reais/contínuas) em uma tela composta por uma grade discreta de pixels?

Duas abordagens de varredura:
- **Por vetores**: variação linear das tensões de deflexão horizontal/vertical proporcional às variações em X e Y (tecnologia de tubos vetoriais, hoje obsoleta).
- **Raster**: preenche o conjunto de pixels que melhor se aproxima da linha desejada entre os dois pontos — é o modelo usado atualmente (monitores raster).

### Dois casos, conforme a inclinação (m)
- **1º caso** — `-1 ≤ m ≤ 1`: 1 pixel por coluna (x varia de 1 em 1, y é a variável dependente).
- **2º caso** — `|m| > 1`: 1 pixel por linha (agora é y que varia de 1 em 1, e x é a variável dependente).

O que diferencia os dois casos é **qual eixo é tratado como variável de controle** (incrementada sempre em 1 unidade) e qual é a variável calculada/arredondada a cada passo.

### Algoritmo DDA (Digital Differential Analyzer)
**Ideia:** a partir de um ponto, encontra-se o próximo somando uma constante `K` (multiplicada por Δx e Δy) às coordenadas atuais; os valores são sempre reais durante o cálculo e **arredondados apenas na hora de plotar o pixel** (a visualização), preservando a precisão dos cálculos intermediários e evitando erro acumulado de arredondamento.
```
K = 1 / max(|Δx|, |Δy|)
```
Ou seja, o número de iterações (passos) é definido pelo **maior** valor entre |Δx| e |Δy| — assim garante-se que a variável dominante avance exatamente 1 pixel por passo (sem pular nenhum pixel na direção de maior variação), enquanto a outra variável avança uma fração (`m` ou `1/m`) por passo.

Pseudocódigo (essência):
```
dx = x2 - x1;  dy = y2 - y1
passos = max(|dx|, |dy|)
xinc = dx / passos ;  yinc = dy / passos
x = x1;  y = y1;  plot(round(x), round(y))
repita "passos" vezes:
    x = x + xinc ;  y = y + yinc
    plot(round(x), round(y))
```

### Algoritmo de Bresenham (retas)
**Problema que resolve:** o DDA usa aritmética de ponto flutuante (incrementos fracionários, arredondamento) em cada passo — mais lento e sujeito a erro de arredondamento acumulado. Bresenham **realiza cálculos apenas com números inteiros** (soma, subtração e comparação), sendo mais rápido e exato.

**Ideia central** (caso `0 ≤ m ≤ 1`): a partir do ponto atual `Pk`, o próximo ponto só pode ser o pixel à direita (**E**) ou o pixel acima-e-à-direita (**NE**). A escolha depende de qual dos dois pixels candidatos está mais próximo da reta real — comparando as distâncias `d1` (até E) e `d2` (até NE):
```
d1 - d2 < 0  →  ponto E
d1 - d2 ≥ 0  →  ponto NE
```
Substituindo a inclinação `m` por `Δy/Δx` (o que elimina a divisão e mantém tudo inteiro), chega-se à variável de decisão incremental:
```
p0 = 2Δy - Δx
Se pk < 0:      próximo = E;   p(k+1) = pk + 2Δy
Se pk ≥ 0:      próximo = NE;  p(k+1) = pk + 2Δy - 2Δx
```
- `Δx` e `Δy` são sempre usados em **valor absoluto** nas fórmulas (o sentido/direção do incremento — crescente ou decrescente — é tratado à parte, pelas variáveis `incrx`/`incry` = +1 ou -1); por isso "delta é sempre positivo".
- A cada iteração, **x é sempre incrementado** (é a variável de controle do laço, no 1º caso); **y só é incrementado quando `p ≥ 0`** (caso NE) — a variável de decisão `p` é atualizada de forma incremental a partir do valor anterior e das constantes `2Δy` / `2Δy-2Δx`.

Versão genérica (qualquer sentido e qualquer octante, do slide):
```c
void bres_gen(int x1,y1,x2,y2){
  dx = x2-x1;  if (dx>=0) incrx=1; else {incrx=-1; dx=-dx;}
  dy = y2-y1;  if (dy>=0) incry=1; else {incry=-1; dy=-dy;}
  x=x1; y=y1; colora_pixel(x,y);
  if (dy < dx) {                       // 1o caso: x domina
    p = 2*dy - dx; const1 = 2*dy; const2 = 2*(dy-dx);
    for (i=0;i<dx;i++){
      x += incrx;
      if (p<0) p += const1;
      else { y += incry; p += const2; }
      colora_pixel(x,y);
    }
  } else {                             // 2o caso: y domina
    p = 2*dx - dy; const1 = 2*dx; const2 = 2*(dx-dy);
    for (i=0;i<dy;i++){
      y += incry;
      if (p<0) p += const1;
      else { x += incrx; p += const2; }
      colora_pixel(x,y);
    }
  }
}
```

---

## 4. Rasterização de Circunferências

### Contexto e problema
Uma circunferência é o conjunto de pontos a uma distância `r` (raio) fixa de um centro. A forma cartesiana da equação:
```
(x - xc)² + (y - yc)² = r²   →   y = yc ± √(r² - (x-xc)²)
```
tem dois problemas sérios para rasterização: **alta carga computacional** (raiz quadrada a cada ponto) e **espaçamento não uniforme entre pixels** (a densidade de pontos varia com a inclinação da curva, deixando "buracos" perto do topo/base do círculo).

A forma **paramétrica** (coordenadas polares) `x = xc + r·cosθ`, `y = yc + r·senθ`, usando passo angular constante, resolve o espaçamento (distâncias uniformes entre pixels), mas ainda usa funções trigonométricas (custosas).

### A ideia de Bresenham para círculos: simetria de 8 vias
Em vez de calcular a circunferência inteira, calcula-se **apenas 1/8 dela** (um octante) e obtêm-se os outros 7 por simetria (troca de sinais e troca x↔y) — reduzindo drasticamente os cálculos. O octante escolhido é o de **45° a 90°**, onde (analogamente ao 1º/2º caso das retas) o próximo ponto só pode ser **E** (à direita) ou **SE** (abaixo-à-direita):
```
d1 - d2 < 0  →  ponto E
d1 - d2 ≥ 0  →  ponto SE
```

### Dedução da variável de decisão
Para o ponto atual `(xk, yk)`, no octante 45°–90°:
```
y² = r² - (xk+1)²
d1 = yk² - y²  = yk² - r² + (xk+1)²
d2 = y² - (yk-1)² = r² - (xk+1)² - (yk-1)²
pk = d1 - d2 = yk² - 2r² + 2(xk+1)² + (yk-1)²
```
Calculando de forma incremental (a partir de `p0 = 3 - 2r`, com ponto inicial `(x0,y0) = (0, r)`):
```
Se pk < 0:   próximo = E;   x(k+1) = xk+1 ;              p(k+1) = pk + 4xk + 6
Se pk ≥ 0:   próximo = SE;  x(k+1) = xk+1 ; y(k+1) = yk-1; p(k+1) = pk + 4(xk-yk) + 10
```
O laço continua **enquanto x < y** — essa é justamente a condição que restringe o cálculo ao octante 45°–90° (quando x alcança/ultrapassa y, o octante termina). A cada iteração, `x` é sempre incrementado (variável de controle do laço); `y` só é decrementado quando a decisão indica **SE**.

### Centro fora da origem e pontos simétricos
O algoritmo sempre calcula os pontos `(x,y)` **como se o centro fosse a origem** (a variável de decisão `p` depende só do raio `r`, nunca do centro). A posição real do centro `(xc,yc)` só entra na hora de "acender o pixel": ponto absoluto = `(xc+x, yc+y)`.

Para obter a circunferência completa a partir do octante calculado, usam-se os **8 pontos simétricos** de cada `(x,y)` local, antes de somar o centro:
```
(x,y)  (y,x)  (-x,y)  (-y,x)  (x,-y)  (y,-x)  (-x,-y)  (-y,-x)
```

### Outras primitivas
- **Elipse**: conjunto de pontos cuja soma das distâncias a dois focos é constante; é rasterizada como uma extensão do algoritmo de circunferências.
- **Caracteres (fontes)**: duas formas de representação — **bitmap font** (malha de pixels pronta; simples, mas ocupa muita memória, pois cada estilo/tamanho precisa ser armazenado por completo) e **outline font** (definida por primitivas geométricas/curvas; ocupa menos memória e permite manipular o estilo, mas exige mais processamento para rasterizar).

---

## 5. Visualização 2D e Recorte (Clipping)

### Pipeline de visualização 2D: Janela e Visor
- **Janela (window)**: a área da cena selecionada para visualização — "o que deve ser visualizado".
- **Visor (viewport)**: a área do dispositivo de saída onde a porção de cena contida na janela será exibida — "onde deve ser visualizado".

Usam-se, em geral, áreas retangulares (maior eficiência de cálculo). A **transformação janela-visor** mapeia a janela para o visor, convertendo coordenadas do universo (cena) para coordenadas do dispositivo, preservando as posições relativas entre os objetos. Isso é feito compondo transformações geométricas: (1) translação da origem da janela para a origem do referencial, (2) mudança de escala para o tamanho do visor, (3) translação para a origem do visor.

### Recorte (Clipping) — o problema
**Recorte** é a operação que identifica quais partes das primitivas de uma cena estão **dentro** ou **fora** de uma região do espaço (a janela). Sem clipping, o sistema gastaria tempo processando/desenhando objetos (ou partes de objetos) que nunca aparecerão na tela.

- **Recorte de pontos**: um ponto está dentro de uma janela retangular se `xmin ≤ x ≤ xmax` e `ymin ≤ y ≤ ymax`.
- **Recorte de segmentos de reta**: um segmento pode estar (L1) totalmente dentro, (L2) totalmente fora, ou (L3/L4) parcialmente dentro da janela — o desafio é decidir isso eficientemente e calcular as interseções quando parcial.

### Algoritmo de Cohen-Sutherland (recorte de retas por códigos)
**Ideia:** codificar a posição de cada extremo do segmento em relação à janela usando um **region code** de 4 bits (ordem Top-Bottom-Right-Left, TBRL): para um ponto `P=(x,y)`, ativa-se o bit correspondente sempre que a condição é verdadeira:
```
bit Top    (bit 3) = 1  se  y > ymax
bit Bottom (bit 2) = 1  se  y < ymin
bit Right  (bit 1) = 1  se  x > xmax
bit Left   (bit 0) = 1  se  x < xmin
```
Isso gera 9 regiões possíveis ao redor/dentro da janela. Note que os códigos **0011 (3)** e **0111 (7)** (e outras combinações com Left=Right=1 simultâneos, ou situações incoerentes) **nunca ocorrem**, pois um ponto não pode estar à esquerda E à direita da janela ao mesmo tempo (nem acima E abaixo simultaneamente) — left/right e top/bottom são mutuamente exclusivos.

**Verificação/condições de parada:**
- Se os dois códigos são **0000** → segmento **totalmente dentro** → aceitar.
- Se o **AND bit-a-bit** dos dois códigos é diferente de zero (`c1 & c2 ≠ 0`) → **totalmente fora** → rejeitar. (Isso funciona porque, se os dois pontos violam a *mesma* fronteira, e a janela é convexa, o segmento inteiro — que é uma reta, convexo — está do lado de fora dessa fronteira.)
- Caso contrário → o segmento está **parcialmente dentro**: escolhe-se um dos pontos com código ≠ 0, calcula-se a interseção do segmento com a fronteira violada (usando a equação da reta), **substitui-se esse ponto** pela interseção, recalcula-se seu código, e repete-se o processo (o mesmo ponto pode ser atualizado **mais de uma vez**, se ainda violar outra fronteira depois do primeiro ajuste) até cair em um dos dois casos de parada.

Fórmulas de interseção (dado o segmento `(x1,y1)-(x2,y2)`):
```
com y = ymin ou ymax:   x = x1 + (x2-x1) * (y_fronteira - y1)/(y2-y1)
com x = xmin ou xmax:   y = y1 + (y2-y1) * (x_fronteira - x1)/(x2-x1)
```
Importante: essas atualizações acontecem sobre **cópias locais** das coordenadas (variáveis de trabalho do algoritmo) — os valores originais dos objetos na cena **não são alterados**.

### Algoritmo de Liang-Barsky (equação paramétrica)
**Ideia:** usar a equação paramétrica da reta, `x = x1 + u.Δx`, `y = y1 + u.Δy`, com `u` variando de 0 (ponto P1) a 1 (ponto P2). Para cada uma das 4 fronteiras da janela, calculam-se coeficientes `pk` e `qk`:
```
p1 = -Δx   q1 = x1 - xmin     (esquerda)
p2 =  Δx   q2 = xmax - x1     (direita)
p3 = -Δy   q3 = y1 - ymin     (baixo)
p4 =  Δy   q4 = ymax - y1     (cima)
```
Para cada fronteira k:
- Se `pk = 0`: a reta é **paralela** a essa fronteira — se `qk < 0`, a reta está totalmente fora (rejeita); caso contrário, essa fronteira não restringe nada (segue para a próxima).
- Se `pk ≠ 0`, calcula-se `rk = qk/pk`:
  - `pk < 0` → a reta está **entrando** (de fora para dentro) por essa fronteira → `u1 = max(u1, rk)`.
  - `pk > 0` → a reta está **saindo** (de dentro para fora) por essa fronteira → `u2 = min(u2, rk)`.

Essas verificações precisam de condicionais **aninhadas** (primeiro testa se é paralela, e só se não for é que se decide, pelo sinal de `pk`, se atualiza `u1` ou `u2`) — são 3 casos distintos (paralela-fora / entrando / saindo) por fronteira.

Os valores iniciais são `u1 = 0` e `u2 = 1`, porque esses são exatamente os limites do segmento **original** (P1 em u=0, P2 em u=1) — antes de qualquer recorte, todo o segmento é candidato a estar visível, e os limites finais [u1,u2] nunca poderão ultrapassar esse intervalo.

Ao final das 4 comparações: se `u1 > u2`, o segmento está totalmente fora (rejeitado); caso contrário, os pontos de interseção finais são calculados **de uma só vez** (`x1+u1.Δx, y1+u1.Δy` e `x1+u2.Δx, y1+u2.Δy`) — diferente do Cohen-Sutherland, que recalcula e substitui as coordenadas a cada iteração, o Liang-Barsky só atualiza as coordenadas no final, pois todos os testes das 4 fronteiras são feitos sobre os parâmetros numéricos `u`/`p`/`q`, sem precisar "recortar" fisicamente a reta a cada passo intermediário.

**A ordem dos recortes (esquerda/direita/cima/baixo, em qualquer algoritmo) não altera o resultado final** — cada fronteira define um semiplano independente, e a interseção de semiplanos (a região visível final) não depende da ordem em que são testados.

### Recorte de Polígonos — Algoritmo de Sutherland-Hodgman
**Problema:** recortar os segmentos de um polígono individualmente (com Cohen-Sutherland, por exemplo) não é suficiente — o resultado seria um conjunto de segmentos soltos, sem formar uma área fechada.

**Propósito do algoritmo:** produzir uma **nova lista de vértices fechada**, representando apenas a parte do polígono original que está dentro da janela.

**Método:**
1. Recorta-se o polígono contra **cada uma** das retas que delimitam a janela, uma de cada vez (ex.: esquerda, direita, baixo, cima), usando a lista de saída de uma fronteira como lista de entrada da próxima.
2. A área do polígono é dada por uma lista ordenada de vértices (percorrida, por convenção, em um sentido — ex. horário).
3. Para cada aresta (vértice atual + vértice anterior), a lista de saída é atualizada segundo 4 critérios:

| Vértice anterior | Vértice atual | Ação |
|---|---|---|
| dentro | dentro | adiciona só o vértice atual |
| dentro | fora | adiciona só o ponto de interseção |
| fora | dentro | adiciona o ponto de interseção **e** o vértice atual |
| fora | fora | não adiciona nada |

---

## 6. Preenchimento de Áreas (Fill)

### Scan Line
**Ideia:** para cada linha de varredura horizontal, calculam-se as interseções dessa linha com as arestas do polígono; **os pontos à direita de um número ímpar de interseções são preenchidos** (regra de paridade).

- **Problema dos vértices**: quando a linha de varredura passa exatamente por um vértice (que liga duas arestas), é preciso ter cuidado para não contar essa interseção duas vezes (o que inverteria a regra de paridade incorretamente). Regra: ordenar as arestas (ex. sentido horário) e contar **1 vértice** se a variável `y` muda de sentido nas duas arestas que se encontram nele, ou **2 vértices** caso contrário (vértice é um mínimo ou máximo local).
- **Eficiência (coerência entre scanlines)**: em vez de recalcular a interseção do zero a cada linha, usa-se um cálculo incremental, aproveitando que a interseção da próxima linha de varredura com uma aresta é próxima da anterior:
```
m = (yk+1 - yk) / (xk+1 - xk)          (inclinação da aresta)
yk+1 = yk - 1  (linha de varredura seguinte, varrendo de cima para baixo)
xk+1 = xk - 1/m
```

### Boundary Fill
**Ideia:** preenche recursivamente o interior de uma região a partir de um **ponto inicial** conhecido, espalhando-se para os pixels vizinhos, até encontrar pixels com a **cor de borda** (contorno).
- **Parâmetros de entrada**: ponto inicial, cor de preenchimento, cor do contorno (borda).
- **Conectividade**: quantidade de pixels vizinhos testados a cada passo — **4** (cima/baixo/esquerda/direita) ou **8** (inclui as diagonais).
- **Cuidado**: se a cor de preenchimento for igual à cor da borda, um pixel já pintado passa a "parecer" borda para os próximos testes — mas, como o teste de parada do algoritmo é justamente "a cor atual é diferente da borda e diferente do preenchimento", quando as duas cores coincidem essa condição simplesmente vira "a cor atual é diferente dessa cor única", o que **ainda funciona corretamente** (o preenchimento avança e para exatamente na borda original).

### Flood Fill
**Ideia:** ao contrário do Boundary Fill (que depende de existir uma cor de contorno única e definida), o Flood Fill **recolore** uma região definida pela sua **cor interna atual** — preenche todos os pixels conectados que tiverem a cor de interior original, substituindo-os pela nova cor de preenchimento.
- **Parâmetros de entrada**: ponto inicial, cor de preenchimento, cor do interior (a cor-alvo a ser substituída).
- Útil quando a borda não tem uma cor única/definida, mas o interior é uniforme.

### Problemas de conectividade 4 e 8
- **Conectividade 4**: pode "vazar" através de uma borda fina que só se conecta na diagonal (a diagonal não é testada, então o preenchimento escapa).
- **Conectividade 8**: resolve o vazamento diagonal, mas pode invadir por engano uma região vizinha que só toca a região atual num único ponto diagonal (deveriam ser regiões separadas).

### Atributos das primitivas
Um **atributo** é qualquer parâmetro que afeta a forma de visualização de uma primitiva.
- **Modo de escrita (RasterOp)** — como combinar o desenho de uma primitiva com o fundo:
  - **Replace**: substitui o fundo pela primitiva.
  - **OR**: acrescenta os pixels ativos da primitiva ao fundo.
  - **AND**: apaga todos os pixels inativos da primitiva (mantém só a interseção).
  - **XOR**: inverte os pixels ativos da primitiva (útil para desenhar/apagar cursores sem destruir o fundo).
- **Atributos de linha**: estilo (sólido, tracejado, pontilhado — feito adaptando os algoritmos de rasterização com máscaras), espessura (replicação de pixels em colunas/linhas) e cor.

---

## 7. Antialiasing

### O problema
Converter valores contínuos (a reta/curva matemática ideal) para valores discretos (pixels) gera distorções visuais chamadas **aliasing** — o efeito "serrilhado" (jaggies) nas bordas — causadas por baixa frequência de amostragem em relação aos detalhes da imagem (**undersampling**). Os métodos de **antialiasing** existem para corrigir/atenuar essas distorções.

### Métodos

**Superamostragem (pós-filtragem)** — calcula a intensidade do pixel numa resolução mais alta (um grid menor/mais fino) e depois reduz (filtra) para a resolução final mais baixa.
- Para retas: é o método mais popular (fácil de implementar), mas é "força bruta" — menos elegante, exige mais espaço de armazenamento e mais tempo de processamento (mais pixels calculados que o necessário).
- Pode ser feito contando o número de subpixels cobertos (para escala de cinza) ou fazendo uma média ponderada (para cor).

**Amostragem por área (pré-filtragem)** — calcula a intensidade do pixel diretamente a partir do **tamanho da área** do pixel que é interceptada/sobreposta pelo objeto (sem precisar de um grid auxiliar em resolução maior). Mais precisa e elegante que a superamostragem, mas exige cálculos geométricos de área de interseção (mais complexa de implementar).

**Uso de máscaras / peso** — a intensidade final é calculada conforme uma **distribuição de pesos** (máscara) sobre a vizinhança do pixel — uma média ponderada, em vez de simplesmente contar subpixels igualmente.

**Pixel Phasing** — em vez de alterar a intensidade/cor, desloca fisicamente a posição em que o feixe sensibiliza o monitor, aproximando a posição de exibição do valor contínuo real (suaviza as extremidades pelo deslocamento, não pela cor). Depende de hardware capaz de fazer esse deslocamento fino de posição.

---

## Mapa mental rápido para revisão

| Tema | Problema resolvido | Ferramenta/algoritmo |
|---|---|---|
| Transformações 2D/3D | Mover/girar/escalar objetos de forma composta e eficiente | Coordenadas homogêneas + matrizes + concatenação |
| Rasterização de retas | Desenhar uma reta contínua em uma grade de pixels | DDA (incremental, ponto flutuante) / Bresenham (incremental, inteiro) |
| Rasterização de círculos | Idem, para circunferências, evitando raiz quadrada e espaçamento irregular | Bresenham/ponto médio + simetria de 8 vias |
| Visualização/Recorte | Não desenhar o que está fora da tela | Window/Viewport; Cohen-Sutherland; Liang-Barsky; Sutherland-Hodgman (polígonos) |
| Preenchimento | Colorir o interior de uma região | Scan Line (por geometria) / Boundary Fill / Flood Fill (por imagem) |
| Antialiasing | Suavizar o serrilhado da rasterização | Superamostragem, amostragem por área, máscaras, pixel phasing |
