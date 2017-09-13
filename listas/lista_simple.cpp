#include <stdio.h>
#include <stdlib.h>
typedef struct elemento
{
    int dato;
    struct elemento *sig;
}Elemento;

typedef struct ListaIdentificar
{
    Elemento *inicio;
    Elemento *fin;
    int tamano;
}Lista;

void menu(void);
void inicializa(Lista *);

Elemento * creaNodo(void);
void imprime(Lista *);
int inserta_primer_elem(Lista *, Elemento *);
int inserta_al_inicio(Lista *, Elemento *);
int inserta_al_final(Lista *, Elemento *);
int inserta_en_pos(Lista *, Elemento *, int);
int elimina_al_inicio(Lista *);
int elimina_al_final(Lista *);
int elimina_ultimo(Lista *);//lista con 1 elemento
int elimina_en_pos(Lista *, int);
void destruye_lista(Lista *);
int cont=0;

int main(void)
{
    int opcion, pos;
    Lista lista1;
    Elemento *nvo;
    inicializa(&lista1);
    do
    {
        menu();
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1: nvo=creaNodo();
                    if(nvo!=NULL){
                        if(inserta_primer_elem(&lista1, nvo))
                            printf("Primer elemento insertado con éxito.");
                        else{
                            cont--;
                            free(nvo);
                            printf("Error.La lista ya contiene elementos.");
                        }
                    }
                    else
                        printf("Error.No se pudo crear nodo.");
                    break;
                    
            case 2: nvo=creaNodo();
                    if(nvo!=NULL)
                    {
                        if(inserta_al_inicio(&lista1,nvo))
                            printf("Elemento insertado con éxito.");
                        else
                        {
                            cont--;
                            free(nvo);
                            printf("Error.Lista vacía.");
                        }
                    }
                    else
                        printf("Error.No se pudo crear nodo.");
                    break;
            case 3: nvo=creaNodo();
                    if(nvo!=NULL)
                    {
                        if(inserta_al_final(&lista1,nvo))
                            printf("Elemento insertado con éxito.");
                        else
                        {
                            cont--;
                            free(nvo);
                            printf("Error.Lista vacía.");
                        }
                    }
                    else
                        printf("Error.No se pudo crear nodo.");
                    break;
            case 4: nvo=creaNodo();
                    if(nvo!=NULL)
                    {
                        printf("¿En qué pos desea insertar?: ");
                        scanf("%d", &pos);
                        if(inserta_en_pos(&lista1,nvo,pos))
                            printf("Elemento insertado con éxito.");
                        else
                        {
                            cont--;
                            free(nvo);
                            printf("Error.");
                        }
                    }
                    else
                        printf("Error.No se pudo crear nodo.");
                    break;
            case 5: if(elimina_ultimo(&lista1))
                        printf("Nodo eliminado.");
                    else
                        printf("Error.");
                    break;
            case 6: if(elimina_al_inicio(&lista1))
                        printf("Nodo eliminado.");
                    else
                        printf("Error.");
                    break;
            case 7: if(elimina_al_final(&lista1))
                        printf("Nodo eliminado.");
                    else
                        printf("Error.");
                    break;
            case 8: printf("¿En qué pos desea eliminar?: ");
                    scanf("%d", &pos);
                    if(elimina_en_pos(&lista1, pos))
                        printf("Nodo eliminado.");
                    else
                        printf("Error.");
                    break;
            case 9: if(lista1.tamano!=0)
                    {
                        destruye_lista(&lista1);
                        printf("Lista destruida");
                    }
                    else
                        printf("Lista vacía.");
                    break;
            case 10:if(lista1.tamano!=0)
                        imprime(&lista1);
                    else
                        printf("Lista vacía.");
                    break;
            case 11: printf("Hasta luego...");
                    break;
            default: printf("Opción inválida");
        }
        system("pause");
    }while(opcion!=11);
}
void menu(void)
{
    system("cls");
    printf("Menú Lista Simple Enlazada.\n\n");
    printf("1) Insertar 1er elemento.\n");
    printf("2) Insertar al inicio.\n");
    printf("3) Insertar al final.\n");
    printf("4) Insertar en alguna posición.\n");
    printf("5) Eliminar último elemento.\n");
    printf("6) Eliminar al inicio.\n");
    printf("7) Eliminar al final.\n");
    printf("8) Eliminar en alguna posición.\n");
    printf("9) Destruir lista.\n");
    printf("10) Imprimir\n");
    printf("11) Salir\n");
    printf("Opción: ");
}

void inicializa(Lista *l)
{
    l->inicio=NULL;
    l->fin=NULL;
    l->tamano=0;
}

Elemento * creaNodo(void){
    Elemento *nvo;
    nvo=(Elemento *)malloc(sizeof(Elemento));
    if(nvo!=NULL)
    {
        nvo->sig=NULL;
        nvo->dato=++cont;
    }
    return nvo;
}

void imprime(Lista *l)
{
    Elemento *aux=l->inicio;
    while(aux!=NULL)
    {
        printf("%d --> ", aux->dato);
        aux=aux->sig;
    }
}
 
int inserta_primer_elem(Lista *l, Elemento *nvo)
{
        if(l->tamano==0){
            l->inicio=nvo;
            l->fin=nvo;
            l->tamano++;
            return 1;
        }
        else
            return 0;
}

int inserta_al_inicio(Lista *l, Elemento *nvo)
{
    if(l->tamano>0)
    {
        nvo->sig=l->inicio;
        l->inicio=nvo;
        l->tamano++;
        return 1;
    }
    else
        return 0;
}

int inserta_al_final(Lista *l, Elemento *nvo){
    if(l->tamano>0)
    {
        l->fin->sig=nvo;
        l->fin=nvo;
        l->tamano++;
        return 1;
    }
    else
        return 0;
}

int inserta_en_pos(Lista *l, Elemento *nvo, int pos)
{
    Elemento *aux=l->inicio;    int i;
    if(l->tamano>0)
    {
        if((pos>0)&&(pos<=(l->tamano)))
        {
            if(pos==1)
                return (inserta_al_inicio(l,nvo));
            else
            {
                for(i=1;i<=(pos-2);i++)
                    aux=aux->sig;
                nvo->sig=aux->sig;
                aux->sig=nvo;
                l->tamano++;
                return 1;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}

int elimina_al_inicio(Lista *l){
    Elemento *aux=l->inicio;
    if(l->tamano>1)
    {
        l->inicio=l->inicio->sig;  //l->inicio=aux->sig;
        free(aux);
        l->tamano--;
        return 1;
    }
    else
        return 0;
}

int elimina_al_final(Lista *l){
    Elemento *aux=l->inicio;   int i;
    if(l->tamano>1){
        for(i=1;i<=(l->tamano-2);i++)
            aux=aux->sig;
        l->fin=aux;
        free(aux->sig);
        l->fin->sig=NULL;
        l->tamano--;
        return 1;
    }
    else
        return 0;
}
int elimina_ultimo(Lista *l)
{
    if(l->tamano==1)
    {
        free(l->inicio);
        inicializa(l);
        return 1;
    }
    else
        return 0;
}
int elimina_en_pos(Lista *l, int pos)
{
    Elemento *aux1=l->inicio, *aux2;   int i;
    if(l->tamano>0)
    {
        if((pos>0)&&(pos<=(l->tamano)))
        {
           if(pos==1)
           {
                if(l->tamano==1)
                    return (elimina_ultimo(l));
                else
                    return (elimina_al_inicio(l));
           }
           else
           {
                if(pos==l->tamano)
                    return (elimina_al_final(l));
                else
                {
                    for(i=1;i<=(pos-2);i++)
                        aux1=aux1->sig;
                    aux2=aux1->sig;
                    aux1->sig=aux2->sig;
                    free(aux2);
                    l->tamano--;
                    return 1;
                }
            }
        }
        else
            return 0;
    }
    else
        return 0;
}
void destruye_lista(Lista *l)
{
    int tmp;
    while(l->tamano>0)
    {
        if(l->tamano==1)
            tmp=elimina_ultimo(l);
        else
            tmp=elimina_al_inicio(l);
    }
}
