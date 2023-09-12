#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node* insert_front(node* head, int data){
    node *ptr = (node*)malloc(sizeof(node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    printf("\n%d is inserted at front of the list.\n",data);
    
    return head;
}

node* insert_end(node* head, int data){
    if (head == NULL){
        head = insert_front(head,data);
    }
    else{
        node *ptr = (node*)malloc(sizeof(node));
        node *p = (node*)malloc(sizeof(node));
        p = head;
        while(p->next != NULL){
            p = p->next;
        }
        ptr->data = data;
        ptr->next = NULL;
        p->next = ptr;
        printf("\n%d is inserted at end of the list.\n",data);
    }
    
    return head;
}

node* insert_index(node* head, int index, int data){
    if (head == NULL || index==0){
        head = insert_front(head,data);
    }
    else{
    	int i;
        node *ptr = (node*)malloc(sizeof(node));
        node *p = (node*)malloc(sizeof(node));
        p = head;
        for(i=0;i<index-1;i++){
            p = p->next;
            if (p == NULL) {
                printf("\nIndex-%d exceeded the length of the list.",index);
                head = insert_end(head,data);
                return head;
            }
        }
        ptr->next = p->next;
        p->next = ptr;
        ptr->data = data;
        printf("\n%d is inserted at index-%d of the list.\n",data,index);
    }
    
    return head;
}

node* delete_front(node* head){
    if (head==NULL){
        printf("\nList is Empty.\n");
    }
    else{
        node *ptr = (node*)malloc(sizeof(node));
        ptr = head;
        head = head->next;
        printf("\n%d is deleted from the front of the list.\n",ptr->data);
        free(ptr);
    }
    return head;
}

node* delete_end(node* head){
    if (head==NULL){
        printf("\nList is Empty.\n");
    }
    else{
        if (head->next == NULL){
            head = delete_front(head);
        }
        else{
            node *ptr = (node*)malloc(sizeof(node));
            node *p = (node*)malloc(sizeof(node));
            ptr = head;
            while((ptr->next)->next != NULL){
                ptr = ptr->next;
            }
            p = ptr->next;
            ptr->next = NULL;
            printf("\n%d is deleted from the end of the list.\n",p->data);
            free(p);
        }
    }
    return head;
}

node* delete_index(node* head, int index){
    if (head==NULL){
        printf("\nList is Empty.\n");
    }
    else{
        if (index == 0){
            head = delete_front(head);
        }
        else{
        	int i;
            node *ptr = (node*)malloc(sizeof(node));
            node *p = (node*)malloc(sizeof(node));
            ptr = head;
            for(i=0;i<index-1;i++){
                ptr = ptr->next;
                if (ptr->next == NULL) {
                    printf("\nIndex-%d exceeded the length of the list.\n",index);
                    return head;
                }
            }
            p = ptr->next;
            ptr->next = p->next;
            printf("\n%d is deleted from Index-%d of the list.\n",p->data,index);
            free(p);
        }
    }
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

node* erase_last(node** head){
    node *ptr = (node*)malloc(sizeof(node));
    node *p = (node*)malloc(sizeof(node));
    ptr = *head;
    while((ptr->next)->next != NULL){
        ptr = ptr->next;
    }
    p = ptr->next;
    ptr->next = NULL;
    
    return p;
}

node* erase_index(node** head,int index){
	int i;
    node *ptr = (node*)malloc(sizeof(node));
    node *p = (node*)malloc(sizeof(node));
    ptr = *head;
    for(i=0;i<index-1;i++){
        ptr = ptr->next;
    }
    p = ptr->next;
    ptr->next = p->next;
    
    return p;
}

node* place_index(node* head,int index,node* ptr){
    if (index == 0){
        ptr->next = head;
        head = ptr;
    }
    else{
    	int i;
        node *p = (node*)malloc(sizeof(node));
        p = head;
        for(i=0;i<index-1;i++){
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    
    return head;
}

node* insert(node* head){
    int n,data,index;
    do{
        printf("\nMenu for insertion : \n");
        printf("1 => Insert at front\n");
        printf("2 => Insert at end\n");
        printf("3 => Insert at index\n");
        printf("4 => Display\n");
        printf("0 => Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 :
                printf("Enter the data : ");
                scanf("%d",&data);
                head = insert_front(head,data);
                break;
            case 2 :
                printf("Enter the data : ");
                scanf("%d",&data);
                head = insert_end(head,data);
                break;
            case 3 :
                printf("Enter the index : ");
                scanf("%d",&index);
                printf("Enter the data : ");
                scanf("%d",&data);
                head = insert_index(head,index,data);
                break;
            case 4 :
                display(head);
                break;
            case 0 :
                printf("\nClosing the menu for insertion.\n");
                break;
            default :
                printf("Invalid Input : Try again!\n");
                break;
        }
    }while(n!=0);
    return head;
}

node* delete(node* head){
    int n,index;
    do{
        printf("\nMenu for deletion : \n");
        printf("1 => Delete from front\n");
        printf("2 => Delete from end\n");
        printf("3 => Delete from index\n");
        printf("4 => Display\n");
        printf("0 => Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&n);
        switch(n)
        {
            case 1 :
                head = delete_front(head);
                break;
            case 2 :
                head = delete_end(head);
                break;
            case 3 :
                printf("Enter the index : ");
                scanf("%d",&index);
                head = delete_index(head,index);
                break;
            case 4 :
                display(head);
            case 0 :
            printf("\nClosing the menu for deletion.\n");
                break;
            default :
                printf("Invalid Input : Try again!\n");
                break;
        }
    }while(n!=0);
    
    return head;
}

node* reverse(node* head){
    int index = 0;
    node* ptr = (node*) malloc (sizeof(node));
    node* p = (node*) malloc (sizeof(node));
    ptr = head;
    while(ptr->next != NULL){
        p = erase_last(&head);
        head = place_index(head,index,p);
        index++;
    }
    printf("\nList is reversed.\n");
    
    return head;
}

node* bubble_sort(node* head){
    if (head == NULL) {
        printf("\nList is empty.\n");
        return head;
    }
    else if (head->next == NULL) {
        printf("\nList is sorted.\n");
        return head;
    }
    else {
        int temp;
        node* p1 = (node*) malloc (sizeof(node));
        node* p2 = (node*) malloc (sizeof(node));
        p1 = head;
        while(p1->next != NULL) {
            p2 = p1->next;
            while(p2 != NULL) {
                if (p2->data < p1->data) {
                    temp = p2->data;
                    p2->data = p1->data;
                    p1->data = temp;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
        }
        printf("\nList is sorted.\n");
    }
    
    return head;
}

void main ()
{
    node *head = NULL;
    int n;
    do
    {
        printf ("\nMenu for Linked list : \n");
        printf ("1 => Insertion\n2 => Deletion\n3 => Reverse\n");
        printf ("4 => Sort\n5 => Display\n0 => Exit\n");
        printf ("Enter your choice : ");
        scanf ("%d", &n);
        switch(n)
        {
            case 1 :
                head = insert(head);
                break;
            case 2 :
                head = delete(head);
                break;
            case 3 :
                head = reverse(head);
                break;
            case 4 :
                head = bubble_sort(head);
                break;
            case 5 :
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



