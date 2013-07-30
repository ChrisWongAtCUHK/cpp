#include <stdio.h>
#include <dirent.h>
#include <string>

#define MAX_PATH_LENGTH 256

void bufferShift(char buffer[], int buffer_len){
	
}

void addSlash(char buffer[], int buffer_len, int index){
	int i = buffer_len;
	while(1){
		buffer[i] = buffer[i - 1];
		i--;
		if(i == index){
			buffer[i] = '\\';
			break;
		}
	}
}

int main(void){
	DIR *dir;
	struct dirent *ent;

	char buffer[MAX_PATH_LENGTH];

	memset(buffer, 0, MAX_PATH_LENGTH);
	if (NULL == getcwd(buffer, MAX_PATH_LENGTH))
	  perror("getcwd error");
	printf("The current directory is %s.\n", buffer);
	int buffer_len = strlen(buffer);
	printf("The length is %d.\n", buffer_len);
	
	int i = 0;
	while(buffer[i]){
		if(buffer[i] == '\\'){
			addSlash(buffer, buffer_len, i++);
			buffer_len++;
		}
		i++;
	}
	
	//addSlash(buffer, buffer_len, 2);
	printf("The new directory is %s.\n", buffer);
	if ((dir = opendir (buffer)) != NULL) {
		/* print all the files and directories within directory */
		  while ((ent = readdir (dir)) != NULL) {
			printf ("%s\n", ent->d_name);
		  }
		  closedir (dir);
	} else {
		/* could not open directory */
	  perror ("");
	  return 1;
	}
	return 0;
}

