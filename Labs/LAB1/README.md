<h1>Laboratório 1 - Introdução a biblioteca pthread</h1>
 
### Ex01: Mostrar como criar um programa concorrente em C usando a bibliotecapthread - Hello.c

> Execute o programa varias vezes (ex.: ./hello) e observe os resultados impressos na tela. Ha mudanças na ordem de execução das threads? Por que isso ocorre?

## Resposta:

Sim, há mudanças na ordem de execução das threads. Isso ocorre, pois, o tempo que cada thread leva para executar difere, ou seja, as threads não seguem um fluxo de execução linear. Sendo assim, pode acontecer de duas ou mais threads serem criadas antes da execução do primeiro hello world e assim por diante. Como não definimos uma ordem de execução das threads, o computador decide qual ira ser executada primeiro e em, qual ordem.

### Ex02: Mostrar como passar um argumento para uma thread - Hello_arg.c

> Execute o programa varias vezes e observe os resultados impressos na tela. Qualfoi a diferença em relação ao programa anterior?

## Resposta:

Em execução, não há mudanças. A diferença é que podemos agora visualizar a ordem de execução do hello world de cada thread, visto que agora estamos utilizando uma variável auxiliar "threads".

### Ex03: Mostrar como passar mais de um argumento para uma thread - Hello_args.c

> Execute o programa varias vezes e observe os resultados impressos na tela. O programa funcionou como esperado?

## Resposta:

Sim. Funciona corretamente, alocando dois espaços de memória para cada thread. Dessa forma, a thread consegue executar a função utilizando ponteiros para acessar essas posições de memória.

### Ex04: Mostrar como fazer a thread principal (main) aguardar as outras threads terminarem - Hello_join.c

> Execute o programa varias vezes e observe os resultados impressos na tela. O que aconteceu de diferente em relação as versões/execuções anteriores?

## Resposta:

Nos exercícios anteriores, às vezes podia acontecer da thread principal ser finalizada entre threads secundárias. No exercício atual, utilizando "pthread_join" a thread principal só termina após todas as outra threads existentes serem finalizadas.
