#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff;

int main() {
    int n;
    scanf("%d", &n);
    string s[n];
    string catalog[n];
    int amount = 0;
    vector<int> count[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        // printf("%s\n", s[i]);
        string login = "";
        string domain = "";
        for (int i = 0; i < n; ++i) {
            bool mouse = false;
            login = "";
            domain = "";
            printf("555555555555555555555555555555555555555555");
            for (int j = 0; s[i][j] != 0; j++) {
                if (s[i][j] == '@') {
                    mouse = true;
                    continue;
                }
                if (mouse) {
                    if (s[i][j] >= 'A' && s[i][j] <= 'Z')
                        domain = domain + (char)(s[i][j] - 'A' + 'a');
                    else
                        domain = domain + s[i][j];
                } else {
                    if (s[i][j] >= 'A' && s[i][j] <= 'Z')
                        login = login + (char)(s[i][j] - 'A' + 'a');
                    else
                        login = login + s[i][j];
                }
            }
            printf("%s\t%s", login, domain);
            if (domain == "bmail.com") {
            }
        //     int m = 0, flag = 1;
        //     while (flag && count[m].size()) {
        //         // printf("-----------------------%s\t%s\n", s1, catalog[m]);
        //         if (strcmp(s1, catalog[m]) == 0) {
        //             count[m].push_back(i);
        //             flag = 0;
        //             break;
        //         }
        //         m++;
        //     }
        //     if (flag) {
        //         strcpy(catalog[m], s1);
        //         count[m].push_back(i);
        //         amount++;
        //     }
        // }
        // for (int i = 0; i < n; i++)
        //     printf("%d\n", count[i].size());
        // printf("%d\n", amount);
        // for (int i = 0; i < n; i++) {
        //     int n = count[i].size();
        //     if (!n)
        //         continue;
        //     printf("%d ", n);
        //     for (int j = 0; j < n; j++)
        //         printf("%s ", s[count[i][j]]);
        //     puts("");
        }
    }
}
