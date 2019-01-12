#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months; // number of months applicable
  double contribution; // per month in $
  double rate_of_return; // per month
};

typedef struct _retire_info retire_info;

void print_current_balance(int ageInMonths, double balance)
{
  printf("Age %3d month %2d you have $%.2lf\n", ageInMonths/12, ageInMonths%12, balance);
}

double retirement_account_balance(double prevBalance, retire_info info)
{
  double interest = prevBalance * info.rate_of_return;
  double newBalance = prevBalance + interest + info.contribution;
  return newBalance;
}

double compute_and_print(int startAge, double initialBalance, retire_info info)
{
  double balance = initialBalance;
  for (int age=startAge; age < (startAge + info.months); age++)
    {
      print_current_balance(age, balance);
      balance = retirement_account_balance(balance, info);
    }
  return balance; // final balance
}

double compute_and_print_in_working(int startAge, double initialBalance, retire_info workingInfo)
 {
   return compute_and_print(startAge, initialBalance, workingInfo);
 }

double compute_and_print_in_retirement(int startAge, double initialBalance, retire_info retiredInfo)
 {
   return compute_and_print(startAge, initialBalance, retiredInfo);
 }

void retirement (int startAge,   //in months
                 double initial, //initial savings in dollars
                 retire_info working, //info about working
                 retire_info retired) //info about being retired
{
  // 1. compute retirement account balance each month while working
  //    At start of each month before balance chnages printout current balance
  double balance = compute_and_print_in_working(startAge, initial, working);
  
  // 2. do same after retirement
  compute_and_print_in_retirement(startAge+working.months, balance, retired);
}

  int main()
  {
    retire_info working;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = .045/12;

    retire_info retired;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = .01/12;

    int startAge = 327;
    double initial = 21345;
    retirement(startAge, initial, working, retired);
  }
 
