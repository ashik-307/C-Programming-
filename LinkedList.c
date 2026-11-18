
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int a[1000], b[1000];
    int n, q, i, j, x;
    int rearA = -1, topA = -1;
    char op[20];

    struct node *frontL = NULL, *rearL = NULL;
    struct node *topL = NULL, *newnode, *temp;

    scanf("%d %d", &n, &q);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        a[++rearA] = x;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(frontL == NULL)
        {
            frontL = newnode;
            rearL = newnode;
        }
        else
        {
            rearL->next = newnode;
            rearL = newnode;
        }
    }
    for(i = 0; i < q; i++)
    {
        scanf("%s", op);
        if(strcmp(op, "ADD") == 0)
        {
            scanf("%d", &x);
            a[++rearA] = x;
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = x;
            newnode->next = NULL;

            if(frontL == NULL)
            {
                frontL = newnode;
                rearL = newnode;
            }
            else
            {
                rearL->next = newnode;
                rearL = newnode;
            }
        }
        else if(strcmp(op, "SERVE") == 0)
        {
            if(rearA >= 0)
            {
                x = a[0];
                for(j = 0; j < rearA; j++)
                {
                    a[j] = a[j + 1];
                }
                rearA--;
                b[++topA] = x;
                temp = frontL;
                frontL = frontL->next;

                if(frontL == NULL)
                {
                    rearL = NULL;
                }

                free(temp);
                newnode = (struct node*)malloc(sizeof(struct node));
                newnode->data = x;
                newnode->next = topL;
                topL = newnode;
            }
            else
            {
                printf("Queue is empty\n");
            }
        }
        else if(strcmp(op, "REOPEN") == 0)
        {
            if(topA >= 0)
            {
                x = b[topA];
                topA--;
                a[++rearA] = x;
                temp = topL;
                topL = topL->next;
                free(temp);

                newnode = (struct node*)malloc(sizeof(struct node));

                newnode->data = x;
                newnode->next = NULL;

                if(frontL == NULL)
                {
                    frontL = newnode;
                    rearL = newnode;
                }
                else
                {
                    rearL->next = newnode;
                    rearL = newnode;
                }
            }
            else
            {
                printf("Stack is empty\n");
            }
        }
    }
    printf("Array Queue: ");
    for(i = 0; i <= rearA; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("Linked Queue: ");
    temp = frontL;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    printf("Array Stack: ");
    for(i = topA; i >= 0; i--)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    printf("Linked Stack: ");
    temp = topL;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
