#include <iostream>
using namespace std;
const int MAX = 50;
const int STOP = -99;
struct Queue
{
	int front, rear;
	int list[MAX];
};

void khoiTao(Queue& q)
{
	q.front = q.rear = -1;
}

int listFull(Queue q)
{
	return (q.rear - q.front == MAX - 1);
}

void reFreshQueue(Queue& q)
{
	for (int i = q.front; i <= q.rear; i++)
		q.list[i - q.front] = q.list[i];
	q.rear = q.rear - q.front;
	q.front = 0;
}

int pushQueue(Queue& q, int x)
{
	if (listFull(q))
	{
		return 0;
	}
	else
	{
		if (q.front == -1)
			q.front = 0;
		else if (q.rear == MAX - 1)
		{
			for (int i = q.front; i <= q.rear; i++)
				q.list[i - q.front] = q.list[i];
				q.rear = MAX - 1 - q.front;
				q.front = 0;
		}
		q.rear++;
		q.list[q.rear] = x;
		return q.rear;
	}
}

void nhap(Queue& q)
{
	int x;
	do
	{
		cout << "\n Nhap Gia Tri: (-99 De Thoat)"; cin >> x;
		if (x == STOP) break;
		pushQueue(q, x);
	} while (1);
}

void xuat(Queue q)
{
	for (int i = q.front; i <= q.rear; i++)
	{
		cout << " " << q.list[i];
	}
}

int isEmpty(Queue q)
{
	if (q.front == -1)
		return 1;
	return 0;
}

int popQueue(Queue& q)
{
	int t;
	if (isEmpty(q))
		return -99;
	else
	{
		t = q.list[q.front];
		q.front++;
	}
	reFreshQueue(q);
	return t;
	
}

void xuatViTriPhanTuGiaTriX(Queue q, int x)
{
	for (int i = q.front; i <= q.rear; i++)
	{
		if (q.list[i] == x)
		{
			cout << " " << i;
		}
	}
}

int demSoLuongPhanTuGiaTriX(Queue q, int x)
{
	int dem = 0;
	for (int i = q.front; i <= q.rear; i++)
	{
		if (q.list[i] == x)
		{
			dem++;
		}
	}
	return dem;
}

int traVeGiaTriPhanTuDauTien(Queue& q, int& x)
{
	if (q.front != -1)
	{
		x = q.list[0];
	}
	return x;
}

void xoaPhanTuGiaTriXDauTien(Queue& q, int x)
{
	while (q.front != -1)
	{
		int pT = popQueue(q);
		if (pT != x)
		{
			pushQueue(q, pT);
		}
		else break;
	}
}

void xoaTatCaPhanTuGiaTriX(Queue& q, int x)
{
	Queue(qT);
	khoiTao(qT);
	while (q.front != -1)
	{
		while (q.front != -1)
		{
			int pT = popQueue(q);
			if (pT != x)
			{
				pushQueue(qT, pT);
			}
			else
			{
				break;
			}
		}
	}
	q = qT;
}

int main()
{
	Queue q;
	khoiTao(q);
	int chon = 0;
	do
	{
		cout << "\n\n\t\t1. Nhap Danh Sach Dac Queue. ";
		cout << "\n\n\t\t2. Xuat Danh Sach Dac Queue. ";
		cout << "\n\n\t\t3. Lay 1 Phan Tu Danh Sach Dac Ra Khoi Queue. ";
		cout << "\n\n\t\t4. Xuat Tat Ca Vi Tri Phan Tu Co Gia Tri X Danh Sach Dac Trong Queue. ";
		cout << "\n\n\t\t5. Dem So Luong Phan Tu Co Gia Tri X Danh Sach Dac Trong Queue. ";
		cout << "\n\n\t\t6. Tra Ve Gia Tri Phan Tu Dau Tien ";
		cout << "\n\n\t\t7. Xoa Phan Tu X Dau Tien Trong Danh Sach Dac Queue. ";
		cout << "\n\n\t\t\8. Xoa Tat Ca Phan Tu X Trong Danh Sach Dac Queue. ";
		cout << "\n\n\t\t0. Dung Lai. ";
		cout << "\n\t\t Nhap So 1 Nguyen De Thuc Thi: "; cin >> chon;
		switch (chon)
		{
		case 1:
			system("cls");
			nhap(q);
			break;
		case 2:
			system("cls");
			xuat(q);
			break;
		case 3:
			system("cls");
			popQueue(q);
			xuat(q);
			break;
		case 4:
			system("cls");
			int x;
			cout << "\n Nhap Gia Tri X ( Xuat Vi Tri ): "; cin >> x;
			xuatViTriPhanTuGiaTriX(q, x);
			break;
		case 5:
			system("cls");
			cout << "\n Nhap Gia Tri X ( Dem So Luong X ): "; cin >> x;
			cout<<" So Luong X Co Trong Danh Sach Dac Queue La: "<<demSoLuongPhanTuGiaTriX(q, x);
			break;
		case 6:
			system("cls");
			int xemPhanTu,a;
			xemPhanTu = traVeGiaTriPhanTuDauTien(q, a);
			cout << "\n Tra Ve Gia Tri PhanTu Dau Tien " << xemPhanTu;
			break;
		case 7:
			system("cls");
			cout << "\n Nhap Gia Tri X: ( Xoa Gia Tri X Dau Tien ) "; cin >> x;
			cout << "\n\t Xoa Phan Tu X Dau Tien Ra Khoi Danh Sach Dac Queue: ";
			xoaPhanTuGiaTriXDauTien(q, x);
			xuat(q);
			break;
		case 8:
			system("cls");
			cout << "\n Nhap Gia Tri X: (Xoa Tat Ca X )"; cin >> x;
			cout << "\n\t Danh Sach Sau Khi Da Xoa: ";
			xoaTatCaPhanTuGiaTriX(q, x);
			xuat(q);
			break;
		default: 
			break;
		}
	} while (chon != 0);
	return 0;
}