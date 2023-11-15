#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
extern char **environ;

/* functions  */
int _putchar(char c);                     
void prints(char *str);                   
char *_strconct(char *s1, char *s2);     
char *_strcpy(char *dest, char *src);     
int _strlen(const char *s);               
int _strcmp(char *s1, char *s2);          
char *_strstr(char *str1, char *str2);    
char *_strdup(char *str);                 
char *_memcpy(char *dest, char *src, unsigned int n);     
char *i_toa(int num, int base);                          
int a_toi(char *a);                                      
/*essential functions */

char **splt_str(char *line, char **env);    
void prmp(void);                           
char *_readinput();                          
void _printenv(char **environ);               
void _puts(char *str);                       

/*process */

int execmd_(char **av, char **args, char **environ, int ymh, int kotari);       
char **_search(char **environ);                                                      
char **_which(char *fpath);                                                         
                     
/*signals */

void hdl_sig(int signal);                       
int stat_(char **cmd, char **menged);                 
int *err_or(char *argv, int count, char *args);       


/*memory */
void *_calloc(unsigned int nmemb, unsigned int size);      

#endif /* MAIN_H */
