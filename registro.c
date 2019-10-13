#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

struct tm *data;

int pdlt(){
    setlocale(LC_ALL, "Portuguese");
	int opcao, pdl;
	char pdlc[5];
	FILE *pdlatual;

	pdlatual = fopen("pdl.txt","r");
	fgets(pdlc, 5, pdlatual);
	pdl = atoi(pdlc);
    fclose(pdlatual);
	printf("Seu pdl está em --> %d \nInsira o valor correto -->",pdl);
    scanf("%d",&pdl);
    pdlatual = fopen("pdl.txt","w");
    fprintf(pdlatual, "%d\n", pdl);
    printf("Seu pdl atual foi alterado para %d\n",pdl);
    fclose(pdlatual);
	getch();
	return pdl;
}

void funcao_mapa(int *mapa, char mapac[20]){
    switch(*mapa){
        case 0 : strcpy(mapac, "------");
                 break;
        case 1 : strcpy(mapac, "Banco");
                 break;
        case 2 : strcpy(mapac, "Fronteira");
                 break;
        case 3 : strcpy(mapac, "Chalet");
                 break;
        case 4 : strcpy(mapac, "Clube");
                 break;
        case 5 : strcpy(mapac, "Litoral");
                 break;
        case 6 : strcpy(mapac, "Consulado");
                 break;
        case 7 : strcpy(mapac, "Kafe Dostoyevsky");
                 break;
        case 8 : strcpy(mapac, "Kanal");
                 break;
        case 9 : strcpy(mapac, "Oregon");
                 break;
        case 10 : strcpy(mapac, "Outback");
                 break;
        case 11 : strcpy(mapac, "Arranha-Ceu");
                 break;
        case 12 : strcpy(mapac, "Mansao");
                 break;
        default : strcpy(mapac, "------");
    }
}

void funcao_mvp(int *mvp, char mvpchar[10]){
    switch(*mvp){
        case 1: strcpy(mvpchar, "CPF");
            break;
        case 2: strcpy(mvpchar, "Gasly");
            break;
        case 3: strcpy(mvpchar, "Jompe");
            break;
        case 4: strcpy(mvpchar, "Pao");
            break;
        case 5: strcpy(mvpchar, "Piai");
            break;
        case 6: strcpy(mvpchar, "Poto");
            break;
        case 7: strcpy(mvpchar, "Mizoo");
            break;       
        case 8: strcpy(mvpchar, "Reid");
            break;
        case 9: strcpy(mvpchar, "Rickson");
            break; 
        case 0:strcpy(mvpchar, "Random");
            break;             
    }
}

void registrar(char *wl, int *pdltotal){
    int mapa, dia, mes, ano, pdl, hora, mvp;
    char pdltotalchar[5], mapac[20], horario[10], mvpc[10];
    time_t segundos;
    FILE *file, *pdlatual;

    file= fopen("registro.txt", "a");
    system("cls");
    printf("Ganhou ou Perdeu?  \n(W) Win    (L) Lose   (S) Sair\n -> ");
    scanf(" %c", wl);
    system("cls");

    if(*wl != 'W' && *wl !='L' && *wl != 'S'&& *wl != 'w' && *wl !='l' && *wl != 's'){
        printf("ERRRROU!\n");
        registrar(wl, pdltotal);
    }
    else{
        while(*wl != 'S' && *wl!='s'){
            system("cls");
            time(&segundos);
            data = localtime(&segundos);
            dia = data->tm_mday;
            mes = data->tm_mon + 1;
            ano = data->tm_year + 1900;
            hora = data->tm_hour;

            switch(hora){
                case  0 ... 6 	: strcpy(horario,"Madrugada");
                        break;
                case  7 ... 12 	: strcpy(horario,"Manha");
                        break;
                case  13 ... 18	: strcpy(horario,"Tarde");
                        break;
                case  19 ... 23 : strcpy(horario,"Noite");
                        break;
            };

            if(*wl=='w'||*wl=='W'){
                printf("Ganhou quanto pdl? \n ->");
                scanf("%d", &pdl);
            }
            else{
                printf("Perdeu quanto pdl? \n ->");
                scanf("%d", &pdl);
            }

            system("cls");
            printf("====Qual mapa?====\n");
            printf("1-Bank (Banco)\t\t\t2-Border (Fronteira)\t\t3-Chalet\n");
            printf("4-Club House (Casa de Festas)\t5-Coastline (Litoral)\t\t6-Consulate(Consulado) \n");
            printf("7-Kafe Dostoyevsky\t\t8-Kanals (Canal)\t\t9-Oregon \n");
            printf("10-Outback\t\t\t11-Skyscraper (Arranha-ceu)\t12-Villa (Mansao)\n");
            printf("0-\"------\"\n -> ");
            scanf("%d", &mapa);
            system("cls");
            funcao_mapa(&mapa, mapac);
            
            system("cls");      
            printf("====Quem foi o MVP?====\n");
            printf("1-CPF\t\t2-Gasly\t\t3-Jompe\n");
            printf("4-Pao\t\t5-Piai\t\t6-Poto\n");
            printf("7-Mizoo\t\t8-Reid\t\t9-Rickson\n0-Random\n->");
            scanf("%d", &mvp);
            funcao_mvp(&mvp, mvpc);
            
            if(*wl == 'w' || *wl == 'W'){
                system("cls");
            	pdlatual = fopen("pdl.txt", "r");
                fgets(pdltotalchar, 5, pdlatual);
                fclose(pdlatual);
                *pdltotal = atoi(pdltotalchar) + pdl;
                printf("Win!  ganhou %d pdl e agora seu pdl eh %d \nMapa: %s \nO mvp foi: %s \nData: %d/%d/%d de %s\n\n\n\n", pdl, *pdltotal, mapac, mvpc, dia, mes, ano, horario);
                fprintf(file, "Win! \t+%d\t %d/%d/%d de %s\t mapa:%s\tMVP:%s\n", pdl, dia, mes, ano, horario, mapac,mvpc);
                pdlatual = fopen("pdl.txt", "w");
                fprintf(pdlatual, "%d\n", *pdltotal);
                fclose(pdlatual);
                getch();
            }
            else{
                system("cls");
            	pdlatual = fopen("pdl.txt", "r");
                fgets(pdltotalchar, 5, pdlatual);
                fclose(pdlatual);
                *pdltotal = atoi(pdltotalchar) - pdl;
                printf("Lose!  perdeu %d pdl e agora seu pdl eh %d \nMapa: %s \nO mvp foi: %s \nData: %d/%d/%d de %s\n\n\n\n", pdl, *pdltotal, mapac, mvpc, dia, mes, ano, horario);
                fprintf(file, "Lose! \t%d\t %d/%d/%d de %s\t mapa:%s\tMVP=%s\n", -pdl, dia, mes, ano, horario, mapac,mvpc);
                pdlatual = fopen("pdl.txt", "w");
                fprintf(pdlatual, "%d\n", *pdltotal);
                fclose(pdlatual);
                getch();
            }

            system("cls");
            printf("Ganhou ou mamou?  \n(W) Win    (L) Lose   (S) Sair\n ->");
            scanf(" %c", wl);

            if(*wl != 'W' && *wl !='L' && *wl != 'S'&& *wl != 'w' && *wl !='l' && *wl != 's'){
                printf("ERRRROU!\n");
                registrar(wl,pdltotal);
            }
        }
    }
    fclose(file);
}

int main(){
    int mapa,pdltotal,opcao;
    char pdlc[5];
    char wl;
    FILE *pdlatual;

    setlocale(LC_ALL, "Portuguese");

	pdlatual = fopen("pdl.txt","r");
	fgets(pdlc, 5, pdlatual);
	pdltotal=atoi(pdlc);
	fclose(pdlatual);

    do{
    	system("cls");
        printf("SEU PDL ESTAH EM %d\n---------------------------------------------------------------\n", pdltotal);
	    printf("MENU \n(1)Alterar seu pdl atual \n(2)Registrar uma partida \n(0)Sair \n ->");
	    scanf("%d",&opcao);
		switch(opcao){
	    	case 1 : pdltotal=pdlt();
	    			 break;
	    	case 2 : registrar(&wl,&pdltotal);
	    			 break;
		}
	}while(opcao!=0);

return 0;
}
