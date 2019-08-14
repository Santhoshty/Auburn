//Santhosh Thundena
//sst0011
//hw2_sst0011.cpp
//The program calculates interest and breaks down payment per mont.
//I observed the notes and slides given on canvas. 
//I looked over http://www.cplusplus.com/reference/ios/fixed/ for clarification on fixed points.
//I looked over http://www.cplusplus.com/reference/iomanip/setprecision/ for set precision reference. 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main()
{
   
   int numPayments = 0;
   double loanAmount, interestRateYearly, monthlyPayments, interestMonth, debtReduction, totalInterest;
   
  //Showpoint for dollar formatting
  std::cout.precision(2);
  
  //user inputs data
   
   cout << "Loan Amount: ";
   cin >> loanAmount;
   cout << "Interest Rate (% per year): ";
   cin >> interestRateYearly;
   cout << "Monthly Payments: ";   
   cin >> monthlyPayments;
   
   //divide by 100 to convert percentage into decimal
   double interestRateMonthly = interestRateYearly/12;
  
  //header
   cout << "******************************************************\n";
   cout << "\tAmortization Table\n";
   cout << "******************************************************\n";
   cout << "Month\tBalance\tPayment\tRate\tInterest\tPrincipal\n";
   
   //first payment
   cout << numPayments << "\t$" << std::fixed;
   cout << loanAmount << "\t\t";
   cout << "N/A\t\t"; 
   cout << "N/A\t\t"; 
   cout << "N/A\t\t";
   cout << "N/A\t\t\n";
        
        
  //second to second to last payment  
   while (monthlyPayments < loanAmount) {
 
      //CALCULATIONS
      //divided by 100 to convert from percentage to decimal
      interestMonth = loanAmount * interestRateMonthly/100;
      //amount debt is reduced after taking into account payment of interest
      debtReduction = monthlyPayments - interestMonth;
      //balance after payment  
      loanAmount = loanAmount - debtReduction;
      //increment the month for next time
      numPayments++;
      // add the interest this month to the total interest
      totalInterest += interestMonth;
           
          //if impossible to pay off  
          if (monthlyPayments < interestMonth) {
            cout << "******************************************************\n";
            cout << "Payment is impossible";
            //exit program
            return 0;  
            }
                 
      //OUTPUTS
      //month
      cout << numPayments << "\t";
      //balance
      cout << "$" << loanAmount << "\t" << std::fixed;
      //payment
      cout << "$" << monthlyPayments << "\t" << std::fixed << std::setprecision(1);
      //rate
      cout << interestRateMonthly << "\t" << std::fixed  << std::setprecision(2);
      //interest
      cout << "$" << interestMonth << "\t" << std::fixed;
      //principal
      cout << "$" << debtReduction << "\t\n" << std::fixed;
        
      }
      
   //LAST PAYMENT (special case as last payment is smaller than regular payments)
   
   //CALCULATIONS
   numPayments++;
   totalInterest += loanAmount*interestRateMonthly/100;
   
   //OUTPUTS
   //month
   cout << numPayments;
   //balance
   cout << "\t$" << 0.00 <<"\t\t$";
   //payment
   cout << loanAmount + loanAmount*interestRateMonthly/100 << std::fixed << std::setprecision(1);
   //rate
   cout << "\t" << interestRateMonthly << "\t$" << std::fixed << std::setprecision(2);
   //interest
   cout << loanAmount*interestRateMonthly/100;
   //principal
   cout << "\t$" << loanAmount << std::fixed;
      
   
   cout << "\n******************************************************\n\n";
   cout << "It takes " << numPayments << " months to pay off the loan.\n";
   cout << "total interest paid is: " << totalInterest;
}
