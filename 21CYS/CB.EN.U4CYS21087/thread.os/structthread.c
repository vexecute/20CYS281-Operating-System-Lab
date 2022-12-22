struct argfunc{
    int a;
    int b;
}
void *addition(void *arg){
    struct addpanu *obj=arg;
    int c=obj->a+obj->b;
    print("%d ", c);
}
void *printWelcomeMessage(void *names) {
    
   sleep(2);    
   char *name = (char *)names;    
   printf("\n[THREAD] Hello, Welcome %s.", name);
   pthread_exit(NULL);
   
}

int main () {

    struct argfunc mobj;
    mobj.a=5;
    mobj.b=10;
    mobj.name="Welcome"
    {
        /* data */
    };
    pthread_create(&thread, NULL, addition, &mobj[]);
   // thread defintion
   pthread_t threads[7];
   
   // parameter to be passed to the called function - printWelcomeMessage
   char names[10][15] = {"Amritha","Praveen","Saurabh","Sangeetha","Lakshmy","Srinivasan","Ramaguru"};
   
   int result;
   
   for(int i = 0; i < 7; i++ ) {
    sleep(1);
   
      printf("\n[MAIN] Creating thread, %d", i);
      
      // Creating the threading and thus calling the function with parameter passed to it
      result = pthread_create(&threads[i], NULL, printWelcomeMessage, (void *)names[i]);
      if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
      }
      
   }
   
   // Exit the thread
   pthread_exit(NULL);
}