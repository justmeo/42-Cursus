
#include "get_next_line.h"

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;

//     if (argc == 2)
//     {
//         fd = open(argv[1], O_RDONLY);
//         while (get_next_line(fd, &line) > 0)
//         {
//             printf("%s\n", line);
//             free(line);
//         }
//         close(fd);
//     }
//     return (0);
// }

int main(){
    
    char* fileName = "test1.txt";

    int fd = open(fileName, O_RDWR);
    
    if(fd == -1){
        printf("\nError Opening File!!\n");
        exit(1);
    }
    else{
        printf("\nFile %s opened sucessfully!\n", fileName);
    }

    char buffer[1024];

    int bytesRead = read(fd, buffer, sizeof(buffer));

    printf("%d bytes read!\n", bytesRead);
    printf("File Contents: %s\n", buffer);

    return 0;
}
