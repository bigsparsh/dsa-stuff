#include <iostream>

class Invoice {
  private: 
    std::string partNum, partDesc;
    int itemQuantity;
    double pricePerItem;
  public:
    Invoice() {
      partNum = "";
      partDesc = "";
      itemQuantity = 0;
      pricePerItem = 0.0;
    };
    std::string getPartNumber () {
      return partNum;
    }
    std::string getPartDescription () {
      return partDesc;
    }
    int getItemQuantity () {
      return itemQuantity;
    }
    double getPricePerItem () {
      return pricePerItem;
    }
    void setPartNumber (std::string n) {
      partNum = n;
    }
    void setPartDescription (std::string pd) {
      partDesc = pd;
    }
    void setItemQuantity (int iq) {
      itemQuantity = iq;
    }
    void setPricePerItem (double ppi) {
      pricePerItem = ppi;
    }
    double getInvoiceAmount () {
      if (itemQuantity < 0) itemQuantity = 0;
      if (pricePerItem < 0.0) itemQuantity = 0.0;
      return itemQuantity * pricePerItem;
    }
};

int main () {
  Invoice invoice;
  std::string pn, pd;
  int qoi, choice;
  double ppi;

  do {
    std::cout << "\nWelcome to invoiceTest program\n 1. Set Part Number\n 2. Set Part Description\n 3. Set Item Quantity\n 4. Set Price Per Item\n 5. Get Part Number\n 6. Get Part Description\n 7. Get Item Quantity\n 8. Get Price Per Item\n 9. Get Invoice Amount\n 10. Exit\n";
    std::cout << "Enter Choice: ";
    std::cin >> choice;

    switch (choice) {
      case 1:
        std::cout << "Enter Part Number: ";
        std::cin >> pn;
        invoice.setPartNumber(pn);
        break;
      case 2:
        std::cout << "Enter Part Description: ";
        std::cin >> pd;
        invoice.setPartDescription(pd);
        break;
      case 3:
        std::cout << "Enter Item Quantity: ";
        std::cin >> qoi;
        invoice.setItemQuantity(qoi);
        break;
      case 4:
        std::cout << "Enter Price Per Item: ";
        std::cin >> ppi;
        invoice.setPricePerItem(ppi);
        break;
      case 5:
        std::cout << "Part Number: " << invoice.getPartNumber() << std::endl;
        break;
      case 6:
        std::cout << "Part Description: " << invoice.getPartDescription() << std::endl;
        break;
      case 7:
        std::cout << "Item Quantity: " << invoice.getItemQuantity() << std::endl;
        break;
      case 8:
        std::cout << "Price Per Item: " << invoice.getPricePerItem() << std::endl;
        break;
      case 9:
        std::cout << "Invoice Amount: " << invoice.getInvoiceAmount() << std::endl;
        break;
      case 10:
        std::cout << "Exiting...";
        break;
      default:
        std::cout << "Invalid Choice\n";
    }

  } while (choice < 10);

}
