// 카드1 bj.2161
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} t_list;

typedef struct queue {
    t_list *front;
    t_list *back;
} t_queue;

t_queue *make_queue()
{
    t_queue *q;

    q = (t_queue *)malloc(sizeof(t_queue));
    q->front = NULL;
    q->back = NULL;
    return (q);
}

t_list *make_node(int nb)
{
    t_list *lst;

    lst = (t_list *)malloc(sizeof(t_list));
    lst->data = nb;
    lst->next = NULL;
    return (lst);
}

void enqueue(t_queue *q, t_list *node)
{
    if (q->front == NULL)
    {
        q->front = node;
        q->back = node;
    }
    else
    {
        q->back->next = node;
        q->back = q->back->next;
    }
}

int dequeue(t_queue *q)
{
    t_list *delete_node;
    int     delete_data;

    delete_node = q->front;
    delete_data = q->front->data;
    q->front = q->front->next;
    free(delete_node);
    return (delete_data);
}

void    initialize_set(t_queue *q, int N)
{
    t_list *new_node;

    for (int i=1; i<=N; i++)
    {
        new_node = make_node(i);
        enqueue(q, new_node);
    }
}

int main()
{
    int N, i = 1;
    t_queue *q;
    t_list *temp;

    scanf("%d", &N);
    q = make_queue();
    initialize_set(q, N);
    while (q->front != q->back)
    {
        if (i % 2 == 1)
            printf("%d ", dequeue(q));
        else
        {
            temp = make_node(q->front->data);
            enqueue(q, temp);
            dequeue(q);
        }
        i++;
    }
    printf("%d", q->front->data);
    dequeue(q);
    free(q);
    return (0);
}