#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PiValue = 3.1416;

float Distance (float x1, float x2, float y1, float y2){
    float DisX = x2-x1;
    float DisY = y2-y1;
    float DisValue = sqrt(pow(DisX,2)+pow(DisY,2));
    return DisValue;
}

float Radius (float x1, float x2, float y1, float y2){
    float radValue = Distance(x1,x2,y1,y2)/2;
    return radValue;
}

float Circumference (float x1, float x2, float y1, float y2){
    float CirValue = 2*PiValue*Radius(x1,x2,y1,y2);
    return CirValue;
}

float Area (float x1, float x2, float y1, float y2){
    float AreaValue = PiValue*pow(Radius(x1,x2,y1,y2),2);
    return AreaValue;
}

int main (){
    float Ax1,Ax2,Ay1,Ay2;
    cout << "Masukkan nilai x1 : ";
    cin >> Ax1;
    cout << "Masukkan nilai x2 : ";
    cin >> Ax2;
    cout << "Masukkan nilai y1 : ";
    cin >> Ay1;
    cout << "Masukkan nilai y2 : ";
    cin >> Ay2;

    cout << "Nilai distance atau diameternya adalah "<<fixed<<setprecision(4)<<Distance(Ax1,Ax2,Ay1,Ay2)<<endl;
    cout << "Nilai radiusnya adalah "<<fixed<<setprecision(4)<<Radius(Ax1,Ax2,Ay1,Ay2)<<endl;
    cout << "Nilai circumference adalah "<<fixed<<setprecision(4)<<Circumference(Ax1,Ax2,Ay1,Ay2)<<endl;
    cout << "Nilai luas area adalah "<<fixed<<setprecision(4)<<Area(Ax1,Ax2,Ay1,Ay2)<<endl;

    return 0;
}
