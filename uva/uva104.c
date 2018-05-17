#include<bits/stdc++.h>

int main(){
    int amount;
    scanf("%d", &amount);
    float value[amount][amount];
    for (int i = 0; i < amount;i++){
        for (int j = 0; j < amount;j++){
            if(i==j){
                value[i][j] = 1;
                continue;
            }
            char tmp[10] = {0};
            scanf("%s", tmp);
            value[i][j]=atof(tmp);
        }
    }
}