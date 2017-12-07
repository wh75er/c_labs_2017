#include "supFunc.h"

void writeToFile(int code, node_t* head, const char* name)
{
        FILE *f = fopen(name, "w");

        node_t* tmp = head;
        while(tmp) {
                fprintf(f, " %d", *((int*)tmp->data));
                tmp = tmp->next;
        }
        fprintf(f, "\n");


        fclose(f);
}



int initNode(node_t **head, FILE *f)
{
        *head = NULL;
        int num;

        while(!feof(f)) {
                if(fscanf(f, "%d", &num)) {
                        push(head, num);
                }
                else
                        return FAILED_TO_INIT;
        }

        fclose(f);
        return OK;
}



int fileOpen(FILE **f, const char *name)
{
        *f = fopen(name, "r");
        if(!*f) {
                return FILE_OPEN_ERROR;
        }
        return OK;
}

int argsInit(int argc)
{
        if(argc != 3)
                return ARGS_ERROR; return OK;
}



int isError(int code, node_t **head, const char* name)
{
        if(code == FILE_OPEN_ERROR) {
                FILE *f = fopen(name, "w");
                freeMem(head);
                fprintf(f, "File open error! Check your input.\n");
                fclose(f);
        }
        if(code == ARGS_ERROR) {
                FILE *f = fopen("emergencyOut_error", "w");
                freeMem(head);
                fprintf(f, "Input parameter error! Check your arguments.\n");
                fclose(f);
        }
        if(code == FAILED_TO_INIT) {
                FILE *f = fopen(name, "w");
                freeMem(head);
                fprintf(f, "Failed to init node!\n");
                fclose(f);
        }
        if(code == REVERSE_NULL_NODE_ERROR) {
                FILE *f = fopen(name, "w");
                freeMem(head);
                fprintf(f, "You cant reverse null node!\n");
                fclose(f);
        }
        if(code == NOTHING_TO_SORT) {
                FILE *f = fopen(name, "w");
                freeMem(head);
                fprintf(f, "There is nothing to do with node, which have only one element.\n");
                fclose(f);
        }

        return code;
}
