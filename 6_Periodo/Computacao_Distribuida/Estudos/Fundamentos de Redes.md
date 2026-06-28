## Fundamentos de Redes de Computadores

As redes classificam-se pela abrangência geográfica:

- PAN (Personal Area Network): Conexão de dispositivos pessoais.
    
- LAN (Local Area Network): Redes locais em edifícios ou campus.
    
- MAN (Metropolitan Area Network): Cobertura urbana.
    
- WAN (Wide Area Network): Escala nacional ou global.
    

Os esquemas de comutação incluem:

- Broadcast: Envio para todos os nós.
    
- Comutação de circuitos: Estabelecimento de canal dedicado.
    
- Comutação de pacotes: Encaminhamento individual de pacotes com base em endereços.
    

## Modelo OSI e Protocolos de Rede

O modelo OSI (Open Systems Interconnection) organiza a comunicação em sete camadas:

1. Física: Transmissão de bits brutos.
    
2. Enlace de Dados: Controle de erros no link direto.
    
3. Rede: Roteamento e endereçamento lógico (ex.: IP).
    
4. Transporte: Controle de fluxo e confiabilidade (ex.: TCP e UDP).
    
5. Sessão: Gerência de diálogos entre aplicações.
    
6. Apresentação: Tradução, criptografia e compressão de dados.
    
7. Aplicação: Interface com programas do usuário (ex.: HTTP, FTP).
    

## Sockets e Programação de Rede

Sockets representam a interface entre a camada de aplicação e a de transporte, permitindo comunicação baseada em:

- TCP: Orientado a conexão, confiável, com controle de fluxo e erro.
    
- UDP: Não orientado a conexão, mais rápido, porém não confiável.
    

A programação envolve a criação de sockets, associando-os a endereços IP e portas, e utilizando operações de leitura e escrita para transmitir dados.

## Dispositivos e Mecanismos de Interligação

- Roteador: Interconecta redes diferentes com base no endereço IP.
    
- Switch: Encaminha quadros dentro de uma mesma rede com base em endereços MAC.
    
- Hub: Repete sinais para todos os ports, sem inteligência de encaminhamento.
    
- NAT (Network Address Translation): Traduz endereços privados em públicos, permitindo que múltiplos dispositivos compartilhem um IP público.
    
- Firewall: Filtra tráfego de rede com base em regras de segurança.

