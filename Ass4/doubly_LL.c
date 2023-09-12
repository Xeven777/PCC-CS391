 #include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *before;
	struct Node *next;
}node;

node* insert(node *head,int index,int data){
    static int count;
	node *ptr = (node*) malloc (sizeof(node));
	ptr->data = data;
	if (index==0) {
		ptr->next = head;
		ptr->before = head;
		head = ptr;
		printf("\n%d is inserted at index-0 of the list.\n",data);
		count++;
	}
	else if(head == NULL){
	    printf("\nList is empty : index should be 0.\n");
	}
	else {
		int i;
		node *p = (node*) malloc (sizeof(node));
		p = head;
		for(i=0;i<index-1;i++){
			p = p->next;
			if (p == NULL) {
                printf("\nIndex-%d exceeded the length of the list.\n",index);
                printf("Index should be less than %d.\n",count+1);
                return head;
			}
		}
		ptr->next = p->next;
		ptr->before = p;
		p->next = ptr;
		if(ptr->next == NULL){
			return head;
		}
		else {			
			(ptr->next)->before = ptr;
		}
		printf("\n%d is inserted at index-%d of the list.\n",data,index);
		count++;
	}
	return head;
}

node* delete(node *head,int index){
	node *ptr = (node*) malloc (sizeof(node));
	ptr = head;
	if (head==NULL) {
		printf("\nList is empty.\n");
	}
	else if(index == 0){
		head = ptr->next;
		(ptr->next)->before = head;
		printf("\n%d is deleted from Index-%d of the list.\n",ptr->data,index);
		free(ptr);
	}
	else{
		int i;
		node *p = (node*) malloc (sizeof(node));
		for(i=0;i<index-1;i++){
			ptr = ptr->next;
			if (ptr->next == NULL) {
                printf("\nIndex-%d exceeded the length of the list.\n",index);
                return head;
			}
		}
		if (ptr->next == NULL) {
            printf("\nIndex-%d exceeded the length of the list.\n",index);
            return head;
		}
		p = ptr->next;
		if(p->next == NULL){
			ptr->next = NULL;
		}
		else{
			ptr->next = p->next;
			(p->next)->before = ptr;
		}
		printf("\n%d is deleted from Index-%d of the list.\n",p->data,index);
		free(p);
	}
	
	return head;
}

node* reverse(node* head){
	node *curr = (node*)malloc(sizeof(node));
	node *prev = (node*)malloc(sizeof(node));
	node *next = (node*)malloc(sizeof(node));
	prev = NULL;
	next = NULL;
	curr = head;
	while(curr != NULL){
	    next = curr->next;
	    curr->next = prev;
	    curr->before = next;
	    prev = curr;
	    curr = next;
	}
	head = prev;
	prev->before = head;
	printf("\nList is reversed.\n");
	
	return head;
}

void display(node* head){
    if (head==NULL){
        printf("\nList is Empty.\n");
    }
    else{
        node *ptr = (node*)malloc(sizeof(node));
        ptr = head;
        printf("\nDisplaying the elements : \n");
        while(ptr != NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


void main(){
	node *head = NULL;
    int n;
    int data,index;
    do
    {
        printf ("\nMenu for Doubly linked list : \n");
        printf ("1 => Insertion\n2 => Deletion\n3 => Reverse\n");
        printf ("4 => Display\n0 => Exit\n");
        printf ("Enter your choice : ");
        scanf ("%d", &n);
        switch(n)
        {
            case 1 :
            	printf("Enter the index : ");
            	scanf("%d",&index);
            	printf("Enter the data : ");
            	scanf("%d",&data);
                head = insert(head,index,data);
                break;
            case 2 :
            	printf("Enter the index : ");
            	scanf("%d",&index);
                head = delete(head,index);
                break;
            case 3 :
                head = reverse(head);
                break;
            case 4 :
				display(head);
                break;
            case 0 :
                printf("\nTerminating the program.\n");
                break;
            default :
                printf("Invalid Input : Try again!\n");
                break;
        }
    }
    while (n != 0);
}
