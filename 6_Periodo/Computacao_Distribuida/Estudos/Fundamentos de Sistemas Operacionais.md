## Conceitos de Sistemas Operacionais

O núcleo (kernel) do sistema operacional gerencia recursos hardware e oferece serviços essenciais:

- Gerenciamento de processos: Criação, escalonamento e sincronização.
    
- Gerenciamento de memória: Alocação, paginação e proteção.
    
- Sistema de arquivos: Organização e acesso a dados em armazenamento persistente.
    
- Drivers de dispositivo: Interface com hardware específico.
    
- Serviços de rede: Implementação de protocolos de comunicação.
    

## Processos e Comunicação Interprocessos (IPC)
Um processo é uma instância de um programa em execução, possuindo atributos como:

- PID (Process ID) e PPID (Parent Process ID)
    
- UID (User ID) real e efetivo
    
- Espaço de endereçamento (código, dados, pilha, heap)
    
- File descriptors para recursos de E/S
    
- Variáveis de ambiente e prioridade
    

A comunicação entre processos (IPC) pode ocorrer através de:

- Pipes: Canais unidirecionais para processos relacionados.
    
- FIFOs (Named Pipes): Pipes com nome no sistema de arquivos, permitindo comunicação entre processos não relacionados.
    
- Filas de Mensagens: Mensagens formatadas com tipo, armazenadas pelo kernel.
    
- Memória Compartilhada: Segmento de memória acessível por múltiplos processos, requerendo sincronização explícita (ex.: semáforos).