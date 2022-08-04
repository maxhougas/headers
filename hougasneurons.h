#include <stdlib.h>
#include "./hougasconsts.h"

/***
A McCullough-Pitts type neuron.
Note that the transfer function is seperate, and called "neuronResolve"
***/

typedef struct
{
 int* ins;
 int* weights;
 int* out;
} neuron;

/***
Intializes a nueron by piping it up.
You must already have data structures to connect ins, weights, and out to
***/

int neuronInit(neuron* neu, int* ins, int* weights, int* out)
{
 int ret = SUCCESS;

 if(!neu)
  ret = NULL_STRUCTURE;
 else
 {
  neu->ins = ins;
  neu->weights = weights;
  neu->out = out;
 }

 return ret;
}

/***
Enacts the transfer function:
 all inputs are multiplied by their associated weights, summed, and compared to trigger;
***/

int neuronResolve(neuron* neu, int netWidth, int trigger)
{
 int ret = SUCCESS;

 if(!neu)
  ret = NULL_STRUCTURE;
 else
 {
  int result = 0;

  int i;
  for(i=0;i<netWidth;i++)
   result += neu->ins[i] * neu->weights[i];

  neu->out[0] = result > trigger;
 }

 return ret;
}

/***
Several assumptions are made:
 Nuerons have as many inputs as net width
 All neurons are identical except for their position
 The network is rectangular
 Nerons do not share weights
 The final output vector is part of the input vector
***/

int initAllNeurons(neuron* neus, int* ins, int* weights, int netWidth, int netDepth)
{
 int ret = SUCCESS;

 int numOfNeus = netWidth*netDepth;

 neus = (neuron*)malloc(numOfNeus*sizeof(neuron));
 ins = (int*)malloc(numOfNeus*sizeof(int) + netWidth*sizeof(int));
 weights = (int*)malloc(netWidth*numOfNeus*sizeof(int));

 if(!(neus && ins && weights))
  ret = MALLOC_FAIL;
 else
 {
  neuron* currentNeuron;
  int* currentInput;
  int* currentWeights;
  int* currentOutput;

  int i;
  for(i=0;i<numOfNeus;i++)
  {
   currentNeuron = &neus[i];
   currentInput = &ins[(i/netWidth)*netWidth];
   currentWeights = &weights[i*netWidth];
   currentOutput = &ins[i + netWidth];

   neuronInit(currentNeuron,currentInput,currentWeights,currentOutput);
  }
 }

 return ret;
}
