#include <stdio.h>

int main(void)
{
    int zippo[4][2] = {{2, 4}, {6, 8}, {1, 3}, {5, 7}};
    printf("zippo = %p, zippo+1=%p\n", zippo, (zippo + 1)); // two int, 8 bits
    printf("zippo[0] = %p, zippo[0] + 1 = %p\n", zippo[0], zippo[0] + 1);
    printf("*zippo = %p,  *zippo + 1 = %p\n", *zippo, *zippo + 1); // 2,6->wrong! zippo is a address of another register which contain two int
    printf("zippo[0][0] = %d\n", zippo[0][0]);                     // so *zippo = address, and address+1 directly add 4 bits
    printf("*zippo[0] = %d\n", *zippo[0]);                         //2
    printf("**zippo = %d\n", **zippo);                             //2
    printf("zippo[2][1] = %d\n", zippo[2][1]);
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1)); // *2?->wrong! 3

    int(*pz)[2]; // a pointer point to 2 int
    pz = zippo;
    // int *pz[2] == int *(pz[2]): two pointers each point to one int
    printf("pz = %p, pz+1=%p\n", pz, (pz + 1)); // two int, 8 bits
    printf("pz[0] = %p, pz[0] + 1 = %p\n", pz[0], pz[0] + 1);
    printf("*pz = %p,  *pz + 1 = %p\n", *pz, *pz + 1); // 2,6->wrong! pz is a address of another register which contain two int
    printf("pz[0][0] = %d\n", pz[0][0]);               // so *pz = address, and address+1 directly add 4 bits
    printf("*pz[0] = %d\n", *pz[0]);                   //2
    printf("**pz = %d\n", **pz);                       //2
    printf("pz[2][1] = %d\n", pz[2][1]);
    printf("*(*(pz+2) + 1) = %d\n", *(*(pz + 2) + 1));
    return 0;
}