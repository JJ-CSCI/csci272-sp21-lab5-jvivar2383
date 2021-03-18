//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Write the assignment code here
class Real{
  protected:
  float real_num;
  public:
  Real(float realnum = 1){
    real_num = realnum;
  }
  double GetReal(){
    return real_num;
  }
  
  Real& operator+(float num){
    real_num += num;
    return *this;
  }
  //void operator +(float num){
    //real_num += num;
    //return real_num;
  //}
};
class Complex : public Real{
  protected:
  float imag_num;
  //double real_num;

  public:
  Complex(float real = 1, float imagnum = 1){
    real_num = real;
    imag_num = imagnum;
  }
  double GetImaginary(){
    return imag_num;
  }

  Complex& operator+(float num){
    real_num += num;
    imag_num += num;
    return *this;
  }
  
  //friend void operator+( Real b, float num){
    //b.real_num += num;

    //return b.real_num;
  //}
  //void operator+(Complex b){
    //imag_num += .num;
    //real_num += num;
    //return imag_num;
    //return real_num;
  //}
};
class Surreal : public Complex {

  protected:
  float surr_num;

  public:

  Surreal(float real, float imag, float surr){
    real_num = real;
    imag_num = imag;
    surr_num = surr;
  }
  float GetSurreal(){
    return surr_num;
  }

  Surreal& operator+(float num){
    real_num += num;
    imag_num += num;
    surr_num += num;

    return *this;
  }
  /*void operator+(float num){
    real_num += num;
    imag_num += num;
    surr_num += num;
  }*/
  

};

//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------
TEST_CASE( "Assignment" ) {
    SECTION( "c1" ) {
        Real n{10.0};
        REQUIRE( n.GetReal() == 10.0 );
    }
    SECTION( "c2" ) {
        Complex n{10.0, 20.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
    }
    SECTION( "c3" ) {
        Surreal n{10.0, 20.0, 30.0};
        REQUIRE( n.GetReal() == 10.0 );
        REQUIRE( n.GetImaginary() == 20.0 );
        REQUIRE( n.GetSurreal() == 30.0 );
    }
    SECTION( "a1" ) {
        Real n{10.0};
        Real r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
    }
    SECTION( "a2" ) {
        Complex n{10.0, 20.0};
        Complex r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
    }
    SECTION( "a3" ) {
        Surreal n{10.0, 20.0, 30.0};
        Surreal r = n + 2.0;
        REQUIRE( r.GetReal() == 12.0 );
        REQUIRE( r.GetImaginary() == 22.0 );
        REQUIRE( r.GetSurreal() == 32.0 );
    }
}
//------------------------------
