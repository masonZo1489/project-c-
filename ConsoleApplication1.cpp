#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void shfr(string& message, string& shifr) {
	string key;
	cout << "Введите сообщение: ";
	cin >> message;
	cout << "Введите ключ: ";
	cin >> key;

	for (size_t i = 0; i < message.size(); i++)
	{

		if (message[i] == ' ')
		{
			shifr.push_back((32 + ((int)key[i % key.size()] - 97)));
		}
		else
			shifr.push_back(char(((((int)message[i] - 97) + ((int)key[i % key.size()] - 97)) % 26) + 97));
	}

	cout << "Шифр: " << shifr << '\n';
}

void ras(string shifr, string& deshifr) {
	string key;
	cout << "введите ключь";
	cin >> key;

	cout << "Шифр: " << shifr << '\n';

	for (size_t i = 0; i < shifr.size(); i++)
	{
		int df = ((int)shifr[i] - 97) - ((int)key[i % key.size()] - 97);
		if (shifr[i] == 32 + key[i % key.size()] - 97)
		{
			deshifr.push_back(' ');
		}
		else
			deshifr.push_back((df >= 0 ? df : df + 26) % 26 + 97);
	}

	cout << "ДеШифр: " << deshifr << '\n';

}






int main() {
	setlocale(LC_ALL, "ru");
	string message, key, shifr, deshifr;
	int x = 0;
	string a;
	cout << "введите название файла в который хотите записать шифр или выписать от туда ";
	cin >> a;
	ofstream fl(a);
	fl.close();
	fstream fla(a, ios::in);
	fla.close();

	while (x != 3) {
		cout << " \n1 - записать в файл шифр \n2 - расшифровать\n3 - завершение работы\n";
		cin >> x;
		switch (x) {
		case 1:
			fl.open(a);
			shfr(message, shifr);
			fl << shifr;
			fl.close();



			break;
		case 2:
			fla.open(a);
			getline(fla, shifr);
			ras(shifr, deshifr);
			fla.close();
			break;


		}
	}

}










