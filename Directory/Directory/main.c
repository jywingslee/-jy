#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

int depth;

void getdir(char* PATH)
{
    DIR *dp;
    struct dirent *dirp;
    struct stat buf;
    
    dp = opendir(PATH);
    dirp = readdir(dp);
    lstat(dirp->d_name,&buf);
        
    if(S_ISDIR(buf.st_mode))
    {
        printf("%s\n", dirp->d_name);
        getdir(dirp->d_name);
        return;
    }
    else{
        printf("%s\n", dirp->d_name);
        return;
    }
    
    puts("");
    
    closedir(dp);
}
int main()
{
    getdir("/Users/user/Documents");
    
    return 0;
}