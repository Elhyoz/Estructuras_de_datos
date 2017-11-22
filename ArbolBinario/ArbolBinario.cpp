#include<stdio.h>
#include<stdlib.h>
typedef struct Nodo
{
    int Info;
    struct Nodo *hijoizq;
    struct Nodo *hijoder;
}ElementoDeArbolBin;
typedef ElementoDeArbolBin *ArbolBinario;
void menu(void);
ArbolBinario CrearNodo(int);
void preorden(ArbolBinario);
void enorden(ArbolBinario);
void postorden(ArbolBinario);
ArbolBinario insertar(int, ArbolBinario);
int profundidad(ArbolBinario);
int contarNodos(ArbolBinario);
void volarArbol(ArbolBinario);
int buscar_dato(ArbolBinario, int , int);
void mostrararbol(ArbolBinario, int);
int main()
{
    ArbolBinario p=NULL;  //Arbol vacío
    p=CrearNodo(9);
    p->hijoizq=CrearNodo(7);
    p->hijoder=CrearNodo(1);
    p->hijoder->hijoder=CrearNodo(4);
    p->hijoder->hijoder->hijoder=CrearNodo(4);
    p->hijoder->hijoizq=CrearNodo(8);
     
    int opcion, dato, n, i,contador=0;
    do
    {
        menu();
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
            {
                printf("Introduce el numero de datos a insertar: ");
                scanf("%d", &n);
                for (i=0; i<n; i++)
                {
                    dato=rand()%100;
                    p=insertar(dato, p);
                }
                break;
            }
            case 2:
            {
                printf("Introduce dato: ");
                scanf("%d", &dato);
                p=insertar(dato, p);
                break;
            }
            case 3:
            {
                printf("Ingresa el dato que quieres buscar: ");
                scanf("%d", &dato);
                if(!buscar_dato(p, dato, 0)) printf("Desgraciadamente el numero %d no se encuentra en el arbol\n", dato);
                else printf("Afortunadamente el numero %d si se encuentra en el arbol\n", dato);
                break;  
            }
            case 6:
            {
                printf("El numero total de nodos es: %d\n", contarNodos(p));
                break;
            }
            case 7:
            {
                printf("Recorrido enorden\n");
                enorden(p);
                printf("\nRecorrido preorden\n");
                preorden(p);
                printf("\nRecorrido postorden\n");
                postorden(p);
                printf("\n");
                break;
            }
            case 9:
            {
                printf("La profundidad es: %d\n", profundidad(p));
                break;
            }
            case 20:
            {
                printf("Hasta luego.\n");
                break;
            }   
            case 8:
                printf("Mostrando arbol\n");
                    mostrararbol(p,contador);
                    printf("\n");
                    system("pause");
            break; 
            default:
            {
                printf("Opcion invalida\n");    
            }
        }
        system("pause");
    }while(opcion!=30);
}
void menu(void)
{
    system("cls");
    printf("Operaciones basicas con un arbol Binario\n");
    printf(" ( 1) Llenar un arbol de forma aleatoria.\n");
    printf(" ( 2) Llenar un arbol de forma manual.\n");
    printf(" ( 3) Buscar un dato.\n");
    printf(" ( 4) Suprimir un dato.\n");
    printf(" ( 5) Buscar minimo y maximo.\n");
    printf(" ( 6) Contar nodos.\n");
    printf(" ( 7) Ver recorridos.\n");
    printf(" ( 8) Ver arbol.\n");
    printf(" ( 9) Ver profundidad del arbol.\n");
    printf(" (30) Salir.\n");
    printf("\tElija una opcion: ");
}
ArbolBinario CrearNodo(int x)
{
    ArbolBinario a;
    a=(ArbolBinario)malloc(sizeof(ElementoDeArbolBin));
    if(a!=NULL)
    {
        a->Info=x;
        a->hijoder=a->hijoizq=NULL;
    }
    return a;
}
void preorden(ArbolBinario p)
{
    if(p)
    {
        printf("%d =>", p->Info);
        preorden(p->hijoizq);
        preorden(p->hijoder);
    }
}
void enorden(ArbolBinario p)
{
    if(p)
    {
        enorden(p->hijoizq);
        printf("%d =>", p->Info);
        enorden(p->hijoder);
    }
}
void postorden(ArbolBinario p)
{
    if(p)
    {
        postorden(p->hijoizq);
        postorden(p->hijoder);
        printf("%d =>", p->Info);
    }
}
ArbolBinario insertar(int dato, ArbolBinario p)
{
    if (!p)
    {
        return CrearNodo(dato);
    }
    if (dato<p->Info)
    {
        p->hijoizq=insertar(dato, p->hijoizq);
    }
    else
    {
        p->hijoder=insertar(dato, p->hijoder);
    }
}
int profundidad(ArbolBinario p)
{
    if (p)//p es el arbol y verifica si es nulo
    {
        int pI, pD; // la funcion es recursiva y se manda a llamar haciendo un incremento por cada que se llama la funcion
        pI=profundidad(p->hijoizq); // hace un recorrido por hijo izq
        pD=profundidad(p->hijoder); //der
        if (pI>pD)
        {
            return pI+1;
        }
        else
        {
            return pD+1;
        }
    }
}
int contarNodos(ArbolBinario p)
{
    if (p)
    {
        int nI, nD;
        nD=contarNodos(p->hijoder);
        nI=contarNodos(p->hijoizq);
        return nI+nD+1;
    }
}
int buscar_dato(ArbolBinario p, int numero, int bandera)
{
    if(p)
    {
        if(p->Info == numero) return 1;
        bandera = buscar_dato(p->hijoder, numero, bandera);
        bandera = buscar_dato(p->hijoizq, numero, bandera);  
    }
    else {
        return bandera;
    }
}
 
void mostrararbol(ArbolBinario p, int cont)
{
    int i;
    if(p == NULL)
    return;
    else
    {
    mostrararbol(p->hijoder, cont+1);
    for(i=0;i<cont;i++)
    printf("     ");
    printf("%d\n",p->Info);
    mostrararbol(p->hijoizq,cont+1);
    }
}
