  // BT.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>

using namespace std;

struct BTItem {
	int a;
	BTItem *left;
	BTItem *right;
};

int dep = 0;

int printtree(BTItem *input) {
	BTItem *curr = input;

	dep++;
	if (curr->right == nullptr) {
		for (int i = 1; i < dep; i++) {
			cout << "-";
		}
		cout << curr->a << endl;
		if (curr->left == nullptr) {
			dep--;
			return 0;
		}
		else {
			printtree(curr->left);
		}
	}
	else {
		printtree(curr->right);
		for (int i = 1; i < dep; i++) {
			cout << "-";
		}
		cout << curr->a << endl;
		if (curr->left == nullptr) {
			dep--;
			return 0;
		}
		else {
			printtree(curr->left);
		}
	}

	dep--;
	return 0;
}

int vyvodtree(BTItem *first) {
	BTItem *curr = first;

	if (first != nullptr) {
		printtree(first);
	}
	else {
		cout << "Список пуст " << endl;
	}
	return 0;
}

int printcrossitem(BTItem *input) {
	BTItem *curr = input;

	if (curr->left != nullptr) {
		printcrossitem(curr->left);
		cout << curr->a << " ";
		if (curr->right != nullptr) {
			printcrossitem(curr->right);
			return 0;
		}
	}
	else {
		cout << curr->a << " ";
		if (curr->right != nullptr) {
			printcrossitem(curr->right);
			return 0;
		}
	}

	return 0;
}

int printreverceitem(BTItem *input) {
	BTItem *curr = input;

	if (curr->left != nullptr) {
		printreverceitem(curr->left);
		if (curr->right != nullptr) {
			printreverceitem(curr->right);
			cout << curr->a << " ";
			return 0;
		}
		else {
			cout << curr->a << " ";
			return 0;
		}
	}
	else {
		if (curr->right != nullptr) {
			printreverceitem(curr->right);
			cout << curr->a << " ";
			return 0;
		}
		cout << curr->a << " ";
	}

	return 0;
}

int printdirectitem(BTItem *input) {
	BTItem *curr = input;

	cout << curr->a << " ";
	if (curr->left != nullptr) {
		printdirectitem(curr->left);
		if (curr->right != nullptr) {
			printdirectitem(curr->right);
			return 0;
		}
	}
	else {
		if (curr->right != nullptr) {
			printdirectitem(curr->right);
			return 0;
		}
	}

	return 0;
}

int vyvoditems(BTItem *first) {
	BTItem *curr = first;
	char operation = 0;

	if (first != nullptr) {
		cout << "a.Прямой обход" << endl;
		cout << "b.Поперечный обход" << endl;
		cout << "c.Обратный обход" << endl;

		cin >> operation;

		switch (operation) {
		case 'a':
			printdirectitem(first);
			break;
		case 'b':
			printcrossitem(first);
			break;
		case 'c':
			printreverceitem(first);
			break;

		default:
			cerr << "Vveden nevernij parametr" << endl;
			break;
		}
	}
	else {
		cout << "Список пуст " << endl;
	}
	return 0;
}


int main(int argc, char*argv[]) {  // argv - массив указателей на строки параметров командной строки, argc - кол-во параметров + 1
	char operation = 'c';

	int items = 0;
	int correct = 0;
	BTItem *first = nullptr;

	setlocale(LC_ALL, "Russian");

	if (argc != 1) {  // проверка на наличие параметров входной строки
		items = (argc - 1);

		for (int i = 0; i<items; i++) {
			BTItem *curr = new BTItem{ atoi(argv[i + 1]), nullptr, nullptr};
			if (i == 0) {
				first = curr;
			}
			else {
				BTItem *tmp = first;
				for (int j = 0; j < i; j++) {
					if (tmp->a != atoi(argv[i + 1])) {
						if (tmp->a > atoi(argv[i + 1])) {
							if (tmp->left != nullptr) {
								tmp = tmp->left;
							}
							else {
								tmp->left = curr;
								break;
							}
						}
						else {
							if (tmp->right != nullptr) {
								tmp = tmp->right;
							}
							else {
								tmp->right = curr;
								break;
							}

						}
					}
					else {
						cerr << "Ошибка входных данных. Повторение значения " << argv[i + 1] << endl;
						correct = 1;
						break;
					}
				}
				if (correct != 0) {
					break;
				}
			}
		}

		if (correct != 0) {
			//!!!Освободить память
			return 1;
		}
	}

	while (operation != '8') {
		cout << endl;
		cout << "Выберите одну из операций:" << endl;
		cout << "1. Вывести дерево на экран" << endl;
		cout << "2. Вывести список узлов дерева" << endl;
/*		cout << "3. Удалить элемент" << endl;
		cout << "4. Найти позиции элементов" << endl;
		cout << "5. Заменить элемент на другой" << endl;
		cout << "6. Отсортировать элементы списка" << endl;
*/
		cout << "8. Завершить работу программы" << endl;

		cin >> operation;

		switch (operation) {
		case '1':
			vyvodtree(first);
			break;

		case '2':
			vyvoditems(first);
			break;

/*		case '3':
			udalitelement(&first);
			break;

		case '4':
			poiskelement(first);
			break;

		case '5':
			zamenitelement(first);
			break;

		case '6':
			sortlist(first);
			break;
*/
		case '8':
			char s[4];

			operation = 0;

			cout << "Вы хотите выйти из программы ? (y, N) : ";
			cin >> s;

			if ((strcmp("y", s) == 0) || (strcmp("Y", s) == 0) || (strcmp("yes", s) == 0) || (strcmp("Yes", s) == 0) || (strcmp("YES", s) == 0)) {
				operation = '8';
				cout << "До свидания !" << endl;
			}
			break;
		default:
			cerr << "Vveden nevernij parametr" << endl;
			break;
		}
	}

	return 0;
}
