<h1>Laboratório 10 - Leitores e escritores usando semáforos em C</h1>

### (a) Quais devem ser os valores iniciais dos semáforos (em_e, em_l, escr, leit) para que o algoritmo funcione corretamente?

Para o algoritmo funcionar corretamente, todos os semáforos devem ser inicializados com 1.

### (b) É possível simplificar esse codigo (reduzir o uso dos mecanismos de sincronizacão)?

Utilizando semáforos, acredito que não porque os 4 semáforos são necessários para haver sincronização entre as threads leitoras-escritoras e também internamente entre leitoras-leitoras e escritoras-escritoras.

### (c) Implemente um programa em C para experimentar esse algoritmo. Inclua mensagens de log para acompanhar a execução e verificar a sua corretude. Teste seu programa variando o numero de threads “leitoras” e “escritoras”. Certifique-se  ́que ele funciona em todos os casos.
## Exemplo de saída do programa
### 4 Threads leitoras 2 Threads escritoras

``` 
L[1] quer ler
L[3] quer ler     
L[3] esta lendo   
L[1] esta lendo   
L[4] quer ler     
L[4] esta lendo   
E[1] quer escrever
E[2] quer escrever
L[2] quer ler     
L[4] terminou de ler
L[1] terminou de ler
L[1] quer ler       
L[4] quer ler       
L[3] terminou de ler
L[3] quer ler
E[1] esta escrevendo
E[1] terminou de escrever
E[2] esta escrevendo
E[2] terminou de escrever
L[2] esta lendo
L[1] esta lendo
L[4] esta lendo
L[3] esta lendo
L[3] terminou de ler
L[3] quer ler
L[3] esta lendo
L[2] terminou de ler
L[2] quer ler
L[2] esta lendo
L[4] terminou de ler
L[4] quer ler
L[4] esta lendo
E[1] quer escrever
L[1] terminou de ler
L[1] quer ler
E[2] quer escrever
L[2] terminou de ler
L[4] terminou de ler
L[4] quer ler
L[2] quer ler
L[3] terminou de ler
E[1] esta escrevendo
E[1] terminou de escrever
L[3] quer ler
E[2] esta escrevendo
E[2] terminou de escrever
L[1] esta lendo
L[4] esta lendo
L[3] esta lendo
L[2] esta lendo
L[3] terminou de ler
L[2] terminou de ler
L[2] quer ler
L[2] esta lendo
E[2] quer escrever
E[1] quer escrever
L[3] quer ler
L[4] terminou de ler
L[4] quer ler
L[1] terminou de ler
L[1] quer ler

```

### 4 Threads leitoras 4 Threads escritoras
```
L[1] quer ler
L[2] quer ler
L[2] esta lendo
L[1] esta lendo
L[4] quer ler
L[4] esta lendo
L[3] quer ler
L[3] esta lendo
E[3] quer escrever
E[4] quer escrever
E[1] quer escrever
E[2] quer escrever
L[3] terminou de ler
L[3] quer ler
L[2] terminou de ler
L[2] quer ler
L[4] terminou de ler
L[4] quer ler
L[1] terminou de ler
L[1] quer ler
E[3] esta escrevendo
E[3] terminou de escrever
E[4] esta escrevendo
E[4] terminou de escrever
E[1] esta escrevendo
E[1] terminou de escrever
E[2] esta escrevendo
E[2] terminou de escrever
L[3] esta lendo
L[2] esta lendo
L[4] esta lendo
L[1] esta lendo
E[2] quer escrever
L[1] terminou de ler
L[1] quer ler
L[3] terminou de ler
L[3] quer ler
E[1] quer escrever
E[3] quer escrever
E[4] quer escrever
L[4] terminou de ler
L[4] quer ler
L[2] terminou de ler
L[2] quer ler
E[2] esta escrevendo
E[2] terminou de escrever
E[1] esta escrevendo
E[1] terminou de escrever
E[3] esta escrevendo
E[3] terminou de escrever
E[4] esta escrevendo
E[4] terminou de escrever
L[1] esta lendo
L[3] esta lendo
L[4] esta lendo
L[2] esta lendo
L[2] terminou de ler
L[2] quer ler
L[3] terminou de ler
L[3] quer ler
L[3] esta lendo
E[3] quer escrever
E[1] quer escrever
E[2] quer escrever
L[4] terminou de ler
L[2] esta lendo
L[1] terminou de ler
L[1] quer ler
L[4] quer ler
E[4] quer escrever


```
### 2 Threads leitoras 3 Threads escritoras
```L[1] quer ler
L[1] esta lendo   
E[2] quer escrever
L[2] quer ler     
E[1] quer escrever
E[3] quer escrever
L[1] terminou de ler
E[2] esta escrevendo     
E[2] terminou de escrever
L[1] quer ler
E[1] esta escrevendo
E[1] terminou de escrever
E[3] esta escrevendo
E[3] terminou de escrever
L[2] esta lendo
L[1] esta lendo
L[1] terminou de ler
L[2] terminou de ler
L[2] quer ler
E[1] quer escrever
E[2] quer escrever
L[1] quer ler
E[3] quer escrever
L[2] esta lendo
L[2] terminou de ler
L[2] quer ler
E[1] esta escrevendo     
E[1] terminou de escrever
E[2] esta escrevendo     
E[2] terminou de escrever
E[3] esta escrevendo     
E[3] terminou de escrever
L[1] esta lendo
L[2] esta lendo```
