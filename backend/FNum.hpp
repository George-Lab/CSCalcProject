#ifndef FNUM
#define FNUM

#include <string>

class FNum {
 public:
  FNum() : int_part("0"), pow("00"), num(0){};

  FNum(double fl);

  FNum(const FNum& other) = default;

  FNum& operator=(const FNum& other);

  void ComputeDouble();

  void ComputeStrings();

  std::string GetString();

  double& GetDouble();

  double GetDouble() const;

  void AddToInt(char dig);

  void AddToFract(char dig);

  void AddToPow(char dig);

  void ChangeIntSign();

  void ChangePowSign();

  friend void swap(FNum& lhs, FNum& rhs);

 private:
  std::string int_part;
  std::string fract_part;
  std::string pow;
  double num;
};

bool operator>=(const FNum& lhs, const FNum& rhs);

bool operator<(const FNum& lhs, const FNum& rhs);

bool operator==(const FNum& lhs, const FNum& rhs);

bool operator!=(const FNum& lhs, const FNum& rhs);

FNum operator+(const FNum& lhs, const FNum& rhs);

FNum operator-(const FNum& lhs, const FNum& rhs);

FNum operator*(const FNum& lhs, const FNum& rhs);

FNum operator/(const FNum& lhs, const FNum& rhs);

FNum RaiseToPow(const FNum& lhs, const FNum& rhs);

FNum ComputeLog(const FNum& fl);

FNum ComputeSin(const FNum& fl);

FNum ComputeCos(const FNum& fl);

FNum MultReverse(const FNum& fl);

FNum ComputeSquare(const FNum& fl);

FNum ComputeSqrt(const FNum& fl);

FNum ComputeExp(const FNum& fl);

FNum GetPi();

#endif
