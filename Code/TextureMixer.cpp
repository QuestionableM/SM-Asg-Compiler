#include "TextureMixer.hpp"

#pragma unmanaged

#include <FreeImage.h>

struct ImageData
{
	FIBITMAP* image_data;
	int width, height;
	std::wstring img_path;

	~ImageData()
	{
		if (image_data)
			FreeImage_Unload(image_data);
	}

	static ImageData* LoadImage(const std::wstring& path, int& original_width, int& original_height, std::wstring& error_msg)
	{
		FREE_IMAGE_FORMAT v_fiFormat = FreeImage_GetFileTypeU(path.c_str());
		if (v_fiFormat == FIF_UNKNOWN)
			v_fiFormat = FreeImage_GetFIFFromFilenameU(path.c_str());

		if (v_fiFormat == FIF_UNKNOWN)
		{
			error_msg = L"Unknown texture format!";
			return nullptr;
		}

		FIBITMAP* v_imgData = FreeImage_LoadU(v_fiFormat, path.c_str());
		if (!v_imgData)
		{
			error_msg = L"Couldn't load the specified path: " + path;
			return nullptr;
		}

		const int v_imgWidth = FreeImage_GetWidth(v_imgData);
		const int v_imgHeight = FreeImage_GetHeight(v_imgData);

		if (original_height != 0 && original_width != 0)
		{
			if (v_imgWidth != original_width || v_imgHeight != original_height)
			{
				error_msg = L"All textures should have the same size!";
				FreeImage_Unload(v_imgData);
				return nullptr;
			}
		}
		else
		{
			original_width = v_imgWidth;
			original_height = v_imgHeight;
		}

		ImageData* v_new_image = new ImageData();
		v_new_image->img_path = path;
		v_new_image->width = v_imgWidth;
		v_new_image->height = v_imgHeight;
		v_new_image->image_data = v_imgData;

		return v_new_image;
	}

	template<int t_channel_id>
	void CombineFibitmaps(FIBITMAP* output)
	{
		RGBQUAD v_rgb_data, v_src_data;

		for (int y = 0; y < this->height; y++)
		{
			for (int x = 0; x < this->width; x++)
			{
				FreeImage_GetPixelColor(this->image_data, x, y, &v_src_data);
				FreeImage_GetPixelColor(output, x, y, &v_rgb_data);

				if constexpr (t_channel_id == 0) {
					v_rgb_data.rgbRed = v_src_data.rgbRed;
				} else if constexpr (t_channel_id == 1) {
					v_rgb_data.rgbGreen = v_src_data.rgbRed;
				} else if constexpr (t_channel_id == 2) {
					v_rgb_data.rgbBlue = v_src_data.rgbRed;
				} else if constexpr (t_channel_id == 3) {
					v_rgb_data.rgbReserved = v_src_data.rgbRed;
				}

				FreeImage_SetPixelColor(output, x, y, &v_rgb_data);
			}
		}
	}
};

std::wstring MixerCore::RunMixer(
	const std::wstring& r_tex_path,
	const std::wstring& g_tex_path,
	const std::wstring& b_tex_path,
	const std::wstring& a_tex_path)
{
	std::wstring v_output_msg;
	ImageData* v_image_array[4];
	std::memset(v_image_array, 0, sizeof(v_image_array));

	int orig_width = 0, orig_height = 0;
	const std::wstring* v_paths[4] =
	{
		&r_tex_path,
		&g_tex_path,
		&b_tex_path,
		&a_tex_path
	};

	for (std::size_t a = 0; a < 4; a++)
	{
		if (v_paths[a]->empty()) continue;

		v_image_array[a] = ImageData::LoadImage(*v_paths[a], orig_width, orig_height, v_output_msg);
		if (!v_image_array[a])
		{
			for (std::size_t b = 0; b < 4; b++)
				if (v_image_array[b]) delete v_image_array[b];

			return v_output_msg;
		}
	}

	FIBITMAP* v_output_image = FreeImage_Allocate(orig_width, orig_height, 32);

	v_image_array[0]->CombineFibitmaps<0>(v_output_image);
	v_image_array[1]->CombineFibitmaps<1>(v_output_image);
	v_image_array[2]->CombineFibitmaps<2>(v_output_image);
	v_image_array[3]->CombineFibitmaps<3>(v_output_image);

	FreeImage_SaveU(FIF_TARGA, v_output_image, L"./OutputImage.tga");
	FreeImage_Unload(v_output_image);

	for (std::size_t b = 0; b < 4; b++)
		if (v_image_array[b]) delete v_image_array[b];

	return L"";
}