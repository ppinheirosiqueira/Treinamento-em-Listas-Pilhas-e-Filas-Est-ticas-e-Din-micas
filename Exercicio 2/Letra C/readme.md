# Treinamento em Listas, Pilhas e Filas Estáticas e Dinâmicas

[![Linguagem C](https://img.shields.io/badge/Linguagem-C-green.svg)](https://devdocs.io/c/)
[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![ISO](https://img.shields.io/badge/ISO-Linux-blueviolet)

## Conteúdos

<p align="center">
 <a href="#apresentação">Apresentação</a> •
 <a href="#lógica">Lógica</a> •
 <a href="#exemplo">Exemplo</a> • 
 <a href="#compilação-e-execução">Compilação e Execução</a> • 
 <a href="#autores">Autores</a> • 
</p>

---

## Apresentação

Este é um subexercício de uma Lista de Exercícios, aqui só trataremos do subexercício C. 

O enunciado deste subexercício é o seguinte:

    C) Elabore uma função que receba uma pilha P1 com 20 posições preenchidas por números inteiros <u>aleatórios</u> entre 1 e 99. Para cada número da pilha, utilize a função <i>totiente</i> de Euler para encontrar para esse número os co-primos. Mostre-os na tela como resultado de sua execução.

Com isso, foi trabalhada a lógica abaixo, que provou ter tido êxito apresentando uma solução plausível para este problema!

## Lógica

Um número A é co-primo de B quando o número 1 é o Máximo Divisor Comum entre eles. Ou seja, para o exercício em questão é necessário checar todos os divisores de um número e compará-lo com os divisores do outro número. Uma boa forma de checar se esta função foi feita corretamente, é checar se todos os números abaixo de um número primo são co-primos desse número primo. Como um número primo, por definição, só pode ser dividido por 1 e ele mesmo, todos os outros números são co-primos de um número primo.

Ao iniciarmos o programa, criamos a pilha com 20 valores aleatórios como pedido. Após isso, essa pilha é jogada em uma função que sempre retirará o valor do topo e retornará os valores co-primos.

Para isso, é feita uma checagem de todos os inteiros menores que este número retirado do topo da pilha. Esta checagem é se o maior divisor comum entre ambos é igual a 1 ou não. Se for igual a 1, esse valor é mostrado na tela junto dos outros, dado que isso significa que são co-primos.

Para a checagem do maior divisor comum foi utilizada uma função recursiva bastante utilizada na internet. Nela existem dois valores, A e B, sempre o valor de A é checado, se esse valor for igual a 0, então é retornado o valor de B. Se não, é mandado novamente para a mesma função, porém com os valores de B % A e A. Para melhor exemplificação fica a tabela:


|Iteração| A   |  B  |                     
|--------| ----| --- |
|1       | 10  | 3   |
|2       | 3   | 10  |
|3       | 1   | 3   |    
|4       | 0   | 1   |    


|Iteração| A   |  B  |                     
|--------| ----| --- |
|1       | 4   | 2   |
|2       | 2   | 4   |
|3       | 0   | 2   |    

Como pode ver, o Maior Divisor Comum entre 3 e 10 é 1, então são co-primos, porém o Maior Divisor Comum entre 2 e 4 é 2, então não são co-primos.
---

## Exemplo

### Saída

<img src="imgs/Saída.png"/>

---

## Compilação e Execução

O programa feito de acordo com a proposta possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             


---

## Autores

Elaborado por [Henrique Souza Fagundes](https://github.com/ohenriquesouza), [Joao Pedro Martin Espíndola](https://github.com/JoaoMEspindola?tab=repositories), [Pedro Henrique Louback Campos](https://github.com/PedroLouback) e [Pedro Pinheiro](https://github.com/ppinheirosiqueira) 

Alunos do 3° periodo do curso de `Engenharia da Computação` no [CEFET-MG](https://www.cefetmg.br)
