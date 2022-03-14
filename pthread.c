unsigned int i;
main()
{
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2
    pthread_create( &thread1, NULL, counter_function, (void*) message1);
    pthread_create( &thread2, NULL, counter_function, (void*) message2);
    return 0;
}
void *counter_function( void *ptr ) {
    char *message;
    message = (char *) ptr;
    while(1)
    +ii;
    printf("%s: i = %f\n", message, i);
}