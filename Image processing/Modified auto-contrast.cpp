#include <iostream>
#include <cmath>
using namespace std;
// Written at 24/12/2018
#define n 320      //number of raws
#define m 320      //number of columns
int total_size = m*n;
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
	//Modified auto-contrast
	float H[256];//commulative histogram
	float sum = hist[0];
	H[0] = sum; //because here i=0 so H[0]=h[0]
	for(int i=1;i<256;i++){
	  sum+=hist[i];
	  H[i] = sum;
	}
	float q_low  = 5*(total_size/100), q_high = (95)*(total_size/100);
	float a_low, a_high;
	for(int i=255;i>=0;i--){
		if(H[i]<=q_high){
			a_high = i;
			break;
		}
	}
	for(int i=0;i<=255;i++){
		if(H[i]>=q_low){
			a_low = i;
			break;
		}
	}
	float a,modified[n][m];
	int index = 0;
	cout << q_low << "  " << q_high <<endl;
	cout << a_low << "  "<<a_high<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			a = x[i][j];
			if(a<=a_low) modified[i][j] = a_low;
			else if(a<=a_low && a>=a_high) modified[i][j] = (a-a_low)*( 255/ (a_high-a_low));
			else if(a>=a_high) modified[i][j] = a_high;
		}
	}
	fb = fopen ("final.raw","wb");
	fwrite(modified,sizeof(float),n*m,fb);
	fclose(fb);
	system("pause");
	return 0;
}
