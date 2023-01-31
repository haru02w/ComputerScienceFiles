# Relatorio - Projeto 5 de ATP2

### O que foi pedido

Foi solicitado um programa que ler do arquivo bigint.dat numeros separados em dois int's em uma struct,
ordena-los e salvar o resultado dos numeros no arquivo correnspondente ao tipo de ordenação,
como insertion.dat para o metodo insertion sort e quick.dat para quick sort.

---

### Teste:
#### Quick Sort
```sh
> time ./quick
./quick  0.06s user 0.01s system 87% cpu 0.083 total

> time ./quick
./quick  0.07s user 0.00s system 88% cpu 0.082 total

> time ./quick
./quick  0.06s user 0.01s system 88% cpu 0.082 total

> time ./quick
./quick  0.07s user 0.00s system 88% cpu 0.081 total

> time ./quick
./quick  0.06s user 0.01s system 88% cpu 0.083 total
```
#### Media: 0,064s

---

### Teste:
#### Insertion Sort
```sh
> time ./insertion
./insertion  14.49s user 0.01s system 99% cpu 14.512 total

> time ./insertion
./insertion  13.72s user 0.00s system 99% cpu 13.731 total

> time ./insertion
./insertion  14.54s user 0.01s system 99% cpu 14.562 total

> time ./insertion
./insertion  13.81s user 0.01s system 99% cpu 13.813 total

> time ./insertion
./insertion  14.63s user 0.01s system 99% cpu 14.653 total
```
#### Media: 14,238s

---

### Conclusão

Conforme confirmado pelos testes, a eficiencia do programa muda drasticamente dependendo do algoritmo utilizado,
demonstrando a importancia de pesquisar e desenvolver melhores algoritmos,
além de escolher bem qual algoritmo utilizar para cada situação.
