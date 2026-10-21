#include <iostream>
#include <Windows.h>

int Visokos(int year1, int year2)
{
	int visokosnye = 0;
	if (year1 < year2)
	{
		for (size_t i = 1; i < (year2 - year1); i++)
		{
			if (year1 + i % 400 == 0 || (year1 + i % 4 == 0 && year1 + i % 100 != 0))
			{
				visokosnye++;
			}
		}
	}
	else if (year2 < year1)
	{
		for (size_t i = 1; i < (year1 - year2); i++)
		{
			if (year2 + i % 400 == 0 || (year2 + i % 4 == 0 && year2 + i % 100 != 0))
			{
				visokosnye++;
			}
		}
	}
	return visokosnye;

}

int Raznost_of_days(int day1, int month1, int year1, int day2, int month2, int year2) 
{
	int total = 0;
	int day_of_month1 = 0;
	int day_of_month2 = 0;
	for (size_t i = month1; i <= month1; i++)
	{
		if (i == 01 || i ==  03 || i == 05 || i == 07 || i == 8 || i == 10 || i == 12)
		{
			day_of_month1 += 31;
		}
		else if (i == '02' && (year1 + i % 400 == 0 || (year1 + i % 4 == 0 && year1 + i % 100 != 0)))
		{
			day_of_month1 += 29;
		}
		else if (i == '02' && (year1 + i % 400 != 0 || (year1 + i % 4 != 0 || year1 + i % 100 == 0)))
		{
			day_of_month1 += 28;
		}
		else
		{
			day_of_month1 += 30;
		}
	}
	for (size_t i = month2; i <= month2; i++)
	{
		if (i == 01 || i == 03 || i == 05 || i == 07 || i == 8 || i == 10 || i == 12)
		{
			day_of_month2 += 31;
		}
		else if (i == '02' && (year2 + i % 400 == 0 || (year2 + i % 4 == 0 && year2 + i % 100 != 0)))
		{
			day_of_month2 += 29;
		}
		else if (i == '02' && (year2 + i % 400 != 0 || (year2 + i % 4 != 0 || year2 + i % 100 == 0)))
		{
			day_of_month2 += 28;
		}
		else
		{
			day_of_month2 += 30;
		}
	}

	if (year1 <= year2)
	{
		total = (year2 - year1) * 365 + Visokos(year1, year2)
			+ (day_of_month2 * (month2) - day_of_month1 * (month1)) + (day2 - day1);
	}
	else
	{
		total = (year1 - year2) * 365 + Visokos(year1, year2)
			+ (day_of_month1 * (month1) - day_of_month2 * (month2)) + (day1 - day2);
	}
	return total;
}

double Arifmetich(int size, double m[]) {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += m[i];
	}
	return sum / size;
}

void What_znak(int size, double m[]) {
	int plus = 0, minus = 0, nul = 0;
	for (int i = 0; i < size; i++)
	{
		if (m[i] > 0)
		{
			plus++;
		}
		else if (m[i] < 0)
		{
			minus++;
		}
		else
		{
			nul++;
		}
	}
	std::cout << "\nКол-во положительных элементов: " << plus;
	std::cout << "\nКол-во отрицательных элементов: " << minus;
	std::cout << "\nКол-во нулевых элементов: " << nul << "\n\n";
}


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	int dz;
	std::cout << "\tВыберите домашку\n";
	std::cout << "1)  Массивы от 24.09\n";
	std::cout << "2)  Функции от 01.10\n\n";
	std::cin >> dz;

	if (dz == 1)
	{
		system("cls");

		// 1
		std::cout << "\tЗадание 1\n";
		const int size = 10;
		int a[size], min = 0, max = 0;

		for (size_t i = 0; i < size; i++)
		{
			a[i] = rand() % 15 + 1;
			if (min == 0)
			{
				min = a[i];
			}
			if (a[i] < min) {
				min = a[i];
			}
			if (a[i] > max) {
				max = a[i];
			}
			std::cout << a[i] << " ";
		}
		std::cout << "\n" << "Минимальное: " << min << "\n";
		std::cout << "Максимальное: " << max << "\n\n";

		// 2
		std::cout << "\tЗадание 2\n";
		const int Size = 20;
		int b[Size], sum = 0, low = 0, high = 0, limit = 0;

		std::cout << "Введите нижний диапазон: ";
		std::cin >> low;
		std::cout << "\nВведите верхний диапазон: ";
		std::cin >> high;
		if (high < low)
		{
			std::cout << "\nНеккоректный ввод! \n\n";
			return 0;
		}
		std::cout << "\nВведите лимитное значение: ";
		std::cin >> limit;
		if (limit > high || limit < low)
		{
			std::cout << "\nЛимит не в рамках диапазона! \n";
		}

		for (size_t i = 0; i < Size; i++)
		{
			b[i] = rand() % (high - low) + low;
			if (b[i] < limit)
			{
				sum += b[i];
			}
			std::cout << b[i] << " ";
		}
		std::cout << "\nСумма элементов: " << sum << "\n";

		// 3
		std::cout << "\tЗадание 3\n";
		int dohod[12], month1 = 0, month2 = 0, Max = 0, Min = 0, monthMin = 0, monthMax = 0;
		std::cout << "Введите прибыль за год: ";
		for (size_t i = 0; i < 12; i++)
		{
			std::cout << "Month " << i + 1 << ": ";
			std::cin >> dohod[i];
		}
		std::cout << "Введите с какого месяца: ";
		std::cin >> month1;
		std::cout << "Введите до какого месяца: ";
		std::cin >> month2;
		if (month2 < month1)
		{
			std::cout << "\nНеккоректный ввод! \n\n";
			return 0;
		}
		else if (month1 == month2)
		{
			std::cout << "\nДиапазон слишком мал! \n\n";
			return 0;
		}

		for (size_t i = month1 - 1; i < month2 - 1; i++)
		{
			if (Min == 0 || Min > dohod[i])
			{
				Min = dohod[i];
				monthMin = i + 1;
			}
			if (Max < dohod[i])
			{
				Max = dohod[i];
				monthMax = i + 1;
			}
		}
		std::cout << "\n" << "Месяц с минимальной прибылью: " << monthMin << "\n";
		std::cout << "Месяц с максимальной прибылью: " << monthMax << "\n\n";

		// 4
		std::cout << "\tЗадание 4";
		int sales[3], salaries[3], sale = 0, salary = 0, best = 0, numberOfBest = 0;
		for (size_t i = 0; i < 3; i++)
		{
			std::cout << "\nВведите уровень продаж менеджера " << i + 1 << ": ";
			std::cin >> sale;
			sales[i] = sale;
			if (sales[i] < 500 && sales[i] > 0)
			{
				salary = 200 + (sales[i] / 100 * 3);
				salaries[i] = salary;
			}
			else if (sales[i] >= 500 && sales[i] <= 1000)
			{
				salary = 200 + (sales[i] / 100 * 5);
				salaries[i] = salary;
			}
			else if (sales[i] > 1000)
			{
				salary = 200 + (sales[i] / 100 * 8);
				salaries[i] = salary;
			}
			else
			{
				std::cout << "\nНекорректный ввод! \n\n";
			}
			if (salaries[i] > best)
			{
				best = salaries[i];
				numberOfBest = i + 1;
			}
		}
		best += 200;
		std::cout << "\n\nЛучший менеджер номер " << numberOfBest << ". Его зарплата: " << best << "$ \n\n";
		for (size_t i = 0; i < 3; i++)
		{
			if (i != (numberOfBest - 1))
			{
				std::cout << "Зарплата менеджера " << i + 1 << " = " << salaries[i] << "$ \n";
			}
		}
	}
	else if (dz == 2)
	{
		// 1
		while (true)
		{
			system("cls");

			std::cout << "\tЗадание 1\n";

			int day1, day2, month1, month2, year1, year2, result = 0;
			std::cout << "Введите первую дату\n";
			std::cout << "число: ";
			std::cin >> day1;
			if (day1 > 31 || day1 < 1)
			{
				std::cout << "Некорректный ввод дня!\n";
				Sleep(800);
				continue;
			}
			std::cout << "месяц: ";
			std::cin >> month1;
			if (month1 > 12 || month1 < 1)
			{
				std::cout << "Некорректный ввод месяца!\n";
				Sleep(800);
				continue;
			}
			std::cout << "год: ";
			std::cin >> year1;
			if (year1 < 1)
			{
				std::cout << "Некорректный ввод года!\n";
				Sleep(800);
				continue;
			}

			std::cout << "Введите вторую дату\n";
			std::cout << "число: ";
			std::cin >> day2;
			if (day2 > 31 || day2 < 1)
			{
				std::cout << "Некорректный ввод дня!\n";
				Sleep(800);
				continue;
			}
			std::cout << "месяц: ";
			std::cin >> month2;
			if (month2 > 12 || month2 < 1)
			{
				std::cout << "Некорректный ввод месяца!\n";
				Sleep(800);
				continue;
			}
			std::cout << "год: ";
			std::cin >> year2;
			if (year2 < 1)
			{
				std::cout << "Некорректный ввод года!\n";
				Sleep(800);
				continue;
			}

			Visokos(year1, year2);
			result = Raznost_of_days(day1, month1, year1, day2, month2, year2);
			std::cout << "Разность между датами составляет " << result << " дней\n\n";
			break;
		}

		// 2

		std::cout << "\tЗадание 2\n";

		int const size = 5;
		double number = 0;
		double arr[size];
		std::cout << "Введите 5 чисел: \n";
		for (int i = 0; i < size; i++)
		{
			std::cin >> number;
			std::cout << "\n";
			arr[i] = number;
		}
		std::cout << "\n Ваше среднее арифметическое: " << Arifmetich(size, arr) << "\n\n";

		// 3

		std::cout << "\tЗадание 3\n";

		double abc[size];
		double Number = 0;
		std::cout << "Введите 5 чисел: \n";
		for (int i = 0; i < size; i++)
		{
			std::cin >> Number;
			std::cout << "\n";
			abc[i] = Number;
		}
		What_znak(size, abc);


	}
	else
	{
		std::cout << "\nНу проверьте домашку пж( \n\n";
	}


	/*  // задание 1
	int number, symma1, symma2;
	char symvol1, symvol2, symvol3, symvol4, symvol5, symvol6 ;

	std::cout << "Введите целое шестизначное число: ";
	std::cin >> number;

	if (number < 1000000 && number > 99999)
	{
		symvol6 = number % 10;
		number = number / 10;
		symvol5 = number % 10;
		number = number / 10;
		symvol4 = number % 10;
		number = number / 10;
		symvol3 = number % 10;
		number = number / 10;
		symvol2 = number % 10;
		number = number / 10;
		symvol1 = number % 10;

		symma1 = symvol1 + symvol2 + symvol3;
		symma2 = symvol4 + symvol5 + symvol6;

		if (symma1 == symma2)
		{
			std::cout << "\nПоздравляем, ваше число счастливое!) \n\n";
		}
		else
		{
			std::cout << "\nСожалеем, ваше число не счастливое( \n\n";
		}
	}
	else
	{
		std::cout << "\nНекорректный ввод данных! Это не шестизначное число. \n\n";
	}

	// задание 2
	int number_;
	int symvol_1, symvol_2, symvol_3, symvol_4;

	std::cout << "Введите четырехзначное число: ";
	std::cin >> number_;

	if (number_ > 999 && number_ < 10000)
	{
		symvol_1 = number_ / 1000;
		symvol_2 = number_ / 100 % 10;
		symvol_3 = number_ / 10 % 10;
		symvol_4 = number_ % 10;

		std::cout << "\nВаше итоговое число: " << symvol_2 << symvol_1 << symvol_4 << symvol_3 << "\n\n";
	}
	else
	{
		std::cout << "\nНекорректный ввод данных! Это не четырехзначное число. \n\n";
	}

	// задание 3
	int b;
	int max;
	std::cout << "Введите 7 чисел: ";
	std::cin >> max;

	for (int i = 1; i < 7; i++)
	{
		std::cin >> b;
		if (b > max) {
			max = b;
		}
	}
	std::cout << "\n Максимальное число: " << max << "\n\n";


	/*
	// задание 1

	double S, speed, hours, t1, t2;

	std::cout << "Введите расстояние в км: ";
	std::cin >> S;
	std::cout << "Введите имеющееся время в часах и минутах: ";
	std::cin >> t1 >> t2;

	if (t2 > 59 || t2 < 0)
	{
		std::cout << "Некорректный ввод минут! \n\n\n";
		return 0;
	}
	else if (t1 != 0 || t2 != 0)
	{
		hours = t1 + t2 / 60;
		speed = S / hours;
		std::cout << "Нужная вам скорость = " << speed << " км/ч\n\n\n";
	}
	else
	{
		std::cout << "Некорректный ввод данных! \n\n\n";
	}


	// задание 2

	int t1_start, t2_start, t3_start, t1_finish, t2_finish, t3_finish, time_start, time_finish,time;
	double bill;

	std::cout << "Введите время начала использования скутера (в формате - час минута секунда): ";
	std::cin >> t1_start >> t2_start >> t3_start;
	std::cout << "Введите время конца использования скутера (в формате -  час минута секунда): ";
	std::cin >> t1_finish >> t2_finish >> t3_finish;

	time_start = t1_start * 3600 + t2_start * 60 + t3_start;
	time_finish = t1_finish * 3600 + t2_finish * 60 + t3_finish;
	time = time_finish - time_start;

	if (time_finish < time_start)
	{
		time = 24 * 3600 - time_start + time_finish;
	}
	if (time % 60 != 0)
	{
		time = time / 60 + 1;
	}
	else
	{
		time = time / 60;
	}

	bill = time * 2;
	std::cout << "Стоимость поездки составила " << bill << " гривен\n\n\n";


	// задание 3

	double s, toplivo, price1, price2, price3,result1,result2, result3, total;

	std::cout << "Введите расстояние в км: ";
	std::cin >> s;
	std::cout << "Введите расход бензина на 100 км: ";
	std::cin >> toplivo;
	std::cout << "Введите стоимость первого, второго и третьего бензина за литр: ";
	std::cin >> price1 >> price2 >> price3;

	if (s < 0 || toplivo < 0 || price1 < 0 || price2 < 0 || price3 < 0)
	{
		std::cout << "Некорректный ввод данных! \n\n\n";
		return 0;
	}

	total = s / 100 * toplivo;
	result1 = total * price1;
	result2 = total * price2;
	result3 = total * price3;


	std::cout << "\t\t\t Сравнительная таблица\n";
	std::cout << "\n==============================================================\n";
	std::cout << "\t\t Цена за литр \t Стоимость всей поездки \n";
	std::cout << "первый бензин\t" << price1 << "\t\t" << result1 << "\n";
	std::cout << "второй бензин\t" << price2 << "\t\t" << result2 << "\n";
	std::cout << "третий бензин\t" << price3 << "\t\t" << result3 << "\n";
	std::cout << "\n==============================================================\n";
	*/
	/*
	std::cout << " _______________________\n"
		<< "| < Happy New Year!)) > |\n"
		<< "|_______________________|\n\n";
	std::cout << "\t"
		<< "\\    " << "^__^\n"
		<< "\t \\   " << "(00)\\______\n"
		<< "\t     " << "(__)\\" << "\t" << ")\\/\\/" << "\n"
		<< "\t\t" << "| |" << "---W |\n"
		<< "\t\t" << "| |" << "    |" << "|";
	*/
	return 0;
}






