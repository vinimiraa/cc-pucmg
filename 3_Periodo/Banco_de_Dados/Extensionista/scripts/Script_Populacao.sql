-- Script para População Inicial e Fictícia do Banco de Dados

USE `SD`;

-- Inserindo dados na tabela PontoColeta

INSERT INTO `PontoColeta` (`idPontoColeta`, `Responsavel`, `Logradouro`, `Numero`, `Complemento`, `Bairro`, `Cidade`, `Estado`, `CEP`)
VALUES
(1, 'João Silva', 'Rua A', '123', 'Próximo ao mercado', 'Centro', 'São Paulo', 'SP', '01001001'),
(2, 'Maria Oliveira', 'Avenida B', '456', 'Sala 2', 'Jardim das Flores', 'Rio de Janeiro', 'RJ', '20020020');

-- Inserindo dados na tabela ObjetoDoavel

INSERT INTO `ObjetoDoavel` (`idObjetoDoavel`, `Nome`, `Categoria`, `Descricao`, `PontoColeta`)
VALUES
(1, 'Cobertor', 'Roupas', 'Cobertor de solteiro em bom estado', 1),
(2, 'Cesta Básica', 'Alimentos', 'Cesta básica com alimentos não perecíveis', 2),
(3, 'Brinquedo', 'Infantil', 'Carrinho de brinquedo para crianças', 1);

-- Inserindo dados na tabela Beneficiario

INSERT INTO `Beneficiario` (`idBeneficiario`, `Nome`, `Idade`, `Genero`, `Descricao`)
VALUES
(1, 'Carlos Pereira', 45, 'M', 'Desempregado em situação de rua'),
(2, 'Ana Santos', 30, 'F', 'Mãe solteira com dois filhos pequenos'),
(3, 'José Lima', 60, 'M', 'Idoso necessitando de auxílio básico');

-- Inserindo dados na tabela Doador

INSERT INTO `Doador` (`idDoador`, `Nome`, `Telefone`, `Email`, `Logradouro`, `Numero`, `Complemento`, `Bairro`, `Cidade`, `Estado`, `CEP`)
VALUES
(1, 'Fernanda Costa', '(11) 99999-1111', 'fernanda@gmail.com', 'Rua das Palmeiras', '45', NULL, 'Centro', 'São Paulo', 'SP', '12345678'),
(2, 'Roberto Souza', '(21) 98888-2222', 'roberto@gmail.com', 'Avenida Paulista', '678', 'Apto 45', 'Bela Vista', 'São Paulo', 'SP', '23456789');

-- Inserindo dados na tabela CampanhaDoacao

INSERT INTO `CampanhaDoacao` (`idCampanhaDoacao`, `Nome`, `DataInicio`, `DataTermino`, `Descricao`)
VALUES
(1, 'Campanha do Agasalho', '2024-11-01', '2024-11-30', 'Arrecadação de agasalhos para o inverno'),
(2, 'Natal Solidário', '2024-12-01', '2024-12-24', 'Doações de brinquedos e alimentos para o Natal');

-- Inserindo dados na tabela Doacao

INSERT INTO `Doacao` (`idDoacao`, `DataEntrega`, `DataCriacao`, `Doador`, `Beneficiario`, `CampanhaDoacao`)
VALUES
(1, '2024-11-10', '2024-11-05', 1, 1, 1),
(2, '2024-11-15', '2024-11-12', 2, 2, 2);

-- Inserindo dados na tabela Contem

INSERT INTO `Contem` (`ObjetoDoavel`, `Doacao`)
VALUES
(1, 1),
(2, 2),
(3, 1);

-- Inserindo dados na tabela Voluntario

INSERT INTO `Voluntario` (`idVoluntario`, `Nome`, `Email`, `Telefone`)
VALUES
(1, 'Julia Almeida', 'julia@voluntarios.com', '(11) 97777-3333'),
(2, 'Pedro Gonçalves', 'pedro@voluntarios.com', '(21) 98888-4444');

-- Inserindo dados na tabela Auxilia

INSERT INTO `Auxilia` (`Voluntario`, `Doacao`)
VALUES
(1, 1),
(2, 2);

-- Inserindo dados na tabela Necessidade

INSERT INTO `Necessidade` (`idNecessidade`, `Descricao`, `CampanhaDoacao`, `Beneficiario`)
VALUES
(1, 'Cobertores para o inverno', 1, 1),
(2, 'Alimentos para mães solteiras', 2, 2),
(3, 'Brinquedos para crianças carentes', 2, 2);

-- Consultar cada Tabela de Dados

-- Mostrar dados da tabela Beneficiario

-- SELECT * FROM Beneficiario;

-- Mostrar dados da tabela CampanhaDoacao

-- SELECT * FROM CampanhaDoacao;

-- Mostrar dados da tabela Doador

SELECT * FROM Doador;

-- Mostrar dados da tabela Doacao

-- SELECT * FROM Doacao;

-- Mostrar dados da tabela Voluntario

-- SELECT * FROM Voluntario;

-- Mostrar dados da tabela PontoColeta

-- SELECT * FROM PontoColeta;

-- Mostrar dados da tabela ObjetoDoavel

-- SELECT * FROM ObjetoDoavel;

-- Mostrar dados da tabela Necessidade

-- SELECT * FROM Necessidade;

-- Mostrar dados da tabela Contem

-- SELECT * FROM Contem;

-- Mostrar dados da tabela Auxilia

-- SELECT * FROM Auxilia;

