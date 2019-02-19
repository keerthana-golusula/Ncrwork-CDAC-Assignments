#include<iostream>
using namespace std;
class queue {
	int r, f, size;
	int *q;
public:
	queue() {
		size = 0;
		r = f = -1;
		q = NULL;
	}
	queue(int x) {
		size = x;
		r = f = -1;
		q = new int[x];
	}
	void enque(int x) {
		if (r == -1 && f == -1) {
			f = 0;
			q[++r] = x;
		}
		else {
			if (!overflow())
			{
				q[++r] = x;
			}
			else
				cout << "overflow!! cannot be inserted" << endl;

		}
	}
	int deque() {
		int x = -999;
		if (!underflow()) {
			if (r == f)
			{
				x = q[f];
				r = f = -1;
			}
			else {
				x = q[f++];
			}
		}
		return x;
	}
	bool overflow() {
		if (r == size - 1)
			return true;
		return false;
	}
	bool underflow() {
		if (r == -1 && f == -1) {
			return true;
		}
		return false;
	}
	void display() {
		if (f != -1) {
			for (int i = f; i <= r; i++)
				cout << q[i] << " ";
		}
		else
			cout << "no elements in queue" << endl;
	}

};
int main() {
	int n,x,op;
	cout << "enter the size of queue" << endl;
	cin >> n;
	queue q(n);
	while (1) {
		cout << "choose the choice" << endl;
		cout << "1.enque the queue" << endl;
		cout << "2.deque the queue" << endl;
		cout << "3.display the queue" << endl;
		cout << "4.exit" << endl;
		cin >> op;
		switch (op) {
		case 1:
			cout << "enter element to be inserted" << endl;
			cin >> x;
			q.enque(x);
			break;
		case 2:
			x = q.deque();
			if (x == -999) {
				cout << "underflow!! cannot be deleted" << endl;
			}
			else
				cout << "deleted element is:" << x << endl;
			break;
		case 3:
			q.display();
			break;
		case 4:
			exit(0);
		default:
			cout << "choose the valid option";
			break;
		}
	}

 }




