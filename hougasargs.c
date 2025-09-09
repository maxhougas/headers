#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _HOUGASARGS 1

#define MJHMAXTOKL 1024

#define hougasargs_flagcount(chart,n) (*((int**)chart)[n*2+1])
#define hougasargs_flagvalue(chart,n) (((char**)chart)[n*2])
#define mjhisflag(str) ((str)[0]=='-'&&(str)[1]!=0)
#define hougasargs_startswithdoubletac(str) ((str)[0]=='-'&&(str)[1]=='-')
#define hougasargs_startswithsingletac(str) ((str)[0]=='-'&&(str)[1]!='-')

/*
 list for args so they can be removed easily
*/
typedef struct hougasargs_argnode
{
 char *arg;
 struct hougasargs_argnode *prev;
 struct hougasargs_argnode *next;
} hougasargs_argnode;

/*
 make a list of argc **argv
*/
hougasargs_argnode *hougasargs_listanize(int argc, char **argv)
{
 hougasargs_argnode *first = (hougasargs_argnode*)malloc(sizeof(hougasargs_argnode));
 hougasargs_argnode *current = first;
 current->prev = NULL;

 int i;
 for(i = 1; i < argc; i++)
 {
  current->arg = argv[i];
  if(i+1 < argc)
  {
   current->next = (hougasargs_argnode*)malloc(sizeof(hougasargs_argnode));
   current->next->prev = current;
   current = current->next;
  }
 }

  current->next = NULL;

 return first;
}

void hougasargs_delarglist(hougasargs_argnode *argnode)
{
 hougasargs_argnode *next;
 hougasargs_argnode *prev;
 if(argnode != NULL)
 {
  next = argnode -> next;
  prev = argnode -> prev;
 }
 while(argnode != NULL)
 {
  free(argnode);
  argnode = next;
  next = argnode == NULL ? NULL : argnode->next;
 }
 argnode = prev;
 while(argnode != NULL);
 {
  free(argnode);
  argnode = prev;
  prev = argnode == NULL ? NULL : argnode->prev;
 }
}

/*
 remove node from list does not free
*/
hougasargs_argnode *hougasargs_removenode(hougasargs_argnode *current)
{
 if(current == NULL) return NULL;

 hougasargs_argnode *prev = current->prev;
 hougasargs_argnode *next = current->next;
 free(current);

 if(prev != NULL) prev->next = next;
 if(next != NULL) next->prev = prev;

 return next;
}

/*
 handle potentially multi-character single char flags
*/
int hougasargs_singletacflag(void **flagchart, char ***validflags, hougasargs_argnode *argnode)
{
 char *arg = argnode->arg;

 int i,j;
 for(i = 1; arg[i] != 0; i++)
 {
  for(j = 0; validflags[j] != NULL && arg[i] != validflags[j][1][0]; j++);

  if(validflags[j] == NULL) {printf("Flag %c invalid\n",arg[i]); return 1;}

  hougasargs_flagcount(flagchart,j)++;

  if(validflags[j][0][0] && arg[i+1] != 0) {printf("Flag %c requires arg\n",arg[i]); return 2;}
 }

 if(!validflags[j][0][0]) return 0;
 if(argnode->next == NULL) {printf("Flag %c requires arg\n",arg[i-1]); return 3;}

 hougasargs_flagvalue(flagchart,j) = argnode->next->arg;
 hougasargs_removenode(argnode->next);


 return 0;
}

/*
 handle multi-character flags
*/
int hougasargs_doubletacflag(void **flagchart, char ***validflags, hougasargs_argnode *argnode)
{
 char *arg = argnode->arg;
 int i,j;
 for(i = 0; validflags[i] != NULL; i++)
  for(j = 2; validflags[i][j] != NULL && strcmp(&arg[2],validflags[i][j]); j++);

 if(validflags[i] == NULL) {printf("Flag %s invalid\n", arg); return 1;}

 hougasargs_flagcount(flagchart,i)++;

 if(validflags[i][0][0] == 0) return 0;
 if(argnode->next == NULL) {printf("Flag %s requires arg"); return 2;}

 hougasargs_flagvalue(flagchart,i) = argnode->next->arg;
 hougasargs_removenode(argnode->next);

 return 0;
}

hougasargs_argnode *hougasargs_argproc(void **flagchart, char ***validflags, int argc, char **argv)
{
 int endofflags;
 for(endofflags = 1; endofflags < argc && strcmp(argv[endofflags],"--"); endofflags++);

 hougasargs_argnode *arghead = hougasargs_listanize(endofflags, argv);

 hougasargs_argnode *current = arghead;
 while(current != NULL)
 {
  if(hougasargs_startswithdoubletac(current->arg))
  {
   if(hougasargs_doubletacflag(flagchart, validflags, current))
   {
    hougasargs_delarglist(current);
    exit(1);
   }
   current = hougasargs_removenode(current);
  }
  else if(hougasargs_startswithsingletac(current->arg) && current->arg[1] != 0)
  {
   if(hougasargs_singletacflag(flagchart, validflags, current))
   {
    hougasargs_delarglist(current);
    exit(1);
   }
   current = hougasargs_removenode(current);
  }
  else current = current->next;
 }
 
 return arghead;
}

int hougasargs_testargproc(void ***pflagchart, char ***validflags, int argc, char **argv)
{
 
 int nvalid = 0; for(;validflags[nvalid] != NULL; nvalid++);
 *pflagchart = (void**)malloc(sizeof(void*)*nvalid*2);
 void **flagchart = *pflagchart;
 int i;
 for(i = 0; i<nvalid*2; i+=2)
 {
  flagchart[i] = NULL;
  flagchart[i+1] = malloc(sizeof(int));
  *((int**)flagchart)[i+1] = 0;
 }


 hougasargs_argnode *leftoverargs = hougasargs_argproc(flagchart, validflags, argc, argv);
 if(leftoverargs == NULL) {perror("testargproc failed"); return 1;}

 return 0;
}

/***
 mjhargsproc generates a chart of commandline flags values and invocation counts
 *flagchart will be in the form of {"val","&count","val","&count"...}
 validflags must be of the form {"single","multi","single","multi",..."--"} blanks must be explicitly ""
 multi-character args must be less than 1 KiB this is hard-coded and can be changed.
***/
/*
int mjhargsproc(void **flagchart, )
{
 int i,j;
 int nvalid = 0; for(;validflags[nvalid][0] != '-'; nvalid++);
 
 * create and zeroize flagchart *
 flagchart = malloc(sizeof(void*)*nvalid*2);
 for(i=0;i<nvalid;i+=2)
 {
  ((char**)flagchart)[i]=NULL;
  ((int**)flagchart)[i+1]=(int*)malloc(sizeof(int));
  *((int**)flachart)[i+1]=0;
 }

 for(i=0; i<argc; i++)
 {
 }
}
*
int mjhargsproc(void** flagchart, char** validflags, int argc, char** argv)
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
    if(!strncmp(&argv[i][2],validflags[j],MJHMAXTOKL))
    {
     (*(*(int***)flagchart)[j])++;
     if(i+1<argc && argv[i+1][0]!='-')
      (*(char***)flagchart)[j-1]=argv[i+1];
 }} }

 return 0;
}
*/

int hougasargs(int argc, char** argv)
{
 int i;
 void **chart;
 char ONE[] = {1};
 char *flags0[] = {ONE,"a","along","aalong",NULL};
 char *flags1[] = {"\0","b","blong","bllong",NULL};
 char *flags2[] = {ONE,"c","clong","cloong",NULL};
 char **validflags[] = {flags0,flags1,flags2,NULL};
 int nvalid = 0; for(;validflags[nvalid] != NULL; nvalid++);

 hougasargs_testargproc(&chart,validflags,argc,argv);

 for(i=0;i<nvalid;i++)
  printf("%s %s %s %d\n",validflags[i][1],validflags[i][2],hougasargs_flagvalue(chart,i),hougasargs_flagcount(chart,i));

 return 0;
}

int main(int argc, char** argv)
{
 return hougasargs(argc,argv);
}
