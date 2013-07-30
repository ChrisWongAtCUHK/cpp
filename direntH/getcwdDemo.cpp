/* CELEBG03

   This example determines the working directory.
	http://publib.boulder.ibm.com/infocenter/zos/v1r12/index.jsp?topic=%2Fcom.ibm.zos.r12.bpxbd00%2Frtgtc.htm
 */
 
#define _POSIX_SOURCE
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <dirent.h>

#define _MAX_PATH 256

int main(void){
   char buffer[_MAX_PATH];

   if (NULL == getcwd(buffer, _MAX_PATH))
      perror("getcwd error");
   printf("The current directory is %s.\n", buffer);
   return 0;

   /****************************************************************************
      The output should be similar to:

      The current directory is E:\C_OS2\MIG_XMPS
	  
	  http://www.warpspeed.com.au/cgi-bin/inf2html.cmd?..%5Chtml%5Cbook%5CToolkt40%5CXPG4REF.INF+148
	  
	  should be #include <direct.h>??
   ****************************************************************************/
}

