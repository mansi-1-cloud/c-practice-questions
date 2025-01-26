#include <stdio.h>
#include <stdlib.h>

typedef struct que
{
    int data;
    struct que *next;
} q;

q *enq(q *);
q *deq(q *);
q *mergeAlternating(q *, q *);
void disp(q *);
// void sdisp(q *);

int main()
{
    q *list1 = NULL, *list2 = NULL;
    q *r1 = NULL, *r2 = NULL;

    r1 = enq(r1);
    if (list1 == NULL)
        list1 = r1;
    r1 = enq(r1);

    r2 = enq(r2);
    if (list2 == NULL)
        list2 = r2;
    r2 = enq(r2);

    q *mergedList = mergeAlternating(list1, list2);

    printf("\nMerged List: ");
    disp(mergedList);

    return 0;
}

q *enq(q *r)
{
    q *p = NULL;
    p = (q *)malloc(sizeof(q));
    if (p != NULL)
    {
        printf("value: ");
        scanf("%d", &(p->data));
        if (r == NULL)
        {
            r = p;
        }
        else
        {
            r->next = p;
            r = p;
        }
        r->next = NULL;
    }
    return r;
}

q *deq(q *f)
{
    if (f == NULL)
    {
        printf("empty...");
    }
    else
    {
        q *p = f;
        printf("value: %d", f->data);
        f = f->next;
        free(p);
    }
    return f;
}

void disp(q *f)
{
    if (f == NULL)
    {
        printf("empty...");
    }
    else
    {
        while (f != NULL)
        {
            printf("%d ", f->data);
            f = f->next;
        }
    }
}

// void sdisp(q *f)
// {
//     if (f == NULL)
//     {
//         return;
//     }
//     else
//     {
//         sdisp(f->next);
//         printf("%d ", f->data);
//     }
// }

q *mergeAlternating(q *list1, q *list2)
{
    if (!list1)
        return list2;
    if (!list2)
        return list1;

    q *head = list1;
    q *ptr1 = list1->next;
    q *ptr2 = list2;
    q *current = head;

    int toggle = 1;
    while (ptr1 && ptr2)
    {
        if (toggle)
        {
            current->next = ptr2;
            ptr2 = ptr2->next;
        }
        else
        {
            current->next = ptr1;
            ptr1 = ptr1->next;
        }
        current = current->next;
        toggle = !toggle;
    }

    if (ptr1)
    {
        current->next = ptr1;
    }
    else
    {
        current->next = ptr2;
    }

    return head;
}