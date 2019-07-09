#include "AlgorithmCommon.h"

/*
 * Description:
 * 急！灾区的食物依然短缺！
 * 为了挽救灾区同胞的生命，心系灾区同胞的你准备自己采购一些粮食支援灾区，现在假设你一共有资金n元，而市场有m种大米，每种大米都是袋装产品，其价格不等，并且只能整袋购买。
 * 请问：你用有限的资金最多能采购多少公斤粮食呢？
 */

struct riceAttr{
    int price;
    int weight;
};

/* 失眠可选大米种类。 */
#define RICE_MAX_TYPE 50
struct riceAttr rice[] = {{100, 15}, {65, 10}, {80, 20}, {120, 25}, {50, 6}};
int riceSelection = sizeof(rice)/sizeof(struct riceAttr);
int riceSchedule[RICE_MAX_TYPE] = {0};
int riceScheduleTmp[RICE_MAX_TYPE] = {0};
int maxWeightInTotal = 0;
int weightInTotal = 0;

/* 解1：
 * 从各种组合中取得最大质量的配置。
 * 
 * 实施：
 * 遍历，利用递归。
 * */

void BuyMostRice(int money, int riceIdx)
{
    int i;
    int maxCounts;

    if(money <= 0 || riceIdx >= riceSelection)
    {
        /* 如果该方案所得大米质量更高，更新最大质量,保存购买方案。 */
        if(maxWeightInTotal < weightInTotal)
        {
            memcpy(riceSchedule, riceScheduleTmp, RICE_MAX_TYPE);
            maxWeightInTotal = weightInTotal;
        }
        return;
    }

    maxCounts = money/rice[riceIdx].price;
    for(i = 0; i <= maxCounts; i++)
    {
        /* 尝试本次分配方案，购买i袋编号riceIdx的大米。 */
        riceScheduleTmp[riceIdx] = i;
        weightInTotal += i*rice[riceIdx].weight;
        /* 剩余金额用于购买下一种大米。 */
        BuyMostRice(money-(i*rice[riceIdx].price), riceIdx+1);
        /* 尝试下次分配方案之前，恢复本次分配方案之前状态。 */
        riceScheduleTmp[riceIdx] = 0;
        weightInTotal -= i*rice[riceIdx].weight;
    }
}

/* 测试输入：
 * Money - 5000
 * Rice Type: struct riceAttr rice[] = {{100, 15}, {65, 10}, {80, 20}, {120, 25}, {50, 6}};
 * 测试结果：
 * [TestBuyMostRice] The int array is:
 * 0 0 61 1 0
 * Total weight is 1245
 */
void TestBuyMostRice(void* input)
{
    BuyMostRice(5000, 0);
    PrintArray(riceSchedule, riceSelection, "TestBuyMostRice");
    printf("Total weight is %d\n", maxWeightInTotal);
}