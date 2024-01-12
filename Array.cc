#include <iostream>
#include <cstdlib>

using namespace std;

int suma(int *array, int s){
	int a=0;
	for(int i=0;i<s;i++){
		a=a+array[i];
	}
	return a;
}

int main(){
//	int a[10],i;
//	char b[10];
	int i;
	
	
	cout<<"Arrays/n"<<endl;
	cin>>i;
	//int *c=(int*)malloc(sizeof(int) *i);// pedir memoria
	int *a=new int [i];// otra forma de pedir memoria
	
/*	a[1]=42;
	a[9]=10;
	
	b[0]='h';
	b[1]='o';
	b[2]='l';
	b[3]='a';*/
	
	/*for(int i=0;i<10;i++)// mostrar el contenido del arreglo
	cout<<b[i]<<endl;*/
	
	for(int j=0;j<i;j++){//llenar el arreglo
		a[j]=23+j;
	}
	
	int s=suma(a,i);
	cout<<"La suma es -> "<<s<<endl;
	
	for(int k=0;k<i;k++){//mostrar el contenido del arreglo
		cout<<a[k]<<endl;
	}
	
	delete []a;// liberar memoria
	
	return 0;
}
