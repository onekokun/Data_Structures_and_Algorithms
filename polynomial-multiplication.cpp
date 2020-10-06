#include <iostream>
using namespace std;

struct node
{
    int coeff;
    int exp;
    struct node* next;
};

void make(int x, int y,struct node** head)
{
    struct node * nNode = (struct node*) malloc(sizeof(struct node));
    nNode->coeff = x;
    nNode->exp = y;
    nNode->next = NULL;

    if(*head == NULL)
        *head = nNode;
    else
    {
        struct node* ptr = *head;

        while(ptr->next!=NULL)
            ptr = ptr->next;

        ptr->next= nNode;
    }
}

void print(struct node* head)
{
    struct node* ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->coeff<<"x^"<<ptr->exp<<"+";
        ptr = ptr->next;
    }
    cout<<0<<endl;
}

bool conExp(struct node* temp,int exponent)
{

    bool exist = false;
    while(temp!=NULL)
    {
        if(temp->exp == exponent)
            exist = true;
        temp=temp->next;
    }
    return exist;
}

void multiply(struct node* ptr1, struct node* ptr2,struct node** ptr)
{

    while(ptr1!=NULL && ptr2!=NULL)
    {
        struct node* temp = ptr2;

        while(ptr1!=NULL)
        {
            ptr2 = temp;
            while(ptr2!=NULL)
            {
                int exponent = ptr1->exp+ptr2->exp;
                int coefficient = ptr1->coeff*ptr2->coeff;
                if(!conExp(*ptr,exponent))
                {
                    make(coefficient, exponent, ptr);
                }

                else
                {
                    struct node* temp2 = *ptr;
                    while(temp2->exp != exponent)
                        temp2 = temp2->next;

                    temp2->coeff += coefficient;

                }
                ptr2 = ptr2->next;
            }

        ptr1 = ptr1->next;
        }

    }
}

int main(void)
{
    struct node *poly1 = NULL, *poly2 = NULL, *poly  = NULL;

    make(2,2,&poly1);
    make(3,1,&poly1);
    make(1,0,&poly1);
    print(poly1);

    make(4,1,&poly2);
    make(2,0,&poly2);
    print(poly2);

    make(0,-1,&poly);

    multiply(poly1,poly2,&poly);

    poly = poly->next;
    print(poly);
}