#include <iostream>
#include <fstream> // ������ � �������
#include <string>
#include <windows.h>

using namespace std;

// �������� �������
void mostRecent(char* text, char* word);

int main() {
	char text[1000] = ""; // ������ �������� (�����)
	char word[30] = ""; // ���� ����� ������������� ����� � ������
	
	cout << "privet" << "\n";

	bool exit = false;
	
	while(!exit)
	{
		char choice;
		cout << "������� ������ ���������� �����!!!!\n�������� ������ ����� �����:\n1) �� �����;\n2) �������� � �������;\n";	
		cin >> choice;
		switch(choice){
		    case('1'):{
		        //������ � ������
				ifstream fin("text.txt");
				if(!fin.is_open()){ //���� ���� �� ������ ������� ��������� �� ������
					cout << "error\n";
					break;
				}
				fin.getline(text, 1000);
				fin.close(); // �������� �����
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
	//���������� ������ � ������� �������
	strcpy(text, strupr(text));
	
	mostRecent(text, word);
	system("pause");
	return 0;
 
void mostRecent(char* text, char* word) { // �������� �����, ���������� � ������� �������� ����� 

	int word_count = 0;//���-�� ���� � ������
	char *words[1000] = {};//������ ����
	words[0] = strtok(text, ".?-,!:;/<>\\| "); // ������ �����
	
	int count_max = 0, current_count = 1; //���������� ���������� ����, ������� ���������� ����
	int index = 0;

	//���� ����� �� ����������� � ������
	while (words[word_count] != NULL) {
		word_count++;//���-�� ���� ��������� �� ����
		words[word_count] = strtok(NULL, ".?-,!:;/<>\\| ");//��������� ����� ����� � ������
	}
	
	// ����� ���� �������
	for (int i = 0; i < word_count; i++) {
		cout << words[i] << " ";
	}
	cout << endl;

	// �������� �� ������� ���� � ���������� ������� �� ���������� 
	for (int i = 0; i < word_count; i++) {
		// ���� �������� ����� ����� �� ���������� ���� � ���� �����
		for (int j = i + 1; j < word_count; j++) {
			if (strcmp(words[i], words[j]) == 0) { // ���� ����� ����� �� ������� ������� ���� �����������
				current_count++;
			}
			
		}
		if (count_max < current_count) { // ���� ������������ ���-�� ���� ������ �������� �� ���� ����� ��������
			count_max = current_count;
			index = i; // ���������� ������ ����
		}
		current_count = 1; // �������� ������� ������� ����
	}
		
	cout << "����� ������������� �����: " << words[index] << "\n�����������: " << count_max << " \n";
	strcpy(word, words[index]); // ����������� ���������� word ���� ����� ������������� �����
} 
