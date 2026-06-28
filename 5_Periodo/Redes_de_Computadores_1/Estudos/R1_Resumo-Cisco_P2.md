# Resumo: Conteúdo da Cisco para a Prova 2

Módulo 4: Camada física  
Módulo 5: Sistemas de números  
Módulo 6: Camada de Enlace de dados  
Módulo 7: Switching Ethernet

Módulo 14: Camada de transporte  
Módulo 15: Camada de aplicação

---
Módulo 4: Camada física
## Conexão Física

- Uma **conexão física pode ser uma conexão com fio** usando um cabo **ou uma conexão sem fio** usando ondas de rádio
- O tipo de conexão física usada depende da configuração da rede. Os dados são transmitidos por meio de um cabo físico.
- Estes são os componentes de um ponto de acesso:
	1. As antenas sem fio (Elas estão incorporadas dentro da versão do roteador mostrada na figura acima.);
	2. Várias portas de comutação Ethernet;
	3. Uma porta de internet
- As placas de interface de rede (NICs) conectam um dispositivo à rede. As NICs Ethernet são usadas para uma conexão com fio, enquanto as NICs da rede local sem fio (WLAN) são usadas para a conexão sem fio.
- Nem todas as conexões físicas são iguais, em termos de nível de desempenho, durante uma conexão com uma rede.

## Camada Física

- A camada física do modelo OSI **fornece os meios para transportar os bits** que formam um quadro da camada de enlace de dados no meio físico de rede. Essa camada aceita um quadro completo da camada de enlace de dados e o codifica como uma série de sinais que são transmitidos à mídia local. Os bits codificados que formam um quadro são recebidos por um dispositivo final ou por um dispositivo intermediário.
- A camada física codifica os quadros e cria os sinais de onda elétrica, óptica ou de rádio que representam os bits em cada quadro. Esses sinais são então enviados pela mídia, **um de cada vez**.
- A camada física do nó destino recupera esses sinais individuais do meio físico, restaura-os às suas representações de bits e passa os bits para a camada de enlace de dados como um quadro completo.

### Padrões da Camada Física

- Os protocolos e operações das **camadas OSI superiores** são executados usando software desenvolvido por engenheiros de software e cientistas da computação. Os serviços e protocolos na suíte TCP/IP são **definidos pela Internet Engineering Task Force (IETF)**.
- Os padrões de hardware, mídia, codificação e sinalização da camada física são definidos e governados por essas organizações de padrões:
	- International Organization for Standardization (ISO)
	- Telecommunications Industry Association/Electronic Industries Association (TIA/EIA)
	- União Internacional de Telecomunicações (ITU)
	- Instituto Nacional de Padronização Americano (ANSI)
	- Institute of Electrical and Electronics Engineers (IEEE)
	- Autoridades reguladoras de telecomunicações nacionais, incluem Federal Communication Commission (FCC) nos EUA e European Telecommunications Standards Institute (ETSI)

#### Componentes Físicos

- Os componentes físicos são os dispositivos de hardware eletrônico, mídia e outros conectores que transmitem os sinais que representam os bits

#### Codificação

- A codificação ou codificação de linha é um método para converter um fluxo de bits de dados em um "código” predefinido. Os códigos são agrupamentos de bits usados para fornecer um padrão previsível que pode ser reconhecido tanto pelo emissor quanto pelo receptor. Em outras palavras, a codificação é o método ou o padrão usado para representar as informações digitais.

#### Sinalização

- A camada física deve gerar os sinais elétricos, ópticos ou sem fio que representam os valores “1” e “0” no meio físico. A maneira como os bits são representados é chamada de método de sinalização. Os padrões de camada física devem definir que tipo de sinal representa o valor “1” e que tipo de sinal representa o valor “0”. Isso pode ser tão simples quanto uma alteração no nível de um sinal elétrico ou de um pulso óptico. Por exemplo, um pulso longo pode representar um 1, enquanto um pulso curto pode representar um 0.

#### Largura de Banda

- **Largura de banda é a capacidade na qual um meio pode transportar dados**. A largura de banda digital mede a quantidade de dados que podem fluir de um lugar para outro durante um determinado tempo.
- Os termos usados para medir a qualidade da largura de banda incluem:
	- **Latência**
		- O termo latência se refere ao tempo necessário para os dados viajarem de um ponto a outro, incluindo atrasos.
	- **Taxa de transferência**
		- Taxa de transferência é a medida da transferência de bits através da mídia durante um determinado período.
	- **Dados úteis**
		- Goodput é a medida de dados usáveis transferidos em um determinado período. Goodput é a taxa de transferência menos a sobrecarga de tráfego para estabelecer sessões, reconhecimentos, encapsulamento e bits retransmitidos. O goodput é sempre menor que a taxa de transferência, que geralmente é menor do que a largura de banda.

---
Módulo 5: Sistemas de números  
## Converter binário para decimal

Para converter um valor binário ( base = 2 ) para decimal ( base = 10 ), usar a soma dos produtos de cada algarismo pela potência da base equivalente à posição: 

```
Sistema binário :
	1010 0011(2) - número na base 2 

Sistema decimal :
	1x2^7 + 0x2^6 + 1x2^5 + 0x2^4 + 0x2^3 + 0x2^2 + 1x2^1 + 1x2^0 - forma canônica 
	128   +   0   +  32   +   0   +   0  +   0    +   2   +  1    = 163(10)

```