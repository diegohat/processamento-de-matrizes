<h1 align="center">Processamento de matrizes por segmentação de arquivo</h1>

# Problema

Neste projeto, foi implementado um sistema de multiplicação de matrizes baseando-se em uma estratégia de segmentação em arquivo. Um arquivo M grande é fornecido no formato NxN com valores inteiros como entrada. Este é processado a partir de várias coordenadas introduzidas por um segundo arquivo, o key.txt. Em key.txt deve ser descrito por linha uma dupla de i e j correspondendo a posição inicial e final a ser lida. Por exemplo, as posições 2,4,6,10 indica que a leitura em M deve iniciar na linha 2 coluna 4 e seguir até a linha 6 coluna 10. 


Feito a leitura da composição de M para um tipo matriz em C, a segunda etapa foi produzir a transposta de M -= MT. Feito isso, foi armazenado em uma hash o resultado da multiplicação como valor para a dupla de i's e j's, os quais foram utilizados como chaves da hash. Assim, para cada novo calculo, antes o sistema consulta a hash para identificar se a multiplicação já foi realizada. Em caso afirmativo, retorna apenas a resposta já calculada. Caso contrário, elabora a multiplicação e armazena o conteúdo em cache. 


# Metodologia

Foi utilizado a linguagem C devido a sua capacidade de criar estruturas complexas manualmente para fins de aprendizado. 

A principio foi desenvolvido uma função para criar matrizes pseudo-aleatórias através de uma semente coletada através da função time(). Após a geração de valores aleatórios dentro de um arquivo, o próximo passo foi desenvolver uma função para extrair os dados da matriz pai através de determinados valores para i e j gerando assim uma submatriz da mesma. Essa submatriz foi alocada em uma estrutura dinâmica e logo em seguida multiplicada por sua transposta através de três for's. Os valores dos resultados sobrescrevem os valores da submatriz para fins de economia de memória. Após isso, a estrutura é salva em uma estrutura HASH que é inicializada no ínicio do programa. Para as chaves foi utilizado as coordenadas Xi, Yi, Xf, Yf que foram retiradas do arquivo key.txt, concatenadas e transformadas em inteiro. Após a resultante da operação ser salva na HASH, ao chamar a criação de uma nova submatriz, ela busca na HASH linearmente comparando o valor da chave extraida com o valor das chaves salvas e caso encontre correspondência imprime somente o resultado.

# Próximos Passos

Criar uma maneira de ler várias coordenadas no arquivo key.txt e inserir automáticamente as transpostas na HASH.

# Funcionamento

Utilizar o menu para realizar as operações. (De preferência em ordem crescente -> 1, 2, 3 ...)
Para testar um novo par de coordenadas é necessário alterar manualmente no arquivo key.txt durante a execução do programa.
Por exemplo, após percorrer todo o menu, altere o valor da chave no arquivo e percorra novamente para salvar outros valores na Hash.

# Executar
* Como executar:

<html>
<table>
    <tr>
        <td><code>make clean</code></td>
    <tr>
        <td><code>make</code></td>
    </tr>
    <tr>
        <td><code>make run</code></td>
    </tr>
    <tr>
</table>
</html>
