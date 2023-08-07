#include "ulist.h"

void initialize_list( UnorderedList *list ){
    list->head = NULL;
}

void add_begin( UnorderedList *list, void *data ){
    Node *new_node = calloc( 1, sizeof( Node ) );

    new_node->data = data;
    new_node->next = list->head;

    list->head = new_node;
}

void add_end( UnorderedList *list, void *data ){
    Node *new_node = calloc( 1, sizeof( Node ) );

    new_node->data = data;
    new_node->next = NULL;

    Node *curr = list->head;
    if( curr == NULL ){
        list->head = new_node;
    }
    else{
        Node *prev = NULL;
        while( curr != NULL ){
            prev = curr;
            curr = curr->next;
        }
        prev->next = new_node;
    }
}

void *delete_begin( UnorderedList *list ){
    if( list->head == NULL ){
        return NULL;
    }

    Node *curr = list->head;
    void *ptr = curr->data;

    list->head = curr->next;
    free( curr );

    return ptr;
}

void *delete_end( UnorderedList *list ){
    if( list->head == NULL ){
        return NULL;
    }

    Node *curr = list->head;
    void *ptr = NULL;
    if( curr->next == NULL ){
        ptr = curr->data;
        free( curr );
        list->head = NULL;

        return ptr;
    }

    Node *prev = NULL;
    while( curr->next != NULL ){
        prev = curr;
        curr = curr->next;
    }
    ptr = curr->data;
    free( curr );
    prev->next = NULL;
    return ptr;
}

void print_list( const UnorderedList *list, PRINT print ){
    Node *curr = list->head;

    puts( "***LIST***");
    while( curr != NULL ){
        print( curr->data );
        curr = curr->next;
    }
}

void delete_all( UnorderedList *list ){
    Node *curr = list->head;
    
    while( curr != NULL ){
        Node *to_del = curr;
        curr = curr->next;
        if( to_del->data != NULL ){
            free( to_del->data );
            to_del->data = NULL;
        }
        free( to_del );

    }

    list->head = NULL;
}