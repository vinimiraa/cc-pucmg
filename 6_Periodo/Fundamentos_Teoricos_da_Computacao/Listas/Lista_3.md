Fundamentos Teóricos da Computação - Lista de Exercícios 3
812839 - Vinícius Miranda de Araújo

1. Gramática das linguagens:
	1. $\{a^n b^n \mid n \to N\}$ <br> R: $S \to aSb \mid \lambda$
	2. $\{a^n b^k c^m \mid k=n+m\}$ <br> R: $S \to AC, A \to aAb \mid \lambda, C \to bCc \mid \lambda$
	3. $\{a^n b^k c^m \mid k=2n+m\}$ <br> R: $S \to AC, A \to aAbb \mid \lambda, C \to bCc \mid \lambda​$
	4. $\{a^m b^n c^i \mid m>n+i\}$ <br> R: $S \to aS \mid aT, T \to aTb \mid U, U \to aUc \mid \lambda$
	5. $\{w\in\{a,b\}^* \mid w\text{ não contém } aba\}$ <br> R: $S \to aA \mid bS \mid \lambda, A \to aA \mid bB \mid \lambda, B \to bS \mid \lambda$
	6. $\{w \mid w\text{ contém igual número de }a\text{ e }b\}$ <br> R: $S \to aSb \mid bSa \mid SS \mid \lambda$
	7. $\{ww^R \mid w\in\{a,b\}^*\}$ <br> R: $S \to aSa \mid bSb \mid \lambda$
	
2. Linguagem das gramáticas:
	1. $S \to aaSB \mid \lambda, B \to bB \mid \lambda$ <br> R: $L=\{a^{2n}b^k\mid n\ge0,\ k\ge0\}$
	2. $S \to aSbb \mid A, A \to cA \mid c$ <br> R: $L=\{a^n c^m b^{2n}\mid n\ge0,m\ge1\}$
	3. $S \to aS \mid bS \mid A, A \to cA \mid c \mid \lambda$ <br> R: $L=\{a,b\}^*c^*$
	4. $S \to abSdc \mid A, A \to cdAba \mid \lambda$ <br> R: $L=\{(ab)^n(cd)^m(ba)^m(dc)^n\mid n,m\ge0\}$
	5. $S \to aA \mid \lambda, A \to bS$ <br> R: $L=\{(ab)^n\mid n\ge0\}$
	6. $P \to Pc \mid Xc, X \to XbC \mid Y, Y \to aYbC \mid \lambda, Cb \to bC, Cc \to cc$ <br> R: $L= \{a^n b^m c^r\mid m\ge n,\ r\ge m\}$
