#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Project1 {

	/// <summary>
	/// MyUserControl �̊T�v
	/// </summary>
	public ref class MyUserControl : public System::Windows::Forms::UserControl
	{
	public:
		MyUserControl(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~MyUserControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::DomainUpDown^ domainUpDown1;
	private: System::Windows::Forms::ImageList^ imageList2;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->domainUpDown1 = (gcnew System::Windows::Forms::DomainUpDown());
			this->imageList2 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->SuspendLayout();
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// domainUpDown1
			// 
			this->domainUpDown1->Location = System::Drawing::Point(231, 110);
			this->domainUpDown1->Name = L"domainUpDown1";
			this->domainUpDown1->Size = System::Drawing::Size(120, 19);
			this->domainUpDown1->TabIndex = 0;
			this->domainUpDown1->Text = L"domainUpDown1";
			// 
			// imageList2
			// 
			this->imageList2->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList2->ImageSize = System::Drawing::Size(16, 16);
			this->imageList2->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// MyUserControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->domainUpDown1);
			this->Name = L"MyUserControl";
			this->Size = System::Drawing::Size(704, 379);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
