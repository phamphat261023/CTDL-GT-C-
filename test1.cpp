#include <stdio.h>
#include <stdlib.h>
struct Node
{
    // khai bao thanh phan du lieu co kieu int
    int data;
    // khai bao con tro next co kieu Node
    Node *next;
};
typedef struct Node NODE;
struct list
{
    // thanh phan dau danh sach
    NODE *pHead;
    // thanh phan cuoi danh sach
    NODE *pTail;
};
typedef struct list LIST;
void KhoiTao(LIST &ds)
{
    // dat dia chi dau danh sach bang NULL
    ds.pHead = NULL;
    // dat dia chi cuoi danh sach bang NULL
    ds.pTail = NULL;
}
int KiemTraRong(LIST ds)
{
    // neu phan tu dau danh sach NULL
    if (ds.pHead == NULL)
    {
        // tra ve 1 la co NULL
        return 1;
    }
    // truong hop nguoc lai tra ve khong null
    return 0;
}
NODE *TaoNode(int x)
{
    // tao mot node p moi
    NODE *p;
    p = new NODE;
    // neu p==NULL thi khong du bo nho
    if (p == NULL)
    {
        printf("KHONG DU BO NHO");
        return NULL;
    }
    // gan thanh phan data = x
    p->data = x;
    // gan con tro next = NULL
    p->next = NULL;
    // tra ve node p da tao
    return p;
}
void ChenDau(LIST &ds, NODE *p)
{
    // neu phan tu dau rong thi danh sach rong
    if (ds.pHead == NULL)
    {
        // chen dau va cuoi deu bang node p
        ds.pHead = p;
        ds.pTail = p;
    }
    // nguoc lai danh sach khong rong
    else
    {
        // gan con tro next cua node p bang phan tu dang la dau tien cua danh sach
        p->next = ds.pHead;
        // gan pHead bang node p
        ds.pHead = p;
    }
}
void ChenCuoi(LIST &ds, NODE *p)
{
    // neu phan tu dau rong thi danh sach rong
    if (ds.pHead == NULL)
    {
        // chen dau va cuoi deu bang node p
        ds.pHead = p;
        ds.pTail = p;
    }
    // nguoc lai danh sach khong rong
    else
    {
        // gan con tro cua phan tu cuoi trong danh sach bang node p
        ds.pTail->next = p;
        // gan pTail bang node p
        ds.pTail = p;
    }
}
void Nhap(LIST &ds, int n)
{
    // duyet N lan
    for (int i = 0; i < n; i++)
    {
        // nhap du lieu la so nguyen int x
        int x;
        printf("Nhap vao so x: ");
        scanf("%d", &x);
        // tao node p
        NODE *p = new NODE;
        // dua du lieu vua nhap vao node p
        p = TaoNode(x);
        // dua node p vao ham chen cuoi
        ChenCuoi(ds, p);
    }
}
void Xuat(LIST ds)
{
    // khoi tao mot node
    NODE *p = new NODE;
    // duyet tu dau danh sach den cuoi danh sach voi dieu kien p!=NULL
    for (p = ds.pHead; p != NULL; p = p->next)
    {
        // hien thi du lieu cua tung node
        printf("%d\n", p->data);
    }
}
int main()
{
    // khai bao mot danh sach
    LIST ds;
    // nhap so luong N tu ban phim
    int n;
    printf("Nhap N: ");
    scanf("%d", &n);
    // khoi tao danh sach
    KhoiTao(ds);
    // goi ham nhap va truyen danh sach va so luong N vao
    Nhap(ds, n);
    // goi ham xuat du lieu
    printf("\nDU LIEU TRONG DANH SACH LIEN KET DON\n");
    Xuat(ds);
}