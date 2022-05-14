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
    <td>0.037290</td>
    <td>0.019089</td>
    <td>0.012501</td>
    <td>0.012815</td>
  </tr>
  <tr>
    <td>10^7</td>
    <td>3.790480</td>
    <td>1.463612</td>
    <td>1.184795</td>
    <td>1.325984</td>
  </tr>
  <tr>
    <td>10^8</td>
    <td>34.429553</td>
    <td>13.834768</td>
    <td>11.421066</td>
    <td>10.557385</td>
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
    <td>1.95348</td>
    <td>2.98296</td>
    <td>2.90987</td>
  </tr>
  <tr>
    <td>10^7</td>
    <td>2.58981</td>
    <td>3.19927</td>
    <td>2.85861</td>
  </tr>
  <tr>
    <td>10^8</td>
    <td>2.48862</td>
    <td>3.01456</td>
    <td>3.26118</td>
  </tr>
</table>

Nosso programa concorrente em comparação com o sequencial conseguiu ser efetivo em todas as comparações, sempre havendo ganha de desempenho, com 1, 2 e 4 threads. Contudo, o programa concorrente ao utilizar 4 threads perde um pouco de desempenho nos vetores de tamanho 10^5 e 10^7. Em geral, o programa concorrente consegue ser 2.5x mais rápido que o programa sequencial.
