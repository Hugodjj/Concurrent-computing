<h1>Resultados das execuções</h1>

Estamos avaliando os tempos de execução sequencial e concorrente de um programa,
que recebe um vetor de números reais e retorna o maior e menor número presente nesse array.

## Tempos após 5 execuções (em segundos)

<table>
  
  <tr>
    <th>Tamanho do vetor</th>
    <th>Sequencial</th>
    <th>Concorrente 1 thread</th>
    <th>Concorrente 2 threads</th>
    <th>Concorrente 4 threads</th>
  </tr>
  <tr>
    <td>10^5</td>
    <td>0.000325</td>
    <td>0.000619</td>
    <td>0.000327</td>
    <td>0.000492</td>
  </tr>
  <tr>
    <td>10^7</td>
    <td>0.032687</td>
    <td>0.34408</td>
    <td>0.18714</td>
    <td>0.028859</td>
  </tr>
  <tr>
    <td>10^8</td>
    <td>0.327552</td>
    <td>0.338934</td>
    <td>0.234045</td>
    <td>0.179879</td>
  </tr>
</table>

## Ganho de tempo (em segundos)

<table>
  
  <tr>
    <th>Tamanho do vetor</th>
    <th>Ganho com 1 thread</th>
    <th>Ganho com 2 threads</th>
    <th>Ganho com 4 threads</th>
  </tr>
  <tr>
    <td>10^5</td>
    <td>0.52504</td>
    <td>0.99388</td>
    <td>0.66056</td>
  </tr>
  <tr>
    <td>10^7</td>
    <td>0.09499</td>
    <td>0.17466</td>
    <td>1.13264</td>
  </tr>
  <tr>
    <td>10^8</td>
    <td>0.96641</td>
    <td>1.39952</td>
    <td>1.82095</td>
  </tr>
</table>


O resultado não foi o esperado porque por vezes o tempo sequencial foi menor que o tempo concorrente.
