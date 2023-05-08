#pragma once

namespace SMAsgCompiler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PathSelector
	/// </summary>
	public ref class PathSelector : public System::Windows::Forms::Form
	{
	public:
		bool is_ready = false;
		PathSelector(void);

	protected:
		~PathSelector();

	private:
		System::Windows::Forms::TextBox^ tb_selected_path;
		System::Windows::Forms::TextBox^ tb_texture_name;
		System::Windows::Forms::GroupBox^ gb_out_tex_name;
		System::Windows::Forms::Button^ btn_convert;
		System::Windows::Forms::Button^ btn_select_path;
		System::Windows::Forms::GroupBox^ gb_tex_out_path;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb_selected_path = (gcnew System::Windows::Forms::TextBox());
			this->btn_convert = (gcnew System::Windows::Forms::Button());
			this->btn_select_path = (gcnew System::Windows::Forms::Button());
			this->gb_tex_out_path = (gcnew System::Windows::Forms::GroupBox());
			this->tb_texture_name = (gcnew System::Windows::Forms::TextBox());
			this->gb_out_tex_name = (gcnew System::Windows::Forms::GroupBox());
			this->gb_tex_out_path->SuspendLayout();
			this->gb_out_tex_name->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb_selected_path
			// 
			this->tb_selected_path->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tb_selected_path->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->tb_selected_path->Location = System::Drawing::Point(6, 19);
			this->tb_selected_path->Name = L"tb_selected_path";
			this->tb_selected_path->Size = System::Drawing::Size(240, 22);
			this->tb_selected_path->TabIndex = 0;
			this->tb_selected_path->TextChanged += gcnew System::EventHandler(this, &PathSelector::tb_selected_path_TextChanged);
			// 
			// btn_convert
			// 
			this->btn_convert->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_convert->Enabled = false;
			this->btn_convert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->btn_convert->Location = System::Drawing::Point(222, 118);
			this->btn_convert->Name = L"btn_convert";
			this->btn_convert->Size = System::Drawing::Size(100, 35);
			this->btn_convert->TabIndex = 1;
			this->btn_convert->Text = L"Convert";
			this->btn_convert->UseVisualStyleBackColor = true;
			this->btn_convert->Click += gcnew System::EventHandler(this, &PathSelector::btn_convert_Click);
			// 
			// btn_select_path
			// 
			this->btn_select_path->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_select_path->Location = System::Drawing::Point(252, 19);
			this->btn_select_path->Name = L"btn_select_path";
			this->btn_select_path->Size = System::Drawing::Size(52, 22);
			this->btn_select_path->TabIndex = 2;
			this->btn_select_path->Text = L",,,";
			this->btn_select_path->UseVisualStyleBackColor = true;
			this->btn_select_path->Click += gcnew System::EventHandler(this, &PathSelector::btn_select_path_Click);
			// 
			// gb_tex_out_path
			// 
			this->gb_tex_out_path->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gb_tex_out_path->Controls->Add(this->tb_selected_path);
			this->gb_tex_out_path->Controls->Add(this->btn_select_path);
			this->gb_tex_out_path->Location = System::Drawing::Point(12, 65);
			this->gb_tex_out_path->Name = L"gb_tex_out_path";
			this->gb_tex_out_path->Size = System::Drawing::Size(310, 47);
			this->gb_tex_out_path->TabIndex = 3;
			this->gb_tex_out_path->TabStop = false;
			this->gb_tex_out_path->Text = L"Texture Output Path";
			// 
			// tb_texture_name
			// 
			this->tb_texture_name->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tb_texture_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->tb_texture_name->Location = System::Drawing::Point(6, 19);
			this->tb_texture_name->MaxLength = 64;
			this->tb_texture_name->Name = L"tb_texture_name";
			this->tb_texture_name->Size = System::Drawing::Size(298, 22);
			this->tb_texture_name->TabIndex = 4;
			this->tb_texture_name->TextChanged += gcnew System::EventHandler(this, &PathSelector::tb_texture_name_TextChanged);
			// 
			// gb_out_tex_name
			// 
			this->gb_out_tex_name->Controls->Add(this->tb_texture_name);
			this->gb_out_tex_name->Location = System::Drawing::Point(12, 12);
			this->gb_out_tex_name->Name = L"gb_out_tex_name";
			this->gb_out_tex_name->Size = System::Drawing::Size(310, 47);
			this->gb_out_tex_name->TabIndex = 5;
			this->gb_out_tex_name->TabStop = false;
			this->gb_out_tex_name->Text = L"Output Texture Name";
			// 
			// PathSelector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(334, 165);
			this->Controls->Add(this->gb_out_tex_name);
			this->Controls->Add(this->gb_tex_out_path);
			this->Controls->Add(this->btn_convert);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PathSelector";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->Text = L"Select Path";
			this->gb_tex_out_path->ResumeLayout(false);
			this->gb_tex_out_path->PerformLayout();
			this->gb_out_tex_name->ResumeLayout(false);
			this->gb_out_tex_name->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		System::Void btn_select_path_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void tb_selected_path_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void tb_texture_name_TextChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_convert_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
