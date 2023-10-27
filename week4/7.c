// 풍선 터뜨리기 bj.2346
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int order;
    int data;
    struct list *next;
} t_list;

typedef struct deque {
    t_list *front;
    t_list *back;
} t_deque;

t_deque *make_deque()
{
    t_deque *q;

    q = (t_deque *)malloc(sizeof(t_deque));
    q->front = NULL;
    q->back = NULL;
    return (q);
}

t_list *make_node(int nb, int data)
{
    t_list *lst;

    lst = (t_list *)malloc(sizeof(t_list));
    lst->order = nb;
    lst->data = data;
    lst->next = NULL;
    return (lst);
}

void q_push_back(t_deque *q, t_list *node)
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

void q_push_front(t_deque *q, t_list *node)
{
    if (q->front == NULL)
    {
        q->front = node;
        q->back = node;
    }
    else
    {
        node->next = q->front;
        q->front = node;
    }
}

int q_pop_back(t_deque *q)
{
    t_list *delete_node;
    t_list *temp;
    int     delete_order;

    delete_node = q->back;
    delete_order = q->back->order;
    if (q->front != q->back)
    {
        temp = q->front;
        while (temp->next != q->back)
            temp = temp->next;
        temp->next = NULL;
        q->back = temp;
    }
    free(delete_node);
    return (delete_order);
}

int q_pop_front(t_deque *q)
{
    t_list *delete_node;
    int     delete_order;

    delete_node = q->front;
    delete_order = q->front->order;
    q->front = q->front->next;
    free(delete_node);
    return (delete_order);
}

void    initialize_set(t_deque *q, int N)
{
    t_list *new_node;
    int data;

    for (int i=1; i<=N; i++)
    {
        scanf("%d", &data);
        new_node = make_node(i, data);
        q_push_back(q, new_node);
    }
}


int main()
{
    int N, info;
    t_deque *q;
    t_list *temp;

    scanf("%d", &N);
    q = make_deque();
    initialize_set(q, N);
    // first
    info = q->front->data;
    printf("%d ", q_pop_front(q));
    while (q->front)
    {
        if (info < 0)
        {
            for (int i=0; i < (-1*info); i++)
            {
                temp = make_node(q->back->order, q->back->data);
                q_push_front(q, temp);
                q_pop_back(q);
            }
        }
        else
        {
            info -= 1;
            for (int i=0; i < info; i++)
            {
                temp = make_node(q->front->order, q->front->data);
                q_push_back(q, temp);
                q_pop_front(q);
            }
        }
        info = q->front->data;
        printf("%d ", q_pop_front(q));
    }
    return (0);
}