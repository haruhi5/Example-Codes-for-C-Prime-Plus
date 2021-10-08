#include <stdio.h>
void swap_content(int *u, int *v);
void swap_addr(int *u, int *v);
void swap_addr2(int *u, int *v);

int main(void)
{

    int x = 5, y = 10;
    printf("Swap content\n");
    printf("Originally x=%d in %p,y=%d in %p\n", x, &x, y, &y);
    swap_content(&x, &y);
    printf("After swap x=%d in %p,y=%d in %p\n", x, &x, y, &y);

    int *px = &x, *py = &y;
    printf("px is a pointer variable in %p\n", &px);
    printf("py is a pointer variable in %p\n", &py);

    swap_addr2(&px, &py);
    printf("px is a pointer variable in %p\n", &px);
    printf("py is a pointer variable in %p\n", &py);

    // printf("Swap address\n");
    // printf("Originally xx=%d in %p,yy=%d in %p\n", x, &x, y, &y);
    // swap_addr(px, py);
    // printf("After swap xx=%d in %p,yy=%d in %p\n", *&x, &x, *&y, &y);
    printf("After swap xx=%d in %p,yy=%d in %p\n", *px, px, *py, py);

    // int xx = 5, yy = 10;
    // printf("Swap address\n");
    // printf("Originally xx=%d in %p,yy=%d in %p\n", xx, &xx, yy, &yy);
    // swap_addr(px, py);
    // printf("After swap xx=%d in %p,yy=%d in %p\n", *&xx, &xx, *&yy, &yy);

    // the address don't change
    // if correct show be: Swap address
    // Originally xx=5 in 000000000061FE14,yy=10 in 000000000061FE10
    // After swap xx=10 in 000000000061FE10,yy=5 in 000000000061FE14
    return 0;
}

void swap_content(int *u, int *v)
{
    int temp;
    temp = *u;
    *u = *v; // x = y
    *v = temp;
    return;
}

void swap_addr(int *u, int *v)
{
    printf("u=%d:%p\n", *u, u);
    printf("v=%d:%p\n", *v, v);
    int *temp;
    temp = u;
    u = v;
    v = temp;
    printf("u=%d:%p\n", *u, u);
    printf("v=%d:%p\n", *v, v);
    return; // it works but not return
}

void swap_addr2(int *u, int *v)
{
    printf("u=%d:%p\n", *u, u);
    printf("v=%d:%p\n", *v, v);
    int temp;
    temp = *u;
    *u = *v; // x = y
    *v = temp;
    printf("u=%d:%p\n", *u, u);
    printf("v=%d:%p\n", *v, v);
    return; // it works but not return
}