#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mjhfc(chart,nvalid,n) (*(int**)chart[n+nvalid])
#define mjhfv(chart,n) ((char**)chart[n])

/***
 mjhprocflags generates a chart of commandline flags values and invocation counts
 *flagchart will be in the form of {"val","val","val",...&count,&count,&count...}
 validflags must be of the form {"single","single",..."multi","multi"...} blanks must be explicitely ""
***/

int mjhprocflags(void** flagchart, char** validflags, int argc, char** argv)
{
 int i,j,k;
 int flength;
 int nvalid = 0; for(;strlen(validflags[nvalid])==1;nvalid++);
 *flagchart = malloc(sizeof(void*)*nvalid*2);
  for(i=0;i<nvalid;i++) (*(char***)flagchart)[i]=NULL;
  for(;i<nvalid*2;i++) {(*(int***)flagchart)[i]=(int*)malloc(sizeof(int)); *(*(int***)flagchart)[i]=0;}

 for(i=1; i<argc && strncmp(argv[i],"--",3); i++)
 {
  if(argv[i][0]=='-' && argv[i][1]!='-')
  {
   for(j=1;argv[i][j];j++)
    for(k=0; k<nvalid; k++)
    {
     if(argv[i][j]==validflags[k][0])
     {
      (*(*(int***)flagchart)[nvalid+k])++;
      if(argv[i][j+1]==0 && i+1<argc && argv[i+1][0]!='-')
       (*(char***)flagchart)[k] = argv[i+1];
     }
    }
  }
  else if (argv[i][0]=='-' && argv[i][1]=='-')
  {
   for(j=0;j<nvalid;j++)
    if(!strncmp(&argv[i][2],validflags[j+nvalid],1024))
    {
     (*(*(int***)flagchart)[nvalid+j])++;
     if(i+1<argc && argv[i+1][0]!='-')
      (*(char***)flagchart)[j] = argv[i+1];
    }
  }
 }

 return 0;
}
