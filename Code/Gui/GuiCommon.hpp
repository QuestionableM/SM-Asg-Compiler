#pragma once

#pragma unmanaged
#include <string>
#pragma managed

namespace GuiCommon
{
	System::Windows::Forms::DialogResult MessageBoxOk(const std::wstring& title, const std::wstring& message, System::Windows::Forms::MessageBoxIcon icon);

	System::Windows::Forms::DialogResult ShowWarningBox(const std::wstring& title, const std::wstring& message);
	System::Windows::Forms::DialogResult ShowErrorBox(const std::wstring& title, const std::wstring& message);
	System::Windows::Forms::DialogResult ShowInfoBox(const std::wstring& title, const std::wstring& message);
}