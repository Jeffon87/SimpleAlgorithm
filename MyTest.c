#include "./common/MyTestCommon.h"
#include <getopt.h> /* 获取参数 */

extern char *optarg;         /*系统声明的全局变量 */
extern int optind, opterr, optopt;

int main(int argc, char **argv)
{
    int c;
    function handler = NULL;
    char *serviceName = NULL;
    int serviceNameLen = 0;

    //printf("Begin: optind %d, argc %d\n", optind, argc);
    while ((c = getopt(argc, argv, "lt:")) != -1) {
        switch(c){
            case 'l': /* List the supported test. */
                //printf("option l\n");
                PrintPackageList();
                break;
            case 't': /* Test type */
                //printf("option t\n");
                serviceName = optarg;
                if(NULL != serviceName)
                {
                    serviceNameLen = strlen(serviceName);
                    //printf("The strlen(serviceName) is %d\n", serviceNameLen);
                    break;
                } else {
                    fprintf(stderr, "Expected argument after options\n");
                    exit(EXIT_FAILURE);
                }

            default:/* '?' */
                fprintf(stderr, "Usage: %s [-t service] [-l]\n",
                        argv[0]);
                exit(EXIT_FAILURE);              
        }
    }
    //printf("End: optind %d, argc %d\n", optind, argc);
   
    handler = MyTestSearchService(serviceName, serviceNameLen);
    if(handler != NULL)
        (*handler)();

  return 0;
}