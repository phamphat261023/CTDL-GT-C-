#include <bits/stdc++.h>

using namespace std;

//KHACH HANG
struct KhachHang
{
    string maKH, tenKH;
};

struct NodeKH
{
    KhachHang info;
    NodeKH *next;
};

struct ListKH
{
    NodeKH *head;
    NodeKH *tail;
};

void NhapKH(KhachHang &kh)
{
    cout << "\tMa khach hang: ";
    getline(cin, kh.maKH);
    cout << "\tTen khach hang: ";
    getline(cin, kh.tenKH);
}

void InKH(KhachHang kh)
{
    cout << setw(8) << kh.maKH << setw(16) << kh.tenKH << endl;
}

void InitKH(ListKH &Qkh)
{
    Qkh.head = NULL;
    Qkh.tail = NULL;
}

NodeKH *GetNodeKH(KhachHang kh)
{
    NodeKH *p = new NodeKH;
    if(p == NULL)
    {
        cout << "Khong du bo nho!";
        return NULL;
    }
    p->info = kh;
    p->next = NULL;
    return p;
}

void InsertFirstKH(ListKH &Qkh, NodeKH *p)
{
    if (Qkh.head == NULL)
    {
        Qkh.head = p;
        Qkh.tail = p;
    }
    else
    {
        p->next = Qkh.head;
        Qkh.head = p;
    }
}

void NhapDSKH(ListKH &Qkh)
{
    int n;
    InitKH(Qkh);
    cout << "\nNhap so luong khach hang: ";
    cin >> n;
    cin.ignore();
    cout << "\nNhap danh sach\n";
    for(int i=0; i<n; i++)
    {
        cout << "Khach hang " << i+1 << endl;
        KhachHang kh;
        NhapKH(kh);
        NodeKH *p = GetNodeKH(kh);
        InsertFirstKH(Qkh, p);
    }
    cout << "\n__________________________________________________________________\n";
}

void InDSKH(ListKH Qkh)
{
    cout << "\nDanh sach khach hang\n";
    cout << setw(8) << "Ma kh" << setw(16) << "Ten kh" << endl;
    for(NodeKH *p = Qkh.head; p!=NULL; p=p->next)
        InKH(p->info);
    cout << "\n__________________________________________________________________\n";
}

void AddTailKH(ListKH &Qkh)
{
    KhachHang kh;
    cout << "\nNhap thong tin cho khach hang can them\n";
    cin.ignore();
    NhapKH(kh);
    NodeKH *p = GetNodeKH(kh);
    if (Qkh.tail == NULL)
    {
        Qkh.head = p;
        Qkh.tail = p;
    }
    else
    {
        Qkh.tail->next = p;
        Qkh.tail = p;
    }
    cout << "\nDanh sach sau khi them phong la:";
    InDSKH(Qkh);
}

void RemoveHeadKH(ListKH &Qkh)
{
    NodeKH *p;
    if(Qkh.head!=NULL)
    {
        p = Qkh.head;
        Qkh.head = Qkh.head->next;
        delete p;
        if(Qkh.head==NULL)
            Qkh.tail = NULL;
    }
    cout << "\nDanh sach sau khi xoa\n";
    InDSKH(Qkh);
}

void GhiFileKH(ListKH Qkh)
{
    NodeKH *tg;
    tg = Qkh.head;
    if(tg == NULL)
    {
        cout << "\nDanh sach khong co du lieu, khong the luu file!";
        cout << "\n__________________________________________________________________\n";
        return;
    }
    ofstream f;
    f.open("KhachHang.dat", ios::out|ios::binary);
    while(tg!=NULL)
    {
        f.write((char*)&(tg->info), sizeof(KhachHang));
        tg = tg->next;
    }
    if(!f.good())
        cout << "\n\nXay ra loi trong qua trinh ghi file!";
    else
        cout << "\n\nGhi file thanh cong...";
    cout << "\n__________________________________________________________________\n";
    f.close();
}

void DocFileKH(ListKH Qkh)
{
    ifstream f;
    InitKH(Qkh);
    f.open("KhachHang.dat", ios::in|ios::binary);
    while(f.eof())
    {
        KhachHang kh;
        f.read((char*)&kh, sizeof(KhachHang));
        NodeKH *p = GetNodeKH(kh);
        InsertFirstKH(Qkh, p);
    }
    if(!f.good())
    {
        cout << "\nDa xay ra loi trong qua trinh doc file";
        cout << "\n__________________________________________________________________\n";
    }
    else
    {
        cout << "\nDoc file thanh cong...";
        cout << "\n__________________________________________________________________\n";
    }
    f.close();
}

void menuKH()
{
    ListKH Qkh;
    int chon;
    do
    {
        cout << "\n========KHACH HANG========\n"
             << "1. Nhap danh sach khach hang\n"
             << "2. Hien danh sach khach hang\n"
             << "3. Ghi danh sach khach hang vao file KhachHang.dat\n"
             << "4. Doc danh sach tu file KhachHang.dat\n"
             << "5. Them 1 khach hang vao cuoi danh sach\n"
             << "6. Xoa 1 khach hang o dau danh sach\n"
             << "0. Quay ve menu chinh\n"
             << "Lua chon cua ban la: ";
        cin >> chon;
        switch(chon)
        {
        case 1:
            NhapDSKH(Qkh);
            break;
        case 2:
            InDSKH(Qkh);
            break;
        case 3:
            GhiFileKH(Qkh);
            break;
        case 4:
            DocFileKH(Qkh);
            break;
        case 5:
            AddTailKH(Qkh);
            break;
        case 6:
            RemoveHeadKH(Qkh);
            break;
        case 0:
            cout << endl;
            break;
        default:
            cout << "\nKhong co chuc nang tren";
            cout << "\n__________________________________________________________________\n";
        }
    }while(chon!=0);
}
//PHONG
struct Phong
{
    string maPhong, tinhTrang;
    int giaTien1h, soNgayO, thanhTien;
};

struct NodePhong
{
    Phong info;
    NodePhong *next;
};

struct ListPhong
{
    NodePhong *head;
    NodePhong *tail;
};

void NhapPhong(Phong &phong)
{
    cout << "\tMa phong: ";
    cin.ignore();
    getline(cin, phong.maPhong);
    cout << "\tTinh trang: ";
    getline(cin, phong.tinhTrang);
    cout << "\tGia tien 1h: ";
    cin >> phong.giaTien1h;
    cout << "\tSo ngay o: ";
    cin >> phong.soNgayO;
    phong.thanhTien = phong.soNgayO * phong.giaTien1h;
}

void InPhong(Phong phong)
{
    cout << setw(8) << phong.maPhong << setw(12) << phong.tinhTrang << setw(16) << phong.giaTien1h << setw(8) << phong.soNgayO << setw(16) << phong.thanhTien <<  endl;
}

void InitPhong(ListPhong &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}

NodePhong *GetNodePhong(Phong phong)
{
    NodePhong *p = new NodePhong;
    if (p == NULL)
    {
        cout << "\nKhong du bo nho!";
        return NULL;
    }
    p->info = phong;
    p->next = NULL;
    return p;
}

void InsertFirstPhong(ListPhong &Q, NodePhong *p)
{
    if (Q.head == NULL)
    {
        Q.head = p;
        Q.tail = p;
    }
    else
    {
        p->next = Q.head;
        Q.head = p;
    }
}

void InsertTailPhong(ListPhong &Q, NodePhong *p)
{
    if (Q.tail == NULL)
    {
        Q.head = p;
        Q.tail = p;
    }
    else
    {
        Q.tail->next = p;
        Q.tail = p;
    }
}

void InsertLocation(ListPhong &Q, NodePhong *q, NodePhong *p)
{
    if (q != NULL)
    {
        p->next = q->next;
        q->next = p;
        if (q == Q.tail)
        {
            Q.tail = p;
        }
    }
    else
    {
        cout << "\nKhong ton tai nut p";
    }
}

void NhapDSPhong(ListPhong &Q)
{
    int n;
    InitPhong(Q);
    cout << "\nNhap so luong phong khach san: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap phong " << i + 1 << endl;
        Phong phong;
        NhapPhong(phong);
        NodePhong *p = GetNodePhong(phong);
        InsertFirstPhong(Q, p);
    }
    cout << "\n__________________________________________________________________\n";
}

void InDSPhong(ListPhong &Q)

{
    cout << "\nDanh sach phong\n";
    cout << setw(8) << "Ma phong" << setw(12) << "Tinh trang" << setw(16) << "Gia tien" << setw(8) << "So ngay o" << setw(16) << "Thanh tien" << endl;
    for (NodePhong *p = Q.head; p != NULL; p = p->next)
        InPhong(p->info);
    cout << "\n__________________________________________________________________\n";
}

void GhiFilePhong(ListPhong Q)
{
    NodePhong *tg;
    tg = Q.head;
    int n=0;
    if (tg == NULL)
    {
        cout << "\nDanh sach khong co du lieu, khong the luu file!";
        cout << "\n__________________________________________________________________\n";
        return;
    }
    ofstream f;
    f.open("Phong.dat", ios::out|ios::binary);
    //for(NodePhong *p = Q.head; p!=NULL; p=p->next)
    //    n++;
    //f.write((char*)&n, sizeof(int));
    while (tg != NULL)
    {
        f.write((char *)&(tg->info), sizeof(Phong));
        tg = tg->next;
    }
    if (!f.good())
        cout << "\n\nXay ra loi trong qua trinh ghi file";
    else
        cout << "\n\nGhi file thannh cong....";
    cout << "\n__________________________________________________________________\n";
    f.close();
}

void DocFilePhong(ListPhong Q)
{
    ifstream f;
    InitPhong(Q);
    f.open("Phong.dat", ios::in | ios::binary);
    while(f.eof())
    {
        Phong phong;
        f.read((char*)&phong, sizeof(Phong));
        NodePhong *p = GetNodePhong(phong);
        InsertFirstPhong(Q, p);
    }
    if (!f.good())
    {
        cout << "\nDa xay ra loi trong qua trinh doc file";
        cout << "\n__________________________________________________________________\n";
    }
    else
    {
        cout << "\nDoc file thanh cong....";
        cout << "\n__________________________________________________________________\n";
    }
    f.close();
}

void DocFilePhong2(ListPhong &Q)
{
    InitPhong(Q);
    FILE *f;
    NodePhong *p;
    Phong phong;
    int i, n;
    f = fopen("Phong.dat", "rb");
    fread(&n,sizeof(int), 1, f);
    cout << "\n n=" << n << endl;
    for(int i=0; i<n; i++)
    {
        fread(&phong,sizeof(Phong),1,f);
        p=GetNodePhong(phong);
        InsertFirstPhong(Q, p);
    }
    fclose(f);
    cout << "\nGhi file thanh cong...\n";
    InDSPhong(Q);
}

void InTien200(ListPhong Q)
{
    cout << "\nDanh sach phong co gia tien 1h tren 200k\n";
    cout << setw(8) << "Ma phong" << setw(12) << "Tinh trang" << setw(16) << "Gia tien 1h" << endl;
    for (NodePhong *p = Q.head; p != NULL; p = p->next)
    {
        if (p->info.giaTien1h > 200000)
        {
            InPhong(p->info);
        }
    }
}

void AddFirst(ListPhong &Q)
{
    Phong phong;
    cout << "\nNhap thong tin cho phong can them\n";
    NhapPhong(phong);
    NodePhong *p = GetNodePhong(phong);
    InsertFirstPhong(Q, p);
    cout << "\nDanh sach sau khi them phong la:";
    InDSPhong(Q);
    cout << "\n__________________________________________________________________\n";
}

void AddTail(ListPhong Q)
{
    Phong phong;
    cout << "\nNhap thong tin cho phong can them\n";
    NhapPhong(phong);
    NodePhong *p = GetNodePhong(phong);
    InsertTailPhong(Q, p);
    cout << "\nDanh sach sau khi them phong la:";
    InDSPhong(Q);
    cout << "\n__________________________________________________________________\n";
}

void RemoveHead(ListPhong &Q)
{
    NodePhong *p;
    if(Q.head!=NULL)
    {
        p = Q.head;
        Q.head = Q.head->next;
        delete p;
        if(Q.head==NULL)
            Q.tail = NULL;
    }
    cout << "\nDanh sach sau khi xoa\n";
    InDSPhong(Q);
    cout << "\n__________________________________________________________________\n";
}

void RemoveMaPhong(ListPhong &Q)
{
    string x;
    cout << "\nNhap ma phong can xoa: ";
    cin.ignore();
    getline(cin, x);
    NodePhong *p = Q.head, *q = NULL;
    while (p != NULL)
    {
        if (p->info.maPhong == x) break;
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "\nKhong tim thay ma phong " << x << " trong danh sach!";
        exit(1);
    }
    if (q != NULL)
    {
        if (p = Q.tail)
            Q.tail = q;
        q->next = p->next;
        delete p;
    }
    else
    {
        Q.head = p->next;
        if (Q.head == NULL) Q.tail = NULL;
    }
    cout << "\nXoa thanh cong! Danh sach sau khi xoala\n";
    InDSPhong(Q);
    cout << "\n__________________________________________________________________\n";
}

void Sort(ListPhong &Q)
{
    for (NodePhong *p = Q.head; p != NULL; p = p->next)
        for (NodePhong *q = p->next; q != NULL; q = q->next)
            if (p->info.giaTien1h > q->info.giaTien1h)
            {
                Phong tg;
                tg = p->info;
                p->info = q->info;
                q->info = tg;
            }
    cout << "\nDanh sach sau khi sap xep la\n";
    InDSPhong(Q);
    cout << "\n__________________________________________________________________\n";
}

void TKTheoMaPhong(ListPhong Q)
{
    NodePhong *p;
    string x;
    cout << "\nNhap ma phong can tim: ";
    cin.ignore();
    getline(cin, x);
    p = Q.head;
    while(p!=NULL)
    {
        if(p->info.maPhong==x) break;
        p=p->next;
    }
    if(p==NULL)
    {
        cout << "\nKhong tim thay ma phong " << x << " trong danh sach";
        cout << "\n__________________________________________________________________\n";
    }
    else
    {
        cout << "\nThong tin cua ma phong " << x << endl;
        cout << setw(8) << "Ma phong" << setw(12) << "Tinh trang" << setw(16) << "Gia tien 1h" << endl;
        InPhong(p->info);
        cout << "\n__________________________________________________________________\n";
    }
}

void DemPhong34(ListPhong Q)
{
    int dem = 0;
    for (NodePhong *p = Q.head; p != NULL; p = p->next)
        if (p->info.giaTien1h >= 300000 && p->info.giaTien1h <= 400000)
            dem++;
    if (dem == 0)
        cout << "\nKhong co phong nao co gia tien tu 300k-400k 1h\n";
    else
        cout << "\nCo " << dem << " phong co gia tien tu 300k-400k 1h\n";
    cout << "\n__________________________________________________________________\n";
}

void TongTienPhong(ListPhong Q)
{
    int sum = 0;
    for (NodePhong *p = Q.head; p != NULL; p = p->next)
    {
        sum += p->info.giaTien1h;
    }
    cout << "\nTong tien cac phong khach san la: " << sum << endl;
    cout << "\n__________________________________________________________________\n";
}

void TienMax(ListPhong Q)
{
    int Max;
    NodePhong *p = Q.head;
    Max = p->info.giaTien1h;
    while (p != NULL)
    {
        if (Max < p->info.giaTien1h)
            Max = p->info.giaTien1h;
        p = p->next;
    }
    cout << "\nDanh sach phong co gia tien cao nhat la\n";
    cout << setw(8) << "Ma phong" << setw(12) << "Tinh trang" << setw(16) << "Gia tien 1h" << endl;
    for (NodePhong *p = Q.head; p != NULL; p = p->next)
        if (p->info.giaTien1h == Max)
            InPhong(p->info);
    cout << "\n__________________________________________________________________\n";
}

void TienMin(ListPhong Q)
{
    int Min;
    NodePhong *p = Q.head;
    Min = p->info.giaTien1h;
    while (p != NULL)
    {
        if (Min > p->info.giaTien1h)
            Min = p->info.giaTien1h;
        p = p->next;
    }
    cout << "\nDanh sach phong co gia tien thap nhat la\n";
    cout << setw(8) << "Ma phong" << setw(12) << "Tinh trang" << setw(16) << "Gia tien 1h" << endl;
    for (NodePhong *p = Q.head; p != NULL; p = p->next)
        if (p->info.giaTien1h == Min)
            InPhong(p->info);
    cout << "\n__________________________________________________________________\n";
}

void PhongTrong(ListPhong Q)
{
    int dem =0;
    for(NodePhong *p=Q.head; p!=NULL; p=p->next)
        if(p->info.tinhTrang == "trong")
            dem++;
    if(dem == 0)
    {
        cout << "\nKhach san da het phong trong";
        cout << "\n__________________________________________________________________\n";
        exit(1);
    }
    cout << "\nCo tat ca " << dem << " phong con trong\nDanh sach phong con trong\n";
    cout << setw(8) << "Ma phong" << setw(12) << "Tinh trang" << setw(16) << "Gia tien" << setw(8) << "So ngay o" << setw(16) << "Thanh tien" << endl;
    for(NodePhong *p=Q.head; p!=NULL; p=p->next)
        if(p->info.tinhTrang=="trong")
            InPhong(p->info);
    cout << "\n__________________________________________________________________\n";
}

void tbcThanhTien(ListPhong Q)
{
    int dem = 0, tong =0;
    long long tbc;
    for(NodePhong *p = Q.head; p!=NULL; p=p->next)
    {
        dem++;
        tong = tong + p->info.thanhTien;
    }
    tbc = (tong*1.0)/dem;
    cout << "\nTrung binh cong thanh tien cua ca danh sach la: " << setw(16) << tbc;
    cout << "\n__________________________________________________________________\n";
}

void menuPhong()
{
    ListPhong Q;
    int chon;
    do
    {
        cout << "\n========PHONG========\n"
             << "1.  Nhap danh sach phong\n"
             << "2.  In danh sach phong\n"
             << "3.  In danh sach phong co gia tien tren 200k/1h\n"
             << "4.  Them phong vao dau danh sach\n"
             << "5.  Them phong vao cuoi danh sach\n"
             << "6.  Xoa phong dau danh sach\n"
             << "7.  Xoa phong theo ma\n"
             << "8.  Sap xep theo gia phong tang dan\n"
             << "9.  Tim kiem theo ma phong\n"
             << "10. Dem so phong co gia tien tu 300k den 400k 1h\n"
             << "11. Tinh tong tien tat ca phong 1h\n"
             << "12. In danh sach phong gia cao nhat\n"
             << "13. In danh sach phong gia thap nhat\n"
             << "14. Ghi danh sach vao file Phong.dat\n"
             << "15. Doc danh sach tu file Phong.dat\n"
             << "16. Thong ke cac phong con trong\n"
             << "17. Tinh tbc thanh tien\n"
             << "0.  Quay ve menu chinh\n"
             << "Lua chon cua ban la: ";
        cin >> chon;

        switch (chon)
        {
        case 1:
            NhapDSPhong(Q);
            break;
        case 2:
            InDSPhong(Q);
            break;
        case 3:
            InTien200(Q);
            break;
        case 4:
            AddFirst(Q);
            break;
        case 5:
            AddTail(Q);
            break;
        case 6:
            RemoveHead(Q);
            break;
        case 7:
            RemoveMaPhong(Q);
            break;
        case 8:
            Sort(Q);
            break;
        case 9:
            TKTheoMaPhong(Q);
            break;
        case 10:
            DemPhong34(Q);
            break;
        case 11:
            TongTienPhong(Q);
            break;
        case 12:
            TienMax(Q);
            break;
        case 13:
            TienMin(Q);
            break;
        case 14:
            GhiFilePhong(Q);
            break;
        case 15:
            DocFilePhong(Q);
            break;
        case 16:
            PhongTrong(Q);
            break;
        case 17:
            tbcThanhTien(Q);
            break;
        case 0:
            cout << endl;
            break;
        default:
            cout << "\nKhong co chuc nang tren";
            cout << "\n__________________________________________________________________\n";
        }

    }while (chon != 0);
}

int main()
{
    int chon;
    do
    {
        cout << "Chon doi tuong de xu ly\n"
             << "1. Khach hang\n"
             << "2. Phong\n"
             << "0. Thoat chuong trinh\n"
             << "Lua chon cua ban la: ";
        cin >> chon;
        switch(chon)
        {
        case 1:
            menuKH();
            break;
        case 2:
            menuPhong();
            break;
        case 0:
            cout << "\nKet thuc chuong trinh...";
            cout << "\n__________________________________________________________________\n";
            break;
        default:
            cout << "\nKhong co chuc nang tren";
            cout << "\n__________________________________________________________________\n";
        }
    }while(chon!=0);
    return 0;
}
