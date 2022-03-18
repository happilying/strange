#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node *PNODE;
typedef struct node NODE;
PNODE createhead(void);
PNODE createlink(PNODE p,int data);
void outlist( PNODE head );
int main(void)
{
    int data;
    char a;
    PNODE head1=createhead(),head2=createhead(),head3=createhead(),p=head1,q=head2,r=head3;
    while ( 1 )    
    {   scanf("%d", &data);
        p=createlink (p, data);    
        if ( (a=getchar())=='\n' ) break;   
    }
    while ( 1 )    
    {   scanf("%d", &data);
        q=createlink (q, data);    
        if ( (a=getchar())=='\n' ) break;   
    }
    p=head1->next;
    q=head2->next;
    while(1)
    {
        if(p->data==q->data) 
        {
            r=createlink(r,p->data);
            p=p->next;
        }
    q=q->next;
    if(q==NULL&&p!=NULL)
    {
        p=p->next;
        q=head2->next;
    }
    if(p==NULL)break;
    }
    if(head3->next!=NULL)outlist(head3);
    else printf("没有交集\n");
    return 0;
}
PNODE createhead(void)
{
    PNODE head;
    head=(PNODE)malloc(sizeof(NODE));
    head->data=0;
    head->next=NULL;
    return head;
}
PNODE createlink(PNODE p,int data)
{
    PNODE q;
    q=(PNODE)malloc(sizeof(NODE));
    q->data=data;
    q->next=p->next;
    p->next=q;
    return q;
}
void outlist( PNODE head )    
{   PNODE p;    
    p = head->next;    
    while ( p!= NULL )    
    {   printf("%d ", p->data);    
        p = p->next;    
    } 
    printf("\n");
}
