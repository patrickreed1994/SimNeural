#include <iostream>
using namespace std;

class Perceptron
{
public:
	int getPrediction(int*);
	void train(int*, int);
	Perceptron(int);
	int* weight;
	int size;
};

Perceptron::Perceptron(int nodes)
{
	size=nodes;
	weight=new int[nodes+1];
	for(int i=0; i<nodes+1; i++)
		weight[i]=0;
}

int Perceptron::getPrediction(int* inputs)
{
	int sum=0;
	for(int i=0; i<size; i++)
	{
		//if(inputs[i]==0) inputs[i]=-1;
		//sum+=inputs[i]*weight[i];

		sum+=(inputs[i]==0?-1:1)*weight[i];
	}
	sum+=1*weight[size];
	if(sum>=0) return 1;
	else return 0;
}

void Perceptron::train(int* inputs, int want)
{
	int prediction = getPrediction(inputs);
	int error = want - prediction;

	for(int i=0; i<size; i++)
	{
		weight[i]+= error * (inputs[i]==0?-1:1);
	}
	weight[size]+=error;	//input is 1, 1*error to bias weight
}

main()
{
	Perceptron* neuron=new Perceptron(2);
	int data[2];

	for (int i=0; i<10000; i++)
	{
		data[0]=0; data[1]=0;
		neuron->train(data,0);
		data[0]=0; data[1]=1;
		neuron->train(data,1);
		data[0]=1; data[1]=0;
		neuron->train(data,1);
		data[0]=1; data[1]=1;
		neuron->train(data,0);
	}

	data[0]=0; data[1]=0;
	cout<<"0,0 is " <<neuron->getPrediction(data)<<endl;
	data[0]=0; data[1]=1;
	cout<<"0,1 is "<<neuron->getPrediction(data)<<endl;
	data[0]=1; data[1]=0;
	cout<<"1,0 is "<<neuron->getPrediction(data)<<endl;
	data[0]=1; data[1]=1;
	cout<<"1,1 is "<<neuron->getPrediction(data)<<endl;
	
}
