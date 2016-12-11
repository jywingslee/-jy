#include <stdio.h>
#include <string.h>
#define MAXX 1000

typedef struct usr{
    char name[30];
}User;

typedef struct sns{
    char usr[30];
    User friends[30];
}SNS_List;

SNS_List g_sns_list[MAXX];
int g_count;

int get_length(char *a){
    int cnt = 0;
    char *ptr = a;
    while(*ptr++){
        cnt++;
    }
    return cnt;
}

int my_strcmp(char *a, char *b){
    int i;
    int aa = get_length(a);
    int bb = get_length(b);
    
    if(aa != bb) return 0;
    
    if(aa == bb){
        for(i=0; i<aa; i++){
            if(a[i] != b[i]) return 0;
        }
    }
    return 1;
}

void add_user(char* a, char* b){
    int i;
    for(i=0; i<g_count; i++){
        if(my_strcmp(g_sns_list[i].usr, a) == 0){
            //add_friends(b);
            g_sns_list[i].friends
        }
        else{
            //make_usr(a, b);
            g_sns_list[g_count++] = a;
            
        }
    }
}

void getFriendsInfo() {
    
    FILE *f;
    f = fopen("/Users/user/sns-friends.txt", "r");
    char a[30],b[30];
    
    while(fscanf(f, "%s %s", a, b) != EOF){
        add_user(a, b);
        //strcpy(g_sns_list[g_count].usr, a);
        g_count++;
    }
}

int main(int argc, const char * argv[]) {
    
    getFriendsInfo();
    int i;
    for(i=0; i<g_count; i++) {
        printf("%s \n", g_sns_list[i].usr);
    }
    return 0;
}
