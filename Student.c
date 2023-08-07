#include "ulist.h"
#include "Student.h"

typedef enum { LOWER, UPPER } LETTER_CASE; //jaka wielkość litery

char rand_letter( LETTER_CASE letter_case );
int i_rand( int min, int max );
void rand_name( char *array, size_t max_len );
void rand_email( char *array, size_t max_len );



int cmp_student_by_last_name( const void *a, const void *b ){
    const Student *s1 = a;
    const Student *s2 = b;
    int cmp = strcmp( s1->last_name, s2->last_name );
    return cmp;
}

void print_student( const void *s ){
  assert( s != NULL );
  const Student *st = s;
  printf( "Dane studenta: %s %s, wiek: %u, adres: %s\n", st->first_name, st->last_name, st->age, st->email );
}

char rand_letter( LETTER_CASE letter_case ){
    char letter = i_rand( 65, 90 );
    if( letter_case == LOWER ){
        letter = tolower( letter );
    }
    return letter;
}

int i_rand( int min, int max ){
    assert( min <= max );
    return rand() % ( max - min + 1 ) + min;
}

void rand_name( char *array, size_t max_len ){ //maksymalny rozmiar tablicy, czyli musimy zostawić jedno miejsce na '\0'!
    int length = i_rand( 1, ( int ) max_len - 1 );
    //printf( "\n*%d*\n", length );

    int i = 0;
    *( array + i ) = rand_letter( UPPER );
    for( i = 1; i < length; i++ ){
        *( array + i ) = rand_letter( LOWER );
    }
    *( array + i ) = '\0';
}

void rand_email( char *array, size_t max_len ){
    char tail[] = "@student.agh.edu.pl";
    int length = i_rand( 1, ( int ) max_len - strlen( tail ) - 1 );
    //printf( "\n*%d*\n", length );

    for( int i = 0; i < length; i++ ){
        *( array + i ) = rand_letter( LOWER );
    }
    *( array + length ) = '\0';
    strcat( array, tail );
    
}

Student *rand_student( void ){ //potem trzeba wyczyścić pamięć!!!
    Student *stud = malloc( sizeof( Student ) );
    if( !stud ) return NULL;
    rand_name( stud->first_name, F_NAME_MAX );
    rand_name( stud->last_name, L_NAME_MAX );
    stud->age = i_rand( 19, 30 );
    rand_email( stud->email, EMAIL_MAX );
    //print_student( stud );
    return stud;
}