#include "GuiCommon.hpp"

namespace WForms = System::Windows::Forms;

WForms::DialogResult GuiCommon::MessageBoxOk(const std::wstring& title, const std::wstring& message, WForms::MessageBoxIcon icon)
{
	return WForms::MessageBox::Show(
		gcnew System::String(message.c_str()),
		gcnew System::String(title.c_str()),
		WForms::MessageBoxButtons::OK,
		icon
	);
}

WForms::DialogResult GuiCommon::ShowWarningBox(const std::wstring& title, const std::wstring& message)
{
	return GuiCommon::MessageBoxOk(title, message, System::Windows::Forms::MessageBoxIcon::Warning);
}

WForms::DialogResult GuiCommon::ShowErrorBox(const std::wstring& title, const std::wstring& message)
{
	return GuiCommon::MessageBoxOk(title, message, System::Windows::Forms::MessageBoxIcon::Error);
}

WForms::DialogResult GuiCommon::ShowInfoBox(const std::wstring& title, const std::wstring& message)
{
	return GuiCommon::MessageBoxOk(title, message, System::Windows::Forms::MessageBoxIcon::Information);
}