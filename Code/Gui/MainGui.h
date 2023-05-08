#pragma once

namespace SMAsgCompiler {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainGui
	/// </summary>
	public ref class MainGui : public System::Windows::Forms::Form
	{
	public:
		MainGui(void);

	protected:
		~MainGui();

	private: System::Windows::Forms::TextBox^ tb_alpha_mask_path;
	private: System::Windows::Forms::TextBox^ tb_specular_map;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^ tb_glow_map;
	private: System::Windows::Forms::TextBox^ tb_reflectivity_map;


	private: System::Windows::Forms::Button^ btn_alpha_mask_search;
	private: System::Windows::Forms::Button^ btn_specular_map_search;
	private: System::Windows::Forms::Button^ btn_glow_map;



	private: System::Windows::Forms::Button^ btn_reflectivity_map;


	private: System::Windows::Forms::CheckBox^ cb_alpha_mask;
	private: System::Windows::Forms::CheckBox^ cb_specular_map;
	private: System::Windows::Forms::CheckBox^ cb_glow_map;
	private: System::Windows::Forms::CheckBox^ cb_reflectivity_map;



	private: System::Windows::Forms::GroupBox^ gb_alpha_mask;
	private: System::Windows::Forms::GroupBox^ gb_specular_map;
	private: System::Windows::Forms::GroupBox^ gb_glow_map;
	private: System::Windows::Forms::GroupBox^ gb_reflectivity_map;
	private: System::Windows::Forms::Button^ btn_convert;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tb_alpha_mask_path = (gcnew System::Windows::Forms::TextBox());
			this->tb_specular_map = (gcnew System::Windows::Forms::TextBox());
			this->tb_glow_map = (gcnew System::Windows::Forms::TextBox());
			this->tb_reflectivity_map = (gcnew System::Windows::Forms::TextBox());
			this->btn_alpha_mask_search = (gcnew System::Windows::Forms::Button());
			this->btn_specular_map_search = (gcnew System::Windows::Forms::Button());
			this->btn_glow_map = (gcnew System::Windows::Forms::Button());
			this->btn_reflectivity_map = (gcnew System::Windows::Forms::Button());
			this->cb_alpha_mask = (gcnew System::Windows::Forms::CheckBox());
			this->cb_specular_map = (gcnew System::Windows::Forms::CheckBox());
			this->cb_glow_map = (gcnew System::Windows::Forms::CheckBox());
			this->cb_reflectivity_map = (gcnew System::Windows::Forms::CheckBox());
			this->gb_alpha_mask = (gcnew System::Windows::Forms::GroupBox());
			this->gb_specular_map = (gcnew System::Windows::Forms::GroupBox());
			this->gb_glow_map = (gcnew System::Windows::Forms::GroupBox());
			this->gb_reflectivity_map = (gcnew System::Windows::Forms::GroupBox());
			this->btn_convert = (gcnew System::Windows::Forms::Button());
			this->gb_alpha_mask->SuspendLayout();
			this->gb_specular_map->SuspendLayout();
			this->gb_glow_map->SuspendLayout();
			this->gb_reflectivity_map->SuspendLayout();
			this->SuspendLayout();
			// 
			// tb_alpha_mask_path
			// 
			this->tb_alpha_mask_path->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tb_alpha_mask_path->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->tb_alpha_mask_path->Location = System::Drawing::Point(6, 19);
			this->tb_alpha_mask_path->Name = L"tb_alpha_mask_path";
			this->tb_alpha_mask_path->Size = System::Drawing::Size(416, 22);
			this->tb_alpha_mask_path->TabIndex = 0;
			// 
			// tb_specular_map
			// 
			this->tb_specular_map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tb_specular_map->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->tb_specular_map->Location = System::Drawing::Point(6, 19);
			this->tb_specular_map->Name = L"tb_specular_map";
			this->tb_specular_map->Size = System::Drawing::Size(416, 22);
			this->tb_specular_map->TabIndex = 1;
			// 
			// tb_glow_map
			// 
			this->tb_glow_map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tb_glow_map->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->tb_glow_map->Location = System::Drawing::Point(6, 19);
			this->tb_glow_map->Name = L"tb_glow_map";
			this->tb_glow_map->Size = System::Drawing::Size(416, 22);
			this->tb_glow_map->TabIndex = 2;
			// 
			// tb_reflectivity_map
			// 
			this->tb_reflectivity_map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tb_reflectivity_map->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->tb_reflectivity_map->Location = System::Drawing::Point(6, 19);
			this->tb_reflectivity_map->Name = L"tb_reflectivity_map";
			this->tb_reflectivity_map->Size = System::Drawing::Size(416, 22);
			this->tb_reflectivity_map->TabIndex = 3;
			// 
			// btn_alpha_mask_search
			// 
			this->btn_alpha_mask_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_alpha_mask_search->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->btn_alpha_mask_search->Location = System::Drawing::Point(428, 19);
			this->btn_alpha_mask_search->Name = L"btn_alpha_mask_search";
			this->btn_alpha_mask_search->Size = System::Drawing::Size(44, 22);
			this->btn_alpha_mask_search->TabIndex = 4;
			this->btn_alpha_mask_search->Text = L"...";
			this->btn_alpha_mask_search->UseVisualStyleBackColor = true;
			this->btn_alpha_mask_search->Click += gcnew System::EventHandler(this, &MainGui::btn_alpha_mask_search_Click);
			// 
			// btn_specular_map_search
			// 
			this->btn_specular_map_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_specular_map_search->Location = System::Drawing::Point(428, 19);
			this->btn_specular_map_search->Name = L"btn_specular_map_search";
			this->btn_specular_map_search->Size = System::Drawing::Size(44, 22);
			this->btn_specular_map_search->TabIndex = 5;
			this->btn_specular_map_search->Text = L"...";
			this->btn_specular_map_search->UseVisualStyleBackColor = true;
			this->btn_specular_map_search->Click += gcnew System::EventHandler(this, &MainGui::btn_specular_map_search_Click);
			// 
			// btn_glow_map
			// 
			this->btn_glow_map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_glow_map->Location = System::Drawing::Point(428, 19);
			this->btn_glow_map->Name = L"btn_glow_map";
			this->btn_glow_map->Size = System::Drawing::Size(44, 22);
			this->btn_glow_map->TabIndex = 6;
			this->btn_glow_map->Text = L"...";
			this->btn_glow_map->UseVisualStyleBackColor = true;
			this->btn_glow_map->Click += gcnew System::EventHandler(this, &MainGui::btn_glow_map_Click);
			// 
			// btn_reflectivity_map
			// 
			this->btn_reflectivity_map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btn_reflectivity_map->Location = System::Drawing::Point(428, 19);
			this->btn_reflectivity_map->Name = L"btn_reflectivity_map";
			this->btn_reflectivity_map->Size = System::Drawing::Size(44, 22);
			this->btn_reflectivity_map->TabIndex = 7;
			this->btn_reflectivity_map->Text = L"...";
			this->btn_reflectivity_map->UseVisualStyleBackColor = true;
			this->btn_reflectivity_map->Click += gcnew System::EventHandler(this, &MainGui::btn_reflectivity_map_Click);
			// 
			// cb_alpha_mask
			// 
			this->cb_alpha_mask->AutoSize = true;
			this->cb_alpha_mask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->cb_alpha_mask->Location = System::Drawing::Point(6, 47);
			this->cb_alpha_mask->Name = L"cb_alpha_mask";
			this->cb_alpha_mask->Size = System::Drawing::Size(151, 20);
			this->cb_alpha_mask->TabIndex = 8;
			this->cb_alpha_mask->Text = L"Alpha Mask Enabled";
			this->cb_alpha_mask->UseVisualStyleBackColor = true;
			this->cb_alpha_mask->CheckedChanged += gcnew System::EventHandler(this, &MainGui::cb_alpha_mask_CheckedChanged);
			// 
			// cb_specular_map
			// 
			this->cb_specular_map->AutoSize = true;
			this->cb_specular_map->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->cb_specular_map->Location = System::Drawing::Point(6, 47);
			this->cb_specular_map->Name = L"cb_specular_map";
			this->cb_specular_map->Size = System::Drawing::Size(164, 20);
			this->cb_specular_map->TabIndex = 9;
			this->cb_specular_map->Text = L"Specular Map Enabled";
			this->cb_specular_map->UseVisualStyleBackColor = true;
			this->cb_specular_map->CheckedChanged += gcnew System::EventHandler(this, &MainGui::cb_specular_map_CheckedChanged);
			// 
			// cb_glow_map
			// 
			this->cb_glow_map->AutoSize = true;
			this->cb_glow_map->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->cb_glow_map->Location = System::Drawing::Point(6, 47);
			this->cb_glow_map->Name = L"cb_glow_map";
			this->cb_glow_map->Size = System::Drawing::Size(140, 20);
			this->cb_glow_map->TabIndex = 10;
			this->cb_glow_map->Text = L"Glow Map Enabled";
			this->cb_glow_map->UseVisualStyleBackColor = true;
			this->cb_glow_map->CheckedChanged += gcnew System::EventHandler(this, &MainGui::cb_glow_map_CheckedChanged);
			// 
			// cb_reflectivity_map
			// 
			this->cb_reflectivity_map->AutoSize = true;
			this->cb_reflectivity_map->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->cb_reflectivity_map->Location = System::Drawing::Point(6, 47);
			this->cb_reflectivity_map->Name = L"cb_reflectivity_map";
			this->cb_reflectivity_map->Size = System::Drawing::Size(175, 20);
			this->cb_reflectivity_map->TabIndex = 11;
			this->cb_reflectivity_map->Text = L"Reflectivity Map Enabled";
			this->cb_reflectivity_map->UseVisualStyleBackColor = true;
			this->cb_reflectivity_map->CheckedChanged += gcnew System::EventHandler(this, &MainGui::cb_reflectivity_map_CheckedChanged);
			// 
			// gb_alpha_mask
			// 
			this->gb_alpha_mask->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gb_alpha_mask->Controls->Add(this->tb_alpha_mask_path);
			this->gb_alpha_mask->Controls->Add(this->cb_alpha_mask);
			this->gb_alpha_mask->Controls->Add(this->btn_alpha_mask_search);
			this->gb_alpha_mask->Location = System::Drawing::Point(12, 12);
			this->gb_alpha_mask->Name = L"gb_alpha_mask";
			this->gb_alpha_mask->Size = System::Drawing::Size(478, 75);
			this->gb_alpha_mask->TabIndex = 12;
			this->gb_alpha_mask->TabStop = false;
			this->gb_alpha_mask->Text = L"Alpha Mask (R Channel)";
			// 
			// gb_specular_map
			// 
			this->gb_specular_map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gb_specular_map->Controls->Add(this->tb_specular_map);
			this->gb_specular_map->Controls->Add(this->cb_specular_map);
			this->gb_specular_map->Controls->Add(this->btn_specular_map_search);
			this->gb_specular_map->Location = System::Drawing::Point(12, 94);
			this->gb_specular_map->Name = L"gb_specular_map";
			this->gb_specular_map->Size = System::Drawing::Size(478, 75);
			this->gb_specular_map->TabIndex = 13;
			this->gb_specular_map->TabStop = false;
			this->gb_specular_map->Text = L"Specular Map (G Channel)";
			// 
			// gb_glow_map
			// 
			this->gb_glow_map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gb_glow_map->Controls->Add(this->cb_glow_map);
			this->gb_glow_map->Controls->Add(this->tb_glow_map);
			this->gb_glow_map->Controls->Add(this->btn_glow_map);
			this->gb_glow_map->Location = System::Drawing::Point(12, 175);
			this->gb_glow_map->Name = L"gb_glow_map";
			this->gb_glow_map->Size = System::Drawing::Size(478, 75);
			this->gb_glow_map->TabIndex = 14;
			this->gb_glow_map->TabStop = false;
			this->gb_glow_map->Text = L"Glow Map (B Channel)";
			// 
			// gb_reflectivity_map
			// 
			this->gb_reflectivity_map->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->gb_reflectivity_map->Controls->Add(this->tb_reflectivity_map);
			this->gb_reflectivity_map->Controls->Add(this->cb_reflectivity_map);
			this->gb_reflectivity_map->Controls->Add(this->btn_reflectivity_map);
			this->gb_reflectivity_map->Location = System::Drawing::Point(12, 256);
			this->gb_reflectivity_map->Name = L"gb_reflectivity_map";
			this->gb_reflectivity_map->Size = System::Drawing::Size(478, 75);
			this->gb_reflectivity_map->TabIndex = 15;
			this->gb_reflectivity_map->TabStop = false;
			this->gb_reflectivity_map->Text = L"Reflectivity Map (A Channel)";
			// 
			// btn_convert
			// 
			this->btn_convert->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btn_convert->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->btn_convert->Location = System::Drawing::Point(390, 337);
			this->btn_convert->Name = L"btn_convert";
			this->btn_convert->Size = System::Drawing::Size(100, 35);
			this->btn_convert->TabIndex = 16;
			this->btn_convert->Text = L"Convert";
			this->btn_convert->UseVisualStyleBackColor = true;
			this->btn_convert->Click += gcnew System::EventHandler(this, &MainGui::btn_convert_Click);
			// 
			// MainGui
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(502, 384);
			this->Controls->Add(this->btn_convert);
			this->Controls->Add(this->gb_reflectivity_map);
			this->Controls->Add(this->gb_glow_map);
			this->Controls->Add(this->gb_specular_map);
			this->Controls->Add(this->gb_alpha_mask);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainGui";
			this->ShowIcon = false;
			this->Text = L"SM Asg Compiler";
			this->gb_alpha_mask->ResumeLayout(false);
			this->gb_alpha_mask->PerformLayout();
			this->gb_specular_map->ResumeLayout(false);
			this->gb_specular_map->PerformLayout();
			this->gb_glow_map->ResumeLayout(false);
			this->gb_glow_map->PerformLayout();
			this->gb_reflectivity_map->ResumeLayout(false);
			this->gb_reflectivity_map->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		System::Void cb_alpha_mask_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void cb_specular_map_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void cb_glow_map_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void cb_reflectivity_map_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_alpha_mask_search_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_specular_map_search_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_glow_map_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_reflectivity_map_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void btn_convert_Click(System::Object^ sender, System::EventArgs^ e);
	};
}