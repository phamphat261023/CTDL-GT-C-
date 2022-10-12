#include <bits/stdc++.h>

using namespace std;

struct Thuoc
{
    string maThuoc;
    string tenThuoc;
    long GiaThuoc;
    int soLieu;
    int tien1Thuoc;
};

struct HoaDon
{
    string maHDon;
    string ngaylap;
    long tongDonGia;
    Thuoc ds[50];
    int n;
};

struct NodeHoaDon
{
    HoaDon info;
    struct NodeHoaDon *next;
};

struct ListHoaDon
{
    NodeHoaDon *head;
    NodeHoaDon *tail;
};

ListHoaDon QHoaDon;

void NhapThuoc(Thuoc &t)
{
    cout << "\nNhap ma thuoc: ";
    cin.ignore();
    getline(cin, t.maThuoc);
    cout << "\nNhap ten thuoc: ";
    getline(cin, t.tenThuoc);
    cout << "\nNhap so lieu thuoc: ";
    cin >> t.soLieu;
    cout << "\nNhap so tien/1 lieu thuoc: ";
    cin >> t.tien1Thuoc;
    t.GiaThuoc = t.soLieu * t.tien1Thuoc;
}

void InThuoc(Thuoc t)
{
    cout << setw(8) << t.maThuoc << setw(12) << t.tenThuoc << setw(16) << t.GiaThuoc << endl;
}

void NhapHoaDon(HoaDon &hd)
{
    cout << "\nNhap ma hoa don: ";
    cin.ignore();
    getline(cin, hd.maHDon);
    cout << "\nNhap ngay lap: ";
    getline(cin, hd.ngaylap);
    cout << "\nNhap don gia: ";
    cin >> hd.tongDonGia;
    cout << "\nNhap so luong thuoc trong 1 hoa don: ";
    cin >> hd.n;

    for (int i = 0; i < hd.n; i++)
    {
        NhapThuoc(hd.ds[i]);
    }
    cout << "\n_______________________________________________\n";
}

void InHoaDon(HoaDon hd)
{
    cout << "\nHoa don\n";
    cout << setw(10) << "Ma hoa don" << setw(14) << "Ngay lap" << setw(16) << "Don gia" << endl;
    cout << setw(10) << hd.maHDon << setw(14) << hd.ngaylap << setw(16) << hd.tongDonGia << endl;

    cout << "\nDanh sach thuoc\n";
    cout << setw(8) << "Ma thuoc" << setw(12) << "Ten thuoc" << setw(16) << "Gia thuoc" << endl;

    for (int i = 0; i < hd.n; i++)
    {
        InThuoc(hd.ds[i]);
    }
    cout << "\n*****************************************\n";
}

void InitHoaDon(ListHoaDon &Q)
{
    Q.head = NULL;
    Q.tail = NULL;
}

NodeHoaDon *GetHoaDon(HoaDon hd)
{
    NodeHoaDon *p = new NodeHoaDon();
    if (p == NULL)
    {
        cout << "\nDanh sach trong!!!\n";
        exit(1);
    }
    p->info = hd;
    p->next = NULL;
    return p;
}

void InsertFirst(ListHoaDon &Q, NodeHoaDon *p)
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

void InsertTail(ListHoaDon &Q, NodeHoaDon *p)
{
    if (Q.head == NULL)
    {
        Q.head = p;
        Q.tail = p;
    }
    else
    {
        Q.tail->next = p;
        ;
        Q.tail = p;
    }
}

void InsertLocation(ListHoaDon &Q, NodeHoaDon *q, NodeHoaDon *p)
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
        InsertFirst(Q, p);
    }
}

void NhapDSHoaDon(ListHoaDon &Q)
{
    int n;
    HoaDon hd;
    NodeHoaDon *p;

    cout << "\nNhap so luong hoa don: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap hoa don " << i + 1 << endl;
        NhapHoaDon(hd);
        p = GetHoaDon(hd);
        InsertFirst(Q, p);
    }
}

void InDSHoaDon(ListHoaDon Q)
{
    cout << "\nDanh sach hoa don\n";
    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
    {
        InHoaDon(p->info);
    }
}

void DonGia2000(ListHoaDon Q)
{
    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
    {
        if (p->info.tongDonGia > 2000)
        {
            InHoaDon(p->info);
        }
    }
}

void AddFirst(ListHoaDon &Q)
{
    cout << "\nThem hoa don vao dau danh sach\n";
    HoaDon hd;
    NhapHoaDon(hd);
    NodeHoaDon *p = GetHoaDon(hd);
    InsertFirst(Q, p);
    cout << "\nDanh sach sau khi them 1 hoa don\n";
    InDSHoaDon(Q);
}

void AddTail(ListHoaDon &Q)
{
    cout << "\nThem 1 hoa don vao cuoi danh sach\n";
    HoaDon x;
    NhapHoaDon(x);
    NodeHoaDon *p = GetHoaDon(x);
    InsertTail(Q, p);
    InDSHoaDon(Q);
}

void ReMoveHead(ListHoaDon &Q)
{
    string maHD;
    cout << "Nhap ma hoa don dau tien trong danh sach hoa don can xoa: ";
    cin.ignore();
    getline(cin, maHD);

    NodeHoaDon *p = Q.head, *q = NULL;

    while (p != NULL)
    {
        if (p->info.maHDon == maHD)
            break;
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "\nKhong tim thay ma hoa don " << maHD << " trong danh sach!";
        exit(1);
    }
    if (q != NULL)
    {
        if (p = Q.tail)
            Q.tail = q;
        q->next = p->next;
        delete p;
    }
    else // Truong hop p la phan tu dau danh sach
    {
        Q.head = p->next;
        if (Q.head == NULL)
            Q.tail = NULL;
    }

    cout << "Xoa thanh cong! Danh sach sau khi xoa ma hoa don " << maHD << ":\n";
    InDSHoaDon(Q);
}

void ReMoveElement(ListHoaDon &Q)
{
    string maHD;
    cout << "\nNhap ma hoa don can xoa: ";
    cin.ignore();
    getline(cin, maHD);
    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
    {
        if (maHD == p->info.maHDon)
        {
            p = p->next;
            delete p;
        }
    }
}

void ReMoveTail(ListHoaDon &Q)
{
    string maHD;
    cout << "Nhap ma hoa don cuoi cung trong danh sach hoa don can xoa: ";
    cin.ignore();
    getline(cin, maHD);

    NodeHoaDon *p = Q.tail, *q = NULL;

    while (p != NULL)
    {
        if (p->info.maHDon == maHD)
            break;
        q = p;
        p = p->next;
    }
    if (p == NULL)
    {
        cout << "\nKhong tim thay ma hoa don " << maHD << " trong danh sach!";
        exit(1);
    }
    if (q != NULL)
    {
        if (p = Q.head)
            Q.head = q;
        q->next = p->next;
        delete p;
    }
    else // Truong hop p la phan tu dau danh sach
    {
        Q.tail = p->next;
        if (Q.tail == NULL)
            Q.head = NULL;
    }

    cout << "Xoa thanh cong! Danh sach sau khi xoa ma hoa don " << maHD << ":\n";
    InDSHoaDon(Q);
}

void SelectionSort(ListHoaDon Q)
{
    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
    {
        for (NodeHoaDon *q = p->next; q != NULL; q = q->next)
        {
            if (p->info.tongDonGia > q->info.tongDonGia)
            {
                HoaDon tg = p->info;
                p->info = q->info;
                tg = q->info;
            }
        }
    }
}

void TKtheoMaDon(ListHoaDon Q)
{
    string id;
    cout << "\nNhap ma hoa don can tim kiem: ";
    cin.ignore();
    getline(cin, id);

    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
    {
        if (id == p->info.maHDon)
        {
            InHoaDon(p->info);
        }
    }
}

void Dem(ListHoaDon Q)
{
    int dem = 0;
    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
        if (p->info.tongDonGia >= 2000 && p->info.tongDonGia <= 3000)
            dem++;
    if (dem == 0)
        cout << "\nKhong co tong don gia nao tu 2000->3000\n";
    else
        cout << "\nCo " << dem << " phong co tong don gia tu 2000->3000\n";
}

void TongDonGia(ListHoaDon Q)
{
    long s = 0;
    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
    {
        s += p->info.tongDonGia;
    }
    cout << "\nTong don gia cua tat ca cac hoa don: " << s << endl;
}

void DonGiaMax(ListHoaDon Q)
{
    long max;
    NodeHoaDon *p = Q.head;
    max = p->info.tongDonGia;
    while (p != NULL)
    {
        if (max < p->info.tongDonGia)
            max = p->info.tongDonGia;
        p = p->next;
    }
    cout << "\nHoa don co tong don ghia cao nhat\n";
    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
    {
        if (p->info.tongDonGia == max)
        {
            InHoaDon(p->info);
        }
    }
}

void DonGiaMin(ListHoaDon Q)
{
    long min;
    NodeHoaDon *p = Q.head;
    min = p->info.tongDonGia;
    while (p != NULL)
    {
        if (min > p->info.tongDonGia)
            min = p->info.tongDonGia;
        p = p->next;
    }
    cout << "\nHoa don co tong don gia thap nhat\n";
    for (NodeHoaDon *p = Q.head; p != NULL; p = p->next)
    {
        if (p->info.tongDonGia == min)
        {
            InHoaDon(p->info);
        }
    }
}

void luuFile(ListHoaDon Q)
{
    NodeHoaDon *tg;
    tg = Q.head;
    if (tg == NULL)
    {
        cout << "\nDanh sach khong co du lieu, khong the luu file!";
        cout << "\n__________________________________________________________________\n";
        return;
    }

    ofstream f;

    f.open("Thuoc.dat", ios::out | ios::binary);

    while (tg != NULL)
    {
        f.write((char *)&(tg->info), sizeof(HoaDon));
        tg = tg->next;
    }

    if (!f.good())
        cout << "\n\nXay ra loi trong qua trinh luu danh sach tren vao file Thuoc.dat";
    else
        cout << "\n\nDa luu danh sach tren vao file Thuoc.dat thannh cong....";

    cout << "\n__________________________________________________________________\n";

    f.close();
}

void docFile()
{
    ListHoaDon A;
    ifstream f;
    HoaDon hd;
    InitHoaDon(A);
    f.open("Thuoc.dat", ios::in | ios::binary);

    while (f.eof())
    {
        f.read((char *)&hd, sizeof(HoaDon));
        NodeHoaDon *p = GetHoaDon(hd);
        InsertFirst(A, p);
    }

    if (!f.good())
    {
        cout << "\nDa xay ra loi trong qua trinh doc file\n";
        return;
    }
    else
    {
        cout << "\nDoc file thanh cong....\n";
    }

    cout << "Danh sach can bo duoc luu trong file Thuoc.dat:\n";

    InDSHoaDon(A);

    cout << "\n__________________________________________________________________\n";

    f.close();
}

int main()
{
    int chon;
    do
    {
        cout << "\nQuan li hoa don thuoc";
        cout << "\n1. Nhap danh sach hoa don thuoc";
        cout << "\n2. In danh sach hoa don thuoc";
        cout << "\n3. In danh sach hoa don thuoc co don gia > 2000";
        cout << "\n4. Them 1 hoa don thuoc vao dau danh sach";
        cout << "\n5. Them 1 hoa don thuoc vao cuoi danh sach";
        cout << "\n6. Xoa 1 hoa don thuoc o dau danh sach";
        cout << "\n7. Xoa 1 hoa don thuoc o 1 vi tri bat ki";
        cout << "\n8. Xoa 1 hoa don thuoc o cuoi danh sach";
        cout << "\n9. Sap xep danh sach hoa don tang dan";
        cout << "\n10. Tim kiem hoa don theo  ma";
        cout << "\n11. Dem phong co tong don gia tu 2000->3000";
        cout << "\n12. Tong tien tat ca cac hoa don";
        cout << "\n13. Hoa don co tong don gia cao nhat";
        cout << "\n14. Hoa don co tong don gia thap nhat";
        cout << "\n15. Ghi File";
        cout << "\n16. Doc File";
        cout << "\n0. Thoat";
        cout << "\nMoi ban chon de chay chuong trinh: ";
        cin >> chon;

        switch (chon)
        {
        case 1:
            NhapDSHoaDon(QHoaDon);
            break;
        case 2:
            InDSHoaDon(QHoaDon);
            break;
        case 3:
            DonGia2000(QHoaDon);
            break;
        case 4:
            AddFirst(QHoaDon);
            break;
        case 5:
            AddTail(QHoaDon);
            break;
        case 6:
            ReMoveHead(QHoaDon);
            break;
        case 7:
            ReMoveElement(QHoaDon);
            cout << "\nDanh sach hoa don sau khi xoa\n";
            InDSHoaDon(QHoaDon);
            break;
        case 8:
            ReMoveTail(QHoaDon);
            break;
        case 9:
            SelectionSort(QHoaDon);
            cout << "\nDanh sach sau khi sap xep\n";
            InDSHoaDon(QHoaDon);
            break;
        case 10:
            TKtheoMaDon(QHoaDon);
            break;
        case 11:
            Dem(QHoaDon);
            break;
        case 12:
            TongDonGia(QHoaDon);
            break;
        case 13:
            DonGiaMax(QHoaDon);
            break;
        case 14:
            DonGiaMin(QHoaDon);
            break;
        case 15:
            luuFile(QHoaDon);
            break;
        case 16:
            docFile();
            break;
        case 0:
            break;

        default:
            break;
        }

        cout << "\nTiep tuc - 0. Thoat: ";
        cin >> chon;

    } while (chon != 0);

    NhapDSHoaDon(QHoaDon);
    InDSHoaDon(QHoaDon);
    DonGia2000(QHoaDon);
    AddFirst(QHoaDon);
    AddTail(QHoaDon);
    ReMoveHead(QHoaDon);
    ReMoveElement(QHoaDon);
    ReMoveTail(QHoaDon);
    return 0;
}