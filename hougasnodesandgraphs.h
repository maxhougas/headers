#include<stdlib.h>
#include<hougasconsts.h>

/***
A node that can have multiple parents and children with a generic data payload
***/

typedef struct
{
  node* parents;
  void* data;
  node* children;
} node;

/***
A queue with a pointer to the head and tail nodes.
***/

typedef struct
{
  node* head;
  node* tail;
} queue;

/***
Initialize node with pre-existing data and structures
***/

int nodeInit(node* nod, node* parents, void* data, node* children)
{
  int ret = SUCCESS;

  nod->parents = parents;
  nod->data = data;
  nod->children = children;

  return ret;
}

/***
Create node, push onto stack
***/

int nodePush(node* stack, void* toPush)
{
  int ret = SUCCESS;

  node* pushNode = (node*)malloc(sizeof(node));
  nodeInit(pushNode,stack,toPush,NULL);
  stack->children = pushNode;

  return ret;
}

/***
Retrieve data from top node, free node, update stack pointer
***/

int nodePop(node* stack, void** out)
{
  int ret = SUCCESS;

  if(stack)
  {
    *out = stack->data;
    stack = stack->parents;
    free(stack->children);
  }
  else
    ret = NULL_STRUCTURE;

  return ret;
}

/***
Retrieve data from top node
***/

int nodePeek(node* stack, void** out)
{
  int ret = SUCCESS;

  *out = stack->data;

  return ret;
}

/***
Create node, add to tail
***/

int enqueue(queue* q, void* dat)
{
  int ret = SUCCESS;

  node* toQueue = (node*)malloc(sizeof(node));

  if(q->head)
  {
    nodeInit(toQueue,q->tail,dat,NULL);
    q->tail->children = toQueue;
    q->tail = toQueue;
  }
  else
  {
    nodeInit(toQueue,NULL,dat,NULL);
    q->head = toQueue;
    q->tail = toQueue;
  }
  return ret;
}

/***
Retrieve data from tail, free tail
***/

int dequeue(queue* q, void** out)
{
  int ret = SUCCESS;

  if(q->head != q->tail)
  {
    *out = q->head->data;
    q->head = q->head->children;
    free(q->head->parents);
  }
  else if(q->head != NULL)
  {
    *out = q->head->data;
    free(q->head);
    q->head = NULL;
    q->tail = NULL;
  }
  else
    ret = EMPTY_SET;

  return ret;
}