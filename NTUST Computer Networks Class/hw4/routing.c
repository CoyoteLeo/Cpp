#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM_LINK 50
#define MAX_NUM_NODE 50
#define INF 99999999.0

struct link {
    int ends[2];
    double cost;
};

struct node {
    int id;
    int last;
    double cost;
};

struct link links[MAX_NUM_LINK];
struct node nodes[MAX_NUM_NODE];
int num_of_link = 0;
int num_of_node = 0;

void readTopo(const char* plaintext) {
    FILE* input_file = fopen(plaintext, "r");
    num_of_link = 0;
    num_of_node = 0;

    if (!input_file) {
        printf("Cannot read the topo file\n");
        return;
    }

    while (!feof(input_file)) {
        int dd;
        int id1;
        int id2;
        double cost;
        fscanf(input_file, "%d %d %d %lf\n", &dd, &id1, &id2, &cost);

        if (id1 > num_of_node)
            num_of_node = id1;
        if (id2 > num_of_node)
            num_of_node = id2;

        if (num_of_link < MAX_NUM_LINK) {
            links[num_of_link].ends[0] = id1;
            links[num_of_link].ends[1] = id2;
            links[num_of_link].cost = cost;

            num_of_link++;
        }

        nodes[id1].last = -1;
        nodes[id1].cost = 0.0;
        nodes[id2].last = -1;
        nodes[id2].cost = 0.0;
    }

    fclose(input_file);
}

void print_path(int* path, int path_len) {
    for (int i = 0; i < path_len; i++) {
        printf("%d\t", path[i]);
    }
    printf("\n");
}
int main(int argc, char* argv[]) {
    int path[MAX_NUM_NODE];
    int path_len = 0;
    int source, destination;

    if (argc != 3) {
        printf("Usage: ./routing <source> <destination>\n");
        return -1;
    }

    source = atoi(argv[1]);
    destination = atoi(argv[2]);

    readTopo("topo.txt");
    /* insert your code here and also you are free to define any function */
    int visit[MAX_NUM_NODE] = {0}, visit_count = 0;  // record which node is visited or not
    // initial distnce between source and each node
    for (int i = 1; i <= num_of_node; i++)
        nodes[i].cost = INF;
    for (int i = 0; i < num_of_link; i++) {
        if (links[i].ends[0] == source) {
            nodes[links[i].ends[1]].cost = links[i].cost;
            nodes[links[i].ends[1]].last = links[i].ends[0];
        }
        if (links[i].ends[1] == source) {
            nodes[links[i].ends[0]].cost = links[i].cost;
            nodes[links[i].ends[0]].last = links[i].ends[1];
        }
    }
    /* dijkstra algorithm  */
    nodes[source].cost = 0;
    visit[source] = 1;
    visit_count = 1;
    while (visit_count < num_of_node) {
        double min_spend = INF;
        int min_point = -1;
        for (int i = 0; i < num_of_node; i++) {
            if (!visit[i] && nodes[i].cost < min_spend) {
                min_point = i;
                min_spend = nodes[i].cost;
            }
        }
        if (min_point == -1)
            break;
        visit[min_point] = 1;
        for (int i = 0; i < num_of_link; i++) {
            if (links[i].ends[0] == min_point && !visit[links[i].ends[1]])
                if (nodes[min_point].cost + links[i].cost < nodes[links[i].ends[1]].cost) {
                    nodes[links[i].ends[1]].cost = nodes[min_point].cost + links[i].cost;
                    nodes[links[i].ends[1]].last = links[i].ends[0];
                }
            if (links[i].ends[1] == min_point && !visit[links[i].ends[0]])
                if (nodes[min_point].cost + links[i].cost < nodes[links[i].ends[0]].cost) {
                    nodes[links[i].ends[0]].cost = nodes[min_point].cost + links[i].cost;
                    nodes[links[i].ends[0]].last = links[i].ends[1];
                }
        }
    }
    /* trace back the path */
    int temp = destination, path_temp[MAX_NUM_NODE] = {0};
    path_len = 0;
    while (temp > 0) {
        path_temp[path_len++] = temp;
        temp = nodes[temp].last;
    }
    for (int i = 0; i < path_len; i++)
        path[path_len - i - 1] = path_temp[i];
    print_path(path, path_len);
}
