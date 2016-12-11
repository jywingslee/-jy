#include <stdio.h>
#include <string.h>

#define MAXX 1000

typedef struct friend{
    int idx;
    char frname[30];
    struct friend* next_friend;
}friend;

typedef struct User{
    char myname[30];
    struct friend* myfriend;
}User;

User user_list[MAXX];
int g_user_cnt;

int is_existed_user(char *a, char *b){
    int i;
    for(i=0; i<g_user_cnt; i++) {
        if(strcmp(user_list[i].myname, a) == 0){
            return i;
        }
    }
    return -1;
}

void add_list(char *a, char *b){
    friend* new_friend = (friend *)malloc(sizeof(friend));
    new_friend->next_friend = NULL;
    strcpy(new_friend->frname, b);
    
    int idx = is_existed_user(a, b);
    if(idx > -1) {
        friend* tmp = user_list[idx].myfriend;
        
        while(tmp){
            if(strcmp(tmp->frname, b)== 0){
              goto existed;
            }
            
            if(tmp->next_friend == NULL) break;
            tmp = tmp->next_friend;
            
        }
        
        tmp->next_friend = new_friend;
    } else {
        strcpy(user_list[g_user_cnt].myname, a);
        user_list[g_user_cnt].myfriend = new_friend;
        g_user_cnt++;
    }

existed:
    
    return;
}

void add_user(char *a, char *b){
    
    add_list(a, b);
    add_list(b, a);
    
    return;
}

void getFriendsInfo() {
    
    FILE *f;
    f = fopen("/Users/user/sns-friends.txt", "r");
    char a[30],b[30];
    
    while(fscanf(f, "%s %s", a, b) != EOF){
        add_user(a, b);
    }
}
void printUser(){
    printf("total user : %d \n", g_user_cnt);
    int i;
    for(i=0; i<g_user_cnt; i++){
        printf("%s \n", user_list[i].myname);
        
        friend* tmp = user_list[i].myfriend;
        while(tmp != NULL){
            printf("  %s, ", tmp->frname);
            tmp = tmp->next_friend;
        }
        printf("\n\n");
    }
}
int main(int argc, const char * argv[]) {
    
    getFriendsInfo();
    
    printUser();
    
    return 0;
}
