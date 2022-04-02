#include <stdio.h>
#include <dirent.h>
int main(int argc, char **argv)
{
    DIR* dir;
    struct dirent* ent;
    dir = opendir(argv[1]);
    ent = readdir(dir);           //   這裡一定可以讀到目錄。Why? 因為有. 和  ..
    while(ent!=NULL) {
	if(ent->d_type == DT_REG) printf("%c\t", 'f');
	if(ent->d_type == DT_DIR) printf("%c\t", 'd');
	if(ent->d_type == DT_LNK) printf("%c\t", 'l');
        printf("%s\n",  ent->d_name);
        ent = readdir(dir);     // 讀取下一筆
    }
    closedir(dir);
    return 0;
}

