#include "algrithmtest.h"
#include "mytest_common.h"
//#include<getopt.h> /* 获取参数 */

extern char *optarg;         /*系统声明的全局变量 */
extern int optind, opterr, optopt;

int main(int argc, char **argv)
{
    int c;
    printf('option 1111\n');
    printf('option 1111\n');
    printf('option 1111\n');
    printf('option 1111\n');
    printf('option 1111\n');
 #if 0
    while ((c = getopt(argc, argv, "lt")) != -1) {
        printf('option 2222\n');
        printf('option 2222\n');
        printf('option 2222\n');
        printf('option 2222\n');

        switch(c){
            case 'l': /* List the supported test. */
                printf('option l\n');
                break;
            case 't': /* Test type */
                printf('option t\n');
                break;
            default:
                printf('Bad parameters, try "--help" for details\n');
                break;                
        }
    }
#endif
  //MySort();
  //MyDataStructure();

  return 0;
}