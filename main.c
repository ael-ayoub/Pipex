#include "pipex.h"

int main(int c , char **v,char **envp)
{

	char *command = v[1];
	//char *cmd[]={"fgfh",""}
	char *vv[] = {"ls", NULL};
	if (c > 0 && v[0])
	{
		char *tst_path = get_path(command,envp);

		char *path = "/usr/bin/ls";
		printf("tst path : .....%s......\n",tst_path);
		printf("path : .....%s......\n",path);
		printf("%d\n",ft_strncmp(path,tst_path,123));

		execve(tst_path,vv,envp);
		//execve(command, args, envp);


		if (path)
		printf("%s\n",path);
		//free(path);
	}
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>

//int main(int argc, char **argv, char **envp) {
//    // Define the command to execute
//    char *command = "/usr/bin/ls";

//    // Define the arguments for the command
//    char *args[] = {"ls", NULL};

//    // Execute the command with execve
//    printf("Executing command: %s\n", command);
//	execve(command, args, envp);


//    return 0;
//}
