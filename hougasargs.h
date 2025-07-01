#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mjhfc(chart,n) (*((int**)chart)[n*2+1])
#define mjhfv(chart,n) (((char**)chart)[n*2])

/***
 mjhprocflags generates a chart of commandline flags values and invocation counts
 *flagchart will be in the form of {"val","&count","val","&count"...}
 validflags must be of the form {"single","multi","single","multi",..."--"} blanks must be explicitly ""
 multi-character args must be less than 1 KiB this is hard-coded and can be changed.
***/

int mjhprocflags(void** flagchart, char** validflags, int argc, char** argv)
{
 int i,j;
 int nvalid = 0; for(;strncmp(validflags[nvalid],"--",3);nvalid++);
 *flagchart = malloc(sizeof(void*)*nvalid*2);

  for(i=0;i<nvalid;i+=2) (*(char***)flagchart)[i]=NULL;
  for(i=1;i<nvalid;i+=2) {(*(int***)flagchart)[i]=(int*)malloc(sizeof(int)); *(*(int***)flagchart)[i]=0;}

 for(i=1; i<argc && strncmp(argv[i],"--",3); i++)
 {
  if(argv[i][0]=='-' && argv[i][1]!='-')
  {
   for(j=0;j<nvalid;j+=2)
   {
    char* flagat=strchr(argv[i],validflags[j][0]);
    if(flagat!=NULL)
    {
     (*(*(int***)flagchart)[j+1])++;
     if(!flagat[1])
      (*(char***)flagchart)[j]=argv[i+1];
  }}}
  else if (argv[i][0]=='-' && argv[i][1]=='-')
  {
   for(j=1;j<nvalid;j+=2)
    if(!strncmp(&argv[i][2],validflags[j],1024))
    {
     (*(*(int***)flagchart)[j+1])++;
     if(i+1<argc && argv[i+1][0]!='-')
      (*(char***)flagchart)[j]=argv[i+1];
 }} }

 return 0;
}

int hougasargs(int argc, char** argv)
{
 int i;
 void* chart;
 char* validflags[] = {"a","along","b","blong","c","clong","--"};
 int nvalid=0; for(;strncmp(validflags[nvalid],"--",3);nvalid++);

 printf("%d %d\n",argc,nvalid);
 mjhprocflags(&chart,validflags,argc,argv);


 for(i=0;i<nvalid;i+=2) printf("%s %s %s %d\n",validflags[i],validflags[i+1],mjhfv(chart,i/2),mjhfc(chart,i/2));
}
