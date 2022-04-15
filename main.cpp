#include <iostream>
#include <fstream> // работы с файлами
#include <string>
#include <windows.h>

using namespace std;

// прототип функции
void mostRecent(char* text, char* word);

int main() {
	char text[1000] = ""; // массив символов (текст)
	char word[30] = ""; // само часто встречающееся слово в тексте
	
	cout << "privet" << "\n";

	bool exit = false;
	
	while(!exit)
	{
		char choice;
		cout << "ВВОДИТЬ ТОЛЬКО АНГЛИЙСКИЙ ТЕКСТ!!!!\nВыберите откуда взять текст:\n1) Из файла;\n2) Написать в консоли;\n";	
		cin >> choice;
		switch(choice){
		    case('1'):{
		        //работа с файлом
				ifstream fin("text.txt");
				if(!fin.is_open()){ //если файл не открыт вывести сообщение об ошыбке
					cout << "error\n";
					break;
				}
				fin.getline(text, 1000);
				fin.close(); // закрытие файла
				exit = true;
				break;
			}	
	    	case('2'):{
	    		cin.ignore();
	        	cin.getline(text, 1000);
	        	exit = true;
	        	break;
	        }
	        default:{
				break;
			}
		}
	}
	//Возведение текста в верхний регистр
	strcpy(text, strupr(text));
	
	mostRecent(text, word);
	system("pause");
	return 0;
 
void mostRecent(char* text, char* word) { // передаем текст, переменную в которую поместим слово 

	int word_count = 0;//кол-во слов в тексте
	char *words[1000] = {};//массив слов
	words[0] = strtok(text, ".?-,!:;/<>\\| "); // первое слово
	
	int count_max = 0, current_count = 1; //наибольшее количество слов, текущее количество слов
	int index = 0;

	//пока слова не закончились в тексте
	while (words[word_count] != NULL) {
		word_count++;//кол-во слов увеличить на один
		words[word_count] = strtok(NULL, ".?-,!:;/<>\\| ");//добавляем новое слово в массив
	}
	
	// вывод слов массива
	for (int i = 0; i < word_count; i++) {
		cout << words[i] << " ";
	}
	cout << endl;

	// проходим по массиву слов и сравниваем текущее со следующими 
	for (int i = 0; i < word_count; i++) {
		// берём следущее слово чтобы не сравнивать одно и тоже слово
		for (int j = i + 1; j < word_count; j++) {
			if (strcmp(words[i], words[j]) == 0) { // если слова равны то счетчик текущих слов увеличиваем
				current_count++;
			}
			
		}
		if (count_max < current_count) { // если максимальное кол-во слов меньше текущего то макс равно текущему
			count_max = current_count;
			index = i; // запоминаем индекс макс
		}
		current_count = 1; // обнуляем счетчик текущих слов
	}
		
	cout << "Самое встречающееся слово: " << words[index] << "\nВстречается: " << count_max << " \n";
	strcpy(word, words[index]); // присваиваем переменной word само часто встречающееся слово
} 
