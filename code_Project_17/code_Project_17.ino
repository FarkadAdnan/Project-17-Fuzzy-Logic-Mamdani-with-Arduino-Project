/*
 By:Farkad Adnan
 E-mail: farkad.hpfa95@gmail.com
 inst : farkadadnan
 #farkadadnan , #farkad_adnan , فرقد عدنان#
 FaceBook: كتاب عالم الاردوينو
 inst : arduinobook
 #كتاب_عالم_الاردوينو  #كتاب_عالم_الآردوينو 
 */
 #include<stdio.h>
 #include<math.h>
float A, B;
int sel_;

float a1, b1a, b1b, c1;

float fudeket[4] = {0, 0, 10, 100};
float fulumayan[3] = {50, 150, 250};
float fujauh[4] = {200, 290, 300, 300};

float fylambat[3] = {0, 0, 100};
float fysedang[3] = {20, 127.5, 235};
float fycepat[3] = {155, 255, 255};

float inputf, outputf;

float FiN(){
    if (inputf < fudeket[2]){return 1;}
    else if (inputf >= fudeket[2] && inputf <= fudeket[3]){return (fudeket[3] - inputf)/(fudeket[3]-fudeket[2]);}
    else if (inputf > fudeket[3]){return 0;}
}

float FiZ(){

    if (inputf < fulumayan[0]){return 0;}
    else if (inputf >= fulumayan[0] && inputf <= fulumayan[1]){return (inputf - fulumayan[0])/(fulumayan[1]-fulumayan[0]);}
    else if (inputf >= fulumayan[1] && inputf <= fulumayan[2]){return (fulumayan[2] - inputf)/(fulumayan[2]-fulumayan[1]);}
    else if (inputf > fulumayan[2]){return 0;}

}

float FiP(){
    if (inputf < fujauh[0]){return 0;}
    else if (inputf >= fujauh[0] && inputf <= fujauh[1]){return (inputf - fujauh[0])/(fujauh[1]-fujauh[0]);}
    else if (inputf > fujauh[1]){return 1;}
}

float FoN(){
    if (outputf < fylambat[1]){return 1;}
    else if (outputf >= fylambat[1] && outputf <= fylambat[2]){return (fylambat[2] - outputf)/(fylambat[2]-fylambat[1]);}
    else if (outputf > fylambat[2]){return 0;}
}

float FoZ(){

    if (outputf < fysedang[0]){return 0;}
    else if (outputf >= fysedang[0] && outputf <= fysedang[1]){return (outputf - fysedang[0])/(fysedang[1]-fysedang[0]);}
    else if (outputf >= fysedang[1] && outputf <= fysedang[2]){return (fysedang[2] - outputf)/(fysedang[2]-fysedang[1]);}
    else if (outputf > fysedang[2]){return 0;}

}

float FoP(){
    if (outputf < fycepat[0]){return 0;}
    else if (outputf >= fycepat[0] && outputf <= fycepat[1]){return (outputf - fycepat[0])/(fycepat[1]-fycepat[0]);}
    else if (outputf > fycepat[1]){return 1;}
}

void implikasi (){
//sesuai dengan rule
// if deket then lambat
a1 = 100 - (FiN() * (fylambat[2] - fylambat[1]));
// if lumayan then sedang
b1a = 20 + (FiZ() * (fysedang[1] - fysedang[0]));
b1b =  235 - (FiZ() * (fysedang[2] - fysedang[1]));
// if jauh then cepat
c1 = 155 + (FiP() * (fycepat[1] - fycepat[0]));
}

float f(float x){

    if (B > 0 && sel_ == 0){
    return ((x-A)/B)*x;
    }
    else if (B > 0 && sel_ == 1){
    return ((A-x)/B)*x;
    }
    else {
    return A*x;
    }
}

/*Function definition to perform integration by Simpson's 1/3rd Rule */
float simpsons(float f(float x), float a,float b,float n){
  float h,integral,x,sum=0;
  int i;
  h=fabs(b-a)/n;
  for(i=1;i<n;i++){
    x=a+i*h;
    if(i%2==0){
      sum=sum+2*f(x);
    }
    else{
      sum=sum+4*f(x);
    }
  }
  integral=(h/3)*(f(a)+f(b)+sum);
  return integral;
}

float fx(float limd, float limu, float a, float b, int sel){
    int n,i=2;
    float h,x,integral,eps=0.1,integral_new;
    A = a;
    B = b;
    sel_ = sel;
    integral_new=simpsons(f,limd,limu,i);

    do{
        integral=integral_new;
        i=i+2;
        integral_new=simpsons(f,limd,limu,i);
    }while(fabs(integral_new-integral)>=eps);

    /*Print the answer */
    return integral_new;
}
int main(){
    printf ("Masukan Input Jarak 0 - 300 :");
    scanf ("%f", &inputf);

    printf ("Keanggotaan Jarak Deket : %f\n", FiN());
    printf ("Keanggotaan Jarak Lumayan : %f\n", FiZ());
    printf ("Keanggotaan Jarak Jauh : %f\n", FiP());

    implikasi();

    printf("a1 : %f\n", a1);
    printf("b1a : %f\n", b1a);
    printf("b1b : %f\n", b1b);
    printf("c1 : %f\n", c1);
}
