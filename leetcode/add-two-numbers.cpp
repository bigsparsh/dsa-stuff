#include <iostream>

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* reverseList (ListNode* head) {
   ListNode *h = head, *tail = nullptr;
   while (h->next != nullptr) h = h->next;
   tail = h;
   h = head;
   while (h != tail) {
     head = head->next;
     h->next = tail->next;
     tail->next = h;
     h = head;
   }
   return head;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode *l3_head = nullptr, *l3_tail = nullptr;
  bool carry = false;


  while (l1 != nullptr && l2 != nullptr) {

      if (l3_head == nullptr) {
          l3_head = l3_tail = new ListNode();
      } else {
          l3_tail->next = new ListNode();
          l3_tail = l3_tail->next;
      }

      l3_tail->val = l1->val + l2->val;
      if (carry) {
          l3_tail->val++;
          carry = false;
      }

      if (l3_tail->val >= 10) {
          carry = true;
          l3_tail->val %= 10;
      }

      l1 = l1->next;
      l2 = l2->next;
  }

  while (l2 != nullptr) {
      l3_tail->next = new ListNode(carry ? l2->val + 1 : l2->val);
      l3_tail = l3_tail->next;
      carry = false;
      if (l3_tail->val >= 10) {
          carry = true;
          l3_tail->val %= 10;
      }
      l2 = l2->next;
  }

  while (l1 != nullptr) {
      l3_tail->next = new ListNode(carry ? l1->val + 1 : l1->val);
      l3_tail = l3_tail->next;
      carry = false;
      if (l3_tail->val >= 10) {
          carry = true;
          l3_tail->val %= 10;
      }
      l1 = l1->next;
  }

  if (carry) {
      l3_tail->next = new ListNode(1);
      l3_tail = l3_tail->next;
      carry = false;
  }

  return l3_head;
};

ListNode* insert (ListNode* tail) {
  int data;
  std::cout << "\nEnter data to insert: ";
  std::cin >> data;
  ListNode *new_node = new ListNode(data);
  if (tail != nullptr) tail->next = new_node;
  tail = new_node; 
  return tail;
}

void display (ListNode* head) {
  std::cout << "\nHere are the elements: \n";
  while (head != nullptr) {
    std::cout << " [ " << head->val << " ] ";
    head = head->next;
  }
  std::cout << std::endl;
}


int main () {
  int size1, size2, choice;
  std::cout << "\nEnter the size of the first list?: ";
  std::cin >> size1;

  std::cout << "\nEnter the size of the second list?: ";
  std::cin >> size2;


  ListNode *head1, *tail1, *head2, *tail2;
  head1 = head2 = tail1 = tail2 = nullptr;
  int temp;


  std::cout << "\nEnter the elements for the first linked list: \n";
  for (int i = 0; i < size1; i++ ) {
    tail1 = insert (tail1);
    if (head1 == nullptr) head1 = tail1;
  }

  std::cout << "\nEnter the elements for the second linked list: \n";
  for (int i = 0; i < size2; i++ ) {
    tail2 = insert (tail2);
    if (head2 == nullptr) head2 = tail2;
  }

  display(head1);
  display(head2);
  display (addTwoNumbers(head1, head2));

  // do {
  //   std::cout << "\nEnter your choice (1-Insert, 2-Display, 3-Exit): ";
  //   std::cin >> choice;
  //
  //   switch (choice) {
  //     case 1:
  //       std::cout << "\nIn which list you want to insert (1/2): ";
  //       std::cin >> temp;
  //       if (temp == 1) {
  //         tail1 = insert (tail1);
  //         if (head1 == nullptr) head1 = tail1;
  //       } else if (temp == 2) {
  //         tail2 = insert (tail2);
  //         if (head2 == nullptr) head2 = tail2;
  //       }
  //       break;
  //     case 2:
  //       display (head1);
  //       display (head2);
  //       break;
  //     case 3:
  //       break;
  //     default: 
  //       std::cout << "\nInvalid input\n";
  //   }
  //
  // } while (choice != 4);
}
