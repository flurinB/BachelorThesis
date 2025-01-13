#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void* ptrs[100];

int main() {
    ptrs[0] = malloc(10);
    ptrs[1] = malloc(20);
    free(ptrs[0]);
    ptrs[2] = malloc(15);
    ptrs[3] = malloc(25);
    free(ptrs[1]);
    ptrs[4] = malloc(30);
    free(ptrs[2]);
    ptrs[5] = malloc(12);
    ptrs[6] = malloc(18);
    free(ptrs[3]);
    ptrs[7] = malloc(22);
    free(ptrs[4]);
    ptrs[8] = malloc(28);
    free(ptrs[5]);
    ptrs[9] = malloc(14);
    ptrs[10] = malloc(16);
    free(ptrs[6]);
    ptrs[11] = malloc(24);
    free(ptrs[7]);
    ptrs[12] = malloc(32);
    free(ptrs[8]);
    ptrs[13] = malloc(11);
    ptrs[14] = malloc(19);
    free(ptrs[9]);
    ptrs[15] = malloc(23);
    free(ptrs[10]);
    ptrs[16] = malloc(29);
    free(ptrs[11]);
    ptrs[17] = malloc(13);
    ptrs[18] = malloc(17);
    free(ptrs[12]);
    ptrs[19] = malloc(21);
    free(ptrs[13]);
    ptrs[20] = malloc(31);
    free(ptrs[14]);
    ptrs[21] = malloc(26);
    ptrs[22] = malloc(33);
    free(ptrs[15]);
    ptrs[23] = malloc(27);
    free(ptrs[16]);
    ptrs[24] = malloc(34);
    free(ptrs[17]);
    ptrs[25] = malloc(35);
    ptrs[26] = malloc(36);
    free(ptrs[18]);
    ptrs[27] = malloc(37);
    free(ptrs[19]);
    ptrs[28] = malloc(38);
    free(ptrs[20]);
    ptrs[29] = malloc(39);
    ptrs[30] = malloc(40);
    free(ptrs[21]);
    ptrs[31] = malloc(41);
    free(ptrs[22]);
    ptrs[32] = malloc(42);
    free(ptrs[23]);
    ptrs[33] = malloc(43);
    ptrs[34] = malloc(44);
    free(ptrs[24]);
    ptrs[35] = malloc(45);
    free(ptrs[25]);
    ptrs[36] = malloc(46);
    free(ptrs[26]);
    ptrs[37] = malloc(47);
    ptrs[38] = malloc(48);
    free(ptrs[27]);
    ptrs[39] = malloc(49);
    free(ptrs[28]);
    ptrs[40] = malloc(50);
    free(ptrs[29]);
    ptrs[41] = malloc(51);
    ptrs[42] = malloc(52);
    free(ptrs[30]);
    ptrs[43] = malloc(53);
    free(ptrs[31]);
    ptrs[44] = malloc(54);
    free(ptrs[32]);
    ptrs[45] = malloc(55);
    ptrs[46] = malloc(56);
    free(ptrs[33]);
    ptrs[47] = malloc(57);
    free(ptrs[34]);
    ptrs[48] = malloc(58);
    free(ptrs[35]);
    ptrs[49] = malloc(59);
    
    // Potential use-after-free
    strcpy(ptrs[0], "Hello");  // ptrs[0] was freed earlier
    printf("%s\n", (char*)ptrs[1]);  // ptrs[1] was freed earlier
    
    // More frees
    free(ptrs[36]);
    free(ptrs[37]);
    free(ptrs[38]);
    free(ptrs[39]);
    free(ptrs[40]);
    free(ptrs[41]);
    free(ptrs[42]);
    free(ptrs[43]);
    free(ptrs[44]);
    free(ptrs[45]);
    
    // More potential use-after-free
    *(int*)ptrs[36] = 100;  // ptrs[36] was just freed
    printf("%d\n", *(int*)ptrs[37]);  // ptrs[37] was just freed
    
    // Final frees
    free(ptrs[46]);
    free(ptrs[47]);
    free(ptrs[48]);
    free(ptrs[49]);

    return 0;
}
