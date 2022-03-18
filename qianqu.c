#include <stdio.h>  
#include <stdlib.h>  
    
struct node    
{  
    int data;    
    struct node * next;    
};    
    
typedef struct node NODE;   
typedef struct node * PNODE;  
   
PNODE createlink( PNODE q, int num );  
void outlist( PNODE );    
int findata( PNODE p, int data );
  
int main( )    
{
    int data,num;
    char a;
    PNODE head,p;    
    
    head = (PNODE)malloc( sizeof(NODE) );    
    head->next = NULL;    
    head->data = -1;
    p=head;    
    
    while ( 1 )    
    {   scanf("%d", &data);
        p=createlink (p, data);    
        if ( (a=getchar())=='\n' ) break;   
    } 
    scanf("%d",&num);
    if(!findata(head,num)) printf("该结点没有前驱结点\n");
    else outlist( head );    
    return 0;    
}    
    
PNODE createlink( PNODE q, int num )  
{   PNODE p;  
    p = (PNODE)malloc( sizeof(NODE) );   
    p->data = num;  
    p->next = q->next;   
    q->next = p;  
    return p;  
}  
  
void outlist( PNODE head )    
{   PNODE p;    
    p = head->next;    
    while ( p->next!= NULL )    
    {   printf("%d ", p->data);    
        p = p->next;    
    }
    printf("%d\n", p->data);    
}
int findata(PNODE p,int data)
{
    PNODE r;
    PNODE q=p;p=p->next;
    if(p->data==data)return 0;
    r=q;q=p;p=p->next;
    while(1)
    {
        if(p->data==data)
        {
            r->next=q->next;
            free(q);
            return 1;
        }
        r=q;q=p;p=p->next;
    }
}