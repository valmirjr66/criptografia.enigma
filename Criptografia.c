#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

void escrever();
void ler();
int comp(char *, char *);
char ALF[70]="!3GCjL2eSJ4dWaTEoHim0r7wY6,uAyb8l1nvBPID RgzZUOpcF?Xfx9QNqt.5KhkMsVs";

int main()
{
    char ch='\0';
again:
    while(ch!='L' && ch!='l' && ch!='E' && ch!='e' && ch!='S' && ch!='s' )
    {
        printf("Para ler pressione 'L', para escrever pressione 'E', para sair pressione 'S'.\n");
        ch=getch();
        if(ch=='L' || ch=='l')
            ler();
        if(ch=='E' || ch=='e')
            escrever();
        if(ch=='S' || ch=='s')
        {
            system("color C");
            setbuf(stdin, '\0');
            return 0;
        }
    }
    printf("\n");
    ch='\0';
    setbuf(stdin, '\0');
    goto again;
    return 0;
}

void escrever(void)
{
    char texto[101], crypt_text[101], aux;
    int i, j, num;
    system("color A");
    srand(time(NULL));
    FILE *fp1;
    fp1=fopen("key.txt", "w");
    FILE *fp2;
    fp2=fopen("text.txt", "w");
again:
    gets(texto);
repeat_crypt:
    printf("\n");
    for(i=0; texto[i]!='\0'; i++)
    {
        for(j=0; ALF[j]!=texto[i]; j++)
            if(ALF[j]=='\0')
                goto again;
        num=rand()%67;
        aux=ALF[num];
        fprintf(fp1, "%d,", num-j);
        printf("%c", aux);
        crypt_text[i]=aux;
    }
    crypt_text[i]='\0';
    if(comp(texto, crypt_text)==1)
        goto repeat_crypt;
    fprintf(fp2, "%s", crypt_text);
    printf("\n");
    fclose(fp1);
    fclose(fp2);
}

void ler(void)
{
    char texto[101], chave[400], *lmt_str, C;
    int i=0, val, j;
    system("color B");

    FILE *p_ler1;
    p_ler1=fopen("text.txt", "r");
    fgets(texto, 100, p_ler1);
    fclose(p_ler1);

    FILE *p_ler2;
    p_ler2=fopen("key.txt", "r");
    fgets(chave, 399, p_ler2);
    lmt_str=strtok(chave, ",");
    while(lmt_str!=NULL)
    {
        val=atoi(lmt_str);
        for(j=0; texto[i]!=ALF[j]; j++);
        printf("%c", ALF[j-val]);
        lmt_str=strtok(NULL, ",");
        i++;
    }
    fclose(p_ler2);
}

int comp(char texto[101], char crypt_text[101])
{
    int i, j;

    return 0;
}
