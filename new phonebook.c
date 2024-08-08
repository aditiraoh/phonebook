#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
void create();
void display();
void del();
void length();
void search();
void update();
struct node
{
        char first_name[20];
        char last_name[20];
        char number[10];

        struct node *next;
        struct node *prev;
};
struct node *start=NULL,*temp,*temp1;
int main()
{
    char num[10];
    char first_name[20];
    int choice;
        while(1)
            {

                printf("\n1. CREATE NEW CONTACT   \n");
                printf("2. DISPLAY ALL CONTACTS  \n");
                printf("3. DELETE A CONTACT  \n");
                printf("4. NO.OF CONTACTS \n");
                printf("5. SEARCH A CONTACT\n");
                printf("6. UPDATE \n");
                printf("7. EXIT \n\n");
                printf("Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                            create();
                            break;
                        case 2:
                            display();
                            break;
                        case 3:
                            del();
                            break;
                        case 4:
                            length();
                            break;
                        case 5:
                            search();
                            break;
                        case 6:
                            update();
                            break;
                         case 7:
                             exit(0);
                        default:
                            printf("\n WRONG CHOICE\n");
                }
            }
}

void create()
{
        struct node *newnode;
        newnode=(struct node *)malloc(sizeof(struct node));
        if(newnode==NULL)
        {
                printf("\n Out of Memory Space:\n");
                exit(0);
        }
        printf("\nENTER FIRST NAME: \n");
        scanf("%s",newnode->first_name);
        printf("ENTER LAST NAME: \n");
        scanf("%s",newnode->last_name);
        printf("ENTER PHONE NUMBER: \n");
        scanf("%s",newnode->number);
        if(start==NULL)
        {
            temp=start=newnode;
            temp->next=NULL;
            temp->prev=NULL;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
            temp->next=NULL;
        }
        printf("\nCONTACT NAMED %s %s CREATED!!! \n",newnode->first_name,newnode->last_name);
}


void display()
{
    struct node*ptr;
    if(start==NULL)
    {
        printf("\n list is empty\n");
        return;
    }
    else
    {
        ptr=start;
        printf("\nCONTACTS ARE:\n\n");
        while(ptr!=NULL)
        {
            printf("\nFIRST NAME= %s\n",ptr->first_name);
            printf("LAST NAME= %s\n",ptr->last_name);
            printf("NUMBER=%s\n\n",ptr->number);
            ptr=ptr->next;
        }
    }
}

void del()
{
    char ch[100];
    gets(ch);
    printf("\nContact name to be deleted: \n");
    gets(ch);
    struct node *p;
    if(start == NULL)
    {
        printf("\nNo Contact exists in this Phone Book List!\n");
        return;
    }
    else
    {
        if(strcmp(((start)->first_name),ch) == 0)
        {
            p=start;
            start = (start)->next;
            free(p);
            printf("CONTACT DELETED!!!\n");
            return;
        }
        else
        {
            p = start;
            while(p->next != NULL)
            {
                if(strcmp((p->next->first_name),ch) == 0)
                {
                    p->next = p->next->next;
                    return;
                }
                p = p->next;

            }
            printf("\nNO SUCH CONTACT EXISTS.\n");
        }
    }
}

void length()
{
    int len=0;
    struct node*temp2;
    temp2=start;
    while(temp2!=NULL)
    {
        len++;
        temp2=temp2->next;
    }
    printf("\nTOTAL NO.OF CONTACTS= %d\n\n",len);
}

void update()
{

        struct node *temp1;

        int pos = 0;
        char newfirst_name[20];
        char newlast_name[20];
        char newnumber[10];
        temp1=(struct node *)malloc(sizeof(struct node));
        temp1 = start;
        printf("\nENTER   FIRST NAME: \n");
        scanf("%s",newfirst_name);
        if(start == NULL)
    {
        printf("\nNo Contact exists in this Phone Book List!\n");
        return;
    }
        if(temp1->first_name==start->first_name)
        {
        printf("\nENTER  new FIRST NAME: \n");
        scanf("%s",&newfirst_name);
        strcpy(temp->first_name,newfirst_name);

        printf("\nENTER new LAST NAME: \n");
        scanf("%s",&newlast_name);
        strcpy(temp->last_name,newlast_name);

        printf("\nENTER new PHONE NUMBER: \n");
        scanf("%s",&newnumber);
        strcpy(temp->number,newnumber);

        }

        else
        {
            temp = temp ->next;
            pos++;
        }

}

void search()
{
    char ch[40];
    gets(ch);
    printf("\nContact name : ");
    struct node *p;
    gets(ch);
    if(start== NULL)
    {
        printf("\nempty\n");
        return;
    }
    else
    {
        p =start;
        while(p != NULL)
        {
            if(strcmp((p->first_name),ch) == 0)
            {
                printf("\nDetails of the contact you searched for:\n");
                printf("\nName %s %s\n",p->first_name,p->last_name);
                printf("\nNumber : %s \n",p->number);
                return;
            }
            p = p->next;
        }
        printf("\nContact does not exist\n ");
    }
}

