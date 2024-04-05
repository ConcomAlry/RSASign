#pragma once
#include <gmpxx.h>
#include <msclr/marshal_cppstd.h>
#include <Windows.h>
#include <stdexcept>
#include <locale>
#include <codecvt>
#include "Signature.h"
#pragma warning (disable : 2020)

namespace RSASign {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
#pragma region Элементы формы


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;


	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(23, 63);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(620, 152);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Ручной ввод";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(20, 96);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(594, 44);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Очистить поля ввода";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(186, 53);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(428, 27);
			this->textBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(16, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Введите q:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(186, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(428, 27);
			this->textBox1->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(103, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Введите р:";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(23, 21);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(137, 24);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Ручной ввод";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MyForm::checkBox1_CheckedChanged);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(23, 297);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(620, 521);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(23, 232);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(259, 44);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(375, 232);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(268, 44);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Очистить всё";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 873);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Генерация ЭЦП по алгоритму RSA";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		static bool isManualInput;

		private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) 
		{
			groupBox1->Enabled = false;
			isManualInput = false;
		}

		private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
		{
			groupBox1->Enabled = checkBox1->Checked;
			isManualInput = checkBox1->Checked;
		}
		
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			try {
				Signature mySignature;
				if (isManualInput)
				{
					mpz_class p, q;
					try {
						readMpzValue(textBox1->Text, p);
						readMpzValue(textBox2->Text, q);
					}
					catch (const std::exception& e) {
						ShowErrorMessage("Данные введены некорректно");
						return;
					}
					if (!isPrime(p, 25) || !isPrime(q, 25)) {
						ShowInfoMessage("Числа p и q должны быть простыми");
						return;
					}
					mySignature = Signature(p, q);
				}
				else
				{
					mySignature = Signature();
				}
				richTextBox1->Clear();
				richTextBox1->Text += "p = " + getString(mySignature.getPublicKey().getP()) + Environment::NewLine;
				richTextBox1->Text += "q = " + getString(mySignature.getPublicKey().getQ()) + Environment::NewLine;
				richTextBox1->Text += "n = " + getString(mySignature.getPublicKey().getN()) + Environment::NewLine;
				richTextBox1->Text += "gamma = " + getString(mySignature.getPrivateKey().getGamma()) + Environment::NewLine;
				richTextBox1->Text += "gamma1 = " + getString(mySignature.getPrivateKey().getGamma1()) + Environment::NewLine;
				richTextBox1->Text += "gamma2 = " + getString(mySignature.getPrivateKey().getGamma2()) + Environment::NewLine;
				richTextBox1->Text += "alpha = " + getString(mySignature.getPublicKey().getAlpha()) + Environment::NewLine;
				richTextBox1->Text += "alphaMod = " + getString(mySignature.getAlphPowGamMod()) + Environment::NewLine;
				richTextBox1->Text += "u = " + getString(mySignature.u) + Environment::NewLine;
				richTextBox1->Text += "z = " + getString(mySignature.z) + Environment::NewLine;
				richTextBox1->Text += "k = " + getString(mySignature.k) + Environment::NewLine;
				richTextBox1->Text += "g = " + getString(mySignature.g) + Environment::NewLine;
				richTextBox1->Text += "r = " + getString(mySignature.getR()) + Environment::NewLine;
				richTextBox1->Text += "s = " + getString(mySignature.getS()) + Environment::NewLine;
				richTextBox1->Text += "leftMod = " + getString(mySignature.leftMod) + Environment::NewLine;
				richTextBox1->Text += "rightMod = " + getString(mySignature.rightMod) + Environment::NewLine;
				richTextBox1->Text += "Проверочное уравнение: " + System::Convert::ToString(mySignature.getEquationIsValid()) + Environment::NewLine;
			}
			catch (const std::exception& e)
			{
				ShowErrorMessage("Не удалось подобрать gamma");
			}
		}				

		void readMpzValue(System::String^ textBoxText, mpz_class& result) {
			std::string str = msclr::interop::marshal_as<std::string>(textBoxText);
			result = mpz_class(str);
		}

		System::String^ getString(mpz_class mpzNum) 
		{
			std::string numberStr = mpzNum.get_str();
			System::String^ numberString = msclr::interop::marshal_as<System::String^>(numberStr);
			return numberString;
		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
			textBox1->Text = "";
			textBox2->Text = "";
			richTextBox1->Text = "";
		}

		void ShowErrorMessage(const std::exception& e) {
			const char* errorMessage = e.what();

			int length = MultiByteToWideChar(CP_UTF8, 0, errorMessage, -1, nullptr, 0);
			wchar_t* wideErrorMessage = new wchar_t[length];
			MultiByteToWideChar(CP_UTF8, 0, errorMessage, -1, wideErrorMessage, length);

			::MessageBoxW(nullptr, wideErrorMessage, L"Ошибка", MB_ICONERROR | MB_OK);

			delete[] wideErrorMessage;
		}

		void ShowErrorMessage(System::String^ customMessage) {
			pin_ptr<const wchar_t> pinnedMessage = PtrToStringChars(customMessage);
			::MessageBox(nullptr, pinnedMessage, L"Ошибка", MB_ICONERROR | MB_OK);
		}

		void ShowInfoMessage(System::String^ customMessage) {
			pin_ptr<const wchar_t> pinnedMessage = PtrToStringChars(customMessage);
			::MessageBox(nullptr, pinnedMessage, L"Справка", MB_ICONINFORMATION | MB_OK);
		}

		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			textBox1->Text = "";
			textBox2->Text = "";
		}

		static bool areCoprime(const mpz_class& a, const mpz_class& b) {
			mpz_class gcd_result;
			mpz_gcd(gcd_result.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());

			return gcd_result == 1;
		}

		bool isPrime(const mpz_class& n, int iterations) {
			if (iterations == 0) {
				iterations = 25; 
			}
			return mpz_probab_prime_p(n.get_mpz_t(), iterations) != 0;
		}
	};
}
