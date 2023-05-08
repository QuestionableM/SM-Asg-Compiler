#include "MainGui.h"

#include "TextureMixer.hpp"
#include "PathSelector.h"
#include "GuiCommon.hpp"

#include "Utils/File.hpp"

#include <msclr/marshal_cppstd.h>

namespace SMAsgCompiler
{
	MainGui::MainGui()
	{
		this->InitializeComponent();

		this->cb_alpha_mask->Checked = true;
		this->cb_specular_map->Checked = true;
		this->cb_glow_map->Checked = true;
		this->cb_reflectivity_map->Checked = true;
	}

	MainGui::~MainGui()
	{
		if (components) delete components;
	}

	void MainGui::cb_alpha_mask_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->tb_alpha_mask_path->Enabled = this->cb_alpha_mask->Checked;
		this->btn_alpha_mask_search->Enabled = this->cb_alpha_mask->Checked;
	}

	void MainGui::cb_specular_map_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->tb_specular_map->Enabled = this->cb_specular_map->Checked;
		this->btn_specular_map_search->Enabled = this->cb_specular_map->Checked;
	}

	void MainGui::cb_glow_map_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->tb_glow_map->Enabled = this->cb_glow_map->Checked;
		this->btn_glow_map->Enabled = this->cb_glow_map->Checked;
	}

	void MainGui::cb_reflectivity_map_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->tb_reflectivity_map->Enabled = this->cb_reflectivity_map->Checked;
		this->btn_reflectivity_map->Enabled = this->cb_reflectivity_map->Checked;
	}

	void MainGui::btn_alpha_mask_search_Click(System::Object^ sender, System::EventArgs^ e)
	{
		const std::wstring v_path = File::OpenFileDialog(
			L"Select an Alpha Mask",
			FOS_FILEMUSTEXIST | FOS_PATHMUSTEXIST,
			L"All Files (*.*)\000*.*\000",
			reinterpret_cast<HWND>(this->Handle.ToPointer()));

		if (!v_path.empty())
			this->tb_alpha_mask_path->Text = gcnew System::String(v_path.c_str());
	}

	void MainGui::btn_specular_map_search_Click(System::Object^ sender, System::EventArgs^ e)
	{
		const std::wstring v_path = File::OpenFileDialog(
			L"Select a Specular Map",
			FOS_FILEMUSTEXIST | FOS_PATHMUSTEXIST,
			L"All Files (*.*)\000*.*\000",
			reinterpret_cast<HWND>(this->Handle.ToPointer()));

		if (!v_path.empty())
			this->tb_specular_map->Text = gcnew System::String(v_path.c_str());
	}

	void MainGui::btn_glow_map_Click(System::Object^ sender, System::EventArgs^ e)
	{
		const std::wstring v_path = File::OpenFileDialog(
			L"Select a Glow Map",
			FOS_FILEMUSTEXIST | FOS_PATHMUSTEXIST,
			L"All Files (*.*)\000*.*\000",
			reinterpret_cast<HWND>(this->Handle.ToPointer()));

		if (!v_path.empty())
			this->tb_glow_map->Text = gcnew System::String(v_path.c_str());
	}

	void MainGui::btn_reflectivity_map_Click(System::Object^ sender, System::EventArgs^ e)
	{
		const std::wstring v_path = File::OpenFileDialog(
			L"Select a Reflectivity Map",
			FOS_FILEMUSTEXIST | FOS_PATHMUSTEXIST,
			L"All Files (*.*)\000*.*\000",
			reinterpret_cast<HWND>(this->Handle.ToPointer()));

		if (!v_path.empty())
			this->tb_reflectivity_map->Text = gcnew System::String(v_path.c_str());
	}

	void MainGui::btn_convert_Click(System::Object^ sender, System::EventArgs^ e)
	{
		static const wchar_t* SpecifiedWarnings[4] =
		{
			L"Path to Alpha Mask must be specified!",
			L"Path to Specular Map must be specified!",
			L"Path to Glow Map must be specified!",
			L"Path to Reflectivity Map must be specified!"
		};

		static const wchar_t* ExistWarnings[4] =
		{
			L"Path to Alpha Mask is invalid!"
			L"Path to Specular Map is invalid!",
			L"Path to Glow Map is invalid!",
			L"Path to Reflectivity Map is invalid!"
		};

		static const wchar_t* IsRegFileWarnings[4] =
		{
			L"Alpha Mask path must lead to a file!",
			L"Specular Map path must lead to a file!",
			L"Glow Map path must lead to a file!",
			L"Reflectivity Map path must lead to a file!"
		};

		std::wstring v_alpha_mask_path = msclr::interop::marshal_as<std::wstring>(tb_alpha_mask_path->Text);
		std::wstring v_specular_map = msclr::interop::marshal_as<std::wstring>(tb_specular_map->Text);
		std::wstring v_glow_map = msclr::interop::marshal_as<std::wstring>(tb_glow_map->Text);
		std::wstring v_reflectivity_map = msclr::interop::marshal_as<std::wstring>(tb_reflectivity_map->Text);

		std::wstring* v_str_ptrs[4] =
		{
			&v_alpha_mask_path,
			&v_specular_map,
			&v_glow_map,
			&v_reflectivity_map
		};

		const bool v_str_flags[4] =
		{
			cb_alpha_mask->Checked,
			cb_specular_map->Checked,
			cb_glow_map->Checked,
			cb_reflectivity_map->Checked
		};

		for (std::size_t a = 0; a < 4; a++)
		{
			if (!v_str_flags[a])
			{
				v_str_ptrs[a]->clear();
				continue;
			}

			if (v_str_ptrs[a]->empty())
			{
				GuiCommon::ShowWarningBox(L"Empty Path", SpecifiedWarnings[a]);
				return;
			}

			if (!File::Exists(*v_str_ptrs[a]))
			{
				GuiCommon::ShowWarningBox(L"Invalid Path", ExistWarnings[a]);
				return;
			}

			if (!File::IsRegularFile(*v_str_ptrs[a]))
			{
				GuiCommon::ShowWarningBox(L"Invalid Path", IsRegFileWarnings[a]);
				return;
			}
		}

		PathSelector^ v_selector = gcnew PathSelector();
		v_selector->ShowDialog();

		if (!v_selector->is_ready)
			return;

		const std::wstring v_message = MixerCore::RunMixer(v_alpha_mask_path, v_specular_map, v_glow_map, v_reflectivity_map);
		if (v_message.empty())
			GuiCommon::ShowInfoBox(L"Success", L"Textures have been combined successfully!");
		else
			GuiCommon::ShowInfoBox(L"Error", v_message.c_str());
	}
}