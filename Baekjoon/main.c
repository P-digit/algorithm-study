#include <stdio.h>

#define MAX_NODES 32005
#define MAX_EDGES 100005

// --- [그래프 자료구조 (Edge Pool 방식)] ---
// malloc 없이 연결 리스트를 구현하여 속도와 메모리를 동시에 잡는 C언어 코테 치트키입니다.
int head[MAX_NODES];
int next_edge[MAX_EDGES];
int to_node[MAX_EDGES];
int edge_count = 0;

int in_degree[MAX_NODES]; // 진입차수 배열

void AddEdge(int from, int to)
{
    edge_count++;
    to_node[edge_count] = to;
    next_edge[edge_count] = head[from];
    head[from] = edge_count;

    in_degree[to]++; // 'to' 문제를 풀기 위해 필요한 선행 문제 1개 증가
}

// --- [최소 힙 (Min-Heap) 자료구조] ---
int min_heap[MAX_NODES];
int heap_size = 0;

void PushHeap(int value)
{
    min_heap[++heap_size] = value;
    int current = heap_size;
    int parent = current / 2;

    // 부모가 나보다 크면 자리를 바꾼다 (위로 올라감)
    while (current > 1 && min_heap[parent] > min_heap[current])
    {
        int temp = min_heap[parent];
        min_heap[parent] = min_heap[current];
        min_heap[current] = temp;

        current = parent;
        parent = current / 2;
    }
}

int PopHeap()
{
    int pop_value = min_heap[1];         // 루트 노드(가장 작은 값)를 빼둔다
    min_heap[1] = min_heap[heap_size--]; // 맨 마지막 노드를 루트로 끌어올림

    int current = 1;
    int left_child = current * 2;
    int right_child = current * 2 + 1;

    // 자식들 중 더 작은 놈과 비교하며 아래로 내려감
    while (left_child <= heap_size)
    {
        int smaller_child = left_child;
        if (right_child <= heap_size && min_heap[right_child] < min_heap[left_child])
        {
            smaller_child = right_child;
        }

        if (min_heap[current] <= min_heap[smaller_child])
        {
            break; // 내가 자식들보다 작으면 자리 잡은 것
        }

        int temp = min_heap[current];
        min_heap[current] = min_heap[smaller_child];
        min_heap[smaller_child] = temp;

        current = smaller_child;
        left_child = current * 2;
        right_child = current * 2 + 1;
    }

    return pop_value;
}

// --- [메인 로직] ---
int main(void)
{
    int total_problems, total_rules;
    if (scanf("%d %d", &total_problems, &total_rules) != 2)
        return 0;

    // 그래프 간선 정보 입력
    for (int i = 0; i < total_rules; i++)
    {
        int earlier_prob, later_prob;
        scanf("%d %d", &earlier_prob, &later_prob);
        AddEdge(earlier_prob, later_prob);
    }

    // 위상 정렬 시작: 진입차수가 0인(당장 풀 수 있는) 문제들을 모조리 힙에 넣는다
    for (int i = 1; i <= total_problems; i++)
    {
        if (in_degree[i] == 0)
        {
            PushHeap(i);
        }
    }

    // 힙이 빌 때까지 하나씩 꺼내서 푼다
    while (heap_size > 0)
    {
        int current_prob = PopHeap();
        printf("%d ", current_prob);

        // 이 문제를 품으로써 새롭게 풀 수 있게 되는 다음 문제들을 탐색
        for (int edge_idx = head[current_prob]; edge_idx != 0; edge_idx = next_edge[edge_idx])
        {
            int next_prob = to_node[edge_idx];
            in_degree[next_prob]--; // 진입차수 1 감소

            // 진입차수가 0이 되었다면 이제 풀 수 있으므로 힙에 투입!
            if (in_degree[next_prob] == 0)
            {
                PushHeap(next_prob);
            }
        }
    }

    return 0;
}