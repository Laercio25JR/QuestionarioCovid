#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int idade, SN, i, I, pontos, risco;
char nome[50], sexo, R[10], CPF[11];


void cadastro () {
    printf("Comecando seu cadastro, insira os dados a seguir.\n");
    printf("CPF: ");
    scanf("%s", &CPF);
    fflush(stdin);
    printf("Nome: ");
    gets(nome);
    fflush(stdin);
    printf("Sexo:\nM - Masculino\nF - Feminino\nO - Outro\n");
    scanf("%c", &sexo);
    fflush(stdin);
    printf("Idade: ");
    scanf("%d", &idade);
    fflush(stdin);
}

void verifCadastro () {
    system("cls");
    printf("CPF: %s\n", CPF);
    printf("Nome: %s\n", nome);
    printf("Sexo: %c\n", sexo);
    printf("Idade: %d\n\n", idade);
    printf("As informacoes acima estao corretas?\n1 - Sim / 2 - Nao\n");
    scanf("%d", &SN);
    fflush(stdin);
}

int respostas () {
    scanf("%c", &R[i]);
    fflush(stdin);
    i = i + 1;
    //printf("%d\n", i);
    return i;
}

void questionario () {
    system("cls");
    printf("Responda as perguntas abaixo com (S) ou (N):\n");
    printf("Tem Febre?\n");
    respostas();
    printf("Tem dor de cabeca?\n");
    respostas();
    printf("Tem secrecao nasal ou espirros?\n");
    respostas();
    printf("Tem dor/irritacao na garganta?\n");
    respostas();
    printf("Tem tosse seca?\n");
    respostas();
    printf("Tem dificuldade respiratoria?\n");
    respostas();
    printf("Tem dores no corpo?\n");
    respostas();
    printf("Tem diarreia?\n");
    respostas();
    printf("Esteve em contato, nos ultimos 14 dias, com um caso diagnosticado com COVID-19?\n");
    respostas();
    printf("Esteve em locais com grande aglomeracao?\n");
    respostas();
    //printf("%d", i);
    //printf("%s", R);
}

void contagemDePontos (){
    //printf("inicio i = %d\n", i);
    for(int I = 0; I < i; I++){
        //printf("Pre switch, I = %d\n", I);
        if (R[I] == 'S' || R[I] == 's') {
            switch (I) {
                case 0:
                    pontos = pontos + 5;
                    break;
                case 1:
                    pontos = pontos + 1;
                    break;
                case 2:
                    pontos = pontos + 1;
                    break;
                case 3:
                    pontos = pontos + 1;
                    break;
                case 4:
                    pontos = pontos + 3;
                    break;
                case 5:
                    pontos = pontos + 10;
                    break;
                case 6:
                    pontos = pontos + 1;
                    break;
                case 7:
                    pontos = pontos + 1;
                    break;
                case 8:
                    pontos = pontos + 10;
                    break;
                case 9:
                    pontos = pontos + 3;
                    break;
            }
        //printf("Fim switch pontos = %d\n", pontos);
        }
    }
}

void encaminhamento () {
    if (pontos < 10) {
        risco = 1;
        printf("Paciente %s deve se dirigir a ala numero 1 (Risco baixo)\n", nome);
    } else if (pontos > 10 && pontos < 20) {
        risco = 2;
        printf("Paciente %s deve se dirigir a ala numero 2 (Risco Medio)\n", nome);
    } else {
        risco = 3;
        printf("Paciente %s deve se dirigir a ala numero 3 (Risco Alto)\n", nome);
    }
}

void armazenamento () {
    FILE *arquivo;
    arquivo = fopen("Banco de dados - Pacientes.txt", "a");
    fprintf(arquivo, "%s", "CPF: ");
    fprintf(arquivo, "%s\n", CPF);
    fprintf(arquivo, "%s", "Nome: ");
    fprintf(arquivo, "%s\n", nome);
    fprintf(arquivo, "%s", "Sexo: ");
    fprintf(arquivo, "%c\n", sexo);
    fprintf(arquivo, "%s", "Idade: ");
    fprintf(arquivo, "%d\n\n", idade);
    fprintf(arquivo, "%s\n", "Respostas do Questionario:");
    fprintf(arquivo, "%s", "Febre - ");
    fprintf(arquivo, "%c\n", R[0]);
    fprintf(arquivo, "%s", "Dor de cabeca - ");
    fprintf(arquivo, "%c\n", R[1]);
    fprintf(arquivo, "%s", "Secrecao nasal ou espirros - ");
    fprintf(arquivo, "%c\n", R[2]);
    fprintf(arquivo, "%s", "Dor/Irritacao na garganta - ");
    fprintf(arquivo, "%c\n", R[3]);
    fprintf(arquivo, "%s", "Tosse seca - ");
    fprintf(arquivo, "%c\n", R[4]);
    fprintf(arquivo, "%s", "Dificuldade Respiratoria - ");
    fprintf(arquivo, "%c\n", R[5]);
    fprintf(arquivo, "%s", "Dores no Corpo - ");
    fprintf(arquivo, "%c\n", R[6]);
    fprintf(arquivo, "%s", "Diarreia - ");
    fprintf(arquivo, "%c\n", R[7]);
    fprintf(arquivo, "%s", "Contato com caso diagnosticado - ");
    fprintf(arquivo, "%c\n", R[8]);
    fprintf(arquivo, "%s", "Locais de aglomeracao - ");
    fprintf(arquivo, "%c\n\n", R[9]);
    fprintf(arquivo, "%s", "Nivel de risco: ");
    fprintf(arquivo, "%d\n", risco);
    fprintf(arquivo, "%s\n\n", "-------------------------------------");
    fclose(arquivo);
    system("pause");
}

int main (){
    system("cls");
    printf("____________Bem vindo____________\n");
    printf("\n");
    cadastro();
    verifCadastro();
    while (SN != 1) {
        system("cls");
        printf("Insira novamente suas informacoes.\n");
        system("pause");
        system("cls");
        cadastro();
        verifCadastro();
    }
    questionario();
    contagemDePontos();
    //printf("Final, pontos = %d\n", pontos);
    encaminhamento();
    armazenamento();
}
