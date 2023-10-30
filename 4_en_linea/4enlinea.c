#include <stdio.h>
#include <windows.h>

//4 en linea 

//generacion tablero
void tablero(char matriz[6][7]);
void mostrar(char matriz[6][7]);

//verificacion de jugada de ficha permitida
char verificar (int n,int x,int lista[],char matriz[6][7]);

//Posicion a poner ficha 
int juego(char matriz[6][7],int n,int lista[],int x);

//verificaciones ganadores por direccion
char ver_horizontal(char matriz[6][7]);
char ver_vertical(char matriz[6][7]);
char ver_diagonal(char matriz[6][7]);

//finalizacion programa 
char winner(char matriz[6][7],int n);

int main()
{

system("cls");

char mesa[6][7];
int disp[7]={5,5,5,5,5,5,5};
int turno=1;
int ficha=0;
char ganador='f';


tablero(mesa);

mostrar(mesa);

do
{
    juego(mesa,turno,disp,ficha);
    

    system("cls");

    mostrar(mesa);

    ganador=winner(mesa,turno);

    turno++;


} while (ganador=='f');

if (ganador=='E')
{
    printf("Empate!!\n");
}

system("pause"); 


    return 0;
}

//genracion y mostrar tablero

void tablero(char matriz[6][7]){
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            matriz[i][j]=' ';
        }
        
    }
    
}

void mostrar(char matriz[6][7]){
    printf("_________________________________________________________________________________________________________________\n");

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("|\t%c\t",matriz[i][j]);
        }
        printf("|");
        printf("\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        
    }
    printf("\n\t1\t\t2\t\t3\t\t4\t\t5\t\t6\t\t7\n");
    printf("\n");
}

//------------------------------------------------------------------------------------------------------------

//verifiacion de jugada legal
char verificar (int n,int x,int lista[],char matriz[6][7]){
    char band='f';

    if (lista[x]>=0 && x<7 && x>=0)
    {
        if (n%2==0)
        {

            matriz[lista[x]][x]='O';


        }
        else
        {
            matriz[lista[x]][x]='x';
        }
        
        band='t';

        lista[x]=lista[x]-1;
    }

    return band;
    
    
}
//solicitud de jugada

int juego(char matriz[6][7],int n,int lista[],int x){
    int i;
    do
    {
        if (n%2==0)
        {
            printf("Jugador 2 Selecciona la columna para la ficha: "); scanf("%i",&i);
        }
        else
        {
            printf("Jugador 1 Selecciona la columna para la ficha: "); scanf("%i",&i);

        }

        x=i-1;
    } while (verificar(n,x,lista,matriz)=='f');

    return i-1;    
    

}

//Verificacion ganador direcciones
char ver_horizontal(char matriz[6][7]){
    char band='f';
    int cont=1;
    char p_winner;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (matriz[i][j]==matriz[i][j+1]&&matriz[i][j]!=' ')
            {
                cont++;
            }
            else
            {
                cont=1;
            }

            if (cont==4)
            {
                p_winner=matriz[i][j];
                band='t';
                printf("El jugador ganador es: %c!\n",p_winner);
                break;
            }
            
            
        }
        cont=1;
        
    }

    

    return band;

}

char ver_vertical(char matriz[6][7]){
    char band='f';
    int cont=1;
    char p_winner;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (matriz[j][i]==matriz[j+1][i]&&matriz[j][i]!=' ')
            {
                cont++;
            }
            else
            {
                cont=1;
            }

            if (cont==4)
            {
                p_winner=matriz[j][i];
                band='t';
                printf("El jugador ganador es: %c!\n",p_winner);
                break;
            }
            
            
        }
        cont=1;
        
    }

    return band;

}

char ver_diagonal(char matriz[6][7]){
    int x=0,y=6;
    int a=0;
    int cont = 1;
    char p_winner;
    char band='f';
    int x_2,y_2;

    //vericiacion diagonal de 0,6 hacia abajo
    
    for ( a = 0; a <= 5; a++)
    {
        x_2=0+a;
        y_2=6-a;
        cont=1;
        for ( x=0 , y_2 ; x <= x_2 && y_2 <= y; x++,y_2++)
        { 
            if (matriz[x][y_2]==matriz[x+1][y_2+1]&&matriz[x][y_2]!=' ')
            {
                cont++;
            }
            else
            {
                cont=1;
            }

            if (cont==4)
            {
                p_winner=matriz[x][y_2];
                band='t';
                printf("El jugador ganador es: %c!\n",p_winner);
                break;
            }
            
            
            
        }
        
    }

    x=5;
    y=5;

    cont=1;

    for ( a=5 ; a >= 0; a--)
    {
        y_2=0+a;
        x_2=5-a;
        cont=1;
        for ( y=0 , x_2 ; y <= y_2 && x_2 <= x; y++,x_2++)
        { 
            if (matriz[x_2][y]==matriz[x_2+1][y+1]&&matriz[x_2][y]!=' ')
            {
                cont++;
            }
            else
            {
                cont=1;
            }

            if (cont==4)
            {
                p_winner=matriz[x][y_2];
                band='t';
                printf("El jugador ganador es: %c!\n",p_winner);
                break;
            }
            
            
            
        }
        
    }

    //verificacion diagonal de 0,0 hacia abajo

    x=0;
    y=0;

    a=0;
    cont=1;

    for (a = 0; a <= 5; a++)
    {
        x=a;
        cont=1;
        for ( x ,y=0; x >= 0 && y <= a; x--, y++)
        {
            if (matriz[x][y]==matriz[x-1][y+1]&&matriz[x][y]!=' ')
            {
                cont++;
            }
            else
            {
                cont=1;
            }
            
            if (cont==4)
            {
                p_winner=matriz[x][y];
                band='t';
                printf("El jugador ganador es: %c!\n",p_winner);
                break;
            }
            
            
        }
        
    }

    x=5;
    y=0;

    a=0;
    cont=1;
    int i=0;
    for (a = 1; a <= 6; a++)
    {
        y=a;
        cont=1;
        for ( x=5 , y; x >= i && y <= 6; x--, y++)
        {
            if (matriz[x][y]==matriz[x-1][y+1]&&matriz[x][y]!=' '&&y<=5)
            {
                cont++;
            }
            else
            {
                cont=1;
            }
            
            if (cont==4)
            {
                p_winner=matriz[x][y];
                band='t';
                printf("El jugador ganador es: %c!!\n",p_winner);
                break;
            }
            
            
        }

        i++;
        
    }
    



    return band;
    
    
    
}

//Finalzacion de juego con ganador
char winner(char matriz[6][7],int n){
    char band='f';

    if (ver_horizontal(matriz)=='t'||ver_vertical(matriz)=='t'||ver_diagonal(matriz)=='t')
    {
        band='t';
    }
    

    if (n>=42)
    {
        band='E';
    }
    
    return band;
    
}


