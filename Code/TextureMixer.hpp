#pragma once

#pragma unmanaged

#include <string>

class MixerCore
{
public:
	inline static std::wstring LastPickedDirectory = L"";
	inline static std::wstring LastPickedName = L"";
	inline static std::wstring LastPickedPath = L"";

	static std::wstring RunMixer(
		const std::wstring& r_tex_path,
		const std::wstring& g_tex_path,
		const std::wstring& b_tex_path,
		const std::wstring& a_tex_path);
};

#pragma managed