#include "phone_number.h"
#include <sstream>
#include <exception>


  PhoneNumber::PhoneNumber(const string &international_number){
  	if(international_number[0]!='+'){
      throw invalid_argument(international_number + " - некорректный номер - не начинается на '+'");
    }
    stringstream ss(international_number);
    ss.ignore(1);
    string country, city, local;
    getline(ss, country, '-');
    getline(ss, city, '-');
    getline(ss, local);
    if(country=="" || city=="" || local==""){
      throw invalid_argument(international_number + " - некорректный номер - есть только код страны и города");
    }
    PhoneNumber::country_code_ = country;
    PhoneNumber::city_code_ = city;
    PhoneNumber::local_number_ = local;
  }

  string PhoneNumber::GetCountryCode() const{
  	return country_code_;
  }

  string PhoneNumber::GetCityCode() const{
  	return city_code_;
  }

  string PhoneNumber::GetLocalNumber() const{
  	return local_number_;
  }

  string PhoneNumber::GetInternationalNumber() const{
  	return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
  }