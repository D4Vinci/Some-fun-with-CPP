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
	// Negation
	fb = fopen("t.raw","wb");
	for(int w=0;w<n;w++){
    for(int h=0;h<m;h++){
			x[w][h] = 255 - x[w][h];
		}
	}
	fwrite(x,sizeof(float),n*m,fb);
	fclose(fb);
	system("pause");
	return 0;
}
