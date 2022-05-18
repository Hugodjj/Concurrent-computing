# Laboratório 5

## Atividade 1

> O resultado foi como o esperado no caso base (3 threads, 2A's e 1B) a thread A printa hello antes da thread B printar bye.<br>
> <br>No segundo caso com 1 thread A e 1 thread B, o programa não finaliza. Isso acontece por dois motivos, a thread A executa antes da thread B começar, além disso, com apenas 1 thread A, a variável global x nunca chegará a ser 2.<br>

### <br>Com duas threads B's, 3 situações podem acontecer.<br>
> 1° Situação: Tudo ocorre normalmente, printando dois hello's e dois bye's.<br>
> 2° Situação: Apeanas uma thread B exetua. Como o programa so emite 1 sinal de desbloqueio, apenas 1 bye é printado quando x == 2 e programa encerra.<br>
> 3° Situação: 2 hello's são printados e apenas 1 bye é printado e o programa nunca termina.<br>

## Atividade 2

> Sim, tudo ocorreu como esperado. As threads A printam bye após a B printar hello.

## Atividade 3

> Não. A thread B as vezes printa numeros como 25, 23 e 38.<br>
> Sim. Podemos porque utilizando o while o programa vai sempre repetir a verificação enquanto com if, ele só verifica uma vez.<br>
>Sim. Todas as execuções foram corretas justamente por causa do while.
