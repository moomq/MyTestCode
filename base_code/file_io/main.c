#include<stdio.h>
#include<string.h>
const char buf[] = "filesystem_test:hello world!\n";
FILE *fp;
char str[100];
int len;

int main(void)
{
	fp=fopen("filesystem_test.txt","w+");
	if(fp==NULL){
		printf("Fail to Open File\n");
		return 0;
	}

	fwrite(buf,1,strlen(buf), fp);
	fwrite("Embedfire\n",1,strlen("Embedfire\n"),fp);

	fflush(fp);

	fseek(fp,0,SEEK_SET);

	len = fread(str,100,1,fp);

	printf("File content:%s \nread len=%d\n",str,len);

	fclose(fp);

	return 0;
}
