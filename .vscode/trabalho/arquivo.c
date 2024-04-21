#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

typedef struct {
  char nome[MAX_LEN];
  char telefone[MAX_LEN];
  char curso[MAX_LEN];
  float nota[2];
} Aluno;

int main() {
  FILE *entrada = fopen("DadosEntrada.csv", "r");
  FILE *saida = fopen("SituacaoFinal.csv", "w");

  if (entrada == NULL || saida == NULL) {
    printf("Erro ao abrir os arquivos.\n");
    return 1;
  } else {
    while (!feof(entrada)) {
      Aluno aluno;

      fscanf(entrada, "%[^,],%[^,],%[^,],%f,%f\n", aluno.nome, aluno.telefone, aluno.curso, &aluno.nota[0], &aluno.nota[1]);

      float media = (aluno.nota[0] + aluno.nota[1]) / 2.0;
      char situacao[MAX_LEN];

      if (media >= 7.0) {
        strcpy(situacao, "APROVADO");
      } else {
        strcpy(situacao, "REPROVADO");
      }

      fprintf(saida, "%s, %.2f, %s\n", aluno.nome, media, situacao);
    }

    printf("SituacaoFinal.csv gerado com sucesso.\n");
  }

  fclose(entrada);
  fclose(saida);

  return 0;
}