#include <stdio.h>
#include "./hougasconsts.h"

/*Modes for parallel math*/
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
#define MOD 4
#define LOD 5

/***
Performs parallel math on vectors
if the operation is parallel load the value of b is irrelevant
***/

int vectorParallelMath(void* result, void* a, void* b, int size, int mode, int dattype)
{
  int i;

  switch(dattype)
  {
    case INT:
      switch(mode)
      {
        case ADD:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] + ((int*)b)[i];
        break;
        case SUB:
          for(i=0;i<size;i++)
           ((int*)result)[i] == ((int*)a)[i] - ((int*)b)[i];
        break;
        case MUL:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] * ((int*)b)[i];
        break;
        case DIV:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] / ((int*)b)[i];
        break;
        case MOD:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] % ((int*)b)[i];
        break;
        case LOD:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i];
        default:
          return INVALID_MODE;
      }
    break;
    case FLO:
      switch(mode)
      {
        case ADD:
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] + ((float*)b)[i];
        break;
        case SUB:
          for(i=0;i<size;i++)
           ((float*)result)[i] == ((float*)a)[i] - ((float*)b)[i];
        break;
        case MUL:
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] * ((float*)b)[i];
        break;
        case DIV:
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] / ((float*)b)[i];
        break;
        case LOD:
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i];
        default:
          return INVALID_MODE;
      }
    break;
    case DOU:
    switch(mode)
      {
        case ADD:
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] + ((double*)b)[i];
        break;
        case SUB:
          for(i=0;i<size;i++)
           ((double*)result)[i] == ((double*)a)[i] - ((double*)b)[i];
        break;
        case MUL:
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] * ((double*)b)[i];
        break;
        case DIV:
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] / ((double*)b)[i];
        break;
        case LOD:
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i];
        default:
          return INVALID_MODE;
      }
    break;
    case CHA:
      switch(mode)
      {
        case ADD:
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] + ((char*)b)[i];
        break;
        case SUB:
          for(i=0;i<size;i++)
           ((char*)result)[i] == ((char*)a)[i] - ((char*)b)[i];
        break;
        case MUL:
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] * ((char*)b)[i];
        break;
        case DIV:
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] / ((char*)b)[i];
        break;
        case LOD:
          for(i=0;i<size;i++)
           ((char*)result)[i] == ((char*)a)[1];
        default:
          return INVALID_MODE;
      }
    default:
      return INVALID_DATATYPE;
  }

  return SUCCESS;
}

/***
 Perform the same function on each element of a vector
***/

int vectorImmediateMath(void* result, void* a, void* b, int size, int mode, int dattype)
{
  int i;

  switch(dattype)
  {
    case INT:
      switch(mode)
      {
        case ADD:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] + *((int*)b);
        break;
        case SUB:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] - *((int*)b);
        break;
        case MUL:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] * *((int*)b);
        break;
        case DIV:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] / *((int*)b);
        break;
        case MOD:
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] % *((int*)b);
        break;
        case LOD:
          for(i=0;i<size;i++)
            ((int*)result)[i] == *((int*)b);
        default:
          return INVALID_MODE;
      }
    case FLO:
      switch(mode)
      {
        case ADD:
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] + *((float*)b);
        break;
        case SUB:
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] - *((float*)b);
        break;
        case MUL:
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] * *((float*)b);
        break;
        case DIV:
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] / *((float*)b);
        break;
        case LOD:
          for(i=0;i<size;i++)
            ((float*)result)[i] == *((float*)b);
        default:
          return INVALID_MODE;
      }
    case DOU:
      switch(mode)
      {
        case ADD:
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] + *((double*)b);
        break;
        case SUB:
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] - *((double*)b);
        break;
        case MUL:
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] * *((double*)b);
        break;
        case DIV:
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] / *((double*)b);
        break;
        case LOD:
          for(i=0;i<size;i++)
            ((double*)result)[i] == *((double*)b);
        default:
          return INVALID_MODE;
      }
    case CHA:
      switch(mode)
      {
        case ADD:
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] + *((char*)b);
        break;
        case SUB:
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] - *((char*)b);
        break;
        case MUL:
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] * *((char*)b);
        break;
        case DIV:
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] / *((char*)b);
        break;
        case MOD:
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] % *((char*)b);
        break;
        case LOD:
          for(i=0;i<size;i++)
            ((char*)result)[i] == *((char*)b);
        default:
          return INVALID_MODE;
      }
    default:
      return INVALID_DATATYPE;
  }

  return SUCCESS;
}

/***
Generates a single value from a vector
***/

int vectorReduce(void* result, void* a, int size, int mode, int dattype)
{
  int i;

  switch(dattype)
  {
    case INT:
      switch(mode)
      {
        case ADD:
          *(int*)result = 0;
          for(i=0;i<size;i++)
            *(int*)result += ((int*)a)[i];
        break;
        case SUB:
          *(int*)result = 0;
          for(i=0;i<size;i++)
            *(int*)result -= ((int*)a)[i];
        break;
        case MUL:
          *(int*)result = 1;
          for(i=0;i<size;i++)
            *(int*)result *= ((int*)a)[i];
        break;
        case DIV:
          *(int*)result = 1;
          for(i=0;i<size;i++)
            *(int*)result /= ((int*)a)[i];
        break;
        default:
          return INVALID_MODE;
      }
    break;
    case FLO:
      switch(mode)
      {
        case ADD:
          *(float*)result = 0;
          for(i=0;i<size;i++)
            *(float*)result += ((float*)a)[i];
        break;
        case SUB:
          *(float*)result = 0;
          for(i=0;i<size;i++)
            *(float*)result -= ((float*)a)[i];
        break;
        case MUL:
          *(float*)result = 1;
          for(i=0;i<size;i++)
            *(float*)result *= ((float*)a)[i];
        break;
        case DIV:
          *(float*)result = 1;
          for(i=0;i<size;i++)
            *(float*)result /= ((float*)a)[i];
        break;
        default:
          return INVALID_MODE;
      }
    break;
    case DOU:
      switch(mode)
      {
        case ADD:
          *(double*)result = 0;
          for(i=0;i<size;i++)
            *(double*)result += ((double*)a)[i];
        break;
        case SUB:
          *(double*)result = 0;
          for(i=0;i<size;i++)
            *(double*)result -= ((double*)a)[i];
        break;
        case MUL:
          *(double*)result = 1;
          for(i=0;i<size;i++)
            *(double*)result *= ((double*)a)[i];
        break;
        case DIV:
          *(double*)result = 1;
          for(i=0;i<size;i++)
            *(double*)result /= ((double*)a)[i];
        break;
        default:
          return INVALID_MODE;
      }
    break;
    case CHA:
      switch(mode)
      {
        case ADD:
          *(char*)result = 0;
          for(i=0;i<size;i++)
            *(char*)result += ((char*)a)[i];
        break;
        case SUB:
          *(char*)result = 0;
          for(i=0;i<size;i++)
            *(char*)result -= ((char*)a)[i];
        break;
        case MUL:
          *(char*)result = 1;
          for(i=0;i<size;i++)
            *(char*)result *= ((char*)a)[i];
        break;
        case DIV:
          *(char*)result = 1;
          for(i=0;i<size;i++)
            *(char*)result /= ((char*)a)[i];
        break;
        default:
          return INVALID_MODE;
      }
    break;
  }

  return SUCCESS;
}

/***
Print vector to terminal
***/

int vectorPrint(void* toprint, int size, int dattype)
{

  printf("<");

  int i;
  switch(dattype)
  {
    case INT:
      for(i=0;i<size-1;i++)
        printf("%d,",((int*)toprint)[i]);
      printf("%d",((int*)toprint)[size-1]);
    break;
    case FLO:
      for(i=0;i<size-1;i++)
        printf("%f,",((float*)toprint)[i]);
      printf("%f",((float*)toprint)[size-1]);
    break;
    case DOU:
      for(i=0;i<size-1;i++)
        printf("%f,",((double*)toprint)[i]);
      printf("%f",((double*)toprint)[size-1]);
    break;
    case CHA:
      for(i=0;i<size-1;i++)
        printf("%d,",((char*)toprint)[i]);
      printf("%d",((char*)toprint)[size-1]);
    break;
    default:
    return INVALID_DATATYPE;
  }

  printf(">\n");

  return SUCCESS;
}
