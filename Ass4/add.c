#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

void insert_front(node** head,int data){
    node* ptr = (node*) malloc (sizeof(node));
    ptr->data = data;
    ptr->next = (*head)->next;
    (*head)->next = ptr;
}

void insert_end(node **head,int data){
    node* ptr = (node*) malloc (sizeof(node));
    node* p = (node*) malloc (sizeof(node));
    ptr->data = data;
    p = *head;
    while(p->next != NULL) {
        p = p->next;
    }
    ptr->next = NULL;
	p->next = ptr; 
}

node* add(node *p1,node *p2,node *p){   
    node *ptr1 = (node*) malloc (sizeof(node));
    node *ptr2 = (node*) malloc (sizeof(node));
    ptr1 = p1->next;
    ptr2 = p2->next;  
    int value;
    while(ptr1!=NULL && ptr2!=NULL){
		value = ptr1->data + ptr2->data;
		insert_end(&p,value);
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return p;
}

void display(node* head,int degree){
	node *ptr = (node*) malloc (sizeof(node));
	ptr = (head)->next;
	while(ptr->next != NULL){
		printf("(%d)x^(%d) +",ptr->data,degree--);
		ptr = ptr->next;
	}
	printf("(%d) = 0\n",ptr->data);
}
 
void main(){
    int n1,n2,i,x;
    node* p1 = (node*) malloc (sizeof(node));
    node* p2 = (node*) malloc (sizeof(node));
    node* p = (node*) malloc (sizeof(node));
    p1->next = NULL;
    p2->next = NULL;
    printf("Enter the degree of polynomial-1 :  ");
    scanf("%d",&n1);
    printf("Enter the coefficients of polynomial-1 : \n");
    printf("(Lower to higher order.)\n");
    for(i=0;i<=n1;i++){
        printf("Coefficient of x^(%d) = ",i);
        scanf("%d",&x);
        insert_front(&p1,x);
    }
    printf("\nDisplaying polynomial-1 :\n");
    display(p1,n1);
    printf("Enter the degree of polynomial-2 :  ");
    scanf("%d",&n2);
    printf("Enter the coefficients of polynomial-2 : \n");
    printf("(Lower to higher order.)\n");
    for(i=0;i<=n2;i++){
        printf("Coefficient of x^(%d) = ",i);
        scanf("%d",&x);
        insert_front(&p2,x);
    }
    printf("\nDisplaying polynomial-2 :\n");
    display(p2,n2);
    
    if (n1>n2){
        for(i=n2;i<n1;i++){
            insert_front(&p2,0);
        }
        p = add(p1,p2,p);
        printf("\nPerforming addition of the given polynomials :\n");
    	display(p,n1);
    }
    else if(n2>n1) {
        for(i=n1;i<n2;i++){
            insert_front(&p1,0);
        }
        p = add(p1,p2,p);
        printf("\nPerforming addition of the given polynomials :\n");
    	display(p,n2);
    }
    else{
    	p = add(p1,p2,p);
    	printf("\nPerforming addition of the given polynomials :\n");
    	display(p,n2);
    }
    
}

