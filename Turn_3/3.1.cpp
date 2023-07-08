// bai 3.1: tao lap va thao tac tren danh sach lien ket
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Khai báo kiểu dữ liệu cho bản ghi Nhân viên
struct Employee
{
    int id; // Mã nhân viên
    string name; // Họ tên
    double salary; // Lương
    Employee* next; // Con trỏ trỏ tới nhân viên kế tiếp trong danh sách
};

// Hàm tạo mới một bản ghi Nhân viên
Employee* createEmployee(int id, string name, double salary)
{
    Employee* emp = new Employee;
    emp->id = id;
    emp->name = name;
    emp->salary = salary;
    emp->next = NULL;
    return emp;
}

// Hàm thêm một bản ghi Nhân viên vào đầu danh sách
Employee* addEmployee(Employee* head, int id, string name, double salary)
{
    Employee* emp = createEmployee(id, name, salary);
    emp->next = head;
    head = emp;
    return head;
}

// Hàm in danh sách Nhân viên
void printList(Employee* head)
{
    int count = 1;
    cout << left << setw(4) << "STT" << " " << left << setw(6) << "Ma NV" << " " << left << setw(20) << "Ho ten" << " " << left << setw(10) << "Luong" << endl;
    cout << setfill('-') << setw(4) << "" << " " << setw(6) << "" << " " << setw(20) << "" << " " << setw(10) << "" << setfill(' ') << endl;
    while (head != NULL)
    {
        cout << left << setw(4) << count << " " << left << setw(6) << head->id << " " << left << setw(20) << head->name << " " << left << setw(10) << head->salary << endl;
        head = head->next;
        count++;
    }
}

// Hàm xóa một bản ghi Nhân viên khỏi danh sách
Employee* deleteEmployee(Employee* head, int id)
{
    Employee* curr = head;
    Employee* prev = NULL;
    while (curr != NULL)
    {
        if (curr->id == id)
        {
            if (prev == NULL)
            {
                head = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Xoa nhan vien co ma so " << id << " thanh cong.\n";
            return head;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Khong tim thay nhan vien co ma so " << id << ".\n";
    return head;
}

// Hàm sửa thông tin về lương của một bản ghi Nhân viên
void editSalary(Employee* head, int id)
{
    Employee* curr = head;
    while (curr != NULL)
    {
        if (curr->id == id)
        {
            double newSalary;
            cout << "Nhap luong moi cho nhan vien co ma so " << id << ": ";
            cin >> newSalary;
            curr->salary = newSalary;
            cout << "Cap nhat thong tin luong cho nhan vien co ma so " << id << " thanh cong.\n";
            return;
        }
        curr = curr->next;
    }
    cout << "Khong tim thay nhan vien co ma so " << id << ".\n";
}

// Hàm tính trung bình lương của các Nhân viên trong danh sách
double averageSalary(Employee* head)
{
    int count = 0;
    double sum = 0;
    while (head != NULL)
    {
        sum += head->salary;
        count++;
        head = head->next;
    }
    if (count > 0)
    {
        return sum / count;
    }
    else
    {
        return 0;
    }
}

// Hàm tìm nhân viên có lương cao nhất
void findMaxSalary(Employee* head)
{
    double maxSalary = 0;
    string maxName;
    int maxId;
    while (head != NULL)
    {
        if (head->salary > maxSalary)
        {
            maxSalary = head->salary;
            maxName = head->name;
            maxId = head->id;
        }
        head = head->next;
    }
    if (maxSalary > 0)
    {
        cout << "Nhan vien co luong cao nhat la:\n";
        cout << "Ma NV: " << maxId << endl;
        cout << "Ho ten: " << maxName << endl;
        cout << "Luong: " << maxSalary << endl;
    }
    else
    {
        cout << "Danh sach nhan vien rong.\n";
    }
}

int main()
{
    Employee* head = NULL;
    int choice;
    do
    {
        cout << "Menu:\n";
        cout << "1. Them nhan vien.\n";
        cout << "2. In danh sach nhan vien.\n";
        cout << "3. Xoa nhan vien.\n";
        cout << "4. Sua thong tin luong nhan vien.\n";
        cout << "5. Tinh trung binh luong cac nhan vien.\n";
        cout << "6. Tim nhan vien co luong cao nhat.\n";
        cout << "0. Thoat chuong trinh.\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int id;
            string name;
            double salary;
            cout << "Nhap ma so nhan vien: ";
            cin >> id;
            cin.ignore(); // Loai bo ky tu xuong dong con lai trong bo dem
            cout << "Nhap ho ten nhan vien: ";
            getline(cin, name);
            cout << "Nhap luong nhan vien: ";
            cin >> salary;
            head = addEmployee(head, id, name, salary);
            cout << "Them nhan vien thanh cong.\n";
            break;
        }
        case 2:
        {
            if (head == NULL)
            {
                cout << "Danh sach nhan vien rong.\n";
            }
            else
            {
                printList(head);
            }
            break;
        }
        case 3:
        {
            if (head == NULL)
            {
                cout << "Danh sach nhan vien rong.\n";
            }
            else
            {
                int id;
                cout << "Nhap ma so nhan vien can xoa: ";
                cin >> id;
                head = deleteEmployee(head, id);
            }
            break;
        }
        case 4:
        {
            if (head == NULL)
            {
                cout << "Danh sach nhan vien rong.\n";
            }
            else
            {
                int id;
                cout << "Nhap ma so nhan vien can sua luong: ";
                cin >> id;
                editSalary(head, id);
            }
            break;
        }
        case 5:
        {
            if (head == NULL)
            {
                cout << "Danh sach nhan vien rong.\n";
            }
            else
            {
                double avgSalary = averageSalary(head);
                cout << "Trung binh luong cac nhan vien la: " << avgSalary << endl;
            }
            break;
        }
        case 6:
        {
            if (head == NULL)
            {
                cout << "Danh sach nhan vien rong.\n";
            }
            else
            {
                findMaxSalary(head);
            }
            break;
        }
        case 0:
        {
            cout << "Cam on ban da su dung chuong trinh.\n";
            break;
        }
        default:
        {
            cout << "Lua chon khong hop le. Vui long chon lai.\n";
            break;
        }
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}
