### Nome:
Thiago Lopes

### Regras De Código:
https://fabiensanglard.net/fd_proxy/doom3/CodeStyleConventions.pdf/

### Exercicio:
#### Trabalho Agenda:
Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.\
1 - Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.\
1.1 - Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.\
1.2 - Exemplo do que não pode: int c; char a; int v[10];  void Funcao(int parametro)\
2 - Não pode usar struct em todo o programa.\
3 - Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.\
4 - Implementar a base de dados da agenda usando lista duplamente ligada\
4.1 - Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

### Git:
https://github.com/Thiago033/algoritmos-e-estrutura-de-dados-i/tree/main/trabalhos/exercicio-3-agenda-parte-2

### Codigo:
Codigo funcionando normalmente.
Erro ao rodar o teste com dr. memory.

### Lista De Testes:
AddPerson - ["a", 10, 11]\
AddPerson - ["d", 20, 22]\
AddPerson - ["c", 30, 33]\
AddPerson - ["b", 40, 44]\
PrintList()\
RemovePerson()\
RemovePerson()\
PrintList()\
SearchPerson - ["c"]\
SearchPerson - ["a"]

### Teste Dr. Memory:
https://github.com/Thiago033/algoritmos-e-estrutura-de-dados-i/blob/main/trabalhos/exercicio-3-agenda-parte-2/test-dr-memory.txt
