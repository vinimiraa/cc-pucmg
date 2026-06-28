# **Estudo Dirigido – Respostas**

## **1. Engenharia de Software e Economia**

Engenharia de Software é a disciplina que aplica princípios, métodos e ferramentas de engenharia ao desenvolvimento e manutenção de software.  
Sua principal preocupação econômica é **reduzir custos de desenvolvimento e manutenção**, aumentando **produtividade, confiabilidade e qualidade**, fatores essenciais para a competitividade de nações desenvolvidas.

<br>

## **2. Verificação vs. Validação (V&V)**

- **Verificação**: “Estamos construindo o produto certo?”. Foca em garantir que o software **está conforme as especificações**.
    
- **Validação**: “Estamos construindo o produto certo?”. Foca em garantir que o software **atende às necessidades do usuário**.  
    Objetivo geral do V&V: **assegurar qualidade**, detectando falhas antes da entrega.

<br>

## **3. Modelos de Processo**

**Desvantagem do Modelo Cascata**: pouca flexibilidade; mudanças são caras porque requisitos só são totalmente definidos no início.  
**Benefício do Incremental**: permite **feedback contínuo** e entrega funcional parcial, reduzindo riscos e acomodando mudanças.

<br>

## **4. Arquitetura Orientada à Reutilização**

- **Sistema COTS**: _Commercial Off-The-Shelf_ — software pronto adquirido e integrado em vez de desenvolvido do zero.
    
- **Etapas do processo orientado à reutilização**:
    
    1. Análise de requisitos baseada em componentes existentes
        
    2. Busca e avaliação de componentes
        
    3. Adaptação/integração dos componentes
        
    4. Desenvolvimento adicional necessário

<br>

## **5. Requisitos Funcionais vs. Não Funcionais**

- **Funcionais**: descrevem o que o sistema deve fazer (serviços, comportamentos).
    
- **Não funcionais**: impõem restrições de qualidade, desempenho, segurança, usabilidade.  
    **Exemplo verificável**: “O sistema deve responder em **menos de 2 segundos** para 95% das requisições”.

<br>

## **6. Elicitação de Requisitos**

Três técnicas:

1. **Entrevistas**
    
2. **Observação**
    
3. **Workshops/Brainstorming**
    

Cenários ou histórias de usuário ajudam a **contextualizar necessidades reais**, mostrando como o usuário interage com o sistema em situações específicas.

<br>

## **7. Histórias de Usuário**

São descrições curtas do tipo: _“Como <usuário>, quero para <benefício>”_.  
O cliente define as histórias de cada incremento, priorizando o que deve ser implementado na próxima versão.

<br>

## **8. Práticas do Extreme Programming**

Duas práticas que promovem compartilhamento e revisão contínua:

- **Programação em Par (Pair Programming)**
    
- **Código Coletivo (Collective Code Ownership)**

<br>

## **9. Gestão Ágil (Scrum)**

Três fases principais (fora o Sprint):

1. **Planejamento** (Sprint Planning)
    
2. **Revisão** (Sprint Review)
    
3. **Retrospectiva** (Sprint Retrospective)

**Função do Scrum Master**: remover impedimentos, garantir aplicação correta do Scrum e facilitar o fluxo de trabalho.

<br>

## **10. Aplicação de Personas**

Personas ajudam a:

- orientar escolhas de design baseadas em **usuários reais**, não suposições
    
- validar decisões de interface (UX)
    
- priorizar funcionalidades conforme o comportamento esperado do usuário ideal

<br>

## **11. Níveis de Reutilização de Software**

Do mais abstrato ao mais concreto:

1. **Reuso de conhecimento** (padrões, princípios)
    
2. **Reuso de componentes** (bibliotecas, frameworks)
    
3. **Reuso de aplicações** (COTS, subsistemas)
    
4. **Reuso de sistemas completos** (SaaS, sistemas configuráveis)

<br>

## **12. IoC e Injeção de Dependência**

IoC é um princípio em que o **fluxo de controle é invertido**, e o framework controla a criação/coordenação.  
DI é uma forma de implementar IoC, fornecendo dependências de fora para dentro.  
**Benefício para testes**: facilita substituição por _mocks_, permitindo testes unitários independentes.

<br>

## **13. Padrão Pipe and Filter**

Arquitetura em cadeia onde _filtros_ processam dados e _pipes_ conectam os filtros.  
Adequado para **processamento sequencial de dados**, como compiladores, transformações de stream, pipelines de processamento.

<br>

## **14. Microserviços vs. SOA**

**SOA**: integração de grandes sistemas corporativos; escopo organizacional amplo.  
**Microserviços**: serviços pequenos, independentes e implantáveis separadamente.  
**APIs** substituem o ESB, reduzindo acoplamento e permitindo comunicação leve (REST/HTTP).

<br>

## **15. Padrões de Design vs. Arquiteturais**

- **Design Pattern**: solução para problemas recorrentes de design de classes. Ex.: _Factory Method_.
    
- **Arquitetural**: define estrutura macro do sistema. Ex.: _MVC_, _Microservices_.

<br>

## **16. TDD**

TDD é desenvolvimento orientado a testes, criando testes antes do código.  
Ciclo (Red → Green → Refactor):

1. **Red**: escrever teste que falha
    
2. **Green**: implementar código mínimo para passar
    
3. **Refactor**: melhorar o código mantendo testes verdes

Benefício: facilita encontrar erros cedo por testes pequenos e isolados.

<br>

## **17. Integração Contínua (CI)**

CI executa _build_ e testes automaticamente a cada mudança.  
Promove qualidade ao:

- detectar erros rapidamente
    
- prevenir regressões
    
- aumentar confiança na base de código por testes automatizados constantes

<br>

## **18. Maturidade de Processos (CMMI / MPS.BR)**

Avaliam **processos organizacionais**, mensurando capacidade, previsibilidade e qualidade.  
Nível mais alto do MPS.BR: **A – Em Otimização**, focado em **melhoria contínua** baseada em métricas.

<br>

## **19. Refatoração vs. Otimização**

- **Refatoração**: melhora estrutura sem mudar comportamento externo.
    
- **Otimização**: melhora desempenho, podendo alterar estrutura interna.

Citação de Knuth:  
**“Premature optimization is the root of all evil.”** — otimizar só quando necessário e no momento certo.

<br>

## **20. Gerenciamento de Configuração**

Três atividades principais:

1. **Controle de versões**
    
2. **Gerenciamento de mudanças**
    
3. **Auditoria/identificação de configurações**

Garantem integridade, rastreabilidade e consistência do sistema.
