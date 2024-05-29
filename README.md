# MyDiary
O código fornecido é um exemplo de um programa de diário simples escrito em C. Ele permite que o usuário adicione entradas ao diário, pesquise por entradas que contenham uma determinada palavra-chave e adicione tags às entradas.

O programa começa declarando uma estrutura chamada Diary, que representa o diário em si. A estrutura possui um campo num_entries para rastrear o número de entradas no diário.

Em seguida, o programa declara algumas variáveis para armazenar a data, o conteúdo e as tags de uma nova entrada. A variável num_tags é usada para armazenar o número de tags que o usuário deseja adicionar.

O programa solicita ao usuário que insira a data no formato "AAAA-MM-DD" e o conteúdo da entrada. Em seguida, solicita o número de tags e as tags separadas por espaço. Os valores inseridos pelo usuário são armazenados nas variáveis correspondentes.

Em seguida, o programa chama a função add_entry para adicionar a nova entrada ao diário. A função recebe como argumentos o endereço da estrutura my_diary, a data, o conteúdo e um array de tags. Neste caso, as tags são passadas como um ponteiro para um array de ponteiros de caracteres.

Após adicionar a entrada, o programa chama a função search_entries para pesquisar por entradas que contenham a palavra-chave "great". Essa função percorre as entradas do diário e imprime aquelas que contêm a palavra-chave especificada.

Em seguida, o programa chama a função add_tags para adicionar tags adicionais à primeira entrada do diário. A função recebe como argumentos o endereço da estrutura my_diary, o índice da entrada (0 no caso) e um array de tags. Neste caso, as tags são passadas como um ponteiro para um array de ponteiros de caracteres, com o último elemento sendo NULL para indicar o fim do array.

Após adicionar as tags, o programa itera sobre as tags da primeira entrada e as imprime na tela.

Por fim, o programa chama a função save_entries_to_file para salvar as entradas do diário em um arquivo.

Este código pode ser usado como ponto de partida para a criação de um programa de diário mais completo, com recursos adicionais, como edição e exclusão de entradas, pesquisa avançada e interface gráfica.
