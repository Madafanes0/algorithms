class Solution {
public:
    string intToRoman(int num) {
        int I=1;
        int IV=4;
        int V=5;
        int IX=9;
        int X=10;
        int XL=40;
        int L=50;
        int XC=90;
        int C=100;
        int CD=400;
        int D=500;
        int CM=900;
        int M=1000;
        string cadena="";

        while(num>0){
            if(num-M>=0){
                num -= M;
                cadena += "M";
            }
            else if(num-CM>=0){
                num -= CM;
                cadena += "CM";
            }
            else if(num-D>=0){
                num -= D;
                cadena += "D";
            }
            else if(num-CD>=0){
                num -= CD;
                cadena += "CD";
            }
            else if(num-C>=0){
                num -= C;
                cadena += "C";
            }
            else if(num-XC>=0){
                num -= XC;
                cadena += "XC";
            }
            else if(num-L>=0){
                num -= L;
                cadena += "L";
            }
            else if(num-XL>=0){
                num -= XL;
                cadena += "XL";
            }
            else if(num-X>=0){
                num -= X;
                cadena += "X";
            }
            else if(num-IX>=0){
                num -= IX;
                cadena += "IX";
            }
            else if(num-V>=0){
                num -= V;
                cadena += "V";
            }
            else if(num-IV>=0){
                num -= IV;
                cadena += "IV";
            }
            else if(num-I>=0){
                num -= I;
                cadena += "I";
            }
        }
        return cadena;
    }
};