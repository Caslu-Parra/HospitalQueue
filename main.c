#include <stdio.h>
#include <stdlib.h>

typedef struct Paciente
{
    char nome[50];
    float severidade;
    struct Paciente *prox;
} Paciente;

Paciente *inicio = NULL;
Paciente *fim = NULL;

float diagnosticarSeveridade()
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
    paciente->severidade = diagnosticarSeveridade();
    paciente->prox = NULL;
    return paciente;
}

void ordenarFila(Paciente *paciente)
{
    Paciente *atual = inicio;
    Paciente *anterior = NULL;

    while (atual != NULL && atual->severidade > paciente->severidade)
    {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL)
    {
        paciente->prox = inicio;
        inicio = paciente;
    }
    else
    {
        anterior->prox = paciente;
        paciente->prox = atual;
    }
}

int main(int argc, char const *argv[])
{
    int opcao = -1;
   
    printf("## Bem-vindo ao sistema de triagem de pacientes! ##\n");
    while (opcao != 0)
    {
        printf("\n------------Menu------------\n");
        printf(" 0 - Encerrar atendimento\n");
        printf(" 1 - Receber paciente \n");
        printf(" 2 - Atender paciente \n");
        printf(" 3 - Imprimir fila de pacientes \n");
        printf(" Digite a opcao desejada:  ");
        scanf("%d", &opcao);

        system("cls || clear");
        switch (opcao)
        {
        case 1:
            printf("Opcao 1 selecionada: Receber paciente.\n");
            // Chame a função para receber paciente
            Paciente *novoPaciente = receberPaciente();
            if (novoPaciente != NULL)
            {
                ordenarFila(novoPaciente);
                printf("Paciente %s foi recebido e diagnosticado com severidade %.2f.\n", novoPaciente->nome, novoPaciente->severidade);
            }
            break;

        case 2:
            printf("Opcao 2 selecionada: Atender paciente.\n");
            if (inicio != NULL)
            {
                Paciente *aux = inicio;
                inicio = inicio->prox;
                printf("Paciente %s atendido com sucesso!", aux->nome);
                free(aux);
                if (inicio == NULL)
                    fim = NULL;
            }
            break;

        case 3:
            printf("Opcao 3 selecionada: Imprimir fila de pacientes.\n");
            Paciente *atual = inicio;
            int posicao = 1;
            if (inicio == NULL)
                printf("A fila de pacientes esta vazia.\n");
            else
            {
                printf("\n--------------Fila de Pacientes---------------\n\n");
                while (atual != NULL)
                {
                    printf("| #%d Posicao - Paciente %s (sev. %.2f)\n", posicao, atual->nome, atual->severidade);
                    atual = atual->prox;
                    posicao++;
                }
                printf("\n----------------------------------------------\n");
            }
            break;

        case 0:
            opcao = 0;
            break;
        }
    }
    return 0;
}
