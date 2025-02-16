/*
 Name: Sparsh Singh
 University Roll No.: 2024329
 Section: C
*/
// 10. Payment Processing System
// • Objective: Implement a base class PaymentMethod with a virtual function
// processPayment(). Derive classes CreditCard and PayPal to simulate different
// payment methods. • Scenario: o Your e-commerce application needs to support
// multiple payment methods such as credit card and PayPal. You need to
// implement a common interface for processing payments. o The base class
// PaymentMethod will have a virtual function processPayment(). The derived
// classes CreditCard and PayPal will implement the actual payment processing
// logic for each method. • Instructions: o Define a base class PaymentMethod
// with a virtual function processPayment() that simulates payment processing.
// o Create derived classes CreditCard and PayPal. In CreditCard, implement
// processPayment() to simulate credit card payment, and in PayPal, implement
// processPayment() to simulate PayPal payment.
// o In the main function, create objects of CreditCard and PayPal, and use
// polymorphism to process payments.

#include <iostream>
using namespace std;

class PaymentMethod {
public:
  virtual void processPayment() = 0;
};

class CreditCard : public PaymentMethod {
public:
  void processPayment() { cout << "Processing credit card payment" << endl; }
};

class PayPal : public PaymentMethod {
public:
  void processPayment() { cout << "Processing PayPal payment" << endl; }
};

int main() {
  PaymentMethod *paymentMethod;
  CreditCard creditCard;
  PayPal payPal;

  paymentMethod = &creditCard;
  paymentMethod->processPayment();

  paymentMethod = &payPal;
  paymentMethod->processPayment();

  return 0;
}
