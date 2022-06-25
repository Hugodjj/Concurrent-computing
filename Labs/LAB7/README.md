<h1>Laboratório 7 - Introduzir a programacão concorrente em Java</h1>
 
### ATV.1:
## Resposta:

Há alteração na ordem de execução das threads porque não estamos utilizando exclusão mutua entre as threads.

Com as linhas 43 – 46 comentadas o programa não espera as threads terminarem de executar antes de printar "Finalizou”. Isso está ocorrendo porque as linhas 43 – 46 que são as responsáveis por esse controle estão comentadas.

Após descomentar as linhas 43 – 46, esse problema é resolvido.

### ATV.2:
## Resposta:

//

### ATV.3:
## Resposta:

A sessão crítica do código é o incremento da variável global s, onde as duas threads podem querer trabalhar em simultâneo, na mesma variável, lendo e escrevendo.

A saída esperada era 200 000, ja que cada thread executa o incremento em s 100 000 vezes. A saída foi correta porque utilizamos os métodos de sincronização "public synchronized" que tem o mesmo objetivo dos locks em C.

### ATV.4:
## Resposta:

Ao comentar as linhas 17 – 23 e descomentar as linhas 27 – 33, o resultado não é sempre o mesmo porque agora a condição de corrida foi liberada com a exclusão dos métodos "public synchronized".
