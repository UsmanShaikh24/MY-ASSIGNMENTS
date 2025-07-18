typedef struct  
{ 
int num1; 
int num2; 
}NUM; 
void* sum_function(void *argp); 
8. Mutual Exclusion and Synchronization of threads   
int main()  
{ 
pthread_t th1; 
NUM N1; 
int n1, n2; 
int ret_val; 
printf("Enter num1\n"); 
scanf("%d",&n1); 
printf("Enter num2\n"); 
scanf("%d",&n2); 
N1.num1 = n1; 
N1.num2 = n2; 
pthread_create(&th1, NULL, sum_function, (void*) &N1); 
pthread_join(th1, (void*)&ret_val); 
printf("sum = %d\n",ret_val); 
return 0;  
} 
void* sum_function(void *argp) 
{ 
NUM *N2 = (NUM*) argp; 
int a = N2>num1; 
int b = N2>num2; 
int sum = a + b; 
return (void*)sum;  
}