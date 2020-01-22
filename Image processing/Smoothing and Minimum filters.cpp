#include <iostream>
#include <math.h>
using namespace std;
// Written at 24/12/2018
#define m 320
#define n 320

int main(){
	float x[n][m];
	FILE* fb;
	fb = fopen("slice7","rb");
	fread(x,sizeof(float),n*m,fb);
	fclose(fb);
	float img[n][m];
	//Smoothing filter (Linear filter)
	
	double filter[3][3] = {
		{1/9, 1/9, 1/9},
		{1/9, 1/9, 1/9},
		{1/9, 1/9, 1/9}
	};
	float sum;
	for(int h=1;h<n-2;h++){
		for(int w=1;w<m-2;w++){
			sum = 0;
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					sum += filter[i][j]*x[h+i][w+j];
				}
			}
			img[h][w] = sum;
		}
	}

	fb = fopen("filter1","wb");
	fwrite(img,sizeof(float),n*m,fb);
	fclose(fb);

	//Minimum filter (Non-linear filter)
	float min;
	for(int h=1;h<n-2;h++){
		for(int w=1;w<m-2;w++){
			min = 255;
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					if(x[h+i][w+j]<min) min = x[h+i][w+j];
				}
			}
			img[h][w] = min;
		}
	}
	fb = fopen("final","wb");
	fwrite(img,sizeof(float),n*m,fb);
	fclose(fb);

cout <<endl;
system("pause");
return 0;
}