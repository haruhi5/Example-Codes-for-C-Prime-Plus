#include <stdio.h>
void swap_content(int *u, int *v);
void swap_addr(int *u, int *v); // no way to swap address !!!

int main(void)
{

    int x = 5, y = 10;
    // this x is actually a nickname of 5 which store in the physical register
    // you can not &x = &y;
    printf("Swap content\n");
    printf("Originally x=%d in %p,y=%d in %p\n", x, &x, y, &y);
    swap_content(&x, &y);
    printf("After swap x=%d in %p,y=%d in %p\n", x, &x, y, &y);

    int *px = &x, *py = &y; // assign the physical address to a pointer variable
    printf("Addr x: %p, y: %p\n", px, py);
    swap_content(px, py);
    printf("Addr x: %p, y: %p\n", px, py);

    printf("px is a pointer variable in %p\n", &px);
    printf("py is a pointer variable in %p\n", &py);

    swap_addr(&px, &py);
    printf("px is a pointer variable in %p\n", &px);
    printf("py is a pointer variable in %p\n", &py);
    printf("After swap px and py x=%d in %p,y=%d in %p\n", *px, px, *py, py);
    printf("But when ref with x and y it should not change x=%d in %p,y=%d in %p\n", x, &x, y, &y);
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
    int temp;
    temp = *u;
    *u = *v; // x = y
    *v = temp;
    printf("u=%d:%p\n", *u, u);
    printf("v=%d:%p\n", *v, v);
    return; // it works but not return
}