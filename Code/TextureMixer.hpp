#pragma once

#pragma unmanaged

#include <string>

namespace MixerCore
{
	std::wstring RunMixer(
		const std::wstring& r_tex_path,
		const std::wstring& g_tex_path,
		const std::wstring& b_tex_path,
		const std::wstring& a_tex_path);
}

#pragma managed