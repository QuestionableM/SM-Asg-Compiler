#pragma once

#pragma unmanaged

#include <ShObjIdl.h>
#include <string>

namespace File
{
	bool Exists(const std::wstring& path);

	std::wstring OpenFileDialog(
		const std::wstring& title,
		FILEOPENDIALOGOPTIONS options = 0,
		LPCWSTR filter = L"All Files (*.*)\0*.*\0",
		HWND owner = NULL
	);
}

#pragma managed