#include <bits/stdc++.h>

using namespace std;

struct KhachHang
{
    string maKH;
    string tenKH;
};

struct Phong
{
    int maP;
    string tenP;
    string tinhTrang;
    long tongTien;
    KhachHang ds[100];
    int n;
};

struct NodePhongKS
{
    Phong info;
    NodePhongKS *next;
    NodePhongKS *previous;
};

struct NodeKH
{
    KhachHang infor;
    NodeKH *next;
    NodeKH *previous;
};

struct ListKH
{
    NodeKH *head;
    NodeKH *tail;
};

ListKH Qkh;

struct ListPhongKS
{
    NodePhongKS *head;
    NodePhongKS *tail;
};

ListPhongKS Qphong;

void NhapKH(KhachHang &kh)
{
    cout << "\nNhap ma khach hang: ";
    cin.ignore();
    getline(cin, kh.maKH);
    cout << "\nNhap ten khach hang: ";
    getline(cin, kh.tenKH);
    cout << "\n_________________________________\n";
}

void InKH(KhachHang kh)
{
    cout << setw(8) << kh.maKH << setw(12) << kh.tenKH << endl;
}

void NhapPhong(Phong &phong)
{
    cout << "\nNhap ma phong: ";
    cin >> phong.maP;
    cout << "\nNhap ten phong: ";
    cin >> phong.tenP;
    cout << "\nNhap tinh trang: ";
    cin >> phong.tinhTrang;
    cout << "\nNhap tong tien: ";
    cin >> phong.tongTien;

    cout << "\nNhap so luong khach hang trong 1 phong: ";
    cin >> phong.n;

    for (int i = 0; i < phong.n; i++)
    {
        cout << "\nKhach hang thu " << i + 1 << endl;
        NhapKH(phong.ds[i]);
    }

    cout << "\n__________________________________________\n";
}

void InPhongKS(Phong phong)
{
    cout << "\nDanh sach phong khach san\n";
    cout << setw(8) << phong.maP << setw(10) << phong.tenP << setw(12) << phong.tinhTrang << setw(14) << phong.tongTien << endl;

    cout << "\nDanh sach khach hang\n";
    cout << setw(10) << "Ma khach hang" << setw(16) << "Ten khach hang" << endl;

    for (int i = 0; i < phong.n; i++)
    {
        InKH(phong.ds[i]);
    }

    cout << "\n__________________________________\n";
}

void Init(ListPhongKS &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}

NodePhongKS *GetNodePhongKS(Phong phong)
{
    NodePhongKS *p;
    p = new NodePhongKS();
    if (p == NULL)
    {
        cout << "\nKhong du bo nho\n";
        exit(1);
    }

    p->info = phong;
    p->next = NULL;
    p->previous = NULL;

    return p;
}

void InsertHead(ListPhongKS &Q, NodePhongKS *p)
{
    if (Q.head == NULL)
    {
        Q.head = p;
        Q.tail = p;
    }
    else
    {
        p->next = Q.head;
        Q.head->previous = p;
        Q.head = p;
    }
}

void InsertTail(ListPhongKS &Q, Phong phong)
{
    NodePhongKS *p = GetNodePhongKS(phong);
    if (p == NULL)
    {
        cout << "\nKhong tao duoc node\n";
        exit(1);
    }
    if (Q.head == NULL)
    {
        Q.head = p;
        Q.tail = Q.head;
        return;
    }
    p->previous = Q.tail;
    Q.tail->next = p;
    Q.tail = p;
}

void CreatListPhongKS(ListPhongKS Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}

void NhapDSPhong(ListPhongKS &Q)
{
    int n;
    Init(Q);

    cout << "\nNhap so luong phong khach san: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phong thu " << i + 1 << endl;
        Phong phong;
        NhapPhong(phong);
        NodePhongKS *p = GetNodePhongKS(phong);
        InsertHead(Q, p);
    }
}

void InDSPhongKS(ListPhongKS Q)
{
    cout << "\nDanh sach phong khach san\n";
    for (NodePhongKS *p = Q.head; p != NULL; p = p->next)
    {
        InPhongKS(p->info);
    }
}

void In2000(ListPhongKS Q)
{
    for (NodePhongKS *p = Q.head; p != NULL; p = p->next)
    {
        if (p->info.tongTien > 2000)
        {
            InPhongKS(p->info);
        }
    }
}

void AddFirst(ListPhongKS Q)
{
    cout << "\nThem phong khach san vao dau danh sach\n";
    Phong phong;
    NhapPhong(phong);
    NodePhongKS *p = GetNodePhongKS(phong);
    InsertHead(Q, p);
    InDSPhongKS(Q);
}

void AddTail(ListPhongKS Q)
{
    cout << "\nThem phong khach san vao cuoi danh sach\n";
    Phong phong;
    NhapPhong(phong);
    NodePhongKS *p = GetNodePhongKS(phong);
    InsertTail(Q, phong);
    InDSPhongKS(Q);
}

void RemoveElement(ListPhongKS &Q)
{
    int id;
    cout << "\nNhap ma phong khach san can xoa: ";
    cin >> id;
    NodePhongKS *p = Q.head;
    while (p != NULL)
    {
        if (p->info.maP == id)
            break;
        p = p->next;
    }

    if (p == NULL)
    {
        cout << "\nDanh sach trong, ma phong khong ton tai!!!!\n";
        exit(1);
    }
    else
    {
        if (p == Q.head && p == Q.tail)
        {
            Q.head == NULL;
            Q.tail == NULL;
        }
        else if (p == Q.head)
            Q.head = p->next;
        else if (p == Q.tail)
        {
            p->previous->next = NULL;
            Q.tail = p->previous;
        }
        else
        {
            p->previous->next = p->next;
            p->next->previous = p->previous;
        }
        free(p);
    }
    cout << "\nDanh sach sau khi xoa ma phong " << id << endl;
    InDSPhongKS(Q);
}

void sxTang(ListPhongKS Q)
{
    for (NodePhongKS *p = Q.head; p != NULL; p = p->next)
    {
        for (NodePhongKS *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.maP > q->info.maP)
            {
                Phong tg = p->info;
                p->info = q->info;
                q->info = tg;
            }
        }
    }
    cout << "\nDanh sach sau khi sap xep\n";
    InDSPhongKS(Q);
}

void TKTheoIDPhong(ListPhongKS Q)
{

    NodePhongKS *p;
    int id;
    cout << "\nNhap ma khach hang can tim kiem thong tin: ";
    cin >> id;

    if (p == NULL)
    {
        cout << "\nDanh sach trong, ma phong khong ton tai!!!\n";
        exit(1);
    }

    for (NodePhongKS *p = Q.head; p != NULL; p = p->next)
    {
        if (id == p->info.maP)
        {
            InPhongKS(p->info);
        }
    }
}

void DemPhong23(ListPhongKS Q)
{
    int dem = 0;
    for (NodePhongKS *p = Q.head; p != NULL; p = p->next)
        if (p->info.tongTien >= 2000 && p->info.tongTien <= 3000)
            dem++;
    if (dem == 0)
        cout << "\nKhong co phong nao co tong tien tu 2000->3000\n";
    else
        cout << "\nCo " << dem << " phong co tong tien tu 2000->3000\n";
}

void TongTienPhong(ListPhongKS Q)
{
    long sum = 0;
    for (NodePhongKS *p = Q.head; p != NULL; p = p->next)
    {
        sum += p->info.tongTien;
    }
    cout << "\nTong tien cac phong khach san la: " << sum << endl;
}

void TienMax(ListPhongKS Q)
{
    long max;
    NodePhongKS *p = Q.head;
    max = p->info.tongTien;
    while (p != NULL)
    {
        if (max < p->info.tongTien)
            max = p->info.tongTien;
        p = p->next;
    }
    cout << "\nDanh sach phong co tong tien cao nhat\n";
    for (NodePhongKS *p = Q.head; p != NULL; p = p->next)
    {
        if (p->info.tongTien == max)
        {
            InPhongKS(p->info);
        }
    }
}

void TienMin(ListPhongKS Q)
{
    long min;
    NodePhongKS *p = Q.head;
    min = p->info.tongTien;
    while (p != NULL)
    {
        if (min > p->info.tongTien)
            min = p->info.tongTien;
        p = p->next;
    }
    cout << "\nDanh sach phong co tong tien thap nhat\n";
    for (NodePhongKS *p = Q.head; p != NULL; p = p->next)
    {
        if (p->info.tongTien == min)
        {
            InPhongKS(p->info);
        }
    }
}

void GhiFile(ListPhongKS &Q)
{
    FILE *f;
    NodePhongKS *p = Q.head;
    f = fopen("KhachSan.dat", "wb");
    while (p != NULL)
    {
        fwrite(&p->info, sizeof(Phong), 1, f);
        p = p->next;
    }

    fclose(f);

    cout << "\nGhi file thanh cong\n";
}

void DocFile(ListPhongKS &Q)
{
    FILE *f;
    Phong phong;
    NodePhongKS *p = Q.head;
    Init(Q);
    f = fopen("KhachSan.dat", "rb");

    while (true)
    {
        fread(&phong, sizeof(Phong), 1, f);
        if (feof(f))
            break;
        InsertHead(Q, GetNodePhongKS(phong));
    }

    fclose(f);

}

int main()
{
    int chon;
    do
    {
        cout << "\nQuan li khach san";
        cout << "\n1. Nhap danh sach phong khach san";
        cout << "\n2. In danh sach phong khach san";
        cout << "\n3. In danh sach phong co tong tien lon hon 2000";
        cout << "\n4. Them phong khach san vao dau danh sach";
        cout << "\n5. Them phong khach san vao cuoi danh sach";
        cout << "\n6. Xoa phong khach san theo ma phong";
        cout << "\n7. Sap xep danh sach phong khach san theo tong tien";
        cout << "\n8. Tim kiem thong tin phong theo ma phong";
        cout << "\n9. Dem so phong khach san co tong tien tu 2000->3000";
        cout << "\n10. Phong khach san co tong tien lon nhat";
        cout << "\n11. Phong khach san co tong tien nho nhat";
        cout << "\n12. Ghi File";
        cout << "\n13. Doc File";
        cout << "\n0. Thoat";
        cout << "\nMoi chon chuc nang de thuc hien chuong trinh: ";
        cin >> chon;

        switch (chon)
        {
        case 1:
            NhapDSPhong(Qphong);
            GhiFile(Qphong);
            break;
        case 2:
            DocFile(Qphong);
            InDSPhongKS(Qphong);
            break;
        case 3:
            In2000(Qphong);
            break;
        case 4:
            AddFirst(Qphong);
            break;
        case 5:
            AddTail(Qphong);
            break;
        case 6:
            RemoveElement(Qphong);
            break;
        case 7:
            sxTang(Qphong);
            break;
        case 8:
            TKTheoIDPhong(Qphong);
            break;
        case 9:
            DemPhong23(Qphong);
            break;
        case 10:
            TienMax(Qphong);
            break;
        case 11:
            TienMin(Qphong);
            break;
        case 12:
            GhiFile(Qphong);
            break;
        case 13:
            DocFile(Qphong);
            break;
        case 0:
            break;

        default:
            break;
        }

        cout << "\nTiep tuc - 0. Thoat: ";
        cin >> chon;
    } while (chon != 0);
    return 0;
}
