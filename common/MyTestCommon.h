#ifndef __MYTEST_COMMON_H__
#define __MYTEST_COMMON_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define felixPrint(fmt, args...) printf("[%s:%d] " fmt "\n", __FUNCTION__, __LINE__, ##args)
#define NAMESTRLEN 24

#define MYTESTSERVICE_FILE "MyTestService.h"

typedef void(*function)(void);
struct serviceHandler{
    char* name;
    function handler;
};

struct serviceProvider{
    char* name;
    int serviceNodeCount;
    struct serviceHandler *node;
};

struct servicePackage{
    char* name;
    int serviceProviderCount;
    struct serviceProvider *provider;
};

#if 0
/* Define an macro to provider the service. */
extern struct servicePackage servicePackageRepo;
#define GET_SERVICE_PACKAGE(name) (name=&servicePackageRepo)
#endif
/* Search service. */
extern function MyTestSearchService(char *serviceName, int serviceNameLen);

/* Print functions. */
void PrintPackage(void);
void PrintPackageList(void);
void PrintCharArray(const char *array, unsigned int arrayLength, const char *flagStr);
void PrintArray(int *array, unsigned int arrayLength, const char *flagStr);
void PrintArrayWithIdx(int *array, int left, int right, const char *flagStr);
void myMemCpy(char *a, char *b, int counts, int bPrint);

#endif
