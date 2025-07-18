#include<pthread.h> 
 
  void *thread(void *vargp); 
 
  int main() 
  { 
   pthread_t tid; 
   pthread_create(&tid,NULL,thread,NULL); 
        exit(0); 
     } 
 
  void *thread(void *vargp) 
  { 
   printf(“Hello World!\n”); 
   return NULL; 
  }