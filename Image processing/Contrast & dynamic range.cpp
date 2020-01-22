#include <iostream>
using namespace std;
// Written at 28/11/2018
#define n 320      //number of raws
#define m 320      //number of columns

int main (){
	float x[n][m];
	//reading image
	FILE *fb;
	fb = fopen ("slice7","rb");
	fread(x,sizeof(float),n*m,fb);
	fclose(fb);
  // image histogram
	int p, hist[256];
	for(int i=0;i<256;i++) hist[i]=0; //Initializing Histogram to zeros
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			p=x[i][j];
			for(int k=0;k<256;k++) {
				if(p==k) hist[k]++;
			}
		}
	}

	//Contrast and Dynamic range
	int min = 255,max = 0;
	int range=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if( x[i][j] >= max) max = x[i][j];
			else min = x[i][j];
		}
	}
	for (int i=0;i<255;i++) if( hist[i] !=0) range++;
	cout << "Max = "<<max<<", Min = "<<min<<endl;
	cout << "Contrast is " << (max-min) << endl;
	cout << "Dynamic range is " << range << endl;
	system("pause");
	return 0;
}
