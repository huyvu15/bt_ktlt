#include <iostream>

using namespace std;

struct Node {
    float data;
    Node* next;

    Node(float value) {
        data = value;
        next = nullptr;
    }
};

// Thêm m?t ph?n t? vào danh sách theo th? t? tang d?n
void insertSorted(Node*& head, float value) {
    Node* newNode = new Node(value);

    if (head == nullptr || value < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// In ra danh sách
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Tìm ph?n t? có giá tr? l?n nh?t trong danh sách
float findMax(Node* head) {
    if (head == nullptr) {
        std::cout << "Danh sach rong" << std::endl;
        return 0;
    }

    float maxVal = head->data;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data > maxVal) {
            maxVal = current->data;
        }
        current = current->next;
    }
    return maxVal;
}

// Tìm ph?n t? có giá tr? nh? nh?t trong danh sách
float findMin(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach rong" << endl;
        return 0;
    }

    float minVal = head->data;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }
    return minVal;
}

int main() {
    // t?o và khai báo 1 bi?n ki?u node
    Node* myList = nullptr;

    // Thêm các ph?n t? vào danh sách theo th? t? tang d?n
    insertSorted(myList, 5.3);
    insertSorted(myList, 2.1);
    insertSorted(myList, 7.8);
    insertSorted(myList, 1.6);
    
    

    // In danh sách
    printList(myList);

    // Tìm giá tr? l?n nh?t và nh? nh?t
    float maxValue = findMax(myList);
    float minValue = findMin(myList);

    cout << "Gia tri lon nhat: " << maxValue << endl;
    cout << "Gia tri nho nhat: " << minValue << endl;

	
	
    return 0;
}

