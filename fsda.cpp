/* ***********************************************
Author        :caowushang
Created Time  :2016-11-7 10:25:04
TASK		  :fsda.cpp
LANG          :C++
Problem		  :
************************************************ */

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int MX=1e5+10;
const int mod=1e9+7;
double f(double x)
{
	return x+sin(x)/3;
}
double Tixing(double a,double b,int n){  
  double h = (b-a)/n;  
  double x = a;  
  double s = 0;  
  for(int k=0; k< n-1; k++){  
    x += h;  
    s += f(x);  
  }  
  double T = (f(a)+s*2+f(b))*h/2;  
  return T;  
} 
double Simpson(double a,double b,int n){  
  double h = (b-a)/n;  
  double x = a+h/2;  
  double s = 4*f(x);  
  for(int k=1;k<n;k++){  
    x += h/2;  
    s += 4*f(x);  
    x += h/2;  
    s += 2*f(x);  
  }  
  double T=(f(a)+s+f(b))*h/6;
  return T;   
}  
int main()
{
    cout << "复化梯形公式计算结果:    " << Tixing(0.3,1.5,7) << endl;
	printf("%.8f\n",Tixing(0.3,1.5,100000));
	cout << "复化Simpson公式计算结果: " << Simpson(0.3,1.5,7) << endl;
	printf("%.8f\n",Simpson(0.3,1.5,100000));
    return 0;
}
