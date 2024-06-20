#pragma once

#include "LexerParser.hpp"
#include <msclr/marshal_cppstd.h>
#include <sstream>

namespace StreamTokenizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	public ref class MainWindow : public System::Windows::Forms::Form
	{
	public:
		MainWindow(void)
		{
			InitializeComponent();
			this->confirmButton->Click += gcnew System::EventHandler(this, &MainWindow::confirmButton_Click);
			this->clearButton->Click += gcnew System::EventHandler(this, &MainWindow::clearButton_Click);
		}

	protected:
		~MainWindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ labelInputString;
	private: System::Windows::Forms::Label^ labelOutputString;
	private: System::Windows::Forms::TextBox^ inputString;
	private: System::Windows::Forms::Label^ outputString;
	private: System::Windows::Forms::Label^ labelToken;

	private: System::Windows::Forms::Button^ confirmButton;
	private: System::Windows::Forms::Button^ clearButton;
	private: System::Windows::Forms::RichTextBox^ outputTokens;



	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->labelInputString = (gcnew System::Windows::Forms::Label());
			this->labelOutputString = (gcnew System::Windows::Forms::Label());
			this->inputString = (gcnew System::Windows::Forms::TextBox());
			this->outputString = (gcnew System::Windows::Forms::Label());
			this->labelToken = (gcnew System::Windows::Forms::Label());
			this->confirmButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->outputTokens = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// labelInputString
			// 
			this->labelInputString->AutoSize = true;
			this->labelInputString->ForeColor = System::Drawing::SystemColors::ControlText;
			this->labelInputString->Location = System::Drawing::Point(15, 10);
			this->labelInputString->Margin = System::Windows::Forms::Padding(10, 10, 3, 0);
			this->labelInputString->MaximumSize = System::Drawing::Size(140, 30);
			this->labelInputString->MinimumSize = System::Drawing::Size(140, 30);
			this->labelInputString->Name = L"labelInputString";
			this->labelInputString->Size = System::Drawing::Size(140, 30);
			this->labelInputString->TabIndex = 0;
			this->labelInputString->Text = L"Enter std::cout instruction";
			this->labelInputString->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelOutputString
			// 
			this->labelOutputString->AutoSize = true;
			this->labelOutputString->Location = System::Drawing::Point(12, 55);
			this->labelOutputString->MaximumSize = System::Drawing::Size(140, 30);
			this->labelOutputString->MinimumSize = System::Drawing::Size(140, 30);
			this->labelOutputString->Name = L"labelOutputString";
			this->labelOutputString->Size = System::Drawing::Size(140, 30);
			this->labelOutputString->TabIndex = 1;
			this->labelOutputString->Text = L"Post-analysis instruction";
			// 
			// inputString
			// 
			this->inputString->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->inputString->Location = System::Drawing::Point(159, 16);
			this->inputString->MaximumSize = System::Drawing::Size(16777215, 16777215);
			this->inputString->MinimumSize = System::Drawing::Size(250, 30);
			this->inputString->Name = L"inputString";
			this->inputString->Size = System::Drawing::Size(250, 30);
			this->inputString->TabIndex = 2;
			// 
			// outputString
			// 
			this->outputString->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->outputString->AutoSize = true;
			this->outputString->Location = System::Drawing::Point(159, 55);
			this->outputString->MaximumSize = System::Drawing::Size(16777215, 16777215);
			this->outputString->MinimumSize = System::Drawing::Size(250, 30);
			this->outputString->Name = L"outputString";
			this->outputString->Size = System::Drawing::Size(250, 30);
			this->outputString->TabIndex = 3;
			// 
			// labelToken
			// 
			this->labelToken->AutoSize = true;
			this->labelToken->Location = System::Drawing::Point(15, 89);
			this->labelToken->Name = L"labelToken";
			this->labelToken->Size = System::Drawing::Size(43, 13);
			this->labelToken->TabIndex = 4;
			this->labelToken->Text = L"Tokens";
			// 
			// confirmButton
			// 
			this->confirmButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->confirmButton->Location = System::Drawing::Point(12, 299);
			this->confirmButton->MinimumSize = System::Drawing::Size(50, 30);
			this->confirmButton->Name = L"confirmButton";
			this->confirmButton->Size = System::Drawing::Size(75, 30);
			this->confirmButton->TabIndex = 6;
			this->confirmButton->Text = L"Confirm";
			this->confirmButton->UseVisualStyleBackColor = true;
			// 
			// clearButton
			// 
			this->clearButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->clearButton->Location = System::Drawing::Point(334, 299);
			this->clearButton->MinimumSize = System::Drawing::Size(50, 30);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(75, 30);
			this->clearButton->TabIndex = 7;
			this->clearButton->Text = L"Clear";
			this->clearButton->UseVisualStyleBackColor = true;
			// 
			// outputTokens
			// 
			this->outputTokens->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->outputTokens->Location = System::Drawing::Point(159, 89);
			this->outputTokens->MinimumSize = System::Drawing::Size(240, 180);
			this->outputTokens->Name = L"outputTokens";
			this->outputTokens->ReadOnly = true;
			this->outputTokens->Size = System::Drawing::Size(240, 180);
			this->outputTokens->TabIndex = 8;
			this->outputTokens->Text = L"";
			this->outputTokens->TextChanged += gcnew System::EventHandler(this, &MainWindow::richTextBox1_TextChanged);
			// 
			// MainWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(424, 361);
			this->Controls->Add(this->outputTokens);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->confirmButton);
			this->Controls->Add(this->labelToken);
			this->Controls->Add(this->outputString);
			this->Controls->Add(this->inputString);
			this->Controls->Add(this->labelOutputString);
			this->Controls->Add(this->labelInputString);
			this->MinimumSize = System::Drawing::Size(440, 400);
			this->Name = L"MainWindow";
			this->Text = L"Stream tokenizer";
			this->Load += gcnew System::EventHandler(this, &MainWindow::MainWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void MainWindow_Load(System::Object^ sender, System::EventArgs^ e) {
		}

		System::Void richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}

		System::Void confirmButton_Click(System::Object^ sender, System::EventArgs^ e) {
			try {
				std::string input = marshal_as<std::string>(inputString->Text);

				std::list<token> tokens = lexer(input);
				parser(tokens);

				std::ostringstream outputTokensStream;
				for (const auto& t : tokens) {
					switch (t.type) {
					case fn_name: outputTokensStream << "Function name\t"; break;
					case str: outputTokensStream << "String\t\t"; break;
					case ident: outputTokensStream << "Identifier\t\t"; break;
					case output_op: outputTokensStream << "Output operator\t"; break;
					case end: outputTokensStream << "End of statement\t"; break;
					default: outputTokensStream << "Unknown\t\t"; break;
					}
					outputTokensStream << t.value << std::endl;
				}

				outputString->Text = gcnew String("Analysis successful");
				outputTokens->Text = gcnew String(outputTokensStream.str().c_str());
			}
			catch (const std::exception& e) {
				outputString->Text = gcnew String("Error: ");
				outputString->Text += gcnew String(e.what());
				outputTokens->Text = "";
			}
		}

		System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) {
			inputString->Clear();
			outputString->Text = "";
			outputTokens->Text = "";
		}
	};
}