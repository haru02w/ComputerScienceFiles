/*
 * 9. Escreva programs em linguagem C para:
 */

#include <math.h>
#include <stdio.h>
/* i. Imprimir na tela:
 * Hello
 * World
 */
void func_1() { printf("Hello\nWorld\n"); }

/*
 * ii. Declare uma variável inteira x, com valor inicial igual a 10. Imprima o
 * valor de x.
 */
void func_2() {
  int x = 10;
  printf("o valor de x é %d", x);
}

/*
 * iii. Leia uma data no formato DDMMAA e mostre:
 * Dia: DD
 * Mes: MM
 * Ano: AA
 */
void func_3() {
  char string[6];
  printf("Digite uma data no formato DDMMAA: ");
  scanf("%s", string);
  printf("\nDia: %c%c\nMes: %c%c\nAno: %c%c", string[0], string[1], string[2],
         string[3], string[4], string[5]);
}

/*
 * iv. Efetuar a soma dos números 5 e 10 e imprimir o resultado
 */
void func_4() { printf("5 + 10 é %d", 5 + 10); }

/*
 * v. Efetuar a soma de três números digitados pelo usuário e imprimir o
 * resultado.
 */
void func_5() {
  int n1, n2, n3;
  printf("Digite 3 numeros: ");
  scanf("%d %d %d", &n1, &n2, &n3);
  printf("O resultado da soma dos numeros é %d", n1 + n2 + n3);
}

/*
 * vi. Efetuar a multiplicação de dois números digitados pelo usuário e imprimir
 * o resultado.
 */
void func_6() {
  int n1, n2;
  printf("Digite 2 numeros: ");
  scanf("%d %d", &n1, &n2);
  printf("O resultado da multiplicação dos numeros é %d", n1 * n2);
}

/*
 * vii. Imprima o seu nome.
 */
void func_7() { printf("Meu nome é Haru02w"); }

/*
 * viii. Imprima o produto entre 15 e 36.
 */
void func_8() { printf("O produto entre 15 e 36 é %d", 15 * 36); }

/*
 * ix. Calcule e mostre a média dos números 10, 13 e 35.
 */
void func_9() {
  printf("A média dos numero 10, 13 e 35 é %d", (10 + 13 + 35) / 3);
}

/*
 * x. Leia um número inteiro e mostre na tela.
 */
void func_10() {
  int n1;
  printf("Digite um numero inteiro: ");
  scanf("%d", &n1);
  printf("O numero digitado foi %d", n1);
}

/*
 * xi. Leia um número inteiro e mostre o seu sucessor e antecessor.
 */
void func_11() {
  int n1;
  printf("Digite um numero inteiro: ");
  scanf("%d", &n1);
  printf("O antecessor do numero digitado é %d\nO sucessor é  %d", n1 - 1,
         n1 + 1);
}

/*
 * xii. Leia dois números inteiros e os imprima na tela.
 */
void func_12() {
  int n1, n2;
  printf("Digite dois numeros inteiros: ");
  scanf("%d %d", &n1, &n2);
  printf("Os numeros digitados foram %d e %d", n1, n2);
}

/*
 * xiii. Leia dois números inteiros e imprima sua soma, subtração, multiplicação
 * e divisão.
 */
void func_13() {
  int n1, n2;
  printf("Digite dois numeros inteiros: ");
  scanf("%d %d", &n1, &n2);

  printf("A soma entre os numeros é: %d\n"
         "A subtração entre os numeros é: %d\n"
         "A multiplicação entre os numeros é: %d\n"
         "A divisão entre os numeros é: %.2f\n",
         n1 + n2, n1 - n2, n1 * n2, (float)n1 / n2);
}

/*
 * xiv. Leia um número real e mostre a metade deste número.
 */
void func_14() {
  float n1;
  printf("Digite um numero real: ");
  scanf("%f", &n1);
  printf("A metade de %.2f é %.2f", n1, n1 / 2);
}

/*
 * xv. Leia quatro notas, com pesos 1, 2, 3 e 4 e imprima sua nota ponderada com
 * duas casas decimais.
 */
void func_15() {
  float n1, n2, n3, n4;
  printf("Digite quatro notas: ");
  scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
  printf("Sua nota ponderada é %.2f",
         ((n1 * 1) + (n2 * 2) + (n3 * 3) + (n4 * 4)) / (1 + 2 + 3 + 4));
}

/*
 * xvi. Leia um valor e incremente-o em 10%, mostrando o resultado final.
 */
void func_16() {
  float n1;
  printf("Digite um numero real: ");
  scanf("%f", &n1);
  printf("%.2f + 10%% = %.2f", n1, n1 * 1.1);
}

/*
 * xvii. Leia a base e altura de um retângulo e imprima seu perímetro e sua
 * área.
 */
void func_17() {
  float n1, n2;
  printf("Digite a base e altura de um retangulo: ");
  scanf("%f %f", &n1, &n2);
  printf("O perimetro do retangulo é %.2f\n A area do retangulo é %.2f",
         (n1 * 2) + (n2 * 2), n1 * n2);
}

/*
 * xviii. Leia o raio de um círculo e imprima o perímetro.
 */
void func_18() {
  float n1;
  printf("Digite o raio de um circulo (um numero): ");
  scanf("%f", &n1);
  printf("O perimetro do circulo é %.2f", 2 * M_PI * n1);
}

/*
 * xix. Leia os valores dos catetos e imprima a hipotenusa.
 */
void func_19() {
  float n1, n2;
  printf("Digite os catetos de um triangulo (2 numeros): ");
  scanf("%f %f", &n1, &n2);
  printf("A hipotenusa do triangulo é %.2f", sqrt(pow(n1, 2) + pow(n1, 2)));
}

/*
 * xx. Leia a hora e minutos atuais, a partir do teclado, e mostre o tempo em
 * minutos.
 */
void func_20() {
  int n1, n2;
  printf("Digite a hora e os minutos atuais: ");
  scanf("%d %d", &n1, &n2);
  printf("A hora atual em minutos é %d", (n1 * 60) + n2);
}

/*
 * xxi. Leia o tempo de duração de um evento em uma fábrica em segundos e
 * imprima-o em horas, minutos e segundos
 */
void func_21() {
  int n1, h, m, s;
  printf("Digite o tempo de duração de um evento em segundos: ");
  scanf("%d", &n1);
  h = n1 / 3600;
  m = n1 / 60;
  s = n1 - (h * 3600) - (m * 60);
  printf("A duração em horas, minutos e segundos é de %d horas %d minutos %d "
         "segundos",
         h, m, s);
}

/*
 * xxii. Leia um número inteiro de 3 dígitos, XYZ, e imprima:
 * Primeiro Dígito: X
 * Segundo Dígito: Y
 * Terceiro Dígito: Z
 */
void func_22() {
  int n1;
  int n[3];
  printf("Digite um numero de 3 digitos: ");
  scanf("%d", &n1);
  n[2] = n1 % 10;
  n1 /= 10;
  n[1] = n1 % 10;
  n[0] = n1 / 10;
  printf("Primeiro digito: %d\nSegundo digito: %d\nTerceiro digito: %d", n[0],
         n[1], n[2]);
}

/*Implementção do menu de escolha: */
void (*function[22])() = {&func_1,  &func_2,  &func_3,  &func_4,  &func_5,
                          &func_6,  &func_7,  &func_8,  &func_9,  &func_10,
                          &func_11, &func_12, &func_13, &func_14, &func_15,
                          &func_16, &func_17, &func_18, &func_19, &func_20,
                          &func_21, &func_22};

int main(int argc, char *argv[]) {
  int response;

  while (1) {
    printf("\nDigite qual subprograma executar (1 - 22): ");
    scanf("%d", &response);
    if (response < 1 || response > 22)
      break;
    function[response - 1]();
  }

  printf("Foi digitado um numero diferente do esperado. "
         "Fechando o programa...\n");
  return 0;
}
