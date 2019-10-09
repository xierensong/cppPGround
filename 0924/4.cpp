#include<stdio.h>

enum hello
{
    a,b=99,c,d=-1
};

sturct student{
    char *name;
};
struct student s;
struct student fun(void)
{
    s.name="newton";
    printf("%s\n", s.name);
    s.name="alan";
    return s;
}

int main()
{
    struct student m = fun();
    printf("%s\n", m.name);
    m.name="turing";
    printf("%s\n", s.name);

    
    enum hello m;
    printf("%d\n%d\n%d\n%d\n", a,b,c,d);
    int i = 0;
    for(i = 0; i < 5; i++)
        if (i < 4)
        {
            printf("hello");
            break;
        }
}