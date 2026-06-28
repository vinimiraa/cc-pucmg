Fundamentos Teóricos da Computação - Lista de Exercícios 2
812839 - Vinícius Miranda de Araújo

1. Par de `b` para $\Sigma^*=\{a, b\}$:
	- $L \subseteq \Sigma^*$
	- Caso base: $\lambda \in L$
	- Passo recursivo: Se $w \in L$, então $aw \in L$ e $wa \in L$ e $bwb \in L$
2. Mostre que:
	- $(ba)^+.(a^*.b^* \cup a^*) = (ba)^*.ba^+.(b^* \cup \lambda)$
		Lado Esquerdo:
			$(a^*.b^* \cup a^*) = (a^*.b^*)$, então $(ba)^+.(a^*.b^* \cup a^*) = (ba)^+.a^*.b^*$
			$(ba)^+ = (ba)^*(ba)$, então $(ba)^+.a^*.b^* = (ba)^* . ba . a^* . b^*$
			$ba . a^* = baa^* = ba^+$, então $(ba)^*.ba^+.b^*$
		Lado Direito:
			$(b^* \cup \lambda) = b^*$, então $(ba)^*.ba^+.(b^* \cup \lambda) = (ba)^*.ba^+.b^*$
		Logo, ambos viram:
			$(ba)^*.ba^+.b^*$ $\to$ verdadeiro
	- $b^+ (a^* b^* \cup \lambda) b = b (b^* a^* \cup \lambda) b^+$
		Lado Esquerdo:
		$(a^* b^* \cup \lambda) = a^* b^*$, então $b^+ (a^* b^* \cup \lambda) b = b^+ a^* b^* b$
		$b^* b = b^+$, então $b^+ a^* b^* b = b^+a^*b^+$
		Lado Direito:
		$(b^* a^* \cup \lambda) = b^* a^*$, então $b (b^* a^* \cup \lambda) b^+ = b b^* a^* b^+$
		$bb^* = b^+$, então $b b^* a^* b^+ = b^+a^*b^+$
		Logo, ambos viram:
		$b^+a^*b^+$ $\to$ verdadeiro
3. Expressões Regulares:
	- $aa^*bb^*$
	- $(a\cup b)^*aa(a \cup b)^*$
	- $b^* aa b^*$
	- $a^+(a^* \cup bb \cup c^*) cc$
	- $(a \cup b)^* bab (a \cup b)^* \cup (a \cup b)^* aba (a \cup b)^*$
	- $(a \cup b \cup c)^* aabbcc (a \cup b \cup c)^*$
	- $((a \cup c)^* \cup bc)^*$
	- $(a \cup b \cup c)(a \cup b \cup c)(a \cup b \cup c)$
	- $(a \cup b \cup c)(a \cup b \cup c)$
	- $(a \cup b \cup c)(a \cup b \cup c)(a \cup b \cup c)^+$
	- impossível
4. AFD's:
	- ![[Pasted image 20260405191641.png]]
	- ![[Pasted image 20260405192054.png]]
5. AFN-$\lambda$:
	- ![[Pasted image 20260405192446.png]]
	- ![[Pasted image 20260405192637.png]]
	- ![[Pasted image 20260405193218.png]]
	- ![[Pasted image 20260405193548.png]]
6. AFD dos AFN-$\lambda$:
	- ![[Pasted image 20260405194134.png]]
	- ![[Pasted image 20260405194324.png]]
	- ![[Pasted image 20260405195223.png]]
	- ![[Pasted image 20260405195832.png]]
7. Prove:
	- $\{0^m 1^n \mid m,n \geq 0\}$:
		Podemos também descrever a linguagem $L$ com uma expressão regular.
		Uma expressão regular para a linguagem $L$ é:  $0^* 1^*$, onde:
		- $0^*$ significa zero ou mais 0's (isso cobre todos os casos de $m \geq 0$ ).
		- $1^*$ significa zero ou mais 1's (isso cobre todos os casos de $n \geq 0$).
		Essa expressão regular descreve exatamente o conjunto de strings que consistem em qualquer número de 0's seguidos por qualquer número de 1's, o que é exatamente a definição de $L$.
	- $\{0^m 1^n 0^m \mid m,n \geq 0\}$:
		Para provar que a linguagem $L = \{ 0^m 1^n 0^m \mid m, n \geq 0 \}$ não é regular, usamos o Lema do Bombeamento.
		1. Suponha que $L$ seja regular. Então, existe um número $p$ (comprimento da bomba) tal que qualquer string $w \in L$ com $|w| \geq p$  pode ser dividida em $w = xyz$, onde:
		    - $|xy| \leq p$,
		    - $|y| > 0$,
		    - Para todo $i \geq 0$, $xy^i z \in L$.
		2. Considerando a string $w = 0^p 1^p 0^p \in L$, com $p$ grande o suficiente.
		3. A string $w$ pode ser dividida em $w = xyz$, onde $x = 0^a$ , $y = 0^b$ , e $z = 1^p 0^p$, com $a + b \leq p$  e $b > 0$.
		4. Ao repetir $y$ ($i$ vezes), a string $xy^i z$ para $i > 1$ ou $i = 0$ resultará em uma string que não pertence a $L$, pois o número de 0's no início e no final da string não será mais o mesmo.
		5. Concluí-se que $L$ não é regular.