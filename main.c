#include <stdio.h>
#include <time.h>

#define UNROLL1(x) x
#define UNROLL2(x) UNROLL1(x); UNROLL1(x)
#define UNROLL5(x) UNROLL2(x); UNROLL2(x); UNROLL1(x)
#define UNROLL10(x) UNROLL5(UNROLL2(x))
#define UNROLL100(x) UNROLL10(UNROLL10(x))

struct node
{
    struct node *next;
};

void populate(struct node *list, __uint32_t count)
{
    while(count > 0) {
        list->next = &(list[1]);
        list = list->next;
        count--;
    }
}

int main()
{
    struct timespec start_time, end_time;

    struct node *p;

    __uint32_t count = 100000;

    struct node list[count];
    populate(list, count);
    p = list;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start_time);

    UNROLL100(UNROLL100(UNROLL10(p = p->next)));

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end_time);

    printf("start: %lu\nend: %lu\nTotal: %lu ns\nAverage: %.2f ns", start_time.tv_nsec, end_time.tv_nsec, (end_time.tv_nsec - start_time.tv_nsec), (end_time.tv_nsec - start_time.tv_nsec)/(float)count);

    return 0;
}
