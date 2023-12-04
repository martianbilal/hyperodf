// https://github.com/MarkTseng/mySampleCode/blob/master/anage-C-Data-Using-the-GLib-Collections-example/ex-glist-1.c
#include <glib.h>
#include <stdio.h>


struct testing {
    int a;
    int b;
    GString *name;
};


static char *get_string(struct testing *test) {
    return test->name->str;
}


int main(int argc, char** argv) {
    GList* list = NULL;
    struct testing test;
    test.a = 1;
    test.b = 2;
    test.name = g_string_new("Hello world!");
    

    
    list = g_list_append(list, &test);
    printf("The first item is '%s'\n", get_string(list->data));

    list = g_list_insert(list, "Baltimore ", 1);
    printf("The second item is '%s'\n", g_list_next(list)->data);
    
    list = g_list_remove(list, "Baltimore "); 
    printf("After removal of 'Baltimore', the list length is %d\n", g_list_length(list));    
    
    GList* other_list = g_list_append(NULL, "Baltimore ");
    list = g_list_concat(list, other_list);	

    printf("After concatenation: ");
    g_list_foreach(list, (GFunc)printf, NULL);
    list = g_list_reverse(list);	
    
    printf("\nAfter reversal: ");
    g_list_foreach(list, (GFunc)printf, NULL);
    g_list_free(list);
    
    printf("\n");
    
    return 0;
}