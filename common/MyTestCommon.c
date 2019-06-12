//#include "algrithmtest.h"
#include "MyTestCommon.h"

/* Extern the service handler start. */
#undef SERVICE_PACKAGE_START
#undef SERVICE_PACKAGE_END
#undef ADD_SERVICEPROVIDER_START
#undef ADD_SERVICEPROVIDER_END
#undef REQUEST_SERVICE
#define SERVICE_PACKAGE_START(name)
#define SERVICE_PACKAGE_END(name)
#define ADD_SERVICEPROVIDER_START(name)
#define ADD_SERVICEPROVIDER_END(name)
#define REQUEST_SERVICE(name) \
        extern void name(void*);

/* Declare the service functions. */
#include MYTESTSERVICE_FILE


/* Declare different service type hadler tables. */
#undef SERVICE_PACKAGE_START
#undef SERVICE_PACKAGE_END
#undef ADD_SERVICEPROVIDER_START
#undef ADD_SERVICEPROVIDER_END
#undef REQUEST_SERVICE
#define SERVICE_PACKAGE_START(name)
#define SERVICE_PACKAGE_END(name)
#define ADD_SERVICEPROVIDER_START(name) static struct serviceHandler name[] = {
#define ADD_SERVICEPROVIDER_END(name) };
#define REQUEST_SERVICE(name) \
        {#name, name},
/* Declare the service array. */
#include MYTESTSERVICE_FILE

/* Declare the provider table. */
#undef SERVICE_PACKAGE_START
#undef SERVICE_PACKAGE_END
#undef ADD_SERVICEPROVIDER_START
#undef ADD_SERVICEPROVIDER_END
#undef REQUEST_SERVICE
#define SERVICE_PACKAGE_START(name)
#define SERVICE_PACKAGE_END(name)
#define ADD_SERVICEPROVIDER_START(name) { \
        #name, sizeof(name)/sizeof(struct serviceHandler), name}
#define ADD_SERVICEPROVIDER_END(name) ,
#define REQUEST_SERVICE(name)

static struct serviceProvider serviceProviderArray[] = {
# include MYTESTSERVICE_FILE
};

/* Declare the package which provide all the service. */
#undef SERVICE_PACKAGE_START
#undef SERVICE_PACKAGE_END
#undef ADD_SERVICEPROVIDER_START
#undef ADD_SERVICEPROVIDER_END
#undef REQUEST_SERVICE
#define SERVICE_PACKAGE_START(name) #name, sizeof(serviceProviderArray)/sizeof(struct serviceProvider), serviceProviderArray
#define SERVICE_PACKAGE_END(name)
#define ADD_SERVICEPROVIDER_START(name)
#define ADD_SERVICEPROVIDER_END(name)
#define REQUEST_SERVICE(name)

struct servicePackage servicePackageRepo = {
# include MYTESTSERVICE_FILE
};

/*  Clean the definition. */
#undef SERVICE_PACKAGE_START
#undef SERVICE_PACKAGE_END
#undef ADD_SERVICEPROVIDER_START
#undef ADD_SERVICEPROVIDER_END
#undef REQUEST_SERVICE

/* Service name split by '.', such as MyTest.sorts.TestHeapSort */
#define MAX_NAME_LEN 30
#define MAX_PATH_DEPTH 3

function MyTestSearchService(char *serviceName, int serviceNameLen)
{
    struct servicePackage *servicePackagePtr = &servicePackageRepo;
    struct serviceProvider *serviceProviderPtr = NULL;
    struct serviceHandler *serviceHandlerPtr = NULL;
    //char ServicePath[MAX_NAME_LEN][MAX_PATH_DEPTH] = {0};
    char *serviceNamePtr = NULL;
    char *serviceNameTmpPtr = serviceName;
    int serviceNameTmpLen = strlen(serviceName);
    int i = 0;

    if(NULL == serviceNameTmpPtr)
        return NULL;

    /**/
    //GET_SERVICE_PACKAGE(servicePackagePtr);
    serviceNamePtr = servicePackagePtr->name;
    if((0 != strncmp(serviceNamePtr, serviceNameTmpPtr, strlen(serviceNamePtr))) ||
        (serviceNameTmpLen <= strlen(serviceNamePtr)) ||
        (serviceNameTmpPtr[strlen(serviceNamePtr)] != '.'))
        printf("No this type of package!\n");

    /* Justify the position and the length. */
    serviceNameTmpPtr = serviceNameTmpPtr + strlen(serviceNamePtr) + 1;
    serviceNameTmpLen = serviceNameTmpLen - ( strlen(serviceNamePtr) + 1);
    for(i=0; i<servicePackagePtr->serviceProviderCount; i++)
    {
        serviceNamePtr = servicePackagePtr->provider[i].name;
        if(((0 != strncmp(serviceNamePtr, serviceNameTmpPtr, strlen(serviceNamePtr))) ||
            (serviceNameTmpLen <= strlen(serviceNamePtr)) ||
            (serviceNameTmpPtr[strlen(serviceNamePtr)] != '.')) &&
            (i == servicePackagePtr->serviceProviderCount - 1))
            {
                printf("No this type of service provider!\n");
                return NULL;
            }
        else{
            serviceProviderPtr = servicePackagePtr->provider + i;
            break;
        }
    }

    /* Justify the position and the length. */
    serviceNameTmpPtr = serviceNameTmpPtr + strlen(serviceNamePtr) + 1;
    serviceNameTmpLen = serviceNameTmpLen - (strlen(serviceNamePtr) + 1);
    for(i=0; i<serviceProviderPtr->serviceNodeCount; i++)
    {
        serviceNamePtr = serviceProviderPtr->node[i].name;
        if((0 != strncmp(serviceNamePtr, serviceNameTmpPtr, strlen(serviceNamePtr))) ||
            (serviceNameTmpLen != strlen(serviceNamePtr)))
            {
                if(i == (serviceProviderPtr->serviceNodeCount - 1))
                {
                    printf("No this type of service!\n");
                    return NULL;
                }
            }
        else{
            printf("Find the service!\n");
            return serviceProviderPtr->node[i].handler;
        }
    }
}

static void PrintProvider(struct serviceProvider *tmp)
{
    int i;
    printf("PrintProvider: name - %s\n", tmp->name);
    printf("PrintProvider: counter - %d\n", tmp->serviceNodeCount);
    for(i=0;i<tmp->serviceNodeCount;i++)
    {
        printf("serviceNode: name - %s, handler - %p\n", tmp->node[i].name, tmp->node[i].handler);
    }
}

void PrintPackage(void)
{
    int i;
    printf("\n\nservicePackage: name - %s\n", servicePackageRepo.name);
    printf("servicePackage: counter - %d\n", servicePackageRepo.serviceProviderCount);
    for(i = 0; i< servicePackageRepo.serviceProviderCount;i++)
    {
        printf("\n\nserviceProvider[%d](servicePackage(%s)): name - %s, service number %d in total!\n", i,
                                servicePackageRepo.name, servicePackageRepo.provider[i].name,
                                servicePackageRepo.provider[i].serviceNodeCount);
        PrintProvider(&servicePackageRepo.provider[i]);
    }
}

static void PrintProviderList(struct serviceProvider *tmp, char *serviceProviderName)
{
    int i;

    for(i=0;i<tmp->serviceNodeCount;i++)
    {
        printf("%s.%s.%s\n", serviceProviderName, tmp->name, tmp->node[i].name);
    }
}

void PrintPackageList(void)
{
    int i;

   for(i = 0; i< servicePackageRepo.serviceProviderCount;i++)
    {
        printf("\n");
        PrintProviderList(&servicePackageRepo.provider[i], servicePackageRepo.name);
    }
}

void PrintCharArray(const char *array, unsigned int arrayLength, const char *flagStr)
{
    int i, k;
    int key;

    if(flagStr != NULL)
        printf("[%s] The string is:\n", flagStr);

    for(i=0; i<arrayLength; i++)
    {
        printf("%c ", array[i]);
    }
    printf("\n");
}

void PrintArray(int *array, unsigned int arrayLength, const char *flagStr)
{
    int i, k;
    int key;

    printf("[%s] The int array is:\n", flagStr);
    for(i=0; i<arrayLength; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void PrintArrayWithIdx(int *array, int left, int right, const char *flagStr)
{
    int i, k;
    int key;

    printf("[%s] The array is:\n", flagStr);
    for(i=left; i<=right; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}