#include "ulist.h"
#include "Student.h"

#define Stack UnorderedList
#define initialize_stack initialize_list
#define push add_begin
#define pop delete_begin
#define print_stack print_list



int main( int argc, char **argv ){ //how_much_add_on_top

    assert( argc == 2 ); //comment

    srand( time( NULL ) );

    int n = atoi( *( argv + 1 ) );
    
    Stack stack;
    initialize_stack( &stack );

    for( int i = 1; i <= n; i++ ){
        Student *student = rand_student();
        push( &stack, student );
    }
    
    print_stack( &stack, print_student );

    void *ptr1 = pop( &stack );
    void *ptr2 = pop( &stack );
    void *ptr3 = pop( &stack );

    puts( "" );
    printf( "----- pop:\n" );
    print_student( ptr1 );
    printf( "----- pop:\n" );
    print_student( ptr2 );
    printf( "----- pop:\n" );
    print_student( ptr3 );

    free( ptr1 );
    ptr1 = NULL;
    free( ptr2 );
    ptr2 = NULL;
    free( ptr3 );
    ptr3 = NULL;

    puts( "" );
    print_stack( &stack, print_student );

    delete_all( &stack );



    return 0;
}