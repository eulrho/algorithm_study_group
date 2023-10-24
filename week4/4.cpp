// 회전하는 큐 bj.1021
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

void q_push_back(t_queue *q, t_list *node)
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
void q_push_front(t_queue *q, t_list *node)
{
    t_list *temp;

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

int q_pop_back(t_queue *q)
{
    t_list *delete_node;
    t_list *temp;
    int     delete_data;

    delete_node = q->back;
    delete_data = q->back->data;
    if (q->front != q->back)
    {
        temp = q->front;
        while (temp->next != q->back)
            temp = temp->next;
        temp->next = NULL;
        q->back = temp;
    }
    free(delete_node);
    return (delete_data);
}

int q_pop_front(t_queue *q)
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
        q_push_back(q, new_node);
    }
}

int    find_node(t_queue *q, int data)
{
    t_list *temp;
    int cnt = 0;

    temp = q->front;
    while (temp->data != data)
    {
        temp = temp->next;
        cnt++;
    }
    return (cnt);
}

int main()
{
    int N, M, nb, cnt = 0, idx;
    t_queue *q;
    t_queue *target;
    t_list *temp;

    scanf("%d %d", &N, &M);
    q = make_queue();
    target = make_queue();
    initialize_set(q, N);
    for (int i=0; i<M; i++)
    {
        scanf("%d", &nb);
        q_push_back(target, make_node(nb));
    }
    for (int j=0; j < M;)
    {
        if (target->front->data == q->front->data)
        {
            q_pop_front(q);
            q_pop_front(target);
            j++;
        }
        else
        {
            idx = find_node(q, target->front->data);
            if (idx <= (N - j) / 2)
            {
                for (int i=0; i<idx; i++)
                {
                    temp = make_node(q->front->data);
                    q_push_back(q, temp);
                    q_pop_front(q);
                }
                cnt += idx;
            }
            else
            {
                for (int i=0; i< (N - j) - idx; i++)
                {
                    temp = make_node(q->back->data);
                    q_push_front(q, temp);
                    q_pop_back(q);
                }
                cnt += ((N - j) - idx);
            }
        }
    }
    printf("%d", cnt);
    for (int i=0; i<N-M; i++)
        q_pop_back(q);
    free(q);
    free(target);
    return (0);
}