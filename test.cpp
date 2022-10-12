#include <iostream>
using namespace std;

// đề bài :nhập danh sách liên kết đơn các số nguyên. tìm giá trị lớn nhất trong dah sách
// khai báo danh sách liên kết đơn

// ======= khai baó 1 node
//-- gán cấu node bằng 1 tên cho tiẹn dùng
//======= kha báo cấu trúc cỉa danh sách liên kết đơn
// gán tên danh sách đơn đấy bằng 1 cái tên cu thể cho dễ dùng
//===== khởi tạo 1 danh sách liên kết đơn
//===viết hàm khởi tạo một cái node à truyền dữ liêu đơn vào cho đât
//=== hàm thêm node vào đầu danh sách liên kết
//=== hàm thêm node p vaò cuối danh sách
// hàm xuất danh

// khái báo 1 node
struct node
{
    int data;
    node *pNext;
};
typedef struct node NODE;
// khai báo cấu truc của 1 list
struct list
{
    NODE *pHead;
    NODE *pTail;
};
typedef struct list LIST;
// khởi tạo liên kết đơn
void khoiTao(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
// viết hàm tạo 1 node vì 1 liên cái liên kết đơn dc tạo nên từ nhiều nút khác nhau
NODE *KhoiTaoNODE(int x)
{
    NODE *p = new NODE;
    if (p == NULL)
    {
        cout << "Khong du bo nho !!!";
    }
    p->data = x;
    p->pNext = NULL;
    return p;
}
void themVaodau(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void themVaoCuoi(LIST &l, NODE *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = l.pTail;
    }
    else
    {
        l.pTail = p->pNext;
        l.pTail = p;
    }
}

void nhapDS(LIST &L, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Nhap vao so x: ";
        cin >> x;
        node *p = new node;
        p = KhoiTaoNODE(x);
        themVaoCuoi(L, p);
    }
}

void xuatDanhSach(LIST L)
{
    NODE *p = new NODE;
    for (p = L.pHead; p != NULL; p = p->pNext)
    {
        cout << p->data;
    }
}

int main()
{
    LIST L;
    khoiTao(L);
    int n;
    cout << "Nhap so node: ";
    cin >> n;
    khoiTao(L);
    nhapDS(L, n);
    cout << "Danh sach lien ket don: " << endl;
    xuatDanhSach(L);
    return 0;
}