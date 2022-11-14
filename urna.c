#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char arrayNomeCandidato[20][50];
int arrayNumeroCandidato[20];
int arrayVotoCandidato[20];

void initArray(void);
void displayMain(void);
void addCandidato(void);
void listaCandidato(void);
void votacao();
void resultado(void);

void main(void)
{
    system("cls");
    initArray();
    
    for(;;){
    displayMain();
    }
}

void initArray(void)
{
    int i;

    for(i = 0; i < 20; i++)
    {
        arrayNumeroCandidato[i] = 0;
    }
}

void displayMain(void)
{
    system("cls");

    char opcao;

    printf("Bem vindo a urna eletronica\n");
    printf("\nPara cadastrar um candidato digite: (c).\n");
    printf("\nPara listar os candidatos cadastrados digite: (l).\n");
    printf("\nPara iniciar votacao digite: (v).\n");
    printf("\nPara ver o resultado digite: (r). \n");
    printf("\nDigite a opcao: ");

    scanf("\n%c", &opcao);

    switch (opcao)
    {
    case 'c':
        addCandidato();
        break;

    case 'l':
        listaCandidato();
        break;

    case 'v':
        votacao();
        break;

    case 'r':
        resultado();
        break;
    
    default:
        displayMain();
        break;
    }
}

void addCandidato(void)
{
    char nome[50];
    int numero;
    int i;
    char t;
    system("cls");
    printf("Digite o nome do candidato: ");
    scanf("%s", &nome);
    printf("Digite o numero do candidato: ");
    scanf("%d", &numero);
    printf("%d", numero);

    for(i = 0; i < 20; i++)
    {
        if(arrayNumeroCandidato[i] == numero) 
        {
            addCandidato();
        }
    }

    for(i = 0; i < 20; i++)
    {
        if(arrayNumeroCandidato[i] == 0){
            strcpy(arrayNomeCandidato[i], nome);
            arrayNumeroCandidato[i] = numero;
            break;
        }
    }
}

void listaCandidato(void)
{
    int i;
    char opcao;
    system("cls");
    printf("Lista de candidatos\n");
    for(i = 0; i < 20; i++)
    {
        if(arrayNumeroCandidato[i] != 0) printf("\nNome: %s""\nN:%d\n--------------------" , arrayNomeCandidato[i] , arrayNumeroCandidato[i]);
    }
    printf("\nDigite s para sair: ");
    scanf("\n%c", &opcao);
}

void votacao()
{
    int voto;
    int i;
    int confirmaVoto;
    char opcao;
    
    system("cls");
    printf("Pagina de votacao:\n");
    printf("Digite o numero do candidato: ");
    scanf("%d", &voto);

    for(i = 0; i < 20; i++)
    {
        if(arrayNumeroCandidato[i] == voto){
            confirmaVoto = arrayNumeroCandidato[i];
            printf("Confirme seu voto digitando (c).: ");
            scanf("\n%c", &opcao);
            if(opcao == 'c')
            {
                arrayVotoCandidato[i] = arrayVotoCandidato[i] + 1;
                break;
            }
            if(opcao = 'r') {resultado(); break;}
        }
    }

    votacao();
}

void resultado(void)
{
    int i;
    char opcao;
    system("cls");
    printf("Lista de candidatos\n");
    for(i = 0; i < 20; i++)
    {
        if(arrayNumeroCandidato[i] != 0) printf("\nNome: %s""\nN:%d""\nVotos: %d\n--------------------" , arrayNomeCandidato[i] , arrayNumeroCandidato[i], arrayVotoCandidato[i]);
    }
    printf("\nDigite s para sair: ");
    scanf("\n%c", &opcao);
}
