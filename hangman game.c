#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>

typedef struct Gabarito
{
    char frase_chosen[9999];
    char palavra_chosen[69];
} Gabarito;

int cleaner(char *string, int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        string[i] = 0;
    }
}

int display(char letras[100], char palavra_chosen[100])
{
    for (int x = 0; x < strlen(palavra_chosen); x++)
    {

        if (strchr(letras, palavra_chosen[x]) == NULL)
        {
            printf("  ");
        }
        else
        {
            printf("%c ", palavra_chosen[x]);
        }
    }
}

int i_rnd(int i)
{

    for (int x = 0; x < 1000; x++)
    {
    }
    return rand() % i;
}

int game_ender(char palavras[100], char letras[100])
{

    for (int x = 0; x < strlen(palavras); x++)
    {
        char *testador = strchr(letras, palavras[x]);
        if (testador == NULL)
            return 0;
    }
    return 1;
}

int main()
{

    srand(time(NULL));
    setlocale(LC_ALL, "");
    Gabarito frase_chosen[100];
    strcpy(frase_chosen[0].palavra_chosen, "conclusao");
    strcpy(frase_chosen[0].frase_chosen, "Parte final do trabalho, em que sao apresentadas as conclusoes correspondentes aos objetivos ou hipoteses e sugestoes relativas ao estudo.");
    strcpy(frase_chosen[1].palavra_chosen, "referencias");
    strcpy(frase_chosen[1].frase_chosen, "Elemento obrigatorio, que consiste na listagem de todos os documentos (livros, artigos de revista ou jornais, poligrafos, CDs, Internet, palestras, etc.), citados 14 no decorrer do trabalho.");
    strcpy(frase_chosen[2].palavra_chosen, "justificativa");
    strcpy(frase_chosen[2].frase_chosen, "e o convencimento de que o trabalho de pesquisa e fundamental para ser efetivado e relevante para a sociedade ou para alguns individuos que se beneficiarao com a pesquisa. ");
    strcpy(frase_chosen[3].palavra_chosen, "problema");
    strcpy(frase_chosen[3].frase_chosen, "Tem como origem uma situacao que provoca questoes sobre o tema e pode ser definido pela propria vivencia do pesquisador ou indicado por profissionais ligados ao tema.");
    strcpy(frase_chosen[4].palavra_chosen, "objetivo");
    strcpy(frase_chosen[4].frase_chosen, "Determina o que o pesquisador quer atingir com a realizacao do trabalho de pesquisa e devem corresponder as questoes propostas.");
    strcpy(frase_chosen[5].palavra_chosen, "tema");
    strcpy(frase_chosen[5].frase_chosen, "E o aspecto do assunto que se deseja abordar, provar ou desenvolver.");
    strcpy(frase_chosen[6].palavra_chosen, "metodologia");
    strcpy(frase_chosen[6].frase_chosen, "E a descricao da estrategia a ser adotada, onde constam todos os passos e procedimentos adotados para realizar a pesquisa e atingir os objetivos.");
    strcpy(frase_chosen[7].palavra_chosen, "objetivo");
    strcpy(frase_chosen[7].frase_chosen, "Devem comecar com o verbo no infinitivo, como por exemplo: esclarecer tal coisa; definir tal assunto; procurar aquilo; permitir aquilo outro, demonstrar alguma coisa, etc.");
    strcpy(frase_chosen[8].palavra_chosen, "referencias");
    strcpy(frase_chosen[8].frase_chosen, "E utilizado para o conjunto de titulos (inclusive sites e documentos eletronicos) consultados pelos autores para a elaboracao de um trabalho.");
    strcpy(frase_chosen[9].palavra_chosen, "justificativa");
    strcpy(frase_chosen[9].frase_chosen, "deve aparecer como as informacoes geradas pela pesquisa sao uteis e a quem. O que a pesquisa ira agregar e que decisoes poderao ser tomadas a partir dos dados gerados.");

    int finisher;
    printf("A frase abaixo foi retirada Manual de orientacoes para projetos de pesquisa da Liberato, ela representa uma definicao de algum dos temas de pesquisa que pesquisamos nas aulas\n\n");
    while (1)
    {
        int random_frases = i_rnd(10);
        char palavra_chosen[100];
        strcpy(palavra_chosen, frase_chosen[random_frases].palavra_chosen);
        char letras[100];
        cleaner(letras, 100);

        int pos = 0;
        int vidas = 3;
        int vidasF = 0;
        char chute = 0;
        
        printf("\t%s\n\n", frase_chosen[random_frases].frase_chosen);
        printf("Tente adivinhar de qual conteudo que a gente aprendeu a definicao fala sobre\n");

        while (!(game_ender(palavra_chosen, letras) || vidas == vidasF))
        {
            printf("\nVoce tem %d vidas sobrando\n", vidas);

            scanf("%c", &chute);
            while (getchar() != '\n')
            {
            }
            letras[pos] = chute;
            pos++;

            display(letras, palavra_chosen);

            if (strchr(palavra_chosen, chute) == NULL)
            {
                vidas--;
                continue;
            }
        }

        if (game_ender(palavra_chosen, letras) == 0)
        {
            int ender;
            printf("\n\n\tVoce perdeu!!\n");
            printf("\tA resposta correta era %s\n\n", palavra_chosen);
            printf("Se quiser jogar novamente aperte 1, se quiser parar aperte 999\n");
            scanf ("%i", &finisher);
            
            while (getchar() != '\n')
            {
            }
            system ("cls");
            if(finisher == 999)
                break;
        }
        else
        {
            int winner;
            printf("\n\n\tVoce venceu!!\n");
            printf("Se quiser jogar novamente aperte 1, se quiser parar aperte 999\n");
            scanf ("%i", &finisher);
            while (getchar() != '\n')
            {
            }
            system ("cls");
            if(finisher == 999)
                break;
        }
    }
}
