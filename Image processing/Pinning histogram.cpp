#include <iostream>
using namespace std;
// Written at 14/11/2018
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
  // code el doctor
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
  //----------------------------------------------------------------------
  // Here we start coding the pinning histogram
	int interval = 256/8; // 8 intervals each one is 256/8=32
	int pinning[8],current=0,sum=0;
	for( int this_interval=0;this_interval<256;){
		this_interval+=32;
		sum=0;
		for (int j=this_interval-32;j<this_interval;j++) sum += hist[j];
		pinning[current] = sum;
		current++;
	}

	cout << "Pinning histogram : \n";
	for(int a5ern=0;a5ern<8;a5ern++) cout << "-["<< a5ern <<"] -> "<<pinning[a5ern]<<endl;
  system("pause");
	return 0;
}
