#include<stdlib.h>
#include<hougasconsts.h>

typedef struct
{
  void* parents;
  void* data;
  void* children;
} node;

int nodeInst(node** out)
{
  int ret = SUCCESS;

 *out = (node*)malloc(sizeof(node));

  return ret;
}

int nodeGetParents(node* nod, void** out)
{
  int ret = SUCCESS;
  *out = nod->parents;
  return ret;
}

int nodeGetData(node* nod, void** out)
{
  int ret = SUCCESS;
  *out = nod->data;
  return ret;
}

int nodeGetChildren(node* nod, void** out)
{
  int ret = SUCCESS;
  *out = nod->children;
  return ret;
}

