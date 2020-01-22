#include <iostream>
#include <cmath>
using namespace std;
// Written at 4/12/2018
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
	//Automated contrast adjustment
	int min = 255,max = 0, total_size = m*n;
	for(int i=0;i<256;i++){
		if(hist[i]!=0){
			min = i;
			break;
		}
	}
	for(int i=255;i>=0;i--){
		if(hist[i]!=0){
			max = i;
			break;
		}
	}
	//a low is min; a high is max
	float a,Auto[n][m];
	int index = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a = x[i][j];
			Auto[i][j] = (a-min)*( 255/ (max-min));
		}
	}
	//----------------------------------------------------
	cout << "Max="<<max<<" min="<<min<<endl;
	fb = fopen("final.raw","wb");
	fwrite(Auto,sizeof(float),n*m,fb);
	fclose(fb);
  system("pause");
	return 0;
}
