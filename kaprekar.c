#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


static int ascending(const void *a, const void *b) {
    return (int)((int)(*(unsigned char *)a) - (int)(*(unsigned char *)b));
}

static int descending(const void *a, const void *b) {
    return (int)((int)(*(unsigned char *)b) - (int)(*(unsigned char *)a));
}

int main() {
    int start_val = 4985;
    int val, high_val, low_val, next_val = 0;
    unsigned char *val_str = NULL, *high_str = NULL, *low_str = NULL;

    int length = snprintf( NULL, 0, "%d", start_val );
    val_str = malloc(length + 1);
    high_str = malloc(length + 1);
    low_str = malloc(length + 1);
    val = start_val;

    while (1) {

	    snprintf(val_str, length + 1, "%d", val);
	    printf("%s\n", val_str);
	    strncpy(high_str, val_str, length + 1);
	    strncpy(low_str, val_str, length + 1);

	    qsort(high_str, length, sizeof(unsigned char), &descending);
	    qsort(low_str, length, sizeof(unsigned char), &ascending);
	    printf("high: %s\nlow: %s\n", high_str, low_str);
	    high_val = strtol(high_str, NULL, 10);
	    low_val = strtol(low_str, NULL, 10);
	    next_val = high_val - low_val;

	    if (val == next_val) {
		    break;
	    }
	    val = next_val;

    }
    printf("Kaprekar's constant is %d\n", val);
    free(val_str);
    free(high_str);
    free(low_str);
    return 0;
}

