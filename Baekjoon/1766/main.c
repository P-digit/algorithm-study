#include <stdio.h>

#define MAX_NODES 32005
#define MAX_EDGES 100005

// 위상 정렬
int head[MAX_NODES];
int to_node[MAX_EDGES];
int next_edge[MAX_EDGES];
int edge_count = 0;
int in_degree[MAX_NODES]; // 진입차수

void AddEdges(int from, int to)
{
    edge_count++; // 엣지 id
    to_node[edge_count] = to;
    next_edge[edge_count] = head[from];
    head[from] = edge_count;

    in_degree[to]++;
}

// 최소힙
int min_heap[MAX_NODES];
int heap_size = 0;

void PushHeap(int value)
{
    min_heap[++heap_size] = value;

    int current = heap_size;
    int parent = heap_size / 2;

    while (current > 1 && min_heap[current] < min_heap[parent])
    {
        int tmp = min_heap[parent];
        min_heap[parent] = min_heap[current];
        min_heap[current] = tmp;

        current = parent;
        parent = current / 2;
    }
}

int PopHeap(void)
{
    int pop_value = min_heap[1];

    min_heap[1] = min_heap[heap_size--];

    int current = 1;
    int left_child = 2 * current;
    int right_child = 2 * current + 1;

    while (left_child <= heap_size)
    {
        int smaller_child = left_child;

        if (right_child <= heap_size && min_heap[right_child] < min_heap[left_child])
        {
            smaller_child = right_child;
        }
        if (min_heap[current] <= min_heap[smaller_child])
            break;

        int tmp = min_heap[current];
        min_heap[current] = min_heap[smaller_child];
        min_heap[smaller_child] = tmp;

        current = smaller_child;
        left_child = current * 2;
        right_child = current * 2 + 1;
    }

    return pop_value;
}

int main(void)
{
    int total_problems;
    int total_rules;

    if (scanf("%d %d", &total_problems, &total_rules) != 2)
    {
        return 0;
    }

    int earlier_prob, later_prob;

    for (int edge = 1; edge <= total_rules; edge++)
    {
        scanf("%d %d", &earlier_prob, &later_prob);
        AddEdges(earlier_prob, later_prob);
    }

    for (int i = 1; i <= total_problems; i++)
    {
        if (in_degree[i] == 0)
        {
            PushHeap(i);
        }
    }

    while (heap_size > 0)
    {
        int current_prob = PopHeap();
        printf("%d ", current_prob);

        for (int edge_idx = head[current_prob]; edge_idx != 0; edge_idx = next_edge[edge_idx])
        {
            int next_prob = to_node[edge_idx];
            in_degree[next_prob]--;

            if (in_degree[next_prob] == 0)
                PushHeap(next_prob);
        }
    }

    return 0;
}