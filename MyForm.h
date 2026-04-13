#pragma once
#include "Maze.h"

namespace GUILabyrinthProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Maze* nativeMaze;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			nativeMaze = new Maze();
		
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (nativeMaze)
			{
				delete nativeMaze;
				nativeMaze = nullptr;
			}
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::PrintPreviewDialog^ printPreviewDialog1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::PictureBox^ MazeBox1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->printPreviewDialog1 = (gcnew System::Windows::Forms::PrintPreviewDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->MazeBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MazeBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// printPreviewDialog1
			// 
			this->printPreviewDialog1->AutoScrollMargin = System::Drawing::Size(0, 0);
			this->printPreviewDialog1->AutoScrollMinSize = System::Drawing::Size(0, 0);
			this->printPreviewDialog1->ClientSize = System::Drawing::Size(400, 300);
			this->printPreviewDialog1->Enabled = true;
			this->printPreviewDialog1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"printPreviewDialog1.Icon")));
			this->printPreviewDialog1->Name = L"printPreviewDialog1";
			this->printPreviewDialog1->Visible = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 530);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(42, 21);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Easy";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(61, 530);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(55, 20);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Medium";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left);
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(122, 531);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(48, 19);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Hard";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left);
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_click);
			// 
			// MazeBox1
			// 
			this->MazeBox1->BackColor = System::Drawing::Color::White;
			this->MazeBox1->Location = System::Drawing::Point(18, 16);
			this->MazeBox1->Name = L"MazeBox1";
			this->MazeBox1->Size = System::Drawing::Size(450, 450);
			this->MazeBox1->TabIndex = 3;
			this->MazeBox1->TabStop = false;
			this->MazeBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MazeBox1_Paint);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->MazeBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->MazeBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
				System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(670, 556);
			this->Controls->Add(this->MazeBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->MazeBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int height = 15, width = 15;
		nativeMaze->Random_Gen(height, width);
		this->MazeBox1->Invalidate();
	}
	private: System::Void button2_click(System::Object^ sender, System::EventArgs^ e) {
		int height = 25, width = 25;
		nativeMaze->Random_Gen(height, width);
		this->MazeBox1->Invalidate();
	}
	private: System::Void button3_click(System::Object^ sender, System::EventArgs^ e) {
		int height = 35, width = 35;
		nativeMaze->Random_Gen(height, width);
		this->MazeBox1->Invalidate();
	}

	private : System::Void MazeBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;

		int rows = nativeMaze->getMazeHeight();
		int cols = nativeMaze->getMazeWidth();

		if (rows <= 0 || cols <= 0) {
			return; // No maze to draw
		}

		float cellWidth = (float)(MazeBox1->Width) / cols;
		float cellHeight = (float)(MazeBox1->Height) / rows;

		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				int val = nativeMaze->getMapArrayValue(i, j);
				System::Drawing::Brush^ brush = System::Drawing::Brushes::White;
				if (val == 1) {
					brush = System::Drawing::Brushes::Black;
				}
				else if (val == 2) {
					brush = System::Drawing::Brushes::Blue;
				}
				else if (val == 3) {
					brush = System::Drawing::Brushes::Gold;
				}
				

				System::Drawing::RectangleF rect(j * cellWidth, i * cellHeight, cellWidth, cellHeight);
				g->FillRectangle(brush, rect);
				g->DrawRectangle(System::Drawing::Pens::Black, rect.X, rect.Y, rect.Width, rect.Height);
			}
		}
	}
	};
}
