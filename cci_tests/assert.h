#define ASSERT(test, message) assert(test,message);

void assert(int test, char* message)
{
    if (!test) { 
        printf("%s\n",message); 
        exit(1);
    }
}
