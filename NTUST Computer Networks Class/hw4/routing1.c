#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM_LINK 50
#define MAX_NUM_NODE 50

struct link {
    int ends[2];
    double cost;
};

struct node {
    int visit;
    double cost;
    int pre;
};

struct link links[MAX_NUM_LINK];
struct node nodes[MAX_NUM_NODE];
int num_of_link = 0;
int num_of_node = 0;
int max = 1000000.0;

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

        nodes[id1].visit = -1;
        nodes[id1].cost = max;
        nodes[id2].visit = -1;
        nodes[id2].cost = max;
    }

    fclose(input_file);
}

void print_path(int* path, int path_len) {
    int i;
    for (i = path_len; i > 0; i--) {
        printf("%d\t", path[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    int path[MAX_NUM_NODE];
    int path_len;
    int source, destination;

    if (argc != 3) {
        printf("Usage: ./routing <source> <destination>\n");
        return -1;
    }

    source = atoi(argv[1]);
    destination = atoi(argv[2]);

    readTopo("topo.txt");

    /* insert your code here and also you are free to define any function */

    int N[num_of_node];  //�ΨӦs�{�b���I�M�U���I
    double precost;      //��o���I���̵u��|
    int prenode;
    N[0] = source;
    nodes[source].visit = 1;  //�_�l�I�]���w��X

    int i1, i2, i3, i4, temp;  //��p�ƪ��ܼƦb�o�̫ŧi
    double tempcost;
    i1 = 0;

    while (i1 < num_of_node) {
        temp = 0;
        tempcost = max;  //�C���䧹�@���I�N�⥦�]�^���j
        precost = 0;
        prenode = N[i1];

        while (prenode != source)  //��L���O�Ĥ@���I���ɭ� �n�����{�b�o���I��_�I��cost
        {
            precost = precost + nodes[prenode].cost;
            prenode = nodes[prenode].pre;
        }
        for (i2 = 0; i2 < num_of_link; i2++)  //�}�l���C�@��link
        {
            if (links[i2].ends[0] == N[i1]) {
                if (links[i2].cost + precost < nodes[links[i2].ends[1]].cost &&
                    nodes[links[i2].ends[1]].visit == -1)
                //�p�G�񥻨�node�̦s��cost�p
                {
                    nodes[links[i2].ends[1]].cost = links[i2].cost + precost;
                }
                if (nodes[links[i2].ends[1]].cost < tempcost &&
                    nodes[links[i2].ends[1]].visit == -1) {
                    temp = links[i2].ends[1];  // temp�ӰO���o���I
                    tempcost = nodes[links[i2].ends[1]].cost;
                }
            }

            if (links[i2].ends[1] == N[i1])  // link�Y���ۤϤ]�i�H �ҥH�A�g�@��
            {
                if (links[i2].cost + precost < nodes[links[i2].ends[0]].cost &&
                    nodes[links[i2].ends[0]].visit == -1) {
                    nodes[links[i2].ends[0]].cost = links[i2].cost + precost;
                }
                if (nodes[links[i2].ends[0]].cost < tempcost &&
                    nodes[links[i2].ends[0]].visit == -1) {
                    temp = links[i2].ends[0];
                    tempcost = nodes[links[i2].ends[0]].cost;
                }
            }
        }

        nodes[temp].visit = 1;    //����cost�̤p���I�]���w��X
        nodes[temp].pre = N[i1];  //��o���I���W�@�ӳ]���{�b���I
        i1++;                     //�䧹���I�ƶq+1
        N[i1] = temp;             //�{�b���I�令����쪺�I �~��while
    }
    for (int i = 1; i <= num_of_node; i++)
        printf("dest%d: cost:%f last:%d\n", i, nodes[i].cost, nodes[i].pre);
    path_len = 0;
    for (i3 = destination; i3 != source; path_len++) {
        path[path_len] = i3;
        i3 = nodes[i3].pre;
        printf("%d	", path[path_len]);
    }

    // printf("%d,%d	",path[0],path[1]);
    // printf("%d\t",source);
    // print_path(path, path_len);
    // printf("%d",path_len);
}
