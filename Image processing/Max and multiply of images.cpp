#include <iostream>
using namespace std;
// Written at 1/12/2018
#define n 320       // Number of raws
#define m 320       // Number of columns
double x1[n][m];    // First image
double x2[n][m];    // Second image
double result[n][m];

void imageJ_Max(double s){
	for(int u=0;u<n;u++){
		for(int v=0;v<m;v++){
			double current = x1[u][v];
			if (current<s) result[u][v] = s;
			else result[u][v] = x1[u][v];
		}
	}
	FILE*f = fopen("maxed.raw","wb");
	fwrite(result,sizeof(double),n*m,f);
	fclose(f);

}

void multiply(){
	for(int u=0;u<n;u++){
		for(int v=0;v<m;v++){
			result[u][v] = x1[u][v] * x2[u][v];
		}
	}
	FILE*f = fopen("multiplied.raw","wb");
	fwrite(result,sizeof(double),n*m,f);
	fclose(f);
}

void main(){
	FILE*f;
	f = fopen("img1.raw","rb");
	fread(x1,sizeof(double),n*m,f);
	fclose(f);
	double temp;
	cout << "Enter value to send to max function :";cin>>temp;
	cout << "\nMaxing the first image...\n";
	imageJ_Max(temp);
	cout << "Finished and saved the result to maxed.raw";

	f = fopen("img2.raw","rb");
	fread(x2,sizeof(double),n*m,f);
	fclose(f);
	cout << "\nMultiplying the two images...\n";
	multiply();
	cout << "Finished and saved the result to multiplied.raw";

cout <<endl;
system("pause");
}