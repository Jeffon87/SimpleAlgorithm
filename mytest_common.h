#ifndef __MYTEST_COMMON__
#define __MYTEST_COMMON__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define felixPrint(fmt, args...) printf("[%s:%d] " fmt "\n", __FUNCTION__, __LINE__, ##args)
#define NAMESTRLEN 24

typedef (void *(void)) serviceHandler;
struct node{
    char name[NAMESTRLEN];
    serviceHandler handler;
};

struct serviceProvider{
    list *pre;
    list *next;
    char name[NAMESTRLEN];
    struct node *n;
};

struct service{
    char name[NAMESTRLEN];
    struct serviceProvider *serviceProvider;
};

struct service myTestService = {"MyTestService", NULL};

#define ADD_SERVICEPROVIDER_START(name) \
        do{ \
            struct serviceProvider *serviceProviderPtr = myTestService.serviceProvider; \
            struct serviceProvider *serviceProvider = (struct serviceProvider *)malloc(sizeof(struct serviceProvider)); \
            if(serviceProvider == NULL){ \
                printf("Allocate space for %s service provider failed!\n", #name); \
                break; \
            } \
            serviceProvider->name = #name; \
            serviceProvider->pre = NULL; \
            serviceProvider->next = NULL; \
            serviceProvider->n = NULL; \
            if(serviceProviderPtr == NULL) \
                serviceProviderPtr = serviceProvider; \
            else{ \
                    while(serviceProviderPtr != NULL) serviceProviderPtr = serviceProviderPtr->next; \
                    serviceProviderPtr = &(newServiceProvider); \
                    serviceProvider.pre = serviceProviderPtr; \
            }
            
#define ADD_SERVICEPROVIDER_END(name) \
        }while(0);

#define ADD_SERVICE_START(name) \
        do{ \
            struct node *serviceNode = (struct node *)malloc(sizeof(struct node)); \
            if(serviceNode == NULL){ \
                printf("Allocate space for %s service failed!\n", #name); \
                break; \
            } \
            serviceNode->name = #name; \
            serviceNode->pre = NULL; \
            serviceNode->next = NULL; \
            serviceNode->n = NULL; \
            if(serviceProviderPtr == NULL) \
                serviceProviderPtr = &(newServiceProvider); \
            else{ \
                    while(serviceProviderPtr != NULL) serviceProviderPtr = serviceProviderPtr->next; \
                    serviceProviderPtr = &(newServiceProvider); \
                    newServiceProvider.pre = serviceProviderPtr; \
            }

#define ADD_SERVICE_END(name) \
        }while(0);


/* List operations. */
        

/* Print functions. */
void PrintCharArray(char *array, unsigned int arrayLength, char *flagStr);
void PrintArray(int *array, unsigned int arrayLength, char *flagStr);
void PrintArrayWithIdx(int *array, int left, int right, char *flagStr);
void myMemCpy(char *a, char *b, int counts, int bPrint);

#endif