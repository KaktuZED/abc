#include <ctime>
#include <fstream>
#include <Windows.h>
#include <string>
#include "VectorLibrary.h"
#pragma warning(disable : 4996)
using namespace std;
using namespace VectorFuns;
Vector vect[10];

HANDLE out;
HANDLE hSemaphore;
HANDLE hThread;

DWORD WINAPI Sort(LPVOID N) {
	char buff[11];
	for (int i = 0; i < 10; i++) {
		for (int j = (10 - 1); j >= (i + 1); j--) {
			if (vect[(int)N].show(j) < vect[(int)N].show(j - 1)) {
				vect[(int)N].swap(j, j - 1);
			}
		}
	}
	for (int i = 0; i < 10; i++)
		buff[i] = vect[(int)N].show(i);
	buff[10] = '\n';
	WriteFile(out, buff, 11, NULL, NULL);
	ReleaseSemaphore(hSemaphore, 1, NULL);
	return 0;
}

namespace Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 1);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(382, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ФИО: Аверкина Анастасия Максимовна";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(3, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Группа: 501";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(623, 5);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 25);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Дата:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(623, 39);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Время: ";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(851, 70);
			this->panel1->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Linen;
			this->panel2->Controls->Add(this->dataGridView1);
			this->panel2->Location = System::Drawing::Point(0, 67);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(851, 349);
			this->panel2->TabIndex = 5;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Location = System::Drawing::Point(67, 9);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 62;
			this->dataGridView1->RowTemplate->Height = 28;
			this->dataGridView1->Size = System::Drawing::Size(728, 314);
			this->dataGridView1->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->button1);
			this->panel3->Location = System::Drawing::Point(0, 415);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(851, 148);
			this->panel3->TabIndex = 6;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(486, 31);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 25);
			this->label6->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label5->Location = System::Drawing::Point(39, 31);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 25);
			this->label5->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(486, 58);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(351, 65);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Отсортировать данные по возростанию и сохранить результат в файл";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(43, 58);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(182, 65);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Загрузить данные из исходного файла";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(849, 550);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
		time_t now = time(0);
		tm* date_time = localtime(&now);
		label3->Text += "      " + date_time->tm_mday + "." + (1 + date_time->tm_mon) + "." + (date_time->tm_year + 1900);
		label4->Text += "   " + date_time->tm_hour + ":" + date_time->tm_min + ":" + date_time->tm_sec;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		ifstream in("input.txt");
		dataGridView1->ColumnCount = 10;
		dataGridView1->RowCount = 10;
			if (in.is_open()) {
				char ch;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < 10; j++) {
						in.get(ch);
						vect[i].push_back(ch);
						dataGridView1->Rows[i]->Cells[j]->Value = ((wchar_t)ch).ToString();
					}
				}
				label5->Text = "Данные успешно загружены";
				in.close();
			}
			else {
				label5->Text = "Ошибка! Не удалось открыть файл";
			}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	out = CreateFile(L"output.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_READONLY, NULL);
	if (out == INVALID_HANDLE_VALUE)
		label6->Text = "Не удалось создать файл";
	else {
		hSemaphore = CreateSemaphore(NULL, 0, 10, NULL);
		for (int i = 0; i < 10; i++) {
			hThread = CreateThread(NULL, 0, Sort, (LPVOID)i, 0, NULL);
			WaitForSingleObject(hSemaphore, INFINITE);
		}
		dataGridView1->ColumnCount = 10;
		dataGridView1->RowCount = 10;
		char ch;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				dataGridView1->Rows[i]->Cells[j]->Value = ((wchar_t)vect[i].show(j)).ToString();
			}
		}
		CloseHandle(out);
		label6->Text = "Результат сохранен в файл";
	}
}
};
}
