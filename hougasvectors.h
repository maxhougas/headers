#include<stdio.h>

//Modes for parallel math
#define ADD 0
#define SUB 1
#define MUL 2
#define DIV 3
#define MOD 4
#define LOD 5

//Numerical data type
#define INT 0
#define FLO 1
#define DOU 2
#define CHA 4

/***
Performs parallel math on vectors
if the operation is parallel load the value of b is irrelevant
***/

int vectorParallelMath(void* result, void* a, void* b, int size, int mode, int dattype)
{
  int ret = 0;

  int i;

  switch(dattype)
  {
    case INT:
      switch(mode)
      {
        case ADD: //add
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] + ((int*)b)[i];
        break;
        case SUB: //subtract
          for(i=0;i<size;i++)
           ((int*)result)[i] == ((int*)a)[i] - ((int*)b)[i];
        break;
        case MUL: //multiply
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] * ((int*)b)[i];
        break;
        case DIV: //divide
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] / ((int*)b)[i];
        break;
        case MOD: //remainder
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] % ((int*)b)[i];
        break;
        case LOD: //copies a to result
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i];
        default:
          ret = 2; //invalid mode
      }
    break;
    case FLO:
      switch(mode)
      {
        case ADD: //add
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] + ((float*)b)[i];
        break;
        case SUB: //subtract
          for(i=0;i<size;i++)
           ((float*)result)[i] == ((float*)a)[i] - ((float*)b)[i];
        break;
        case MUL: //multiply
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] * ((float*)b)[i];
        break;
        case DIV: //divide
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] / ((float*)b)[i];
        break;
        case LOD: //copies a to result
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i];
        default:
          ret = 2; //invalid mode
      }
    break;
    case DOU:
    switch(mode)
      {
        case ADD: //add
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] + ((double*)b)[i];
        break;
        case SUB: //subtract
          for(i=0;i<size;i++)
           ((double*)result)[i] == ((double*)a)[i] - ((double*)b)[i];
        break;
        case MUL: //multiply
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] * ((double*)b)[i];
        break;
        case DIV: //divide
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] / ((double*)b)[i];
        break;
        case LOD: //copies a to result
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i];
        default:
          ret = 2; //invalid mode
      }
    break;
    case CHA:
      switch(mode)
      {
        case ADD: //add
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] + ((char*)b)[i];
        break;
        case SUB: //subtract
          for(i=0;i<size;i++)
           ((char*)result)[i] == ((char*)a)[i] - ((char*)b)[i];
        break;
        case MUL: //multiply
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] * ((char*)b)[i];
        break;
        case DIV: //divide
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] / ((char*)b)[i];
        break;
        case MOD: //remainder
      }
    default:
      ret = 3; //invalid data type;
  }

  return ret;
}

/***
 Perform the same function on each element of a vector
***/

int vectorImmediateMath(void* result, void* a, void* b, int size, int mode, int dattype)
{
  int ret = 0;

  int i;

  switch(dattype)
  {
    case INT:
      switch(mode)
      {
        case ADD: //add
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] + *((int*)b);
        break;
        case SUB: //subtract
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] - *((int*)b);
        break;
        case MUL: //multiply
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] * *((int*)b);
        break;
        case DIV: //divide
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] / *((int*)b);
        break;
        case MOD: //remainder
          for(i=0;i<size;i++)
            ((int*)result)[i] == ((int*)a)[i] % *((int*)b);
        break;
        case LOD: //copies a to result
          for(i=0;i<size;i++)
            ((int*)result)[i] == *((int*)b);
        default:
          ret = 2; //invalid mode
      }
    case FLO:
      switch(mode)
      {
        case ADD: //add
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] + *((float*)b);
        break;
        case SUB: //subtract
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] - *((float*)b);
        break;
        case MUL: //multiply
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] * *((float*)b);
        break;
        case DIV: //divide
          for(i=0;i<size;i++)
            ((float*)result)[i] == ((float*)a)[i] / *((float*)b);
        break;
        case LOD: //copies a to result
          for(i=0;i<size;i++)
            ((float*)result)[i] == *((float*)b);
        default:
          ret = 2; //invalid mode
      }
    case DOU:
      switch(mode)
      {
        case ADD: //add
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] + *((double*)b);
        break;
        case SUB: //subtract
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] - *((double*)b);
        break;
        case MUL: //multiply
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] * *((double*)b);
        break;
        case DIV: //divide
          for(i=0;i<size;i++)
            ((double*)result)[i] == ((double*)a)[i] / *((double*)b);
        break;
        case LOD: //copies a to result
          for(i=0;i<size;i++)
            ((double*)result)[i] == *((double*)b);
        default:
          ret = 2; //invalid mode
      }
    case CHA:
      switch(mode)
      {
        case ADD: //add
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] + *((char*)b);
        break;
        case SUB: //subtract
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] - *((char*)b);
        break;
        case MUL: //multiply
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] * *((char*)b);
        break;
        case DIV: //divide
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] / *((char*)b);
        break;
        case MOD: //remainder
          for(i=0;i<size;i++)
            ((char*)result)[i] == ((char*)a)[i] % *((char*)b);
        break;
        case LOD: //copies a to result
          for(i=0;i<size;i++)
            ((char*)result)[i] == *((char*)b);
        default:
          ret = 2; //invalid mode
      }
    default:
      ret = 3; //invalid data type
  }

    return ret;
}

/***
Generates a single value from a vector
***/

int vectorReduce(void* result, void* a, int size, int mode, int dattype)
{
  int ret = 0;

  int i;
  switch(dattype)
  {
    case INT:
      switch(mode)
      {
        case ADD: //add
          *(int*)result = 0;
          for(i=0;i<size;i++)
            *(int*)result += ((int*)a)[i];
        break;
        case SUB: //subtract
          *(int*)result = 0;
          for(i=0;i<size;i++)
            *(int*)result -= ((int*)a)[i];
        break;
        case MUL: //multiply
          *(int*)result = 1;
          for(i=0;i<size;i++)
            *(int*)result *= ((int*)a)[i];
        break;
        case DIV: //divide
          *(int*)result = 1;
          for(i=0;i<size;i++)
            *(int*)result /= ((int*)a)[i];
        break;
        default:
          ret = 2; //invalid mode
      }
    break;
    case FLO:
      switch(mode)
      {
        case ADD: //add
          *(float*)result = 0;
          for(i=0;i<size;i++)
            *(float*)result += ((float*)a)[i];
        break;
        case SUB: //subtract
          *(float*)result = 0;
          for(i=0;i<size;i++)
            *(float*)result -= ((float*)a)[i];
        break;
        case MUL: //multiply
          *(float*)result = 1;
          for(i=0;i<size;i++)
            *(float*)result *= ((float*)a)[i];
        break;
        case DIV: //divide
          *(float*)result = 1;
          for(i=0;i<size;i++)
            *(float*)result /= ((float*)a)[i];
        break;
        default:
          ret = 2; //invalid mode
      }
    break;
    case DOU:
      switch(mode)
      {
        case ADD: //add
          *(double*)result = 0;
          for(i=0;i<size;i++)
            *(double*)result += ((double*)a)[i];
        break;
        case SUB: //subtract
          *(double*)result = 0;
          for(i=0;i<size;i++)
            *(double*)result -= ((double*)a)[i];
        break;
        case MUL: //multiply
          *(double*)result = 1;
          for(i=0;i<size;i++)
            *(double*)result *= ((double*)a)[i];
        break;
        case DIV: //divide
          *(double*)result = 1;
          for(i=0;i<size;i++)
            *(double*)result /= ((double*)a)[i];
        break;
        default:
          ret = 2; //invalid mode
      }
    break;
    case CHA:
      switch(mode)
      {
        case ADD: //add
          *(char*)result = 0;
          for(i=0;i<size;i++)
            *(char*)result += ((char*)a)[i];
        break;
        case SUB: //subtract
          *(char*)result = 0;
          for(i=0;i<size;i++)
            *(char*)result -= ((char*)a)[i];
        break;
        case MUL: //multiply
          *(char*)result = 1;
          for(i=0;i<size;i++)
            *(char*)result *= ((char*)a)[i];
        break;
        case DIV: //divide
          *(char*)result = 1;
          for(i=0;i<size;i++)
            *(char*)result /= ((char*)a)[i];
        break;
        default:
          ret = 2; //invalid mode
      }
    break;
  }

    return ret;
}

int printVector(void* toprint, int size, int dattype)
{
  int ret = 0;

  printf("<");

  int i;
  switch(dattype)
  {
    case INT:
      for(i=0;i<size-1;i++)
        printf("%d,",((int*)toprint)[i]);
      printf("%d",((int*)toprint)[size]);
    break;
    case FLO:
      for(i=0;i<size-1;i++)
        printf("%f,",((float*)toprint)[i]);
      printf("%f",((float*)toprint)[size]);
    break;
    case DOU:
      for(i=0;i<size-1;i++)
        printf("%f,",((double*)toprint)[i]);
      printf("%f",((double*)toprint)[size]);
    break;
    case CHA:
      for(i=0;i<size-1;i++)
        printf("%d,",((char*)toprint)[i]);
      printf("%d",((char*)toprint)[size]);
    break;
    default:
    ret = 3; //invalid data type
  }

  printf(">\n");

  return ret;
}