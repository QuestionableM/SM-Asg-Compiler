#include "File.hpp"

#pragma unmanaged

#include <ShlObj.h>
#include <filesystem>

bool File::Exists(const std::wstring& path)
{
	namespace fs = std::filesystem;

	std::error_code v_ec;
	const bool v_exists = fs::exists(path, v_ec);
	return v_exists && !v_ec;
}

bool File::IsDirectory(const std::wstring& path)
{
	namespace fs = std::filesystem;

	std::error_code v_ec;
	const bool v_is_dir = fs::is_directory(path, v_ec);

	return v_is_dir && !v_ec;
}

bool File::IsRegularFile(const std::wstring& path)
{
	namespace fs = std::filesystem;

	std::error_code v_ec;
	const bool v_is_file = fs::is_regular_file(path, v_ec);

	return v_is_file && !v_ec;
}

bool File::IsPathValid(const std::wstring& path)
{
	namespace fs = std::filesystem;

	std::error_code v_ec;
	const bool exists = fs::exists(path, v_ec);

	return !v_ec;
}

std::wstring File::OpenFileDialog(
	const std::wstring& title,
	FILEOPENDIALOGOPTIONS options,
	LPCWSTR filter,
	HWND owner
) {
	std::wstring _Output = L"";

	CoUninitialize();
	HRESULT hr = CoInitializeEx(NULL, COINIT_DISABLE_OLE1DDE | COINIT_APARTMENTTHREADED);

	if (SUCCEEDED(hr))
	{
		IFileOpenDialog* pFileOpen;

		hr = CoCreateInstance(CLSID_FileOpenDialog, NULL, CLSCTX_ALL,
			IID_IFileOpenDialog, reinterpret_cast<void**>(&pFileOpen));

		if (SUCCEEDED(hr))
		{
			pFileOpen->SetOptions(options);
			pFileOpen->SetTitle(title.c_str());
			hr = pFileOpen->Show(owner);

			if (SUCCEEDED(hr))
			{
				IShellItem* pItem;
				hr = pFileOpen->GetResult(&pItem);
				if (SUCCEEDED(hr))
				{
					PWSTR pszFilePath;
					hr = pItem->GetDisplayName(SIGDN_FILESYSPATH, &pszFilePath);

					if (SUCCEEDED(hr))
					{
						_Output = std::wstring(pszFilePath);
						CoTaskMemFree(pszFilePath);
					}

					pItem->Release();
				}
			}
			pFileOpen->Release();
		}
		CoUninitialize();
	}

	return _Output;
}