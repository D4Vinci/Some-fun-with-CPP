#include <iostream>
#include <cmath>
using namespace std;
// Written at 5/12/2018
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
  //Commulative histogram
  float H[256];
  float sum = hist[0];
  H[0] = sum; //because here i=0 so H[0]=h[0]
  for(int i=1;i<256;i++){
    sum+=hist[i];
    H[i] = sum;
  }
  //Histogram equalization
  int k = 255;    //Maximum value (k-1=256-1=255)
  float f[256];  //Feq
  for(int i=0;i<256;i++) f[i] = floor(H[i]*(k/total_size)); //include cmath to use floor
  cout << "\n\nThe new histogram:\n";
  for(int i=0;i<256;i++) cout << i << " -> "<< f[i]<<endl;
  system("pause");
  return 0;
  }
