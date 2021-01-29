// base pour faire SON shell ;p
// gcc -g -fanalyzer -Wall -Wextra -pedantic micro_shell.c -o micro_shell

#include <stdlib.h> // EXIT_SUCCESS
#include <stdio.h>  // printf
#include <string.h>
#include <sys/types.h> // pid_t
#include <unistd.h>    // fork
#include <sys/wait.h>  // wait

typedef enum {
  false = 0,
  true = 1
} Bool;

Bool is_Finish(char * str1, char*str2){
    if (strlen(str1)!=strlen(str2)) {
        return false ;
    } else {
        int i=0;
        while (str1[i]!='\0' && str2[i]!='\0') {
            if(str1[i]!=str2[i]){
                return false;
            }
        }
        return true;
    }
}

int main(int argc, char * argv[]) {
    // cannot fail always have a name :)
    const char * prog_name = argv[0];
//    printf("welcome into %s\n", prog_name);

//    char * cmp = "3";
//    char * str;
//    str=malloc(sizeof(str)*4096);
//    fgets(str,sizeof(str)*4096, stdin);
////    scanf("%s",str);
//    // dupliquer le processus avec fork
//    while (strcmp(str,"3")!=0) {
//        printf("OKK\n");
////        scanf("%s",str);
//        fgets(str,sizeof(str)*4096, stdin);
//    }
    //int cnt = 0;
    char str[25];
//    printf("saisir :");
//    fgets(str, sizeof(str), stdin);
    int i=0;
    while (i<5) {
        printf("saisir :");
        fgets(str, sizeof(str), stdin);


        char * tab[15];
        int j=0;
        int nbr_arg=0;
    //    tab = {"az","eez",NULL} = tab [][];
        char *test;
        int len = strlen(str);
        char d[] = " ";
        char *p = strtok(str, d);
        while(p != NULL)
          {
              tab[j]=p;

//        printf("'%s'\n", p);
    //        printf("test de res  ;; %s\n", tab[j]);
        p = strtok(NULL, d);

              j++;

          }
        nbr_arg=j;
//        printf("\nnbr chaine %d\n",nbr_arg);
//        printf("\ntest\n");
        for (int i = 0; i<j; i++) {
    //        printf("'%s' \n",tab[i]);
        }
        for (int i = 0; i<3; i++) {
            if (tab[nbr_arg-1][i] == '\n') {
                tab[nbr_arg-1][i]='\0';
            }
//            printf("'%c' \n",tab[nbr_arg-1][i]);

        }

        char *cmd= tab[0];
        int i;
                for (i=0; i<=j; i++) {
                    if (i==j) {
                        tab[i] = NULL;
                    }
//                    printf("conteur i = %d ",i);
//                    printf("%s \n",tab[i]);

                }
        char *arg[j-1];
        for (i=1; i<=j; i++) {
            arg[i-1]=tab[i];
        }

    pid_t pid = fork();

//    printf("Hello from pid<%d>\n", pid);
    //the PID of the child process is returned in the parent
    if (pid > 0) {
        // parent:
//        printf("I am your parent kid'z\n");
        int status = 0;
        wait(&status);
//        printf("My child is done, so my time is done too!\n");
    } else if (pid == 0) {
        // enfant:
        // and 0 is returned in the child.
//        char * prog_name_to_run = argv[1];
//        char * env[2] = { argv[1], NULL };
        // NE PAS FAIRE ./micro_shell micro_shell

        // tel l'agent smith votre memoire est changée en vol comme ça
        // pouf vous devenez le programme a executer
        execvp(cmd, arg);
//        printf("After exec no body, can ear you.\n");
        i++;
    } else {
        // erreur :(
        // On failure, -1 is returned in  the  parent,
        perror("Waouh fork failed everything is totally wrooong!\n");
        return EXIT_FAILURE;
    }


    }
}
