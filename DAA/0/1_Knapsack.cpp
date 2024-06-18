#include <bits/stdc++.h>
using namespace std;

struct Item
{
    float weight;
    float volume;
    int cost;
    int value;
};

struct Node
{
    int level, profit, bound;
    float weight;
    float volume;
    int cost;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int bound(Node u, int n, float W, float V, int C, Item arr[])
{
    if (u.weight >= W || u.volume >= V || u.cost >= C)
        return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    float totweight = u.weight;
    float totvolume = u.volume;
    int totcost = u.cost;

    while ((j < n) && (totweight + arr[j].weight <= W) && (totvolume + arr[j].volume <= V) && (totcost + arr[j].cost <= C))
    {
        totweight += arr[j].weight;
        totvolume += arr[j].volume;
        totcost += arr[j].cost;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
    {
        profit_bound += (W - totweight) * arr[j].value / arr[j].weight;
        profit_bound += (V - totvolume) * arr[j].value / arr[j].volume;
        profit_bound += (C - totcost) * arr[j].value / arr[j].cost;
    }

    return profit_bound;
}

int knapsack(int W, int V, int C, Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = u.volume = u.cost = 0;
    Q.push(u);

    int maxProfit = 0;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        if (u.level == -1)
            v.level = 0;
        if (u.level == n-1)
            continue;
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.volume = u.volume + arr[v.level].volume;
        v.cost = u.cost + arr[v.level].cost;
        v.profit = u.profit + arr[v.level].value;
        if (v.weight <= W && v.volume <= V && v.cost <= C && v.profit > maxProfit)
            maxProfit = v.profit;
        v.bound = bound(v, n, W, V, C, arr);
        if (v.bound > maxProfit)
            Q.push(v);
        v.weight = u.weight;
        v.volume = u.volume;
        v.cost = u.cost;
        v.profit = u.profit;
        v.bound = bound(v, n, W, V, C, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

int main()
{
    int W = 50; // Weight limit
    int V = 50; // Volume limit
    int C = 50; // Cost limit
    Item arr[] = {{10, 10, 20, 100}, {20, 20, 30, 120}, {30, 15, 25, 60}, {5, 5, 8, 50}};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum possible profit = " << knapsack(W, V, C, arr, n);

    return 0;
}
