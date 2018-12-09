#include "MySort.h"
#include "mytest_common.h"
#ifdef FUNCTEST
#include "testarray.h"
#endif
/*
 KMP是一种模式匹配的算法. 从长串中寻找特定子串其实就是一种模式匹配.
 1, 传统的做法是每次移动一个字符来匹配,当匹配子串中含有重复的字段时,这种匹配方法会比较低效.
 2, 改进的方法是对待查找子串进行分析然后再去进行匹配,当字符不匹配的时候向后几位(而不是一位)继续进行匹配.
     2.1) KMP的方法是用一个数组存储待匹配的字符串的信息.
     2.2) 数组大小为待匹配子串的长度,内容为当对应字符不匹配时下一匹配位置的信息.
 */
void GenerateLpsArray(char *pat, int  M, int *lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0; // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// 提取待匹配字符串的信息.
/*
[patternString1] The string is:
a a s d a b a s d
0 1 0 0 1 0 1 0 0
[patternString2] The string is:
a s d f b a s d a
0 0 0 0 0 1 2 3 1
[patternString3] The string is:
a a s d f b a a d
0 1 0 0 0 0 1 2 0
[patternString4] The string is:
s d f b a s d b a
0 0 0 0 0 1 2 0 0
[patternString5] The string is:
s d a a a s a a a
0 0 0 0 0 1 0 0 0
[patternString6] The string is:
a b c d f a b c d
0 0 0 0 0 1 2 3 4
*/
#ifdef FUNCTEST
void TestGenerateLpsArray(void)
{
    int lps1[PATTERNLEN] = {0};
    int lps2[PATTERNLEN] = {0};
    int lps3[PATTERNLEN] = {0};
    int lps4[PATTERNLEN] = {0};
    int lps5[PATTERNLEN] = {0};
    int lps6[PATTERNLEN] = {0};
    int lps7[PATTERNLEN] = {0};
    int lps8[PATTERNLEN] = {0};
    int lps9[PATTERNLEN] = {0};

    GenerateLpsArray(patternString1, PATTERNLEN, lps1);
    GenerateLpsArray(patternString2, PATTERNLEN, lps2);
    GenerateLpsArray(patternString3, PATTERNLEN, lps3);
    GenerateLpsArray(patternString4, PATTERNLEN, lps4);
    GenerateLpsArray(patternString5, PATTERNLEN, lps5);
    GenerateLpsArray(patternString6, PATTERNLEN, lps6);
    GenerateLpsArray(patternString7, PATTERNLEN, lps7);
    GenerateLpsArray(patternString8, PATTERNLEN, lps8);
    GenerateLpsArray(patternString9, PATTERNLEN, lps9);

    PrintCharArray(patternString1, PATTERNLEN, "patternString1");
    PrintArray(lps1, PATTERNLEN, "patternString1");
    PrintCharArray(patternString2, PATTERNLEN, "patternString2");
    PrintArray(lps2, PATTERNLEN, "patternString2");
    PrintCharArray(patternString3, PATTERNLEN, "patternString3");
    PrintArray(lps3, PATTERNLEN, "patternString3");
    PrintCharArray(patternString4, PATTERNLEN, "patternString4");
    PrintArray(lps4, PATTERNLEN, "patternString4");
    PrintCharArray(patternString5, PATTERNLEN, "patternString5");
    PrintArray(lps5, PATTERNLEN, "patternString5");
    PrintCharArray(patternString6, PATTERNLEN, "patternString6");
    PrintArray(lps6, PATTERNLEN, "patternString6");
    PrintCharArray(patternString7, PATTERNLEN, "patternString7");
    PrintArray(lps7, PATTERNLEN, "patternString7");
    PrintCharArray(patternString8, PATTERNLEN, "patternString8");
    PrintArray(lps8, PATTERNLEN, "patternString8");
    PrintCharArray(patternString9, PATTERNLEN, "patternString9");
    PrintArray(lps9, PATTERNLEN, "patternString9");
}
#endif


#ifdef FUNCTEST
void KMP_PatternMatch(void)
{
    TestGenerateLpsArray();
}
#else
void KMP_PatternMatch(const char *inputStr, int inputStrLen, const char *pattern, int patternLen)
{
    int i;
    int j = 0;
    int k = 0;
    int *lps = NULL;

    PrintCharArray(inputStr, inputStrLen, "KMP_PatternMatch - inputStr");
    PrintCharArray(pattern, patternLen, "KMP_PatternMatch - pattern");
    
    lps = (int*)malloc(sizeof(int)*patternLen);
    if(lps == NULL)
    {
        printf("Malloc lps array failed\n");
        return;
    }

    for(i=0; i<=inputStrLen;)
    {
        if(inputStr[i] == pattern[j])
        {
            if(j == patternLen-1)
            {
                printf("Find the %d pattern, start index is %d\n", ++k, i-j);
                j = lps[j];
            }else{
                j++;
            }
            i++;
            continue;
        }else{//inputStr[i] != pattern[j]
            if(j>0) j--;
            else i++;
        }
    }
}
#endif
