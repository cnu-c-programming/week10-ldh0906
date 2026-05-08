#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    int score;
    char name[8];
    struct Node* node;
} Node;

static Node* arr;
int size = 0;

void add(Node n) {
      if (arr == NULL) {
          arr = (Node*)malloc(sizeof(Node) * 10);
      }

      arr[size] = n;
      arr[size].node = NULL;
      size++;
  }

void delete(char name[]) {
    for(int i = 0; i < size; i++) {
        // 문자열은 ==가 아니라 strcmp로 내용을 비교해야 한다.
        if(strcmp(arr[i].name, name) == 0) {
            // 삭제한 위치 뒤의 값들을 한 칸씩 앞으로 당긴다.
            for(int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
            break;
        }
    }
}

void print() {
    for(int i = 0; i < size; i++) {
        printf("%s %d\n", arr[i].name, arr[i].score);
    }
}

int quit() {
    free(arr);
    return 1;
}

int main() {
    while(1) {
        char command[20];
        scanf("%s", command);
        if(strcmp(command,"add") == 0) {
            char newName[8];
            int score = 0;
            scanf("%s %d",newName,&score);
            Node n;
            strcpy(n.name,newName);
            n.score = score;
            add(n);
        } else if (strcmp(command,"delete") == 0) {
            char delName[8];
            scanf("%s", delName);            
            delete(delName);
        } else if (strcmp(command,"print") == 0) {
            print();
        } else if (strcmp(command,"quit") == 0) {
            quit();
            break;
        }
        
    }
}
