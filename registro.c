#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<locale.h>

struct tm *data;

void atualiza_tempo(){
    time_t segundos;
    time(&segundos);
    data = localtime(&segundos);  
}

int getpdl(){
    FILE *pdlatual;
    int pdl;
    char temp1[5];
    pdlatual = fopen("pdl.txt", "r");
    fgets(temp1, 5, pdlatual);
    fclose(pdlatual);
    pdl = atoi(temp1);
    return pdl;
}

void funcao_mapa(char mapac[20]){
    int mapa;
    system("cls");
            printf("====Qual mapa?====\n");
            printf("1-Bank (Banco)\t\t\t2-Border (Fronteira)\t\t3-Chalet\n");
            printf("4-Club House (Casa de Festas)\t5-Coastline (Litoral)\t\t6-Consulate(Consulado) \n");
            printf("7-Kafe Dostoyevsky\t\t8-Kanals (Canal)\t\t9-Oregon \n");
            printf("10-Outback\t\t\t11-Skyscraper (Arranha-ceu)\t12-Villa (Mansao)\n");
            printf("0-\"------\"\n -> ");
            scanf("%d", &mapa);
            system("cls");
    switch(mapa){
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

void funcao_mvp(char mvpchar[10]){
    int mvp;
    system("cls");      
            printf("====Quem foi o MVP?====\n");
            printf("1-CPF\t\t2-Gasly\t\t3-Jompe\n");
            printf("4-Pao\t\t5-Piai\t\t6-Poto\n");
            printf("7-Mizoo\t\t8-Reid\t\t9-Rickson\n0-Random\n->");
            scanf("%d", &mvp);
    switch(mvp){
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

int pdlt(){
	int opcao, pdl;
	FILE *pdlatual;
    system("cls");
	pdl=getpdl();
	printf("Seu pdl está em --> %d \nInsira o valor correto -->",pdl);
    scanf("%d",&pdl);
    pdlatual = fopen("pdl.txt","w");
    fprintf(pdlatual, "%d\n", pdl);
    printf("Seu pdl atual foi alterado para %d\n",pdl);
    fclose(pdlatual);
	getch();
	return pdl;
}

void funcao_horario(char horario[10]){
    switch(data->tm_hour){
                case  0 ... 6 	: strcpy(horario,"Madrugada");
                        break;
                case  7 ... 12 	: strcpy(horario,"Manha");
                        break;
                case  13 ... 18	: strcpy(horario,"Tarde");
                        break;
                case  19 ... 23 : strcpy(horario,"Noite");
                        break;
            };
}

void win(int *pdltotal){
    FILE *file, *pdlatual;
    int pdl;
    char mapac[20], mvpc[10], horario[10];


    printf("Ganhou quanto pdl? \n ->");
    scanf("%d", &pdl);
    *pdltotal = getpdl()+ pdl;
    funcao_mapa(mapac);
    funcao_mvp(mvpc);
    atualiza_tempo();
    funcao_horario(horario);
    system("cls");
    file=fopen("registro.txt","a");
    printf("Win!  ganhou %d pdl e agora seu pdl eh %d \nMapa: %s \nO mvp foi: %s \nData: %d/%d/%d de %s\n\n\n\n", pdl, *pdltotal, mapac, mvpc, data->tm_mday, data->tm_mon+1, data->tm_year+1900, horario);
    fprintf(file, "Win! \t+%d\t %d/%d/%d de %s\t mapa:%s\tMVP:%s\n", pdl, data->tm_mday, data->tm_mon+1, data->tm_year+1900, horario, mapac,mvpc);
    fclose(file);
    pdlatual = fopen("pdl.txt", "w");
    fprintf(pdlatual, "%d\n", *pdltotal);
    fclose(pdlatual);
    getch();
}

void lose(int *pdltotal){
    FILE *file, *pdlatual;
    int pdl;
    char mapac[20], horario[10];


    printf("Perdeu quanto pdl? \n ->");
    scanf("%d", &pdl);
    *pdltotal = getpdl()- pdl;
    funcao_mapa(mapac);
    atualiza_tempo();
    funcao_horario(horario);
    system("cls");
    file=fopen("registro.txt","a");
    printf("Lose!  perdeu %d pdl e agora seu pdl eh %d \nMapa: %s \nData: %d/%d/%d de %s\n\n\n\n", pdl, *pdltotal, mapac, data->tm_mday, data->tm_mon+1, data->tm_year+1900, horario);
    fprintf(file, "Lose! \t%d\t %d/%d/%d de %s\t mapa:%s\n", -pdl, data->tm_mday, data->tm_mon+1, data->tm_year+1900, horario, mapac);
    fclose(file);
    pdlatual = fopen("pdl.txt", "w");
    fprintf(pdlatual, "%d\n", *pdltotal);
    fclose(pdlatual);
    getch();
}


void registrar(char *wl, int *pdltotal){
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
            if(*wl=='w'||*wl=='W'){
                win(pdltotal);
            }
            else{
                lose(pdltotal);
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

    pdltotal=getpdl();
	
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
