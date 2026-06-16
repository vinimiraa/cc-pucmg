-- Script para Criação do Banco de Dados

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

DROP SCHEMA IF EXISTS `SD` ;

CREATE SCHEMA IF NOT EXISTS `SD` DEFAULT CHARACTER SET utf8 ;
USE `SD` ;

DROP TABLE IF EXISTS `Auxilia` ;
DROP TABLE IF EXISTS `Beneficiario` ;
DROP TABLE IF EXISTS `CampanhaDoacao` ;
DROP TABLE IF EXISTS `Contem` ;
DROP TABLE IF EXISTS `Doacao` ;
DROP TABLE IF EXISTS `Doador` ;
DROP TABLE IF EXISTS `Necessidade` ;
DROP TABLE IF EXISTS `ObjetoDoavel` ;
DROP TABLE IF EXISTS `PontoColeta` ;
DROP TABLE IF EXISTS `Voluntario` ;

-- Criação de Tabelas

CREATE TABLE IF NOT EXISTS `Auxilia` (
    `Voluntario` INT NOT NULL,
    `Doacao` INT NOT NULL,
    PRIMARY KEY (`Voluntario`, `Doacao`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `Beneficiario` (
    `idBeneficiario` INT NOT NULL AUTO_INCREMENT,
    `Nome` VARCHAR(255) NULL,
    `Idade` TINYINT(1) NULL,
    `Genero` CHAR(1) NULL,
    `Descricao` VARCHAR(255) NULL,
    PRIMARY KEY (`idBeneficiario`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `CampanhaDoacao` (
    `idCampanhaDoacao` INT NOT NULL AUTO_INCREMENT,
    `Nome` VARCHAR(255) NULL,
    `DataInicio` DATE NULL,
    `DataTermino` DATE NULL,
    `Descricao` VARCHAR(255) NULL,
    PRIMARY KEY (`idCampanhaDoacao`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `Contem` (
    `ObjetoDoavel` INT NOT NULL,
    `Doacao` INT NOT NULL,
    PRIMARY KEY (`ObjetoDoavel`, `Doacao`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `Doacao` (
    `idDoacao` INT NOT NULL AUTO_INCREMENT,
    `DataEntrega` DATE NULL,
    `DataCriacao` DATE NULL,
    `Doador` INT NOT NULL,
    `Beneficiario` INT NOT NULL,
    `CampanhaDoacao` INT NOT NULL,
    PRIMARY KEY (`idDoacao`, `Doador`, `Beneficiario`, `CampanhaDoacao`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `Doador` (
    `idDoador` INT NOT NULL AUTO_INCREMENT,
    `Nome` VARCHAR(255) NULL,
    `Telefone` VARCHAR(20) NULL,
    `Email` VARCHAR(255) NULL,
    `Logradouro` VARCHAR(120) NULL,
    `Numero` VARCHAR(15) NULL,
    `Complemento` VARCHAR(80) NULL,
    `Bairro` VARCHAR(80) NULL,
    `Cidade` VARCHAR(80) NULL,
    `Estado` VARCHAR(2) NULL,
    `CEP` VARCHAR(8) NULL,
    PRIMARY KEY (`idDoador`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `Necessidade` (
    `idNecessidade` INT NOT NULL AUTO_INCREMENT,
    `Descricao` VARCHAR(255) NULL,
    `CampanhaDoacao` INT NOT NULL,
    `Beneficiario` INT NOT NULL,
    PRIMARY KEY (`idNecessidade`, `CampanhaDoacao`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `ObjetoDoavel` (
    `idObjetoDoavel` INT NOT NULL AUTO_INCREMENT,
    `Nome` VARCHAR(255) NULL,
    `Categoria` VARCHAR(80) NULL,
    `Descricao` VARCHAR(255) NULL,
    `PontoColeta` INT NOT NULL,
    PRIMARY KEY (`idObjetoDoavel`, `PontoColeta`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `PontoColeta` (
    `idPontoColeta` INT NOT NULL,
    `Responsavel` VARCHAR(255) NULL,
    `Logradouro` VARCHAR(45) NULL,
    `Numero` VARCHAR(45) NULL,
    `Complemento` VARCHAR(45) NULL,
    `Bairro` VARCHAR(45) NULL,
    `Cidade` VARCHAR(45) NULL,
    `Estado` VARCHAR(45) NULL,
    `CEP` VARCHAR(45) NULL,
    PRIMARY KEY (`idPontoColeta`)
) ENGINE = InnoDB;

CREATE TABLE IF NOT EXISTS `Voluntario` (
    `idVoluntario` INT NOT NULL AUTO_INCREMENT,
    `Nome` VARCHAR(255) NULL,
    `Email` VARCHAR(255) NULL,
    `Telefone` VARCHAR(20) NULL,
    PRIMARY KEY (`idVoluntario`)
) ENGINE = InnoDB;

-- Criação de Restrições

ALTER TABLE `Auxilia` ADD CONSTRAINT `FK_Auxilia_Voluntario`
    FOREIGN KEY (`Voluntario`)
    REFERENCES `Voluntario` (`idVoluntario`)
    ON DELETE CASCADE
    ON UPDATE CASCADE;

ALTER TABLE `Auxilia` ADD CONSTRAINT `FK_Auxilia_Doacao`
    FOREIGN KEY (`Doacao`)
    REFERENCES `Doacao` (`idDoacao`)
    ON DELETE CASCADE
    ON UPDATE CASCADE;

ALTER TABLE `Contem` ADD CONSTRAINT `FK_Contem_ObjetoDoavel`
    FOREIGN KEY (`ObjetoDoavel`)
    REFERENCES `ObjetoDoavel` (`idObjetoDoavel`)
    ON DELETE NO ACTION
    ON UPDATE CASCADE;

ALTER TABLE `Contem` ADD CONSTRAINT `FK_Contem_Doacao`
    FOREIGN KEY (`Doacao`)
    REFERENCES `Doacao` (`idDoacao`)
    ON DELETE CASCADE
    ON UPDATE CASCADE;

ALTER TABLE `Doacao` ADD CONSTRAINT `FK_Doacao_Doador`
    FOREIGN KEY (`Doador`)
    REFERENCES `Doador` (`idDoador`)
    ON DELETE NO ACTION
    ON UPDATE CASCADE;

ALTER TABLE `Doacao` ADD CONSTRAINT `FK_Doacao_Beneficiario`
    FOREIGN KEY (`Beneficiario`)
    REFERENCES `Beneficiario` (`idBeneficiario`)
    ON DELETE CASCADE
    ON UPDATE CASCADE;

ALTER TABLE `Doacao` ADD CONSTRAINT `FK_Doacao_CampanhaDoacao`
    FOREIGN KEY (`CampanhaDoacao`)
    REFERENCES `CampanhaDoacao` (`idCampanhaDoacao`)
    ON DELETE CASCADE
    ON UPDATE CASCADE;

ALTER TABLE `Necessidade` ADD CONSTRAINT `FK_Necessidade_CampanhaDoacao`
    FOREIGN KEY (`CampanhaDoacao`)
    REFERENCES `CampanhaDoacao` (`idCampanhaDoacao`)
    ON DELETE CASCADE
    ON UPDATE CASCADE;

ALTER TABLE `Necessidade` ADD CONSTRAINT `FK_Necessidade_Beneficiario`
    FOREIGN KEY (`Beneficiario`)
    REFERENCES `Beneficiario` (`idBeneficiario`)
    ON DELETE CASCADE
    ON UPDATE CASCADE;

ALTER TABLE `ObjetoDoavel` ADD CONSTRAINT `FK_ObjetoDoavel_PontoColeta`
    FOREIGN KEY (`PontoColeta`)
    REFERENCES `PontoColeta` (`idPontoColeta`)
    ON DELETE NO ACTION
    ON UPDATE CASCADE;

-- Criação de Índices

CREATE INDEX `IDX_FK_Auxilia_Doacao` ON `Auxilia` (`Doacao` ASC) VISIBLE;

CREATE INDEX `IDX_FK_Auxilia_Voluntario` ON `Auxilia` (`Voluntario` ASC) VISIBLE;

CREATE INDEX `IDX_FK_Contem_Doacao` ON `Contem` (`Doacao` ASC) VISIBLE;

CREATE INDEX `IDX_FK_Contem_ObjetoDoavel` ON `Contem` (`ObjetoDoavel` ASC) VISIBLE;

CREATE INDEX `IDX_FK_Doacao_Doador` ON `Doacao` (`Doador` ASC) VISIBLE;

CREATE INDEX `IDX_FK_Doacao_Beneficiario` ON `Doacao` (`Beneficiario` ASC) VISIBLE;

CREATE INDEX `IDX_FK_Doacao_CampanhaDoacao` ON `Doacao` (`CampanhaDoacao` ASC) VISIBLE;

CREATE INDEX `IDX_FK_Necessidade_CampanhaDoacao` ON `Necessidade` (`CampanhaDoacao` ASC) INVISIBLE;

CREATE INDEX `IDX_FK_Necessidade_Beneficiario` ON `Necessidade` (`Beneficiario` ASC) INVISIBLE;

CREATE INDEX `IDX_FK_ObjetoDoavel_PontoColeta` ON `ObjetoDoavel` (`PontoColeta` ASC) VISIBLE;

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
