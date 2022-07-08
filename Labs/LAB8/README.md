<h1>Laboratório 8 - Leitores e escritores usando monitores em Java</h1>

Esse código possui 3 tipos de threads, a thread Leitor que apenas lê o valor da variável compartilhada e diz se é impar ou par. A thread Escritor que incrementa
o valor da variável compatilhada e a thread Leitor e Escritor que primeiramente lê o valor da variável compartilhada, depois ela escreve na variável atualiza
o valor da variável compartilhada pelo id atual da thread.



## Exemplo de saída do programa

```
le = verificaLE.LE()
le.leitorLendo(1)
le.leitorLendo(3)
le.leitorLendo(2)
@@@ Valor da variavel: 0 @@@
le.leitorSaindo(2)
@@@ Valor da variavel: 0 @@@
le.escritorBloqueado(2)
le.leitorLendo(1)
@@@ Valor da variavel: 0 @@@
le.leitorSaindo(1)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorLendo(4)
le.leitorLendo(3)
le.leitorLendo(2)
le.leitorSaindo(3)
le.escritorBloqueado(3)
@@@ Variavel par @@@
le.leitorSaindo(1)
@@@ Variavel par @@@
le.leitorSaindo(4)
@@@ Variavel par @@@
le.leitorSaindo(3)
@@@ Variavel par @@@
le.leitorSaindo(2)
le.escritorEscrevendo(2)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(3)
le.leitorBloqueado(1)
le.escritorSaindo(1)
le.escritorEscrevendo(3)
le.leitorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorSaindo(3)
le.leitorLendo(1)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(3)
le.leitorLendo(2)
le.leitorLendo(1)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(1)
le.escritorBloqueado(1)
le.leitorLendo(2)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(2)
le.escritorBloqueado(2)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(2)
le.escritorEscrevendo(1)
le.leitorBloqueado(3)
le.escritorSaindo(1)
le.escritorEscrevendo(2)
le.leitorBloqueado(3)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.leitorBloqueado(1)
le.escritorSaindo(2)
le.leitorLendo(3)
le.leitorLendo(1)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorLendo(4)
le.escritorBloqueado(1)
@@@ Variavel impar @@@
le.leitorSaindo(3)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(4)
le.escritorEscrevendo(3)
le.leitorBloqueado(2)
le.leitorBloqueado(3)
le.escritorSaindo(3)
le.escritorEscrevendo(1)
le.leitorBloqueado(3)
le.leitorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.escritorBloqueado(2)
le.escritorSaindo(1)
le.leitorLendo(3)
@@@ Valor da variavel: 1 @@@
le.leitorSaindo(3)
le.escritorEscrevendo(3)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorBloqueado(2)
le.escritorSaindo(3)
le.escritorEscrevendo(2)
le.leitorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.leitorBloqueado(1)
le.escritorSaindo(2)
le.leitorLendo(2)
le.leitorLendo(1)
@@@ Valor da variavel: 4 @@@
le.leitorSaindo(1)
le.escritorBloqueado(1)
le.leitorLendo(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorLendo(3)
@@@ Variavel par @@@
le.leitorSaindo(2)
@@@ Variavel par @@@
le.leitorSaindo(1)
@@@ Variavel par @@@
le.leitorSaindo(3)
le.escritorEscrevendo(1)
le.escritorBloqueado(3)
le.leitorBloqueado(4)
le.leitorBloqueado(1)
le.escritorSaindo(1)
le.escritorEscrevendo(2)
le.leitorBloqueado(1)
le.leitorBloqueado(4)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(3)
le.escritorSaindo(2)
le.leitorLendo(1)
le.leitorLendo(3)
@@@ Valor da variavel: 2 @@@
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.leitorLendo(4)
le.leitorSaindo(3)
le.escritorBloqueado(3)
le.leitorLendo(2)
le.leitorLendo(1)
@@@ Valor da variavel: 2 @@@
le.leitorSaindo(1)
le.escritorBloqueado(1)
@@@ Variavel par @@@
le.leitorSaindo(1)
@@@ Variavel par @@@
le.leitorSaindo(4)
@@@ Variavel par @@@
le.leitorSaindo(2)
le.escritorEscrevendo(2)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(3)
le.leitorBloqueado(3)
le.leitorBloqueado(1)
le.leitorBloqueado(2)
le.escritorSaindo(1)
le.escritorEscrevendo(1)
le.leitorBloqueado(2)
le.leitorBloqueado(1)
le.leitorBloqueado(3)
le.escritorBloqueado(3)
le.escritorBloqueado(3)
le.escritorSaindo(1)
le.leitorLendo(2)
@@@ Valor da variavel: 1 @@@
le.escritorBloqueado(3)
le.escritorBloqueado(3)
le.leitorLendo(3)
le.leitorLendo(1)
le.leitorSaindo(2)
le.escritorBloqueado(2)
le.leitorLendo(2)
le.escritorBloqueado(1)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(3)
le.escritorBloqueado(2)
@@@ Variavel impar @@@
le.leitorSaindo(2)
le.escritorEscrevendo(3)
le.leitorBloqueado(1)
le.escritorSaindo(3)
le.escritorEscrevendo(3)
le.leitorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.leitorBloqueado(4)
le.escritorSaindo(3)
le.leitorLendo(1)
@@@ Valor da variavel: 4 @@@
le.leitorLendo(4)
le.leitorLendo(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorSaindo(1)
le.escritorBloqueado(1)
@@@ Variavel par @@@
@@@ Variavel par @@@
le.leitorSaindo(1)
le.leitorSaindo(4)
le.escritorEscrevendo(2)
le.leitorBloqueado(2)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.leitorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(3)
le.leitorBloqueado(1)
le.escritorSaindo(1)
le.leitorLendo(2)
le.leitorLendo(1)
le.leitorLendo(3)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorLendo(3)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(3)
le.escritorBloqueado(3)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(3)
@@@ Variavel impar @@@
le.leitorSaindo(2)
le.escritorEscrevendo(2)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(3)
le.leitorBloqueado(2)
le.leitorBloqueado(1)
le.escritorSaindo(1)
le.escritorEscrevendo(1)
le.leitorBloqueado(1)
le.leitorBloqueado(2)
le.escritorBloqueado(3)
le.escritorBloqueado(3)
le.escritorSaindo(1)
le.leitorLendo(1)
le.escritorBloqueado(3)
le.escritorBloqueado(3)
le.leitorLendo(2)
@@@ Valor da variavel: 2 @@@
le.leitorSaindo(2)
le.escritorBloqueado(2)
le.leitorLendo(2)
le.leitorLendo(4)
le.leitorLendo(1)
@@@ Valor da variavel: 2 @@@
le.leitorSaindo(1)
le.escritorBloqueado(1)
@@@ Variavel par @@@
le.leitorSaindo(1)
le.escritorBloqueado(2)
@@@ Variavel par @@@
@@@ Variavel par @@@
le.leitorSaindo(4)
le.leitorSaindo(2)
le.escritorEscrevendo(3)
le.escritorBloqueado(1)
le.leitorBloqueado(3)
le.escritorSaindo(3)
le.escritorEscrevendo(3)
le.leitorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.escritorSaindo(3)
le.leitorLendo(3)
le.leitorLendo(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
@@@ Variavel impar @@@
le.leitorSaindo(3)
@@@ Variavel impar @@@
le.leitorSaindo(1)
le.escritorEscrevendo(2)
le.leitorBloqueado(2)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.leitorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.escritorSaindo(1)
le.leitorLendo(2)
le.leitorLendo(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
@@@ Variavel impar @@@
le.leitorSaindo(2)
@@@ Variavel impar @@@
le.leitorSaindo(1)
le.escritorEscrevendo(2)
le.leitorBloqueado(4)
le.leitorBloqueado(1)
le.leitorBloqueado(3)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.leitorBloqueado(3)
le.leitorBloqueado(1)
le.leitorBloqueado(4)
le.escritorBloqueado(3)
le.leitorBloqueado(2)
le.leitorBloqueado(1)
le.leitorBloqueado(3)
le.escritorSaindo(1)
le.leitorLendo(3)
le.leitorLendo(3)
@@@ Valor da variavel: 3 @@@
le.leitorLendo(1)
le.leitorLendo(2)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(2)
le.escritorBloqueado(2)
le.escritorBloqueado(3)
le.leitorLendo(4)
le.leitorLendo(1)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(1)
le.escritorBloqueado(1)
le.leitorSaindo(3)
le.escritorBloqueado(3)
@@@ Variavel impar @@@
le.leitorSaindo(3)
@@@ Variavel impar @@@
le.leitorSaindo(4)
@@@ Variavel impar @@@
le.leitorSaindo(1)
le.escritorEscrevendo(2)
le.leitorBloqueado(2)
le.escritorBloqueado(1)
le.escritorSaindo(2)
le.escritorEscrevendo(3)
le.escritorBloqueado(1)
le.leitorBloqueado(2)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.escritorSaindo(3)
le.escritorEscrevendo(1)
le.leitorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.leitorBloqueado(2)
le.escritorSaindo(1)
le.leitorLendo(1)
le.leitorLendo(2)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorLendo(2)
@@@ Valor da variavel: 4 @@@
le.leitorSaindo(2)
le.escritorBloqueado(2)
@@@ Variavel par @@@
le.leitorSaindo(2)
@@@ Variavel par @@@
le.leitorSaindo(1)
le.escritorEscrevendo(3)
le.escritorBloqueado(1)
le.leitorBloqueado(3)
le.escritorSaindo(3)
le.escritorEscrevendo(1)
le.leitorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.leitorBloqueado(4)
le.escritorSaindo(1)
le.leitorLendo(3)
le.leitorLendo(4)
le.leitorLendo(1)
le.escritorBloqueado(2)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.leitorLendo(2)
@@@ Variavel impar @@@
le.leitorSaindo(3)
@@@ Variavel impar @@@
le.leitorSaindo(4)
@@@ Variavel impar @@@
le.leitorSaindo(1)
le.leitorLendo(1)
@@@ Valor da variavel: 1 @@@
le.leitorSaindo(1)
le.escritorBloqueado(1)
@@@ Variavel impar @@@
le.leitorSaindo(2)
le.escritorEscrevendo(2)
le.leitorBloqueado(1)
le.escritorSaindo(2)
le.escritorEscrevendo(2)
le.leitorBloqueado(1)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.leitorBloqueado(3)
le.escritorSaindo(2)
le.leitorLendo(1)
le.leitorLendo(3)
@@@ Valor da variavel: 2 @@@
le.leitorSaindo(3)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
@@@ Variavel par @@@
le.leitorSaindo(1)
le.escritorEscrevendo(3)
le.leitorBloqueado(2)
le.leitorBloqueado(3)
le.escritorSaindo(3)
le.escritorEscrevendo(1)
le.leitorBloqueado(3)
le.leitorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.escritorSaindo(1)
le.leitorLendo(3)
le.leitorLendo(1)
le.escritorBloqueado(2)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.leitorLendo(2)
le.leitorLendo(2)
@@@ Valor da variavel: 4 @@@
le.leitorSaindo(2)
le.escritorBloqueado(2)
le.leitorLendo(4)
@@@ Variavel par @@@
le.leitorSaindo(3)
@@@ Variavel par @@@
le.leitorSaindo(2)
@@@ Variavel par @@@
le.leitorSaindo(1)
@@@ Variavel par @@@
le.leitorSaindo(4)
le.escritorEscrevendo(2)
le.escritorBloqueado(1)
le.escritorSaindo(2)
le.escritorEscrevendo(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorBloqueado(1)
le.escritorSaindo(3)
le.escritorEscrevendo(1)
le.leitorBloqueado(1)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(3)
le.leitorBloqueado(2)
le.escritorSaindo(1)
le.leitorLendo(1)
le.leitorLendo(2)
le.leitorLendo(3)
@@@ Valor da variavel: 7 @@@
le.leitorSaindo(3)
le.escritorBloqueado(3)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(2)
le.escritorEscrevendo(3)
le.escritorBloqueado(2)
le.leitorBloqueado(3)
le.escritorBloqueado(1)
le.escritorSaindo(3)
le.escritorEscrevendo(2)
le.escritorBloqueado(1)
le.leitorBloqueado(3)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorBloqueado(1)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.leitorBloqueado(1)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(3)
le.leitorBloqueado(4)
le.escritorBloqueado(3)
le.escritorSaindo(1)
le.leitorLendo(1)
le.escritorBloqueado(3)
le.leitorLendo(4)
le.leitorLendo(3)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorLendo(2)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(4)
@@@ Variavel impar @@@
le.leitorSaindo(3)
@@@ Variavel impar @@@
le.leitorSaindo(2)
le.escritorEscrevendo(3)
le.escritorBloqueado(1)
le.leitorBloqueado(2)
le.escritorSaindo(3)
le.escritorEscrevendo(2)
le.leitorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(1)
le.leitorBloqueado(1)
le.leitorBloqueado(3)
le.escritorSaindo(2)
le.leitorLendo(2)
@@@ Valor da variavel: 5 @@@
le.leitorSaindo(2)
le.escritorEscrevendo(2)
le.leitorBloqueado(3)
le.leitorBloqueado(1)
le.escritorBloqueado(1)
le.escritorBloqueado(1)
le.escritorSaindo(2)
le.leitorLendo(3)
@@@ Valor da variavel: 2 @@@
le.escritorBloqueado(1)
le.escritorBloqueado(1)
le.leitorLendo(1)
le.leitorSaindo(3)
le.escritorBloqueado(3)
le.leitorLendo(2)
@@@ Variavel par @@@
le.leitorSaindo(1)
@@@ Variavel par @@@
le.leitorSaindo(2)
le.escritorEscrevendo(1)
le.leitorBloqueado(3)
le.escritorBloqueado(2)
le.escritorSaindo(1)
le.escritorEscrevendo(1)
le.escritorBloqueado(2)
le.leitorBloqueado(3)
le.escritorBloqueado(3)
le.leitorBloqueado(1)
le.escritorBloqueado(3)
le.leitorBloqueado(4)
le.leitorBloqueado(2)
le.escritorSaindo(1)
le.escritorEscrevendo(2)
le.leitorBloqueado(2)
le.leitorBloqueado(4)
le.escritorBloqueado(3)
le.leitorBloqueado(1)
le.escritorBloqueado(3)
le.leitorBloqueado(3)
le.escritorBloqueado(1)
le.escritorSaindo(2)
le.leitorLendo(2)
@@@ Valor da variavel: 2 @@@
le.leitorSaindo(2)
le.escritorEscrevendo(2)
le.escritorBloqueado(1)
le.leitorBloqueado(3)
le.escritorBloqueado(3)
le.leitorBloqueado(1)
le.escritorBloqueado(3)
le.leitorBloqueado(4)
le.leitorBloqueado(2)
le.leitorBloqueado(1)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.leitorBloqueado(1)
le.leitorBloqueado(2)
le.leitorBloqueado(4)
le.escritorBloqueado(3)
le.leitorBloqueado(1)
le.escritorBloqueado(3)
le.leitorBloqueado(3)
le.escritorSaindo(1)
le.leitorLendo(1)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(1)
le.escritorEscrevendo(1)
le.leitorBloqueado(3)
le.escritorBloqueado(3)
le.leitorBloqueado(1)
le.escritorBloqueado(3)
le.leitorBloqueado(4)
le.leitorBloqueado(2)
le.escritorSaindo(1)
le.leitorLendo(3)
le.leitorLendo(2)
le.leitorLendo(4)
le.escritorBloqueado(3)
le.leitorLendo(1)
le.escritorBloqueado(3)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorLendo(2)
@@@ Valor da variavel: 1 @@@
le.leitorSaindo(2)
le.escritorBloqueado(2)
@@@ Variavel impar @@@
le.leitorSaindo(3)
@@@ Variavel impar @@@
le.leitorSaindo(2)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(4)
le.escritorEscrevendo(3)
le.leitorBloqueado(1)
le.escritorSaindo(3)
le.escritorEscrevendo(3)
le.leitorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorBloqueado(1)
le.escritorSaindo(3)
le.leitorLendo(1)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(1)
le.escritorEscrevendo(1)
le.leitorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.escritorSaindo(1)
le.leitorLendo(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorLendo(2)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(2)
le.escritorEscrevendo(2)
le.leitorBloqueado(3)
le.leitorBloqueado(1)
le.escritorSaindo(2)
le.escritorEscrevendo(1)
le.leitorBloqueado(1)
le.leitorBloqueado(3)
le.escritorBloqueado(2)
le.escritorBloqueado(3)
le.leitorBloqueado(1)
le.leitorBloqueado(4)
le.escritorSaindo(1)
le.leitorLendo(1)
@@@ Valor da variavel: 3 @@@
le.leitorLendo(4)
le.leitorLendo(1)
le.escritorBloqueado(3)
le.escritorBloqueado(2)
le.leitorLendo(3)
le.leitorSaindo(1)
le.escritorBloqueado(1)
le.leitorLendo(3)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(3)
le.escritorBloqueado(3)
le.leitorLendo(2)
@@@ Variavel impar @@@
le.leitorSaindo(4)
@@@ Variavel impar @@@
le.leitorSaindo(1)
@@@ Variavel impar @@@
le.leitorSaindo(3)
le.escritorBloqueado(1)
le.leitorLendo(2)
@@@ Valor da variavel: 3 @@@
le.leitorSaindo(2)
le.escritorBloqueado(2)
@@@ Variavel impar @@@
le.leitorSaindo(2)
le.escritorEscrevendo(3)
le.leitorBloqueado(1)
le.escritorSaindo(3)
le.escritorEscrevendo(2)
le.leitorBloqueado(1)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorSaindo(2)
le.leitorLendo(1)
le.escritorBloqueado(1)
le.escritorBloqueado(3)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
@@@ Variavel impar @@@
le.leitorSaindo(1)
le.escritorEscrevendo(1)
le.leitorBloqueado(2)
le.leitorBloqueado(3)
le.escritorSaindo(1)
le.escritorEscrevendo(3)
le.leitorBloqueado(3)
le.leitorBloqueado(2)
le.escritorBloqueado(2)
le.escritorBloqueado(1)
le.leitorBloqueado(1)
le.escritorSaindo(3)
le.leitorLendo(3)
le.leitorLendo(1)
le.escritorBloqueado(1)
le.escritorBloqueado(2)
le.leitorLendo(2)
le.escritorBloqueado(2)
le.leitorLendo(4)
le.escritorBloqueado(3)
le.leitorLendo(1)
@@@ Valor da variavel: 3 @@@
```