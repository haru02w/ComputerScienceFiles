#include <stdio.h>
#define M 5
#define L 110

void a(double matrix[][M]) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < M; j++)
      printf("%.2lf\t", matrix[i][j]);
    printf("\n");
  }
}
void b(double matrix[][M]) {
  double cidade;
  for (unsigned i = 0; i < M; i++) {
    cidade = 0;
    for (int j = 0; j < M; j++) {
      cidade += matrix[i][j];
    }
    if (cidade - L >= 0)
      printf("Cidade %u está com a termoeletrica ligada\n", i + 1);
  }
}

void c1(double matrix[][M]) {
  double total;
  for (int i = 0; i < M; i++)
    for (int j = 0; j < M; j++)
      total = matrix[i][j];
  printf("A potencia total utilizada: %lf", total);
}

void c2(double matrix[][M]) {
  double cidade, total = 0;
  for (unsigned i = 0; i < M; i++) {
    cidade = 0;
    for (int j = 0; j < M; j++) {
      cidade += matrix[i][j];
    }
    if (cidade >= L)
      total += L;
    else
      total += cidade;
  }
  printf("A potencia fornecida por todas as turbinas é: %lf", total);
}

void c3(double matrix[][M]) {
  double cidade, total = 0;
  for (unsigned i = 0; i < M; i++) {
    cidade = 0;
    for (int j = 0; j < M; j++) {
      cidade += matrix[i][j];
    }
    if (cidade - L >= 0)
      total += cidade - L;
  }
  printf("A energia fornecida pelas termoeletricas é %.2lf\n", total);
}

void d(double matrix[][M]) {
  double cidade, total = 0;
  for (unsigned i = 0; i < M; i++) {
    cidade = 0;
    for (unsigned j = 0; j < M; j++) {
      cidade += matrix[i][j];
    }
    if (cidade - L <= 0)
      total += (cidade - L) * -1;
  }
  printf("A energia total que sobra das turbinas: %lf\n", total);
}

void e(double matrix[][M]) {
  double potencia;
  printf("Digite a potencia: ");
  scanf("%lf", &potencia);
  double cidade, total = 0;
  for (unsigned i = 0; i < M; i++) {
    cidade = 0;
    for (unsigned j = 0; j < M; j++) {
      cidade += matrix[i][j];
    }
    if (cidade - L <= 0)
      total += (cidade - L) * -1;
  }
  total = total - potencia;
  printf("A diferença entre a sobra e a potencia fornecida é: %lf\n", total);
}
void f(double matrix[][M]) {
  double potencia;
  printf("Digite a potencia: ");
  scanf("%lf", &potencia);
  double cidade, total = 0;
  for (unsigned i = 0; i < M; i++) {
    cidade = 0;
    for (unsigned j = 0; j < M; j++) {
      cidade += matrix[i][j];
    }
    if (cidade - L <= 0)
      total += (cidade - L) * -1;
  }
  total = total - potencia;
  if (total >= 0) {
    printf("Potencia da cidade adicionada: %lf MW\n", total);

  } else {
    printf("Há uma sobrecarga de %lf para que a nova cidade seja incluída na "
           "malha elétrica\n",
           -1 * total);
  }
}
int main(int argc, char *argv[]) {
  // matriz cidades x regioes
  // usina cada cidade com limite de 110mW
  // caso ultrapasse, liga a termo
  // Construa a matriz 5x5
  // imprimir
  // mostrar as que excederam 110 e o quanto precisa a mais

  unsigned int n;
  double matrix[][M] = {{7.03, 14.87, 26.41, 9.18, 27.05},
                        {24.26, 21.14, 11.89, 22.74, 31.62},
                        {22.4, 12, 29.8, 24.06, 27.23},
                        {19, 16.04, 18.81, 9.62, 13.05},
                        {24.66, 22.01, 26, 28.2, 28.56}};
  printf("Digite a opção:\n1) Imprimir a matriz \n2) Termoeletricas "
         "ativadas\n3) Potencia total consumida\n4) Potencia total de todas as "
         "turbinas\n5) Energia de todas as turbinas\n6) Energia q sobra das "
         "turbinas\n7) Diferença da potencia fornecida e a sobra\n8) Mostrar "
         "sobrecarga ou suficiencia para a potencia fornecida\nR:");
  scanf("%u", &n);
  switch (n) {
  case 1:
    a(matrix);
    break;
  case 2:
    b(matrix);
    d(matrix);
    break;
  case 3:
    c1(matrix);
    break;
  case 4:
    c2(matrix);
    break;
  case 5:
    c3(matrix);
    break;
  case 6:
    d(matrix);
    break;
  case 7:
    e(matrix);
    break;
  case 8:
    f(matrix);
    break;
  }

  return 0;
}
