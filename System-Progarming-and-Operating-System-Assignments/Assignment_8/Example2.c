 
void *thread(void *vargp); 
int main() 
{ 
 pthread_t tid; 
 pthread_create(&tid,NULL,thread,NULL); 
 pthread_join(tid,NULL); 
} 
 
/* Thread  Routine*/ 
 
void *thread(void *vargp) 
{ 
 printf(“Hello World!\n”); 
