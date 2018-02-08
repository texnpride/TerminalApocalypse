#include <stdio.h>  // The Standard Input and Output library; functions for reading and writing data
#include <string.h> // The String library; functions for manipulating strings
#include <stdlib.h> // The Standard library; general purpose functions
#include <stdio.h>
#define MAX_LEN 128
 
void print_image(FILE *fptr);
 
int main(void)
{
    char *filename = "image.txt";
    FILE *fptr = NULL;
 
    if((fptr = fopen(filename,"r")) == NULL)
    {
        fprintf(stderr,"error opening %s\n",filename);
        return 1;
    }
 
    print_image(fptr);
 
    fclose(fptr);
 
    return 0;
}
 
void print_image(FILE *fptr)
{
    char read_string[MAX_LEN];
 
    while(fgets(read_string,sizeof(read_string),fptr) != NULL)
        printf("%s",read_string);
}
