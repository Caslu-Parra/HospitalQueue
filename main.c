#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente
{
    char nome[50];
    float severidade;
    struct Paciente *prox;
} Paciente;

float calcularSeveridade()
{
    float severidade = 0;
    int resposta;

    printf("Paciente apresenta dores nos olhos? (1 - sim, 0 - nao): ");
    scanf("%d", &resposta);
    if (resposta == 1)
        severidade += 1.5;

    printf("Paciente apresenta dores de cabeca? (1 - sim, 0 - nao): ");
    scanf("%d", &resposta);
    if (resposta == 1)
        severidade += 1;

    printf("Paciente apresenta febre? (1 - sim, 0 - nao): ");
    scanf("%d", &resposta);
    if (resposta == 1)
        severidade += 2;

    printf("Paciente apresenta tosse? (1 - sim, 0 - nao): ");
    scanf("%d", &resposta);
    if (resposta == 1)
        severidade += 0.5;

    printf("Paciente apresenta dores proximas ao coracao? (1 - sim, 0 - nao): ");
    scanf("%d", &resposta);
    if (resposta == 1)
        severidade += 5;
    return severidade;
}

Paciente *receberPaciente()
{
    Paciente *paciente = malloc(sizeof(Paciente));
    if (paciente == NULL)
    {
        printf("Erro ao alocar memória para o paciente.\n");
        return NULL;
    }
    printf("Digite o nome do paciente: ");
    scanf("%s", paciente->nome);
    paciente->severidade = calcularSeveridade();
    paciente->prox = NULL;
    return paciente;
}

int main(int argc, char const *argv[])
{
    int opcao = -1;
    printf("## Bem-vindo ao sistema de triagem de pacientes! ##\n");
    while (opcao != 0)
    {
        printf("\n------Menu------\n");
        printf(" 1 - Receber paciente \n");
        printf(" 2 - Atender paciente \n");
        printf(" 3 - Imprimir fila de pacientes \n");
        printf(" 0 - Encerrar atendimento\n");
        printf(" Digite a opcao desejada:  ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Opcao 1 selecionada: Receber paciente.\n");
            // Chame a função para receber paciente
            Paciente *novoPaciente = receberPaciente();
            if (novoPaciente != NULL)
            {
                printf("Paciente %s recebido com severidade %.2f.\n", novoPaciente->nome, novoPaciente->severidade);
                // Adicione o paciente à fila (implemente a lógica da fila)
            }
            break;

        case 2:
            printf("Opcao 2 selecionada: Atender paciente.\n");
            // Implemente a lógica para atender o próximo paciente da fila
            break;

        case 3:
            printf("Opcao 3 selecionada: Imprimir fila de pacientes.\n");
            // Implemente a lógica para imprimir a fila de pacientes
            break;

        case 0:
            opcao = 0;
            break;
        }
    }
    return 0;
}
