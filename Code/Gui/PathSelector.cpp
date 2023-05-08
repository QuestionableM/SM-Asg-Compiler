#include "PathSelector.h"

#include "Utils/File.hpp"

#include "TextureMixer.hpp"
#include "GuiCommon.hpp"

#include <msclr/marshal_cppstd.h>

namespace SMAsgCompiler
{
	PathSelector::PathSelector()
	{
		this->InitializeComponent();

		if (!MixerCore::LastPickedDirectory.empty())
			tb_selected_path->Text = gcnew System::String(MixerCore::LastPickedDirectory.c_str());

		if (!MixerCore::LastPickedName.empty())
			tb_texture_name->Text = gcnew System::String(MixerCore::LastPickedName.c_str());
	}

	PathSelector::~PathSelector()
	{
		if (components) delete components;
	}

	void PathSelector::btn_select_path_Click(System::Object^ sender, System::EventArgs^ e)
	{
		const std::wstring v_out_path = File::OpenFileDialog(
			L"Select a Texture Output Path",
			FOS_PICKFOLDERS | FOS_PATHMUSTEXIST,
			L"All Files (*.*)\000*.*\000",
			reinterpret_cast<HWND>(this->Handle.ToPointer())
		);

		if (!v_out_path.empty())
			tb_selected_path->Text = gcnew System::String(v_out_path.c_str());
	}
	
	void PathSelector::tb_selected_path_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		btn_convert->Enabled = (tb_selected_path->TextLength > 0 && tb_texture_name->TextLength > 0);
	}

	void PathSelector::tb_texture_name_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		btn_convert->Enabled = (tb_selected_path->TextLength > 0 && tb_texture_name->TextLength > 0);
	}

	void PathSelector::btn_convert_Click(System::Object^ sender, System::EventArgs^ e)
	{
		const std::wstring v_output_name = msclr::interop::marshal_as<std::wstring>(tb_texture_name->Text);
		const std::wstring v_output_directory = msclr::interop::marshal_as<std::wstring>(tb_selected_path->Text);
		if (v_output_directory.empty())
		{
			GuiCommon::ShowWarningBox(L"Empty Path", L"The path to the folder must be specified!");
			return;
		}

		if (!File::Exists(v_output_directory))
		{
			GuiCommon::ShowWarningBox(L"Invalid Path", L"The path to the folder is invalid!");
			return;
		}

		if (!File::IsDirectory(v_output_directory))
		{
			GuiCommon::ShowWarningBox(L"Invalid Path", L"The path must lead to a folder!");
			return;
		}

		std::wstring v_output_name_fixed = v_output_name;
		const std::size_t v_last_dot = v_output_name_fixed.find_last_of(L'.');
		if (v_last_dot != std::wstring::npos)
		{
			const std::wstring v_chunk = v_output_name_fixed.substr(0, v_last_dot);
			v_output_name_fixed = v_output_name_fixed.substr(0, v_last_dot) + L".tga";
		}
		else
		{
			v_output_name_fixed.append(L".tga");
		}

		const std::wstring v_output_path = v_output_directory + L"\\" + v_output_name_fixed;
		if (!File::IsPathValid(v_output_path))
		{
			GuiCommon::ShowWarningBox(L"Invalid Texture Name", L"Texture name is invalid!\n\nTry a different one");
			return;
		}

		if (File::Exists(v_output_path))
		{
			System::Windows::Forms::DialogResult v_result = System::Windows::Forms::MessageBox::Show(
				L"The specified texture already exists.\n\nWould you like to replace it?",
				L"Texture Exists",
				System::Windows::Forms::MessageBoxButtons::YesNo,
				System::Windows::Forms::MessageBoxIcon::Question
			);

			if (v_result != System::Windows::Forms::DialogResult::Yes)
				return;
		}
			

		MixerCore::LastPickedDirectory = v_output_directory;
		MixerCore::LastPickedName = v_output_name;
		MixerCore::LastPickedPath = v_output_path;

		this->is_ready = true;
		this->Close();
	}
}