#include <iostream>
using namespace std;
// Written at 23/12/2018
#define n 320
#define m 320
int main(){
	float x[n][m];
	FILE *fb;
	fb = fopen("slice7","rb");
	fread(x,sizeof(float),n*m,fb);
	fclose(fb);
	// Histogram
	int h[256],temp;
	for(int i=0;i<256;i++) h[i]=0; //Initializing Histogram to zeros
	fb = fopen("t.raw","wb");
	for(int w=0;w<n;w++){
		for(int h=0;h<m;h++){
			temp = x[w][h];
      if (temp>0 && temp<256) h[temp] +=1;
		}
	}
	fwrite(x,sizeof(float),n*m,fb);
	fclose(fb);
  /*
  // image histogram
  // code el doctor
  int p, hist[256];
  for(int i=0;i<256;i++) hist[i]=0;
  //cout<<hist[i] <<"\n";
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      p=x[i][j];
      for(int k=0;k<256;k++) {
        if(p==k) hist[k]++;
      }
    }
  }
  */
	system("pause");
	return 0;
}
